#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Define constants for the screen size
#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 20

// Define a struct for the game state
typedef struct {
    int player_x;
    int player_y;
    bool game_over;
} GameState;

// Define a struct for the game objects
typedef struct {
    int x;
    int y;
    char symbol;
} GameObject;

// Define a struct for the game level
typedef struct {
    int num_objects;
    GameObject objects[100];
} GameLevel;

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
void draw_screen(GameState *state, GameLevel *level) {
    // Clear the screen
    system("cls");

    // Draw the level objects
    for (int i = 0; i < level->num_objects; i++) {
        printf("%c", level->objects[i].symbol);
    }
    printf("\n");

    // Draw the player
    for (int y = 0; y < SCREEN_HEIGHT; y++) {
        for (int x = 0; x < SCREEN_WIDTH; x++) {
            if (x == state->player_x && y == state->player_y) {
                printf("@");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

// Function to generate a random level
void generate_level(GameLevel *level) {
    // Initialize the random number generator
    srand(time(NULL));

    // Add some random objects to the level
    level->num_objects = 10;
    for (int i = 0; i < level->num_objects; i++) {
        level->objects[i].x = rand() % SCREEN_WIDTH;
        level->objects[i].y = rand() % SCREEN_HEIGHT;
        level->objects[i].symbol = 'X';
    }
}

// Main function
int main() {
    // Initialize the game state
    GameState state;
    initialize_game(&state);

    // Generate a random level
    GameLevel level;
    generate_level(&level);

    // Loop until the game is over
    while (!state.game_over) {
        // Update the game state
        update_game(&state);

        // Draw the game screen
        draw_screen(&state, &level);
    }

    // Game over!
    printf("Game over.\n");

    return 0;
}

//Plewese follow :/
