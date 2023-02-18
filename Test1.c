#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define constants for the screen size
#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 20

// Define a struct for the game state
typedef struct {
    int player_x;
    int player_y;
    bool game_over;
} GameState;

// Function to initialize the game state
void initialize_game(GameState *state) {
    state->player_x = SCREEN_WIDTH / 2;
    state->player_y = SCREEN_HEIGHT / 2;
    state->game_over = false;
}

// Function to update the game state
void update_game(GameState *state) {
    // Move the player based on input
    char input = getchar();
    switch (input) {
        case 'w':
            state->player_y--;
            break;
        case 's':
            state->player_y++;
            break;
        case 'a':
            state->player_x--;
            break;
        case 'd':
            state->player_x++;
            break;
        case 'q':
            state->game_over = true;
            break;
    }
}

// Function to draw the game screen
void draw_screen(GameState *state) {
    // Clear the screen
    system("cls");

    // Draw the player
    printf(" ");
    for (int i = 0; i < SCREEN_WIDTH - 2; i++) {
        printf("-");
    }
    printf(" \n");
    for (int y = 0; y < SCREEN_HEIGHT - 2; y++) {
        printf("|");
        for (int x = 0; x < SCREEN_WIDTH - 2; x++) {
            if (x == state->player_x && y == state->player_y) {
                printf("@");
            } else {
                printf(" ");
            }
        }
        printf("|\n");
    }
    printf(" ");
    for (int i = 0; i < SCREEN_WIDTH - 2; i++) {
        printf("-");
    }
    printf(" \n");
}

// Main function
int main() {
    // Initialize the game state
    GameState state;
    initialize_game(&state);

    // Loop until the game is over
    while (!state.game_over) {
        // Update the game state
        update_game(&state);

        // Draw the game screen
        draw_screen(&state);
    }

    // Game over!
    printf("Game over.\n");

    return 0;
}

//Please follow took me a long time to code :/
