#include "../defines.h"

#include "./enemy.h"

Enemy* new_enemy() {
  time_t t;
  srand((unsigned) time(&t));

  int rand_v = rand();

  int x = (rand_v % 2) * ((rand_v) % 600);
  int y = (1 - (rand_v % 2)) * ((rand_v) % 600);

  //       direction of movement           speed
  int vx = ((rand() % 2) * (-2) + 1) * ((rand() % 7) + 1);
  int vy = ((rand() % 2) * (-2) + 1) * ((rand() % 7) + 1);

  if (x == 0) {
    // y is random
    if (vx < 0) {
      x = 599;
    } else {
      x = -69;
    }
  } else {
    // x is random
    if (vy < 0) {
      y = 599;
    } else {
      y = -69;
    }
  }
  printf("VX => %d\n", vx);
  printf("VY => %d\n", vy);
  Enemy* enemy = (Enemy *)malloc(sizeof(Enemy));
  enemy->x = x;
  enemy->y = y;
  enemy->w = 70;
  enemy->h = 70;
  enemy->vx = vx;
  enemy->vy = vy;

  enemy->bg = IMG_Load("./assets/images/character/1.png");

  (enemy->rect).x = enemy->x;
  (enemy->rect).y = enemy->y;
  (enemy->rect).w = enemy->w;
  (enemy->rect).h = enemy->h;

  return enemy;
}

void move_enemy(Enemy* enemy) {
  enemy->x += enemy->vx;
  enemy->y += enemy->vy;

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
