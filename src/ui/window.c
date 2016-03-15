#include "../defines.h"

#include "./window.h"

static int w_width = 600;
static int w_height = 600;

SDL_Window* get_main_window() {
  return SDL_CreateWindow(GAME_TITLE,
                          SDL_WINDOWPOS_CENTERED,
                          SDL_WINDOWPOS_CENTERED,
                          w_width,
                          w_height,
                          0);
}

void destroy_main_window(SDL_Window* window) {
  SDL_DestroyWindow(window);
}
