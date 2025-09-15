#ifndef PLAYER_H
#define PLAYER_H

typedef struct {
    // Variables for player position
    float x, y;

    // Variables for width and height of the player
    int width, height;

    // Variables for player speed in each direction and speed modifier
    float dx, dy;
    int speed;

    // For keeping track of which way the player texture is facing
    bool facingRight;

    // Keep track of if the player is on the ground
    bool onGround;
} Player;

void InitPlayer(Player *player, int startX, int startY, int width, int height, int speed);
void UpdatePlayer(Player *player);
void DrawPlayer(Player *player, Color colour);

#endif