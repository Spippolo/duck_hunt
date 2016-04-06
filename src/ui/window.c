#include "../defines.h"

#include "./window.h"

static int w_width = 600;
static int w_height = 600;
static SDL_Surface* background;
static SDL_Surface* scaled_bg;

static int x = 10;
static int y = 10;

static SDL_Surface* surfaces[10] = { NULL };
static SDL_Rect rects[10];

SDL_Window* get_main_window() {
  return SDL_CreateWindow(GAME_TITLE,
                          SDL_WINDOWPOS_CENTERED,
                          SDL_WINDOWPOS_CENTERED,
                          w_width,
                          w_height,
                          0);
}

static void init_surface(SDL_Window* window) {
  SDL_Surface* screen = SDL_GetWindowSurface(window);

  for (int i = 0; i < 10; i++) {
    if (surfaces[i] != NULL) {
      SDL_BlitSurface(surfaces[i], NULL, screen, &rects[i]);
    }
  }

  SDL_UpdateWindowSurface(window);
}

void init_main_window(SDL_Window* window) {
  SDL_Surface* screen = SDL_GetWindowSurface(window);

  background = IMG_Load("./assets/images/backgrounds/1.png");
  scaled_bg = SDL_CreateRGBSurface(0, w_width, w_height, 32, 0, 0, 0, 0);

  SDL_Rect scaled_rect = { .x = 0, .y = 0, .w = w_width, .h = w_height };

  // SDL_Rect screen_rect = { .x = 0, .y = 0, .w = background->w, .h = background->h };

  if (SDL_BlitScaled(background, NULL, scaled_bg, NULL) < 0) {
    printf("%s\n", SDL_GetError());
  }

  surfaces[0] = scaled_bg;
  rects[0] = scaled_rect;
  SDL_BlitSurface(surfaces[0], NULL, screen, &rects[0]);
}

void destroy_main_window(SDL_Window* window) {
  SDL_DestroyWindow(window);
}

static bool check_enemy_visibility(Enemy* enemy) {
  return !(enemy->x < -70 || enemy->y < -70 || enemy->x > 600 || enemy->y > 600);
}

void main_window_move_enemy(SDL_Window* window, Enemy** enemy) {
  // printf("ENEMY => %d\n", *enemy);
  move_enemy(*enemy);

  if (check_enemy_visibility(*enemy)) {

    SDL_Surface* enemy_sf = get_enemy_surface(*enemy);
    SDL_Rect enemy_rect = get_enemy_rect(*enemy);

    surfaces[1] = enemy_sf;
    rects[1] = enemy_rect;

  } else {
    // destroy the enemy
    if (*enemy != NULL) {
      // printf("FREE\n");
      init_enemy_position(*enemy);
      // *enemy = NULL;
    }
  }
  init_surface(window);
}
