#ifndef LEARN_OPENGL_COMMON_H
#define LEARN_OPENGL_COMMON_H

#include "GLFW/glfw3.h"

using std::string;

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

void init_glfw();
GLFWwindow*  window_setting(int width=SCR_WIDTH, int height=SCR_HEIGHT);

class Shader
{
public:
    // the program ID
    unsigned int ID;

    // constructor reads and builds the shader
    Shader(const char* vertexPath, const char* fragmentPath);
    // use/activate the shader
    void use() const;
    // utility uniform functions
    void setBool(const std::string &name, bool value) const;
    void setInt(const std::string &name, int value) const;
    void setFloat(const std::string &name, float value) const;
private:
    static void checkCompileErrors(unsigned int shader, const string& type);
};

#endif //LEARN_OPENGL_COMMON_H
