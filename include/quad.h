#ifndef quad_h
#define quad_h

#include <glad/glad.h>
#include <cglm/cglm.h>

typedef struct Quad {
  mat4 model;
  vec3 pos, rotation;
  float angle, scale;
  GLuint vao, vbo, ebo;
} Quad;

typedef enum QuadDirection {
  QUAD_UP,
  QUAD_DOWN,
  QUAD_LEFT,
  QUAD_RIGHT
} QuadDirection;

Quad add_quad(vec3 pos, vec3 rotation, float angle, float scale);
void draw_quad(Quad *quad, GLuint shader);
void move_quad(Quad *quad, QuadDirection direction, float delta_time);
void destroy_quad(Quad *quad);

#endif
