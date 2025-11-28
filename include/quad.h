#ifndef quad_h
#define quad_h

#include <cglm/cglm.h>

typedef struct Quad {
  mat4 model;
} Quad;

Quad add_quad(vec3 pos, vec3 rotation, float angle, float scale);

#endif
