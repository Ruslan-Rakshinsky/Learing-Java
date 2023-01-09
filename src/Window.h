#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Window {
private:
  // Variables
  // Window vars
  GLFWwindow *m_window = {};
  GLFWcursor *m_cursor = {};
  int m_width = {};
  int m_height = {};
  int framebufferWidth = {};
  int framebufferHeight = {};
  const char *m_title = {};

  // Delta time
  float m_dt = {};
  float m_curTime = {};
  float m_lastTime = {};

  // Methods
  void initGLFW();
  void initGLEW();
  void createWindow();
  void mainLoop();
  void render();
  void getVersion();

public:
  Window(int width, int height, const char *title);
  ~Window();
};