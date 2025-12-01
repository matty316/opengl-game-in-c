#include "game.h"
#include "texture.h"
#include <stdbool.h>
#include <stdlib.h>

int main() {
  init(true);
  GLuint texture_id = load_texture("resources/Audi.png");
  run(texture_id);
  return EXIT_SUCCESS;
}
