#ifndef LEARN_OPENGL_COMMON_H
#define LEARN_OPENGL_COMMON_H

#include "GLFW/glfw3.h"

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

void init_glfw();
GLFWwindow*  window_setting(int width=SCR_WIDTH, int height=SCR_HEIGHT);

#endif //LEARN_OPENGL_COMMON_H
