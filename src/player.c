#include "raylib.h"
#include "player.h"

// Initialises player variables and data
void InitPlayer(Player *player, int startX, int startY, int width, int height, int speed) {
    player->x = startX;
    player->y = startY;

    player->width = width;
    player->height = height;

    player->dx = 0;
    player->dy = 0;

    player->speed = speed;

    player->facingRight = true;
    player->onGround = true;
}

// Updates player position and data
void UpdatePlayer(Player *player) {
    // Checks if the left or right keys are down and updates velocity accordingly
    if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)) player->dx -= player->speed * GetFrameTime();
    if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) player->dx += player->speed * GetFrameTime();

    // Update player position based on velocity
    player->x += player->dx;

    // Dampen velocity to slow down player
    player->dx *= 0.97;
}

// Draws the player on the screen
void DrawPlayer(Player *player, Color colour) {
    DrawRectangle(player->x, player->y, player->width, player->height, colour);
}