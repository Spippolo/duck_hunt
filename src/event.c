#include "./event.h"

void main_loop(SDL_Window* window) {
  unsigned int last_time = 0, current_time;
  bool running = true;
  SDL_Event event;

  while (running) {
    current_time = SDL_GetTicks();
    if (current_time > last_time + 1000.0 / 30.0) {
      last_time = current_time;
      printf("frame!\n");
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
