
#include "Window.h"
#include "Triangle.hpp"
#include <stdexcept>

Window::Window(int width, int height, const char *title)
    : m_width(width), m_height(height), m_title(title) {
  initGLFW();
  createWindow();
  initGLEW();
  getVersion();
  mainLoop();
}

void Window::initGLFW() {
  if (!glfwInit()) {
    throw std::runtime_error("Could not initialize GLFW!");
  }
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
  glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
}

void Window::initGLEW() {
  glewExperimental = GL_TRUE;
  if (GLEW_OK != glewInit()) {
    throw std::runtime_error("Could not init GLEW!");
  }
  glEnable(GL_DEPTH_TEST);
} // void Window::initGLEW()

void Window::createWindow() {
  m_window = glfwCreateWindow(m_width, m_height, m_title, NULL, NULL);
  if (m_window == nullptr) {
    throw std::runtime_error("Could not create a window!");
  }
  glfwMakeContextCurrent(m_window);
}

Window::~Window() {
  glfwDestroyCursor(m_cursor);
  glfwDestroyWindow(m_window);
  glfwTerminate();
}

void Window::mainLoop() {
  while (!glfwWindowShouldClose(m_window)) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    render();

    glfwPollEvents();
    glfwSwapBuffers(m_window);
  }
}

void Window::getVersion() {
  // get version info
  const GLubyte *renderer = glGetString(GL_RENDERER); // get renderer string
  const GLubyte *version = glGetString(GL_VERSION);   // version as a string
  printf("Renderer: %s\n", renderer);
  printf("OpenGL version supported %s\n", version);
}

void Window::render() {
  Triangle trg;
  glUseProgram(trg.shader_programme);
  glBindVertexArray(trg.vao);
  glDrawArrays(GL_TRIANGLES, 0, 3);
}