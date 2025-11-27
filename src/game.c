#include "game.h"
#include "shader.h"
#include "common.h"
#include <stdio.h>
#include <stdlib.h>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

void framebuffer_size_callback(GLFWwindow *window, int width, int height) {
  glViewport(0, 0, width, height);
}

void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods) {
  printf("%d", key);
  if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
      glfwSetWindowShouldClose(window, GLFW_TRUE);
}

void create_vertex_buffer_objects(GLuint *vao, GLuint *vbo, GLuint *ebo) {
  float vertices[] = {
     0.5f,  0.5f, 0.0f,  // top right
     0.5f, -0.5f, 0.0f,  // bottom right
    -0.5f, -0.5f, 0.0f,  // bottom left
    -0.5f,  0.5f, 0.0f   // top left
  };

  unsigned int indices[] = {  // note that we start from 0!
    0, 1, 3,   // first triangle
    1, 2, 3    // second triangle
  };


  glGenVertexArrays(1, vao);
  glGenBuffers(1, vbo);
  glGenBuffers(1, ebo);

  glBindVertexArray(*vao);

  glBindBuffer(GL_ARRAY_BUFFER, *vbo);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, *ebo);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);

  glBindBuffer(GL_ARRAY_BUFFER, 0);
  glBindVertexArray(0);
}

void init(GLFWwindow **window) {
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  *window = glfwCreateWindow(width, height, "OpenGL in C", NULL, NULL);
  if (*window == NULL) {
    printf("Failed to create GLFW window\n");
    glfwTerminate();
    exit(EXIT_FAILURE);
  }
  glfwMakeContextCurrent(*window);

  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    printf("Failed to init GLAD\n");
    glfwTerminate();
    exit(EXIT_FAILURE);
  }

  int actual_width, actual_height;
  glfwGetFramebufferSize(*window, &actual_width, &actual_height);
  glViewport(0, 0, actual_width, actual_height);

  glfwSetFramebufferSizeCallback(*window, framebuffer_size_callback);
  glfwSetKeyCallback(*window, key_callback);
}

void run() {
  GLFWwindow *window;
  init(&window);

  GLuint shader = create_shader("shaders/shader.vert", "shaders/shader.frag");
  use(shader);

  GLuint vao, vbo, ebo;
  create_vertex_buffer_objects(&vao, &vbo, &ebo);

  while (!glfwWindowShouldClose(window)) {
    glClearColor(0.8f, 0.8f, 0.98f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    use(shader);
    glBindVertexArray(vao);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glDeleteVertexArrays(1, &vao);
  glDeleteBuffers(1, &vbo);
  glDeleteBuffers(1, &ebo);
  glDeleteProgram(shader);
  glfwTerminate();
}
