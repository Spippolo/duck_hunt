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

void init_main_window(SDL_Window* window) {
  SDL_Surface* screen = SDL_GetWindowSurface(window);
  SDL_Surface* background = IMG_Load("./assets/images/backgrounds/1.png");
  SDL_Surface* scaled_bg = SDL_CreateRGBSurface(0, w_width, w_height, 32, 0, 0, 0, 0);

  SDL_Rect scaled_rect = { .x = 0, .y = 0, .w = w_width, .h = w_height };

  SDL_Rect screen_rect = { .x = 0, .y = 0, .w = background->w, .h = background->h };

  if (SDL_BlitScaled(background, NULL, scaled_bg, NULL) < 0) {
    printf("%s\n", SDL_GetError());
  }

  SDL_BlitSurface(scaled_bg, NULL, screen, &scaled_rect);
  SDL_UpdateWindowSurface(window);
}

void destroy_main_window(SDL_Window* window) {
  SDL_DestroyWindow(window);
}
