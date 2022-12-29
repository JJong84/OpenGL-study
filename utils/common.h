#ifndef LEARN_OPENGL_COMMON_H
#define LEARN_OPENGL_COMMON_H

#include "GLFW/glfw3.h"

#include <glm/glm.hpp>

using std::string;
using glm::vec2, glm::vec3, glm::vec4, glm::mat2, glm::mat3, glm::mat4;

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

void init_glfw();

GLFWwindow *window_setting(int width = SCR_WIDTH, int height = SCR_HEIGHT);

class Shader {
public:
    // the program ID
    unsigned int ID;

    // constructor reads and builds the shader
    Shader(const char *vertexPath, const char *fragmentPath);

    // use/activate the shader
    void use() const;

    // utility uniform functions
    void setBool(const std::string &name, bool value) const;

    void setInt(const std::string &name, int value) const;

    void setFloat(const std::string &name, float value) const;

    void setVec2(const std::string &name, const vec2 &value) const;

    void setVec2(const std::string &name, float x, float y) const;

    void setVec3(const std::string &name, const glm::vec3 &value) const;

    void setVec3(const std::string &name, float x, float y, float z) const;

    void setVec4(const std::string &name, const glm::vec4 &value) const;

    void setVec4(const std::string &name, float x, float y, float z, float w) const;

    void setMat2(const std::string &name, const glm::mat2 &mat) const;

    void setMat3(const std::string &name, const glm::mat3 &mat) const;

    void setMat4(const std::string &name, const glm::mat4 &mat) const;

private:
    static void checkCompileErrors(unsigned int shader, const string &type);
};

#endif //LEARN_OPENGL_COMMON_H
