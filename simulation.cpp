#include "simulation.h"
#include "connection.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <QString> // Ajouter l'inclusion Qt

// Définir les noms des équipes dynamiquement
const char* BLUE_TEAM_NAME = "";
const char* RED_TEAM_NAME = "";
SDL_Window* window = nullptr;
SDL_Renderer* renderer = nullptr;
TTF_Font* fontScore = nullptr;
TTF_Font* fontNormal = nullptr;
TTF_Font* fontFormation = nullptr;
TTF_Font* fontCoach = nullptr;
Mix_Music* music = nullptr;
Mix_Chunk* whistleSound = nullptr;


void drawCircle(SDL_Renderer* renderer, int x, int y, int radius) {
    for (int w = 0; w < radius * 2; w++) {
        for (int h = 0; h < radius * 2; h++) {
            int dx = radius - w;
            int dy = radius - h;
            if ((dx*dx + dy*dy) <= (radius*radius)) {
                SDL_RenderDrawPoint(renderer, x + dx, y + dy);
            }
        }
    }
}

void drawGradientRect(SDL_Renderer* renderer, SDL_Rect rect, SDL_Color start, SDL_Color end) {
    for(int i = 0; i < rect.h; i++) {
        float ratio = (float)i / rect.h;
        Uint8 r = start.r + (end.r - start.r) * ratio;
        Uint8 g = start.g + (end.g - start.g) * ratio;
        Uint8 b = start.b + (end.b - start.b) * ratio;
        SDL_SetRenderDrawColor(renderer, r, g, b, 255);
        SDL_RenderDrawLine(renderer, rect.x, rect.y + i, rect.x + rect.w, rect.y + i);
    }
}

void drawAdvertising(SDL_Renderer* renderer) {
    static int adOffset = 0;
    static Uint32 lastUpdate = SDL_GetTicks();
    const SDL_Color adColor = {255, 255, 255, 200};
    const std::string adText = "    |  PALESTINE   |    ";

    SDL_Rect bottomAdRect = {0, SCREEN_HEIGHT - 60, SCREEN_WIDTH, 30};
    drawGradientRect(renderer, bottomAdRect, {40, 40, 40, 255}, {20, 20, 20, 255});

    if (SDL_GetTicks() - lastUpdate > 20) {
        adOffset -= 1;
        if (adOffset < -800) adOffset = 0;
        lastUpdate = SDL_GetTicks();
    }

    SDL_Surface* textSurface = TTF_RenderText_Solid(fontNormal, adText.c_str(), adColor);
    SDL_Texture* adTexture = SDL_CreateTextureFromSurface(renderer, textSurface);

    SDL_Rect bottomAdText = {
        adOffset + 800,
        SCREEN_HEIGHT - 100 + 8,
        textSurface->w,
        textSurface->h
    };

    SDL_RenderCopy(renderer, adTexture, NULL, &bottomAdText);
    SDL_FreeSurface(textSurface);
    SDL_DestroyTexture(adTexture);
}

void drawStadium(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 30, 30, 30, 255);
    SDL_Rect upperStand = {0, 0, SCREEN_WIDTH, (SCREEN_HEIGHT - FIELD_HEIGHT)/2};
    SDL_Rect lowerStand = {0, SCREEN_HEIGHT - (SCREEN_HEIGHT - FIELD_HEIGHT)/2, SCREEN_WIDTH, (SCREEN_HEIGHT - FIELD_HEIGHT)/2};
    SDL_RenderFillRect(renderer, &upperStand);
    SDL_RenderFillRect(renderer, &lowerStand);

    const int SCREEN_MARGIN_TOP = 20;
    const int STADIUM_SCREEN_W = 150;
    const int STADIUM_SCREEN_H = 80;

    SDL_Rect stadiumScreen = {
        (SCREEN_WIDTH - STADIUM_SCREEN_W)/2,
        SCREEN_MARGIN_TOP,
        STADIUM_SCREEN_W,
        STADIUM_SCREEN_H
    };

    SDL_SetRenderDrawColor(renderer, 40, 40, 40, 255);
    SDL_RenderFillRect(renderer, &stadiumScreen);

    SDL_SetRenderDrawColor(renderer, 100, 100, 100, 255);
    SDL_RenderDrawRect(renderer, &stadiumScreen);
    for(int i = 0; i < 4; i++) {
        SDL_RenderDrawLine(renderer,
                           stadiumScreen.x + 10,
                           stadiumScreen.y + 10 + i*20,
                           stadiumScreen.x + stadiumScreen.w - 10,
                           stadiumScreen.y + 10 + i*20);
    }

    for(int row = 0; row < ROWS; row++) {
        for(int col = 0; col < SCREEN_WIDTH; col += SEAT_SIZE + SEAT_SPACING) {
            if(col > stadiumScreen.x - 50 && col < stadiumScreen.x + stadiumScreen.w + 50) continue;

            SDL_SetRenderDrawColor(renderer, 218, 165, 32, 255);
            SDL_Rect seat = {
                col,
                20 + row * (SEAT_SIZE + SEAT_SPACING),
                SEAT_SIZE,
                SEAT_SIZE/2
            };
            SDL_RenderFillRect(renderer, &seat);
        }
    }

    drawAdvertising(renderer);

    static float flagWave = 0.0f;
    flagWave += 0.1f;
    const int FIELD_TOP = (SCREEN_HEIGHT - FIELD_HEIGHT)/2;
    const int FIELD_BOTTOM = SCREEN_HEIGHT - FIELD_TOP;
    const int FLAG_Y_OFFSET = 20;

    SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
    SDL_RenderDrawLine(renderer, 100, FIELD_TOP - FLAG_Y_OFFSET, 100, FIELD_TOP - FLAG_Y_OFFSET - FLAG_POLE_HEIGHT);
    SDL_Point flagTopLeft[3] = {
        {100, FIELD_TOP - FLAG_Y_OFFSET - FLAG_POLE_HEIGHT},
        {100 + 20 + static_cast<int>(sin(flagWave)*FLAG_WAVE_AMPLITUDE*2), FIELD_TOP - FLAG_Y_OFFSET - FLAG_POLE_HEIGHT},
        {100, FIELD_TOP - FLAG_Y_OFFSET - FLAG_POLE_HEIGHT + 20}
    };
    SDL_RenderDrawLines(renderer, flagTopLeft, 3);

    SDL_RenderDrawLine(renderer, SCREEN_WIDTH-100, FIELD_TOP-FLAG_Y_OFFSET, SCREEN_WIDTH-100, FIELD_TOP-FLAG_Y_OFFSET-FLAG_POLE_HEIGHT);
    SDL_Point flagTopRight[3] = {
        {SCREEN_WIDTH-100, FIELD_TOP-FLAG_Y_OFFSET-FLAG_POLE_HEIGHT},
        {SCREEN_WIDTH-100-20-static_cast<int>(sin(flagWave)*FLAG_WAVE_AMPLITUDE*2), FIELD_TOP-FLAG_Y_OFFSET-FLAG_POLE_HEIGHT},
        {SCREEN_WIDTH-100, FIELD_TOP-FLAG_Y_OFFSET-FLAG_POLE_HEIGHT+20}
    };
    SDL_RenderDrawLines(renderer, flagTopRight, 3);

    SDL_RenderDrawLine(renderer, 100, FIELD_BOTTOM+FLAG_Y_OFFSET, 100, FIELD_BOTTOM+FLAG_Y_OFFSET+FLAG_POLE_HEIGHT);
    SDL_Point flagBottomLeft[3] = {
        {100, FIELD_BOTTOM+FLAG_Y_OFFSET+FLAG_POLE_HEIGHT},
        {100+20+static_cast<int>(sin(flagWave)*FLAG_WAVE_AMPLITUDE*2), FIELD_BOTTOM+FLAG_Y_OFFSET+FLAG_POLE_HEIGHT},
        {100, FIELD_BOTTOM+FLAG_Y_OFFSET+FLAG_POLE_HEIGHT-20}
    };
    SDL_RenderDrawLines(renderer, flagBottomLeft, 3);

    SDL_RenderDrawLine(renderer, SCREEN_WIDTH-100, FIELD_BOTTOM+FLAG_Y_OFFSET, SCREEN_WIDTH-100, FIELD_BOTTOM+FLAG_Y_OFFSET+FLAG_POLE_HEIGHT);
    SDL_Point flagBottomRight[3] = {
        {SCREEN_WIDTH-100, FIELD_BOTTOM+FLAG_Y_OFFSET+FLAG_POLE_HEIGHT},
        {SCREEN_WIDTH-100-20-static_cast<int>(sin(flagWave)*FLAG_WAVE_AMPLITUDE*2), FIELD_BOTTOM+FLAG_Y_OFFSET+FLAG_POLE_HEIGHT},
        {SCREEN_WIDTH-100, FIELD_BOTTOM+FLAG_Y_OFFSET+FLAG_POLE_HEIGHT-20}
    };
    SDL_RenderDrawLines(renderer, flagBottomRight, 3);
}

void drawField(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 50, 205, 50, 255);
    SDL_Rect field = {0, (SCREEN_HEIGHT - FIELD_HEIGHT)/2, SCREEN_WIDTH, FIELD_HEIGHT};
    SDL_RenderFillRect(renderer, &field);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderDrawRect(renderer, &field);
    SDL_RenderDrawLine(renderer, SCREEN_WIDTH/2, (SCREEN_HEIGHT - FIELD_HEIGHT)/2, SCREEN_WIDTH/2, (SCREEN_HEIGHT + FIELD_HEIGHT)/2);
    drawCircle(renderer, SCREEN_WIDTH/2, SCREEN_HEIGHT/2, 50);

    SDL_Rect boxLeft = {0, (SCREEN_HEIGHT - BOX_HEIGHT)/2, BOX_WIDTH, BOX_HEIGHT};
    SDL_Rect boxRight = {SCREEN_WIDTH - BOX_WIDTH, (SCREEN_HEIGHT - BOX_HEIGHT)/2, BOX_WIDTH, BOX_HEIGHT};
    SDL_RenderDrawRect(renderer, &boxLeft);
    SDL_RenderDrawRect(renderer, &boxRight);

    SDL_SetRenderDrawColor(renderer, 200, 200, 200, 255);
    SDL_Rect leftGoal = {
        0,
        (SCREEN_HEIGHT - GOAL_HEIGHT)/2 - 10,
        GOAL_WIDTH + 20,
        GOAL_HEIGHT + 20
    };
    SDL_RenderFillRect(renderer, &leftGoal);

    SDL_SetRenderDrawColor(renderer, 100, 100, 100, 255);
    for(int y = leftGoal.y; y < leftGoal.y + leftGoal.h; y += 8) {
        for(int x = leftGoal.x; x < leftGoal.x + leftGoal.w; x += 8) {
            SDL_RenderDrawLine(renderer, x, y, x + 8, y + 8);
        }
    }

    SDL_SetRenderDrawColor(renderer, 200, 200, 200, 255);
    SDL_Rect rightGoal = {
        SCREEN_WIDTH - GOAL_WIDTH - 20,
        (SCREEN_HEIGHT - GOAL_HEIGHT)/2 - 10,
        GOAL_WIDTH + 20,
        GOAL_HEIGHT + 20
    };
    SDL_RenderFillRect(renderer, &rightGoal);

    SDL_SetRenderDrawColor(renderer, 100, 100, 100, 255);
    for(int y = rightGoal.y; y < rightGoal.y + rightGoal.h; y += 8) {
        for(int x = rightGoal.x; x < rightGoal.x + rightGoal.w; x += 8) {
            SDL_RenderDrawLine(renderer, x + 8, y, x, y + 8);
        }
    }

    SDL_SetRenderDrawColor(renderer, 80, 80, 80, 255);
    SDL_Rect leftPost = {0, (SCREEN_HEIGHT - GOAL_HEIGHT)/2 - 10, 5, GOAL_HEIGHT + 20};
    SDL_Rect rightPost = {SCREEN_WIDTH - 5, (SCREEN_HEIGHT - GOAL_HEIGHT)/2 - 10, 5, GOAL_HEIGHT + 20};
    SDL_RenderFillRect(renderer, &leftPost);
    SDL_RenderFillRect(renderer, &rightPost);
}

void drawText(SDL_Renderer* renderer, const std::string& text, int x, int y, SDL_Color color, TTF_Font* font, bool rightAlign) {
    SDL_Surface* textSurface = TTF_RenderText_Solid(font, text.c_str(), color);
    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);

    SDL_Rect textRect;
    if(rightAlign) {
        textRect = {x - textSurface->w, y, textSurface->w, textSurface->h};
    } else {
        textRect = {x, y, textSurface->w, textSurface->h};
    }

    SDL_RenderCopy(renderer, textTexture, NULL, &textRect);
    SDL_FreeSurface(textSurface);
    SDL_DestroyTexture(textTexture);
}

void drawGoalMessages(SDL_Renderer* renderer, const std::vector<GoalMessage>& messages) {
    const int START_Y = SCREEN_HEIGHT / 3;
    int yOffset = 0;

    for (const auto& msg : messages) {
        SDL_Color color = msg.color;
        color.a = msg.alpha;

        SDL_Surface* surface = TTF_RenderText_Blended(fontNormal, msg.text.c_str(), color);
        SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);

        SDL_Rect rect = {
            (SCREEN_WIDTH - surface->w) / 2,
            START_Y + yOffset,
            surface->w,
            surface->h
        };

        SDL_RenderCopy(renderer, texture, nullptr, &rect);
        SDL_FreeSurface(surface);
        SDL_DestroyTexture(texture);

        yOffset += 40;
    }
}

std::string formatTime(int frames, bool isFirstHalf) {
    int totalFrames = isFirstHalf ? frames : HALF_TIME_DURATION + frames;
    int totalSeconds = totalFrames / 60;
    int seconds = totalSeconds % 60;
    int hundredths = (frames * 100) / 60 % 100;

    std::ostringstream oss;
    oss << std::setw(2) << std::setfill('0') << seconds << ":"
        << std::setw(2) << std::setfill('0') << hundredths;
    return oss.str();
}

void movePlayer(Entity& p, const std::vector<Entity>& team, MatchStats& stats) {
    p.position.x += p.dx;
    p.position.y += p.dy;

    for (const auto& other : team) {
        if (&other != &p) {
            int dx = p.position.x - other.position.x;
            int dy = p.position.y - other.position.y;
            int dist = sqrt(dx*dx + dy*dy);

            if (dist < PLAYER_SIZE * 2) {
                p.position.x += dx / 2;
                p.position.y += dy / 2;

                if ((rand() % 100) == 0) {
                    if (p.color.r == 0 && stats.yellowCardsBlue < NUM_PLAYERS) {
                        stats.yellowCardsBlue++;
                    } else if (stats.yellowCardsRed < NUM_PLAYERS) {
                        stats.yellowCardsRed++;
                    }
                }
            }
        }
    }

    if ((p.zone.x == 0 && p.zone.y == (SCREEN_HEIGHT - FIELD_HEIGHT)/2 && p.zone.w == 30 && p.zone.h == FIELD_HEIGHT) ||
        (p.zone.x == SCREEN_WIDTH - 30 && p.zone.y == (SCREEN_HEIGHT - FIELD_HEIGHT)/2 && p.zone.w == 30 && p.zone.h == FIELD_HEIGHT)) {
        p.dx = 0;
        int vitesse = 2;
        if (p.position.y < p.zone.y) p.dy = vitesse;
        else if (p.position.y > p.zone.y + p.zone.h) p.dy = -vitesse;
        else p.dy = (rand() % 2 == 0) ? vitesse : -vitesse;
    } else {
        if (p.position.x < p.zone.x || p.position.x > p.zone.x + p.zone.w) p.dx *= -1;
        if (p.position.y < p.zone.y || p.position.y > p.zone.y + p.zone.h) p.dy *= -1;
    }
}

void moveBall(Ball& ball, const std::vector<Entity>& players, MatchStats& stats) {
    if (ball.goalCooldown > 0) {
        ball.goalCooldown--;
        return;
    }

    int dx = ball.target.x - ball.position.x;
    int dy = ball.target.y - ball.position.y;
    float distance = sqrt(dx*dx + dy*dy);

    if (distance > 2) {
        ball.position.x += ball.speed * dx / distance;
        ball.position.y += ball.speed * dy / distance;
    } else {
        ball.target.x = rand() % SCREEN_WIDTH;
        ball.target.y = rand() % SCREEN_HEIGHT;
    }

    if (ball.position.x < 0 || ball.position.x > SCREEN_WIDTH ||
        ball.position.y < (SCREEN_HEIGHT - FIELD_HEIGHT)/2 ||
        ball.position.y > (SCREEN_HEIGHT + FIELD_HEIGHT)/2)
    {
        bool inVerticalBox = ball.position.y > (SCREEN_HEIGHT - BOX_HEIGHT)/2 &&
                             ball.position.y < (SCREEN_HEIGHT + BOX_HEIGHT)/2;

        if(ball.position.x < 0 && inVerticalBox && !ball.lastTouchedByBlue) {
            stats.cornersBlue++;
        }
        else if(ball.position.x > SCREEN_WIDTH && inVerticalBox && ball.lastTouchedByBlue) {
            stats.cornersRed++;
        }

        ball.position = {SCREEN_WIDTH/2, SCREEN_HEIGHT/2};
        ball.target = {SCREEN_WIDTH/2 + rand()%100-50, SCREEN_HEIGHT/2 + rand()%100-50};
        ball.speed = 3.0f;
        ball.goalCooldown = 30;
        return;
    }

    for (const auto& p : players) {
        if (abs(ball.position.x - p.position.x) < BALL_RADIUS * 2 &&
            abs(ball.position.y - p.position.y) < BALL_RADIUS * 2)
        {
            if(p.color.r == 0 && stats.passesBlue < MAX_PASSES) {
                ball.lastTouchedByBlue = true;
                stats.passesBlue++;
            }
            else if (stats.passesRed < MAX_PASSES) {
                ball.lastTouchedByBlue = false;
                stats.passesRed++;
            }

            float angle = atan2(p.position.y - ball.position.y, p.position.x - ball.position.x);
            ball.target.x = ball.position.x + 100 * cos(angle);
            ball.target.y = ball.position.y + 100 * sin(angle);
        }
    }

    ball.speed = std::min(ball.speed + 0.02f, 6.0f);
}

void createTeam(Uint8 r, Uint8 g, Uint8 b,
                SDL_Rect goalkeeperZone,
                SDL_Rect defendersZone,
                SDL_Rect midfieldersZone,
                SDL_Rect forwardsZone,
                std::vector<Entity>& team) {
    Entity goalkeeper;
    goalkeeper.color = {r, g, b, 255};
    goalkeeper.zone = goalkeeperZone;
    goalkeeper.position = {goalkeeperZone.x + goalkeeperZone.w/2, goalkeeperZone.y + goalkeeperZone.h/2};
    goalkeeper.dx = 0;
    goalkeeper.dy = 2;
    goalkeeper.playerNumber = 1;
    team.push_back(goalkeeper);

    for(int i=0; i<4; i++) {
        Entity player;
        player.color = {r, g, b, 255};
        player.zone = defendersZone;
        player.position = {
            defendersZone.x + rand()%defendersZone.w,
            defendersZone.y + rand()%defendersZone.h
        };
        player.dx = (rand()%3)-1;
        player.dy = (rand()%3)-1;
        player.playerNumber = 2 + i;
        team.push_back(player);
    }

    for(int i=0; i<4; i++) {
        Entity player;
        player.color = {r, g, b, 255};
        player.zone = midfieldersZone;
        player.position = {
            midfieldersZone.x + rand()%midfieldersZone.w,
            midfieldersZone.y + rand()%midfieldersZone.h
        };
        player.dx = (rand()%3)-1;
        player.dy = (rand()%3)-1;
        player.playerNumber = 6 + i;
        team.push_back(player);
    }

    for(int i=0; i<2; i++) {
        Entity player;
        player.color = {r, g, b, 255};
        player.zone = forwardsZone;
        player.position = {
            forwardsZone.x + rand()%forwardsZone.w,
            forwardsZone.y + rand()%forwardsZone.h
        };
        player.dx = (rand()%3)-1;
        player.dy = (rand()%3)-1;
        player.playerNumber = 10 + i;
        team.push_back(player);
    }
}

void drawPlayerNumber(SDL_Renderer* renderer, const Entity& player, TTF_Font* font) {
    SDL_Color textColor = {255, 255, 255, 255};
    std::string numberStr = std::to_string(player.playerNumber);
    SDL_Surface* textSurface = TTF_RenderText_Solid(font, numberStr.c_str(), textColor);
    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);

    SDL_Rect textRect = {
        player.position.x - textSurface->w/2,
        player.position.y - textSurface->h/2,
        textSurface->w,
        textSurface->h
    };

    SDL_RenderCopy(renderer, textTexture, NULL, &textRect);
    SDL_FreeSurface(textSurface);
    SDL_DestroyTexture(textTexture);
}

void drawScoreboard(SDL_Renderer* renderer, MatchStats& stats, bool isFirstHalf, int gameTime) {
    const int scoreboardX = (SCREEN_WIDTH - SCOREBOARD_WIDTH) / 2;
    const int scoreboardY = 20;

    SDL_Rect scoreboardRect = {scoreboardX, scoreboardY, SCOREBOARD_WIDTH, SCOREBOARD_HEIGHT};
    drawGradientRect(renderer, scoreboardRect, {40, 40, 40, 255}, {20, 20, 20, 255});
    SDL_SetRenderDrawColor(renderer, 80, 80, 80, 255);
    SDL_RenderDrawRect(renderer, &scoreboardRect);

    int textWidth, textHeight;
    const int centerX = scoreboardX + SCOREBOARD_WIDTH/2;

    SDL_Color blueColor = {30, 144, 255, 255};
    SDL_Color redColor = {255, 50, 50, 255};

    TTF_SizeText(fontNormal, BLUE_TEAM_NAME, &textWidth, &textHeight);
    drawText(renderer, BLUE_TEAM_NAME, centerX - 120 - textWidth/2, scoreboardY + 30, blueColor, fontNormal);

    TTF_SizeText(fontNormal, RED_TEAM_NAME, &textWidth, &textHeight);
    drawText(renderer, RED_TEAM_NAME, centerX + 120 - textWidth/2, scoreboardY + 30, redColor, fontNormal);

    std::string scoreText = std::to_string(stats.blueScore) + " - " + std::to_string(stats.redScore);
    SDL_Color scoreColor = {255, 215, 0, 255};
    TTF_SizeText(fontScore, scoreText.c_str(), &textWidth, &textHeight);
    drawText(renderer, scoreText, centerX - textWidth/2, scoreboardY + 30, scoreColor, fontScore);

    std::string sloganText;
    SDL_Color sloganColor = {200, 200, 200, 200};
    if(stats.blueScore > stats.redScore) {
        sloganText = "Victory is within reach !";
        sloganColor = {30, 144, 255, 200};
    }
    else if(stats.redScore > stats.blueScore) {
        sloganText = "The suspense is still alive !";
        sloganColor = {255, 50, 50, 200};
    }
    else {
        sloganText = "Balanced match, anything can happen !";
    }

    TTF_SizeText(fontNormal, sloganText.c_str(), &textWidth, &textHeight);
    drawText(renderer, sloganText, centerX - textWidth/2, scoreboardY + 90, sloganColor, fontNormal);

    std::string timerText = formatTime(gameTime, isFirstHalf) + (isFirstHalf ? "  (1st)" : "  (2nd)");
    TTF_SizeText(fontNormal, timerText.c_str(), &textWidth, &textHeight);
    drawText(renderer, timerText, centerX - textWidth/2, scoreboardY + SCOREBOARD_HEIGHT - 80, {160, 160, 160, 255}, fontNormal);
}


void drawStatsTable(SDL_Renderer* renderer, MatchStats& stats) {
    const int tableWidth = 800;
    const int tableHeight = 600;
    const int tableX = (SCREEN_WIDTH - tableWidth) / 2;
    const int tableY = (SCREEN_HEIGHT - tableHeight) / 2;

    SDL_Rect tableRect = {tableX, tableY, tableWidth, tableHeight};
    drawGradientRect(renderer, tableRect, {30,30,30,255}, {50,50,50,255});

    SDL_Color titleColor = {255, 215, 0, 255};
    std::string titleText = "MATCH STATISTICS";
    int titleWidth, titleHeight;
    TTF_SizeText(fontScore, titleText.c_str(), &titleWidth, &titleHeight);
    drawText(renderer, titleText,
             tableX + (tableWidth - titleWidth)/2,
             tableY + 30,
             titleColor, fontScore);

    SDL_Rect headerRect = {tableX, tableY + 80, tableWidth, 60};
    drawGradientRect(renderer, headerRect, {70,70,70,255}, {90,90,90,255});

    int teamHeaderX = tableX + tableWidth * 0.35;
    drawText(renderer, BLUE_TEAM_NAME,
             teamHeaderX - 50,
             tableY + 100,
             {30, 144, 255, 255}, fontNormal);

    teamHeaderX = tableX + tableWidth * 0.65;
    drawText(renderer, RED_TEAM_NAME,
             teamHeaderX - 50,
             tableY + 100,
             {255, 50, 50, 255}, fontNormal);

    std::vector<StatRow> rows = {
        {"Possession",
         std::to_string((stats.possessionBlue*100)/(stats.possessionBlue+stats.possessionRed)) + "%",
         std::to_string((stats.possessionRed*100)/(stats.possessionBlue+stats.possessionRed)) + "%"},
        {"Passes",
         std::to_string(stats.passesBlue),
         std::to_string(stats.passesRed)},
        {"Pass accuracy",
         "85%",
         "78%"},
        {"Yellow cards",
         std::to_string(stats.yellowCardsBlue),
         std::to_string(stats.yellowCardsRed)},
        {"Red cards",
         "0",
         "0"},
        {"Corners",
         std::to_string(stats.cornersBlue),
         std::to_string(stats.cornersRed)}
    };

    int y = tableY + 160;
    const int ROW_HEIGHT = 60;
    const int VALUE_SPACING = 150;

    for(size_t i = 0; i < rows.size(); i++) {
        SDL_SetRenderDrawColor(renderer, 60, 60, 60, (i % 2 == 0) ? 150 : 100);
        SDL_Rect rowRect = {tableX, y, tableWidth, ROW_HEIGHT};
        SDL_RenderFillRect(renderer, &rowRect);

        drawText(renderer, rows[i].name,
                 tableX + 20,
                 y + 20,
                 {200, 200, 200, 255}, fontNormal);

        drawText(renderer, rows[i].blueValue,
                 tableX + tableWidth/2 - VALUE_SPACING,
                 y + 20,
                 {180, 220, 255, 255}, fontNormal);

        drawText(renderer, rows[i].redValue,
                 tableX + tableWidth/2 + VALUE_SPACING - 50,
                 y + 20,
                 {255, 180, 180, 255}, fontNormal);

        if(i == 0) {
            int total = stats.possessionBlue + stats.possessionRed;
            int blueWidth = 400 * stats.possessionBlue / total;

            SDL_Rect bgBar = {tableX + 200, y + 45, 400, 8};
            SDL_SetRenderDrawColor(renderer, 50, 50, 50, 255);
            SDL_RenderFillRect(renderer, &bgBar);

            SDL_Rect blueBar = {tableX + 200, y + 45, blueWidth, 8};
            SDL_SetRenderDrawColor(renderer, 30, 144, 255, 255);
            SDL_RenderFillRect(renderer, &blueBar);

            SDL_Rect redBar = {tableX + 200 + blueWidth, y + 45, 400 - blueWidth, 8};
            SDL_SetRenderDrawColor(renderer, 255, 50, 50, 255);
            SDL_RenderFillRect(renderer, &redBar);
        }

        y += ROW_HEIGHT;
    }

    SDL_Color stadiumColor = {255, 215, 0, 255};
    std::string stadiumText = "France Stadium - Final Score";

    int textWidth, textHeight;
    TTF_SizeText(fontScore, stadiumText.c_str(), &textWidth, &textHeight);

    drawText(renderer, stadiumText,
             tableX + (tableWidth - textWidth)/2,
             tableY + tableHeight - 50,
             stadiumColor,
             fontScore);

    SDL_SetRenderDrawColor(renderer, 100, 100, 100, 100);
    SDL_RenderDrawRect(renderer, &tableRect);
}

void drawFormation(SDL_Renderer* renderer, const std::string& formation, SDL_Color teamColor, int baseX, int baseY) {
    const int FIELD_WIDTH = 600;
    const int FIELD_HEIGHT = 400;
    const int PLAYER_RADIUS = 14;

    for(int y = 0; y < FIELD_HEIGHT; y++) {
        SDL_Color lineColor = {
            static_cast<Uint8>(50 - y * 0.1),
            static_cast<Uint8>(205 - y * 0.2),
            static_cast<Uint8>(50 - y * 0.1),
            255
        };
        SDL_SetRenderDrawColor(renderer, lineColor.r, lineColor.g, lineColor.b, 255);
        SDL_RenderDrawLine(renderer, baseX, baseY + y, baseX + FIELD_WIDTH, baseY + y);
    }

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 200);
    SDL_Rect fieldRect = {baseX, baseY, FIELD_WIDTH, FIELD_HEIGHT};
    SDL_RenderDrawRect(renderer, &fieldRect);

    drawCircle(renderer, baseX + FIELD_WIDTH/2, baseY + FIELD_HEIGHT/2, 60);
    SDL_RenderDrawLine(renderer,
                       baseX + FIELD_WIDTH/2, baseY,
                       baseX + FIELD_WIDTH/2, baseY + FIELD_HEIGHT
                       );

    SDL_Rect leftBox = {baseX, baseY + FIELD_HEIGHT/2 - 80, 120, 160};
    SDL_Rect rightBox = {baseX + FIELD_WIDTH - 120, baseY + FIELD_HEIGHT/2 - 80, 120, 160};
    SDL_RenderDrawRect(renderer, &leftBox);
    SDL_RenderDrawRect(renderer, &rightBox);

    std::vector<std::pair<SDL_Point, int>> players;

    if(formation == "4-4-2") {
        players = {
            {{baseX + 30, baseY + FIELD_HEIGHT/2}, 1},
            {{baseX + 100, baseY + FIELD_HEIGHT - 80}, 2},
            {{baseX + 200, baseY + FIELD_HEIGHT - 100}, 3},
            {{baseX + 400, baseY + FIELD_HEIGHT - 100}, 4},
            {{baseX + 500, baseY + FIELD_HEIGHT - 80}, 5},
            {{baseX + 150, baseY + FIELD_HEIGHT/2 + 40}, 6},
            {{baseX + 250, baseY + FIELD_HEIGHT/2}, 7},
            {{baseX + 350, baseY + FIELD_HEIGHT/2}, 8},
            {{baseX + 450, baseY + FIELD_HEIGHT/2 + 40}, 9},
            {{baseX + 280, baseY + 60}, 10},
            {{baseX + 320, baseY + 60}, 11}
        };
    }
    else if(formation == "4-3-3") {
        players = {
            {{baseX + 30, baseY + FIELD_HEIGHT/2}, 1},
            {{baseX + 100, baseY + FIELD_HEIGHT - 80}, 2},
            {{baseX + 200, baseY + FIELD_HEIGHT - 100}, 3},
            {{baseX + 400, baseY + FIELD_HEIGHT - 100}, 4},
            {{baseX + 500, baseY + FIELD_HEIGHT - 80}, 5},
            {{baseX + 200, baseY + FIELD_HEIGHT/2 + 40}, 6},
            {{baseX + 300, baseY + FIELD_HEIGHT/2}, 7},
            {{baseX + 400, baseY + FIELD_HEIGHT/2 + 40}, 8},
            {{baseX + 150, baseY + 60}, 9},
            {{baseX + 300, baseY + 40}, 10},
            {{baseX + 450, baseY + 60}, 11}
        };
    }

    for(const auto& [pos, number] : players) {
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        drawCircle(renderer, pos.x, pos.y, PLAYER_RADIUS + 2);

        SDL_SetRenderDrawColor(renderer, teamColor.r, teamColor.g, teamColor.b, 255);
        drawCircle(renderer, pos.x, pos.y, PLAYER_RADIUS);

        SDL_Color textColor = {255, 255, 255, 255};
        std::string numStr = std::to_string(number);
        SDL_Surface* textSurface = TTF_RenderText_Solid(fontNormal, numStr.c_str(), textColor);
        SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, textSurface);

        SDL_Rect textRect = {
            pos.x - textSurface->w/2,
            pos.y - textSurface->h/2,
            textSurface->w,
            textSurface->h
        };

        SDL_RenderCopy(renderer, texture, NULL, &textRect);
        SDL_FreeSurface(textSurface);
        SDL_DestroyTexture(texture);
    }
}

void showPreMatchScreen(const std::string& teamName, const std::string& formation,
                        const std::string& coach, Uint32 startTime, SDL_Color teamColor) {
    float elapsed = SDL_GetTicks() - startTime;
    float progress = elapsed / PRE_MATCH_DURATION;

    int alpha = static_cast<int>(255 * (progress < 0.5f ? progress * 2 : 1.0 - (progress - 0.5) * 2));

    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
    SDL_SetRenderDrawColor(renderer, 20, 20, 20, 200);
    SDL_Rect bgRect = {SCREEN_WIDTH/2 - 450, SCREEN_HEIGHT/2 - 300, 900, 600};
    SDL_RenderFillRect(renderer, &bgRect);

    int centerX = SCREEN_WIDTH/2;
    int startY = SCREEN_HEIGHT/2 - 280;

    drawFormation(renderer, formation, teamColor, centerX - 300, startY);

    int textY = startY + 400;
    const int SPACING = 60;

    SDL_Color teamNameColor = {teamColor.r, teamColor.g, teamColor.b, static_cast<Uint8>(alpha)};
    drawText(renderer, teamName, centerX, textY, teamNameColor, fontScore, true);
    textY += SPACING;

    SDL_Color formationColor = {200, 220, 255, static_cast<Uint8>(alpha)};
    drawText(renderer, "FORMATION: " + formation,
             centerX, textY, formationColor, fontFormation, true);
    textY += SPACING;


    SDL_Color coachColor = {180, 255, 180, static_cast<Uint8>(alpha)};
    drawText(renderer, "MANAGER: " + coach,
             centerX, textY, coachColor, fontFormation, true);
}
