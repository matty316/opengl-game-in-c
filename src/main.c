#include "game.h"
#include "texture.h"
#include <stdbool.h>
#include <stdlib.h>

int main() {
  init(false, 1920, 1080);
  GLuint texture_id = load_texture("resources/Audi.png");
  run(texture_id);
  return EXIT_SUCCESS;
}
