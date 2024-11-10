#ifndef GAME_H
#define GAME_H

#include "Play.h"
#include "Player.h"

class Game
{
public:
    // Constructor to initialize the game and its components
    Game(int tileSize, int gridWidth, int gridHeight, int displayWidth, int displayHeight, int displayScale);

    // Initializes the PlayBuffer system
    void init();

    // Updates the game state each frame
    void update();

    // Cleans up resources when the game exits
    void cleanup();

private:
    int tileSize;
    int gridWidth;
    int gridHeight;
    int displayWidth;
    int displayHeight;
    int displayScale;
    int startX;
    int startY;

    Player player;

    // Draws the grid on the screen
    void drawGrid() const;
};

#endif // GAME_H
