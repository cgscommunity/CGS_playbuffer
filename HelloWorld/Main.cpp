#define PLAY_IMPLEMENTATION
#include "Play.h"
#include "Game.h"

// Set the display dimensions to match the grid layout exactly
int TILE_SIZE = 40;
int GRID_WIDTH = 20;
int GRID_HEIGHT = 15;
int DISPLAY_WIDTH = TILE_SIZE * GRID_WIDTH;
int DISPLAY_HEIGHT = TILE_SIZE * GRID_HEIGHT;
int DISPLAY_SCALE = 1;

// Create a game instance
Game game(TILE_SIZE, GRID_WIDTH, GRID_HEIGHT, DISPLAY_WIDTH, DISPLAY_HEIGHT, DISPLAY_SCALE);

// Initializes the PlayBuffer system
void MainGameEntry(PLAY_IGNORE_COMMAND_LINE)
{
    game.init();
}

// Updates the game state every frame
bool MainGameUpdate(float elapsedTime)
{
    game.update();
    return Play::KeyDown(Play::KEY_ESCAPE); // Exit if Escape is pressed
}

// Cleans up resources when the game exits
int MainGameExit(void)
{
    game.cleanup();
    return PLAY_OK;
}
