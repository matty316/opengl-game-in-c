#include "quad.h"
#include "cglm/affine-pre.h"
#include "cglm/affine.h"
#include "cglm/mat4.h"

Quad add_quad(vec3 pos, vec3 rotation, float angle, float scale) {
  Quad quad;
  mat4 model;

  glm_mat4_identity(model);
  glm_translate(model, pos);
  glm_rotate(model, angle, &rotation[0]);
  glm_rotate(model, angle, &rotation[1]);
  glm_rotate(model, angle, &rotation[2]);
  glm_scale(model, &scale);

  glm_mat4_copy(quad.model, model);

  return quad;
}
