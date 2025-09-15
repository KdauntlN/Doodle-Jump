#include <raylib.h>
#include "player.h"

// Declare screen width and height constants
const int SCREEN_WIDTH = 400;
const int SCREEN_HEIGHT = 600;

int main(void) {
    //Initialise window and some other stuff
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Doodle Jump");
    SetExitKey(KEY_NULL);
    SetTargetFPS(60);

    // Create new player and initialise fields
    Player player;
    InitPlayer(&player, 0, 0, 20, 40, 15);

    // Main game loop
    while (!WindowShouldClose()) {
        // Update the player's position and info
        UpdatePlayer(&player);

        // Setup framebuffer for drawing and clear the screen
        BeginDrawing();
        
        // Clear background and draw player
        ClearBackground(RAYWHITE);
        DrawPlayer(&player, RED);

        // End drawing and swap buffers
        EndDrawing();
    }

    // Take a guess at what this does
    CloseWindow();

    return 0;
}