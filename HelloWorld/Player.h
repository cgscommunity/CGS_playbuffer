#ifndef PLAYER_H
#define PLAYER_H

#include "Play.h"

class Player
{
public:
    // Constructor to initialize the player's position
    Player(int startX, int startY, int tileSize);

    // Updates the player's position based on input
    void update(int gridWidth, int gridHeight);

    // Renders the player on the screen
    void render(int startX, int startY) const;

private:
    int posX, posY;   // Player's position in grid coordinates
    int tileSize;     // Size of each tile
};

#endif // PLAYER_H
