#ifndef shader_h
#define shader_h

#include <glad/glad.h>

GLuint create_shader(const char *vertex_path, const char *fragment_path);
void use(GLuint shader);
#endif
