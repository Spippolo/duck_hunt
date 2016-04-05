#pragma once

typedef struct _Enemy Enemy;

struct _Enemy {
  int x;
  int y;
  int w;
  int h;
  int vx;
  int vy;
  SDL_Surface* bg;
  SDL_Rect rect;
};

Enemy*        new_enemy();
void          move_enemy(Enemy* enemy);
SDL_Surface*  get_enemy_surface(Enemy* enemy);
SDL_Rect      get_enemy_rect(Enemy* enemy);
bool          enemy_hit(Enemy* enemy, int x, int y);
