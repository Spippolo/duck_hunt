#include "../defines.h"

#include "./enemy.h"

Enemy* new_enemy() {

  Enemy* enemy = (Enemy *)malloc(sizeof(Enemy));
  init_enemy_position(enemy);
  return enemy;
}

void move_enemy(Enemy* enemy) {
  enemy->x += enemy->vx;
  enemy->y += enemy->vy;

  (enemy->rect).x = enemy->x;
  (enemy->rect).y = enemy->y;

  // printf("Moving: x -> %d, y -> %d\n", enemy->x, enemy->y);
}

void init_enemy_position(Enemy* enemy) {
  time_t t;
  srand((unsigned) time(&t));

  // int x = (rand_v % 2) * ((rand_v) % 529) + 101;
  // int y = (1 - (rand_v % 2)) * ((rand_v) % 529) + 101;

  int x = rand() % 450 + 20;
  int y = rand() % 450 + 20;
  //
  // int x = 390;
  // int y = 120;

  printf("X: %d, Y: %d", x, y);

  //       direction of movement           speed
  int vx = ((rand() % 2) * (-2) + 1) * ((rand() % 12) + 1);
  int vy = ((rand() % 2) * (-2) + 1) * ((rand() % 12) + 1);


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

}

void invert_vy(Enemy* enemy) {
  time_t t;
  srand((unsigned) time(&t));
  int speed_factor = 0.4 * ((rand() % 10) + 1);
  enemy->vy = -speed_factor * enemy->vy;
}

void invert_vx(Enemy* enemy) {
  time_t t;
  srand((unsigned) time(&t));
  int speed_factor = 0.2 * ((rand() % 10) + 1);
  enemy->vx = -speed_factor * enemy->vx;
}

SDL_Surface* get_enemy_surface(Enemy* enemy) {
  return enemy->bg;
}

SDL_Rect get_enemy_rect(Enemy* enemy) {
  return enemy->rect;
}

bool enemy_hit(Enemy *enemy, int x, int y) {
  return (enemy->x <= x && x <= (enemy->x + enemy->w) && enemy->y <= y && y <= (enemy->y + enemy->h));
}
