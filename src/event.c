#include "unistd.h"
#include "./event.h"

void main_loop(SDL_Window* window) {
  unsigned int last_time = 0;
  unsigned int current_time;
  float remaining_time = 0.0;
  bool running = true;
  SDL_Event event;

  Enemy* enemy = NULL;
  while (running) {
    SDL_MouseButtonEvent *mouse;
    while (SDL_PollEvent(&event) != 0) {
      switch (event.type) {
      case SDL_MOUSEBUTTONDOWN:
        printf("Mouse\n");
        mouse = (SDL_MouseButtonEvent*) &event;
        if (enemy_hit(enemy, mouse->x, mouse->y)) {
          printf("HIT!\n");
        }
        break;

      case SDL_QUIT:
        running = false;
        break;
      }
    }

    current_time = SDL_GetTicks();
    float fps = 30.0;
    float frame_duration = 1000.0 / fps;

    // Run the loop if enough time has passed
    if (current_time > last_time + frame_duration) {
      last_time = current_time;
      // printf("frame!\n");

      if (enemy == NULL) {
        // printf("New enemy\n");
        enemy = new_enemy();
        // printf("ENEMY 1 => %d\n", enemy);
      }

      main_window_move_enemy(window, &enemy);
    }

    // Sleep for the remaining time until next loop (milliseconds)
    remaining_time = (frame_duration - (SDL_GetTicks() - current_time));
    // printf("Sleeping for %f milliseconds\n", remaining_time);
    // sleep() requires seconds
    sleep(remaining_time/1000.0);
  }
}
