#include "Player.h"

// Constructor to initialize the player's position
Player::Player(int startX, int startY, int tileSize)
    : posX(startX), posY(startY), tileSize(tileSize)
{
}

// Update the player's position based on WASD input
void Player::update(int gridWidth, int gridHeight)
{
    if (Play::KeyPressed(Play::KEY_W) && posY < gridHeight - 1)
    {
        posY++; // Move up by increasing Y
    }
    if (Play::KeyPressed(Play::KEY_S) && posY > 0)
    {
        posY--; // Move down by decreasing Y
    }
    if (Play::KeyPressed(Play::KEY_A) && posX > 0)
    {
        posX--; // Move left by decreasing X
    }
    if (Play::KeyPressed(Play::KEY_D) && posX < gridWidth - 1)
    {
        posX++; // Move right by increasing X
    }
}

// Render the player as a red filled square within the grid
void Player::render(int startX, int startY) const
{
    int playerScreenX = startX + posX * tileSize;
    int playerScreenY = startY + posY * tileSize;
    Play::DrawRect(Play::Vector2f(playerScreenX, playerScreenY),
                   Play::Vector2f(playerScreenX + tileSize, playerScreenY + tileSize),
                   Play::cRed, true);
}
