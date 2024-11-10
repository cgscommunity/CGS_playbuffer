#include "Game.h"

// Constructor to initialize the game and its components
Game::Game(int tileSize, int gridWidth, int gridHeight, int displayWidth, int displayHeight, int displayScale)
    : tileSize(tileSize), gridWidth(gridWidth), gridHeight(gridHeight),
    displayWidth(displayWidth), displayHeight(displayHeight), displayScale(displayScale),
    player(5, 5, tileSize)
{

    // Calculate starting positions to center the grid vertically
    startX = 0;
    startY = (displayHeight - gridHeight * tileSize) / 2;
}

// Initializes the PlayBuffer system
void Game::init()
{
    Play::CreateManager(displayWidth, displayHeight, displayScale);
}

// Updates the game state each frame
void Game::update()
{
    Play::ClearDrawingBuffer(Play::cBlack); // Clear the screen with a black background

    // Draw the grid and update/render the player
    drawGrid();
    player.update(gridWidth, gridHeight);
    player.render(startX, startY);

    Play::PresentDrawingBuffer();
}

// Cleans up resources when the game exits
void Game::cleanup()
{
    Play::DestroyManager();
}

// Draws the tile-based grid
void Game::drawGrid() const
{
    for (int x = 0; x < gridWidth; x++)
    {
        for (int y = 0; y < gridHeight; y++)
        {
            int left = startX + x * tileSize;
            int top = startY + y * tileSize;
            int right = left + tileSize;
            int bottom = top + tileSize;

            Play::DrawRect(Play::Vector2f(left, top), Play::Vector2f(right, bottom), Play::cWhite, false);
        }
    }
}
