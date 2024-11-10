#define PLAY_IMPLEMENTATION
#include "Play.h"

// STRUCTS
/////////////////////////////////////////////////////////////
struct GameState
{
    int playerX{ 5 }; // Initial x position (grid coordinate)
    int playerY{ 5 }; // Initial y position (grid coordinate)
};

// GLOBALS
/////////////////////////////////////////////////////////////
int TILE_SIZE = 40;
int GRID_WIDTH = 20;
int GRID_HEIGHT = 15;

int DISPLAY_WIDTH = 800;     // 800 pixels
int DISPLAY_HEIGHT = 600;   // 600 pixels
int DISPLAY_SCALE = 1;

GameState gameState;

// FUNCTIONS
/////////////////////////////////////////////////////////////
void MainGameEntry(PLAY_IGNORE_COMMAND_LINE)
{
    Play::CreateManager(DISPLAY_WIDTH, DISPLAY_HEIGHT, DISPLAY_SCALE);
}

bool MainGameUpdate(float elapsedTime)
{
    // Clear the screen
    Play::ClearDrawingBuffer(Play::cBlack);

    // Draw the tile-based grid
    for (int x = 0; x < GRID_WIDTH; x++)
    {
        for (int y = 0; y < GRID_HEIGHT; y++)
        {
            int left = x * TILE_SIZE;
            int top = y * TILE_SIZE;
            int right = left + TILE_SIZE;
            int bottom = top + TILE_SIZE;

            Play::DrawRect(Play::Vector2f(left, top), Play::Vector2f(right, bottom), Play::cWhite);
        }
    }

    // Handle input
    if (Play::KeyPressed(Play::KEY_W) && gameState.playerY < GRID_HEIGHT - 1)
    {
        gameState.playerY++;
    }
    if (Play::KeyPressed(Play::KEY_S) && gameState.playerY > 0)
    {
        gameState.playerY--;
    }
    if (Play::KeyPressed(Play::KEY_A) && gameState.playerX > 0)
    {
        gameState.playerX--;
    }
    if (Play::KeyPressed(Play::KEY_D) && gameState.playerX < GRID_WIDTH - 1)
    {
        gameState.playerX++;
    }

    // Draw player
    int playerPosX = gameState.playerX * TILE_SIZE;
    int playerPosY = gameState.playerY * TILE_SIZE;
    Play::DrawRect(Play::Vector2f(playerPosX, playerPosY), Play::Vector2f(playerPosX + TILE_SIZE, playerPosY + TILE_SIZE), Play::cRed, true);

    // Draw the buffer
    Play::PresentDrawingBuffer();

    // Exit on ESC
    return Play::KeyDown(Play::KEY_ESCAPE);
}

int MainGameExit(void)
{
    Play::DestroyManager();
    return PLAY_OK;
}