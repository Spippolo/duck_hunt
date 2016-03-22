#include "../defines.h"

#include "./enemy.h"

Enemy* new_enemy() {
  Enemy* enemy = (Enemy *)malloc(sizeof(Enemy));
  enemy->x = 0;
  enemy->y = 0;
  enemy->w = 70;
  enemy->h = 70;

  enemy->bg = IMG_Load("./assets/images/character/1.png");

  (enemy->rect).x = enemy->x;
  (enemy->rect).y = enemy->y;
  (enemy->rect).w = enemy->w;
  (enemy->rect).h = enemy->h;

  return enemy;
}

void move_enemy(Enemy* enemy) {
  enemy->x += 1;
  enemy->y += 1;

  (enemy->rect).x = enemy->x;
  (enemy->rect).y = enemy->y;

  printf("Moving: x -> %d, y -> %d\n", enemy->x, enemy->y);
}

SDL_Surface* get_enemy_surface(Enemy* enemy) {
  return enemy->bg;
}

SDL_Rect get_enemy_rect(Enemy* enemy) {
  return enemy->rect;
}
