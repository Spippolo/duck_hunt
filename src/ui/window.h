#pragma once

#include "../ai/enemy.h"

SDL_Window* get_main_window();
void init_main_window(SDL_Window* window);
void destroy_main_window(SDL_Window* window);
void main_window_move_enemy(SDL_Window* window, Enemy** enemy);
