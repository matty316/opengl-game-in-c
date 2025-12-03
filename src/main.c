#include "game.h"
#include "texture.h"
#include <stdbool.h>
#include <stdlib.h>

int main() {
  ope_init(false, 1920, 1080);
  GLuint texture_id = load_texture("resources/Audi.png");
  ope_run(texture_id);
  return EXIT_SUCCESS;
}
