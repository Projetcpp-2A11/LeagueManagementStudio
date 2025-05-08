#define SDL_MAIN_HANDLED
#include "simulationrun.h"

#include "simulation.h"
#include "connection.h"
#include "match.h"

#include <QApplication>
#include <QDebug>
#include <QStringList>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <cstdlib>
#include <ctime>

// Inclure les fonctions de dessin, mouvement, etc., selon besoin

int SimulationRun::run(int matchId) {
    int argc = 0;
    char** argv = nullptr;
    QApplication a(argc, argv);

    if (matchId == -1) {
        qDebug() << "Aucun MATCHID fourni, utilisation de l’ID par défaut 541";
        matchId = 541;
    }

    connection conn;
    if (!conn.createconnect()) {
        qDebug() << "Échec de connexion à la base!";
        return 1;
    }

    Match m;
    QString team1, team2, scoreStr;
    if (!m.fetchMatchData(matchId, team1, team2, scoreStr)) {
        qDebug() << "Match non trouvé!";
        return 1;
    }

    QStringList scores = scoreStr.split("-");
    if (scores.size() != 2) {
        qDebug() << "Format de score invalide!";
        return 1;
    }

    BLUE_TEAM_NAME = strdup(team1.toStdString().c_str());
    RED_TEAM_NAME = strdup(team2.toStdString().c_str());

    MatchStats stats;
    // Initialiser les scores à 0
    stats.blueScore = 0;
    stats.redScore = 0;

    // Récupérer le nombre de buts pour chaque équipe
    int blueGoals = scores[0].toInt();
    int redGoals = scores[1].toInt();

    // Générer les buts pour la première et deuxième mi-temps
    std::vector<Goal> firstHalfGoals;
    std::vector<Goal> secondHalfGoals;

    // Répartir les buts de l'équipe bleue
    for (int i = 0; i < blueGoals; ++i) {
        Goal goal;
        goal.isBlueTeam = true;
        if (rand() % 2 == 0) {
            goal.time = rand() % HALF_TIME_DURATION; // Mi-temps 1
            firstHalfGoals.push_back(goal);
        } else {
            goal.time = rand() % HALF_TIME_DURATION; // Mi-temps 2 (temps relatif)
            secondHalfGoals.push_back(goal);
        }
    }

    // Répartir les buts de l'équipe rouge
    for (int i = 0; i < redGoals; ++i) {
        Goal goal;
        goal.isBlueTeam = false;
        if (rand() % 2 == 0) {
            goal.time = rand() % HALF_TIME_DURATION;
            firstHalfGoals.push_back(goal);
        } else {
            goal.time = rand() % HALF_TIME_DURATION; // Temps relatif
            secondHalfGoals.push_back(goal);
        }
    }

    // Trier les buts par temps dans chaque mi-temps
    std::sort(firstHalfGoals.begin(), firstHalfGoals.end(), [](const Goal& a, const Goal& b) {
        return a.time < b.time;
    });
    std::sort(secondHalfGoals.begin(), secondHalfGoals.end(), [](const Goal& a, const Goal& b) {
        return a.time < b.time;
    });
    if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0) {
        std::cerr << "ERREUR SDL_Init: " << SDL_GetError() << std::endl;
        return 1;
    }

    window = SDL_CreateWindow("Football Simulator Pro",
                              SDL_WINDOWPOS_CENTERED,
                              SDL_WINDOWPOS_CENTERED,
                              SCREEN_WIDTH,
                              SCREEN_HEIGHT,
                              0);

    if(!window) {
        std::cerr << "Erreur création fenêtre: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if(!renderer) {
        std::cerr << "Erreur création renderer: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    if (TTF_Init() == -1) {
        std::cerr << "Erreur TTF_Init: " << TTF_GetError() << std::endl;
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        std::cerr << "Erreur Mix_OpenAudio: " << Mix_GetError() << std::endl;
        TTF_Quit();
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }


    // Force l'affichage de la fenêtre
    SDL_ShowWindow(window);
    // Corriger les chemins des polices
    fontScore = TTF_OpenFont("C:/Users/choua/OneDrive/Bureau/Projet C++/LMS/font/OpenSans-Bold.ttf", 36);
    fontNormal = TTF_OpenFont("C:/Users/choua/OneDrive/Bureau/Projet C++/LMS/font/OpenSans-Bold.ttf", 24);
    fontFormation = TTF_OpenFont("C:/Users/choua/OneDrive/Bureau/Projet C++/LMS/font/OpenSans-Bold.ttf", FORMATION_FONT_SIZE);
    fontCoach = TTF_OpenFont("C:/Users/choua/OneDrive/Bureau/Projet C++/LMS/font/OpenSans-Bold.ttf", COACH_FONT_SIZE);

    // Corriger le chemin de la musique
    music = Mix_LoadMUS("C:/Users/choua/OneDrive/Bureau/Projet C++/LMS/song/manchester-united-football-club-55798.mp3");
    whistleSound = Mix_LoadWAV("C:/Users/choua/OneDrive/Bureau/Projet C++/LMS/song/referee-whistle-blow-gymnasium-6320.mp3");
    if (!whistleSound) {
        std::cerr << "Erreur chargement sifflet: " << Mix_GetError() << std::endl;
    }

    std::vector<Entity> blueTeam, redTeam;
    Ball ball = {{SCREEN_WIDTH/2, SCREEN_HEIGHT/2}, {SCREEN_WIDTH/2, SCREEN_HEIGHT/2}};


    createTeam(0, 0, 255,
               {0, (SCREEN_HEIGHT - FIELD_HEIGHT)/2, 30, FIELD_HEIGHT},
               {50, (SCREEN_HEIGHT - FIELD_HEIGHT)/2 + 50, 150, FIELD_HEIGHT - 100},
               {200, (SCREEN_HEIGHT - FIELD_HEIGHT)/2 + 50, 150, FIELD_HEIGHT - 100},
               {350, (SCREEN_HEIGHT - FIELD_HEIGHT)/2 + 50, 150, FIELD_HEIGHT - 100},
               blueTeam);

    createTeam(255, 0, 0,
               {SCREEN_WIDTH - 30, (SCREEN_HEIGHT - FIELD_HEIGHT)/2, 30, FIELD_HEIGHT},
               {SCREEN_WIDTH - 200, (SCREEN_HEIGHT - FIELD_HEIGHT)/2 + 50, 150, FIELD_HEIGHT - 100},
               {SCREEN_WIDTH - 350, (SCREEN_HEIGHT - FIELD_HEIGHT)/2 + 50, 150, FIELD_HEIGHT - 100},
               {SCREEN_WIDTH - 500, (SCREEN_HEIGHT - FIELD_HEIGHT)/2 + 50, 150, FIELD_HEIGHT - 100},
               redTeam);

    bool quit = false;
    SDL_Event event;
    GameState gameState = PRE_MATCH;
    int gameTime = 0;
    bool isFirstHalf = true;
    int alpha = 0;
    bool textFadingIn = false;
    Uint32 preMatchStartTime = SDL_GetTicks();
    int currentTeamInfo = 0;
    bool musicStopped = false;
    // Variables de contrôle audio
    bool whistleKickOffPlayed = false;
    bool whistleHalfTimePlayed = false;
    bool whistleFullTimePlayed = false;


    while (!quit) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) quit = true;
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        drawStadium(renderer);
        drawField(renderer);

        if (gameState == PRE_MATCH) {
            Uint32 elapsed = SDL_GetTicks() - preMatchStartTime;

            if (currentTeamInfo == 0) {
                showPreMatchScreen(BLUE_TEAM_NAME, "4-4-2", "Erik Ten Hag",
                                   preMatchStartTime, {30, 144, 255, 255});
                if (elapsed > PRE_MATCH_DURATION) {
                    currentTeamInfo++;
                    preMatchStartTime = SDL_GetTicks();
                }
            }
            else if (currentTeamInfo == 1) {
                showPreMatchScreen(RED_TEAM_NAME, "4-3-3", "Luis Enrique",
                                   preMatchStartTime, {220, 20, 60, 255});
                if (elapsed > PRE_MATCH_DURATION) {
                    currentTeamInfo++;
                    preMatchStartTime = SDL_GetTicks();
                }
            }
            else {
                float alpha = std::min(255.0f, (SDL_GetTicks() - preMatchStartTime) * 0.5f);
                if (alpha > 255) alpha = 510 - alpha;

                SDL_Color color = {255, 0, 0, static_cast<Uint8>(alpha)};
                drawText(renderer, "KICK-OFF!",
                         SCREEN_WIDTH/2 +100 , SCREEN_HEIGHT/2 ,
                         color, fontScore, true);

                if (SDL_GetTicks() - preMatchStartTime > 3000) {
                    gameState = PLAYING;
                    if (!whistleKickOffPlayed && whistleSound) {
                        Mix_PlayChannel(-1, whistleSound, 0);
                        whistleKickOffPlayed = true;
                    }
                    Mix_PlayMusic(music, -1);
                }
            }
        }

        if (gameState == PLAYING) {
            gameTime++;

            std::vector<Goal>& currentGoals = isFirstHalf ? firstHalfGoals : secondHalfGoals;
            if (gameTime >= HALF_TIME_DURATION) {
                if (isFirstHalf) {
                    gameState = HALF_TIME;
                    firstHalfGoals = stats.goals;
                    gameTime = 0;
                    isFirstHalf = false;
                } else {
                    gameState = MATCH_END;
                }
                alpha = 0;
                textFadingIn = true;
            }

            // Dans la boucle principale, pendant l'état PLAYING :


            if (!currentGoals.empty() && gameTime >= currentGoals.front().time) {
                if (whistleSound) {
                    Mix_PlayChannel(-1, whistleSound, 0);
                }
                Goal goal = currentGoals.front();
                currentGoals.erase(currentGoals.begin());

                if (goal.isBlueTeam) stats.blueScore++;
                else stats.redScore++;

                // Ajouter le message de but
                GoalMessage message;
                message.text = "BUT! " + std::string(goal.isBlueTeam ? BLUE_TEAM_NAME : RED_TEAM_NAME) + " " +
                               std::to_string(stats.blueScore) + "-" + std::to_string(stats.redScore) +
                               " (" + formatTime(goal.time, isFirstHalf) + ")";
                message.duration = GOAL_MESSAGE_DURATION;
                message.alpha = 255;
                message.color = {255, 255, 255, 255};
                stats.goalMessages.push_back(message);

                // Animation flash
                stats.flashAlpha = 128;
                stats.flashColor = goal.isBlueTeam ? SDL_Color{0, 0, 255, 128} : SDL_Color{255, 0, 0, 128};

                // Réinitialiser la position de la balle
                ball.position = {SCREEN_WIDTH/2 + rand()%100-50, SCREEN_HEIGHT/2 + rand()%100-50};
                ball.target = {SCREEN_WIDTH/2, SCREEN_HEIGHT/2};
                ball.speed = 2.0f;
            }

            std::vector<Entity> allPlayers = blueTeam;
            allPlayers.insert(allPlayers.end(), redTeam.begin(), redTeam.end());
            moveBall(ball, allPlayers, stats);

            stats.displayedBlueScore += (stats.blueScore - stats.displayedBlueScore) * SCORE_ANIMATION_SPEED;
            stats.displayedRedScore += (stats.redScore - stats.displayedRedScore) * SCORE_ANIMATION_SPEED;

            if(std::abs(stats.displayedBlueScore - stats.blueScore) < 0.1f)
                stats.displayedBlueScore = stats.blueScore;
            if(std::abs(stats.displayedRedScore - stats.redScore) < 0.1f)
                stats.displayedRedScore = stats.redScore;

            (ball.position.x < SCREEN_WIDTH/2) ? stats.possessionRed++ : stats.possessionBlue++;

            for (auto& p : blueTeam) movePlayer(p, blueTeam, stats);
            for (auto& p : redTeam) movePlayer(p, redTeam, stats);

            for (auto it = stats.goalMessages.begin(); it != stats.goalMessages.end();) {
                it->duration -= 2;
                it->alpha = std::max(0, std::min(255, (it->duration * 255) / GOAL_MESSAGE_DURATION));
                if (it->duration <= 0) {
                    it = stats.goalMessages.erase(it);
                } else {
                    ++it;
                }
            }

            if (stats.flashAlpha > 0) {
                stats.flashAlpha -= 8;
                if (stats.flashAlpha < 0) stats.flashAlpha = 0;
            }

            drawScoreboard(renderer, stats, isFirstHalf, gameTime);

            for (auto& p : blueTeam) {
                SDL_SetRenderDrawColor(renderer, p.color.r, p.color.g, p.color.b, 255);
                drawCircle(renderer, p.position.x, p.position.y, PLAYER_SIZE);
                drawPlayerNumber(renderer, p, fontNormal);
            }
            for (auto& p : redTeam) {
                SDL_SetRenderDrawColor(renderer, p.color.r, p.color.g, p.color.b, 255);
                drawCircle(renderer, p.position.x, p.position.y, PLAYER_SIZE);
                drawPlayerNumber(renderer, p, fontNormal);
            }
            SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
            drawCircle(renderer, ball.position.x, ball.position.y, BALL_RADIUS);

            if (!stats.goalMessages.empty()) {
                drawGoalMessages(renderer, stats.goalMessages);
            }

            if (stats.flashAlpha > 0) {
                SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
                SDL_SetRenderDrawColor(renderer, stats.flashColor.r, stats.flashColor.g, stats.flashColor.b, stats.flashAlpha);
                SDL_Rect flashRect = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};
                SDL_RenderFillRect(renderer, &flashRect);
            }
        }

        if (gameState == HALF_TIME) {
            if (whistleSound) {
                Mix_PlayChannel(-1, whistleSound, 0);
            }
            if (textFadingIn) {
                alpha = std::min(alpha + TEXT_FADE_SPEED, 255);
                if (alpha == 255) {
                    SDL_Delay(2000);
                    textFadingIn = false;
                }
            } else {
                alpha = std::max(alpha - TEXT_FADE_SPEED, 0);
                if (alpha == 0) {
                    gameState = PLAYING;
                    isFirstHalf = false;
                    gameTime = 0;
                    stats.goals.clear();
                    ball = {{SCREEN_WIDTH/2, SCREEN_HEIGHT/2}, {SCREEN_WIDTH/2, SCREEN_HEIGHT/2}};
                }
            }

            SDL_Color textColor = {255, 0, 0, static_cast<Uint8>(alpha)};
            drawText(renderer, "HALF-TIME!", SCREEN_WIDTH/2 - 100, SCREEN_HEIGHT/2 - 30, textColor, fontScore);
        }

        if (gameState == MATCH_END) {
            if (!whistleFullTimePlayed && whistleSound) {
                Mix_PlayChannel(-1, whistleSound, 0);
                whistleFullTimePlayed = true;
            }
            if (!musicStopped && Mix_PlayingMusic()) {

                Mix_HaltMusic();
                musicStopped = true;
            }

            if (alpha < 255) {
                alpha = std::min(alpha + TEXT_FADE_SPEED, 255);
                SDL_Color textColor = {255, 0, 0, static_cast<Uint8>(alpha)};
                drawText(renderer, "FULL TIME!", SCREEN_WIDTH/2 - 100, SCREEN_HEIGHT/2 - 30, textColor, fontScore);

                if (alpha == 255) {
                    SDL_Delay(MATCH_END_DELAY);
                }
            } else {
                drawStatsTable(renderer, stats);
            }
        }

        SDL_RenderPresent(renderer);
        SDL_Delay(16);
    }

    TTF_CloseFont(fontScore);
    TTF_CloseFont(fontNormal);
    TTF_CloseFont(fontFormation);
    TTF_CloseFont(fontCoach);
    Mix_FreeMusic(music);
    Mix_FreeChunk(whistleSound);

    Mix_CloseAudio();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_Quit();
    SDL_Quit();
    return 0;
}

