#include "raylib.h"
#include "player.h"

const float GRAVITY = 0.8;
int screen_height = 600;
int distance_to_ground;

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
    player->onGround = false;
}

// Updates player position and data
void UpdatePlayer(Player *player) {
    // Checks if the left or right keys are down and updates velocity accordingly
    if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)) player->dx -= player->speed * GetFrameTime();
    if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) player->dx += player->speed * GetFrameTime();
    
    // Functionality for jumping
    if ((IsKeyDown(KEY_W) || IsKeyDown(KEY_SPACE) || IsKeyDown(KEY_UP)) && player->onGround) {
        player->onGround = false;
        player->dy = -17;
    }

    // Update player position based on velocity
    player->x += player->dx;

    // If the player isn't on the ground, apply gravity until it is
    if (!player->onGround) {
        player->dy += GRAVITY;
        player->y += player->dy;

        // Check if player is about to go below ground
        if (player->y + player->dy > GetScreenHeight() - player->height) {
            player->dy = 0;
            distance_to_ground = GetScreenHeight() - (player->y + player->height);
            player->y += distance_to_ground + 1;
            player->onGround = true;
        }
    }

    // Dampen velocity to slow down player
    player->dx *= 0.97;
}

// Draws the player on the screen
void DrawPlayer(Player *player, Color colour) {
    DrawRectangle(player->x, player->y, player->width, player->height, colour);
}