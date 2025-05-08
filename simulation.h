#ifndef SIMULATION_H
#define SIMULATION_H
#include "connection.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <string>
#include <vector>
#include <cmath>
const int SCREEN_WIDTH = 1200;
const int SCREEN_HEIGHT = 800;
const int FIELD_HEIGHT = 600;
const int PLAYER_SIZE = 16;
const int BALL_RADIUS = 8;
const int GOAL_WIDTH = 20;
const int GOAL_HEIGHT = 120;
const int BOX_WIDTH = 180;
const int BOX_HEIGHT = 400;
const int NUM_PLAYERS = 11;
const int GOAL_COOLDOWN = 180;
const int HALF_TIME_DURATION = 360;
const int TEXT_FADE_SPEED = 5;
const float SCORE_ANIMATION_SPEED = 0.008f;
const int GOAL_MESSAGE_DURATION = 300;
const int MATCH_END_DELAY = 2000;
const int MAX_PASSES = 500;
const int MAX_CORNERS = 20;
extern const char* BLUE_TEAM_NAME;
extern const char* RED_TEAM_NAME;
const int FLAG_POLE_HEIGHT = 30;
const int FLAG_WAVE_AMPLITUDE = 5;
const int AD_HEIGHT = 40;
const float AD_BLINK_SPEED = 0.02f;
const int SEAT_SIZE = 6;
const int ROWS = 15;
const int SEAT_SPACING = 3;
const int SCOREBOARD_WIDTH = 400;
const int SCOREBOARD_HEIGHT = 80;
const int PRE_MATCH_DURATION = 4000;
const int FORMATION_FONT_SIZE = 28;
const int COACH_FONT_SIZE = 15;

enum GameState { PRE_MATCH, PLAYING, HALF_TIME, MATCH_END };


struct Goal {
    int time;
    bool isBlueTeam;
};


struct GoalMessage {
    std::string text;
    int duration;
    int alpha;
    SDL_Color color;
};

struct StatRow {
    std::string name;
    std::string blueValue;
    std::string redValue;
};
extern const char* BLUE_TEAM_NAME;
extern const char* RED_TEAM_NAME;

struct MatchStats {
    int blueScore = 0;  // Initialisation par défaut
    int redScore = 0;
    float displayedBlueScore = 0.0f;
    float displayedRedScore = 0.0f;
    std::vector<Goal> goals;
    int possessionBlue = 0;
    int possessionRed = 0;
    int cornersBlue = 0;
    int cornersRed = 0;
    int passesBlue = 0;
    int passesRed = 0;
    int yellowCardsBlue = 0;
    int redCardsBlue = 0;
    int yellowCardsRed = 0;
    int redCardsRed = 0;
    std::vector<GoalMessage> goalMessages;
    int flashAlpha = 0;
    SDL_Color flashColor;
};

struct Entity {
    SDL_Point position;
    SDL_Color color;
    SDL_Rect zone;
    int dx, dy;
    int playerNumber;
};

struct Ball {
    SDL_Point position;
    SDL_Point target;
    float speed = 4.0f;
    int goalCooldown = 0;
    bool lastTouchedByBlue = false;
};

extern SDL_Window* window;
extern SDL_Renderer* renderer;
extern TTF_Font* fontScore;
extern TTF_Font* fontNormal;
extern TTF_Font* fontFormation;
extern TTF_Font* fontCoach;
extern Mix_Music* music;
extern Mix_Chunk* whistleSound;


void drawCircle(SDL_Renderer* renderer, int x, int y, int radius);
void drawGradientRect(SDL_Renderer* renderer, SDL_Rect rect, SDL_Color start, SDL_Color end);
void drawAdvertising(SDL_Renderer* renderer);
void drawStadium(SDL_Renderer* renderer);
void drawField(SDL_Renderer* renderer);
void drawText(SDL_Renderer* renderer, const std::string& text, int x, int y, SDL_Color color, TTF_Font* font, bool rightAlign = false);
void drawGoalMessages(SDL_Renderer* renderer, const std::vector<GoalMessage>& messages);
std::string formatTime(int frames, bool isFirstHalf);
void movePlayer(Entity& p, const std::vector<Entity>& team, MatchStats& stats);
void moveBall(Ball& ball, const std::vector<Entity>& players, MatchStats& stats);
void createTeam(Uint8 r, Uint8 g, Uint8 b, SDL_Rect goalkeeperZone, SDL_Rect defendersZone, SDL_Rect midfieldersZone, SDL_Rect forwardsZone, std::vector<Entity>& team);
void drawPlayerNumber(SDL_Renderer* renderer, const Entity& player, TTF_Font* font);
void drawScoreboard(SDL_Renderer* renderer, MatchStats& stats, bool isFirstHalf, int gameTime);
void drawStatsTable(SDL_Renderer* renderer, MatchStats& stats);
void drawFormation(SDL_Renderer* renderer, const std::string& formation, SDL_Color teamColor, int baseX, int baseY);
void showPreMatchScreen(const std::string& teamName, const std::string& formation, const std::string& coach, Uint32 startTime, SDL_Color teamColor);

#endif // SIMULATION_H
