#include "./event.h"

void main_loop(SDL_Window* window) {
  unsigned int last_time = 0, current_time;
  bool running = true;
  SDL_Event event;

  Enemy* enemy = NULL;
  while (running) {
    current_time = SDL_GetTicks();
    if (current_time > last_time + 1000.0 / 30.0) {
      last_time = current_time;
      printf("frame!\n");

      if (enemy == NULL) {
        printf("New enemy\n");
        enemy = new_enemy();
        printf("ENEMY 1 => %d\n", enemy);
      }

      main_window_move_enemy(window, &enemy);
    }

    while (SDL_PollEvent(&event) != 0) {
      switch (event.type) {
      case SDL_QUIT:
        running = false;
        break;
      }
    }
  }
}
