#include "./defines.h"

#include "./ui/window.h"
#include "./event.h"

int main(int argc, char* argv[]) {

  if(SDL_Init(SDL_INIT_EVERYTHING) != 0) {
    return 1;
  }

  SDL_Window* window = get_main_window();

  if (window == NULL) {
    return 1;
  }

  init_main_window(window);

  main_loop(window);

  destroy_main_window(window);

  SDL_Quit();

  return 0;
}
