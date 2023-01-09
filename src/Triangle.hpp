#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Triangle {

public:
  Triangle() {
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, 9 * sizeof(float), points, GL_STATIC_DRAW);

    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);

    glShaderSource(vs, 1, &vertex_shader, NULL);
    glCompileShader(vs);

    glShaderSource(fs, 1, &fragment_shader, NULL);
    glCompileShader(fs);

    glAttachShader(shader_programme, fs);
    glAttachShader(shader_programme, vs);
    glLinkProgram(shader_programme);
  }

  GLuint vbo = 0;
  GLuint vao = 0;
  const char *vertex_shader = "#version 400\n"
                              "in vec3 vp;"
                              "void main() {"
                              "  gl_Position = vec4(vp, 1.0);"
                              "}";

  const char *fragment_shader = "#version 400\n"
                                "out vec4 frag_colour;"
                                "void main() {"
                                "  frag_colour = vec4(1.0, 0.0, 0.5, 1.0);"
                                "}";

  GLuint vs = glCreateShader(GL_VERTEX_SHADER);
  GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);

  GLuint shader_programme = glCreateProgram();

  float points[9] = {0.0f, 0.5f, 0.0f, 0.5f, -0.5f, 0.0f, -0.5f, -0.5f, 0.0f};
};