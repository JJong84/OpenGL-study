#include <iostream>

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "../utils/common.h"

namespace hello_triangle_ex2 {
    void processInput(GLFWwindow *window) {
        // Check if escape key is pressed
        // GLFW_RELEASE - not pressed
        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            // set WindowShouldClose property to true
            glfwSetWindowShouldClose(window, true);
    }

    const char *vertexShaderSource = "#version 330 core\n"
                                     "layout (location = 0) in vec3 aPos;\n"
                                     "void main()\n"
                                     "{\n"
                                     "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
                                     "}\0";

    const char *fragmentShaderSource = "#version 330 core\n"
                                       "out vec4 FragColor;\n"
                                       "void main()\n"
                                       "{\n"
                                       "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
                                       "}\0";

    const float vertices1[] = {
            -0.25f, 0.5f, 0.0f,
            -0.5f, -0.5f, 0.0f,
            0.0f, -0.5f, 0.0f,
    };

    const float vertices2[] = {
            0.25f, 0.5f, 0.0f,
            0.5f, -0.5f, 0.0f,
            0.0f, -0.5f, 0.0f,
    };

    unsigned int create_and_compile_vertex_shader() {
        // Create Vertex Shader
        unsigned int vertexShader;
        vertexShader = glCreateShader(GL_VERTEX_SHADER);

        // attach source
        glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);

        // compile shader
        glCompileShader(vertexShader);

        // Check if shader compiling was successful
        int success;
        char infoLog[512];
        glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
        if (!success) {
            glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
            std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
        }

        return vertexShader;
    }

    unsigned int create_and_compile_fragment_shader() {
        unsigned int fragmentShader;
        fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);

        glCompileShader(fragmentShader);

        return fragmentShader;
    }

    unsigned int create_and_link_shader() {
        unsigned int shaderProgram;
        shaderProgram = glCreateProgram();

        unsigned int vertex_shader = create_and_compile_vertex_shader();
        unsigned int fragment_shader = create_and_compile_fragment_shader();

        glAttachShader(shaderProgram, vertex_shader);
        glAttachShader(shaderProgram, fragment_shader);
        glLinkProgram(shaderProgram);

        // Check if shader compiling was successful
        int success;
        char infoLog[512];
        glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
        if (!success) {
            glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
            std::cout << "ERROR::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
        }

        glDeleteShader(vertex_shader);
        glDeleteShader(fragment_shader);

        return shaderProgram;
    }

    int render() {
        init_glfw();

        GLFWwindow *window = window_setting();
        if (!window) {
            return -1;
        }

        // Load the address of function pointers by glad
        if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
            std::cout << "Failed to initialize GLAD" << std::endl;
            return -1;
        }

        unsigned int shaderProgram = create_and_link_shader();

        unsigned int VAO1, VBO1, VAO2, VBO2;

        // Generate Array and Buffers
        glGenVertexArrays(1, &VAO1);
        glGenBuffers(1, &VBO1);

        glGenVertexArrays(1, &VAO2);
        glGenBuffers(1, &VBO2);

        glBindVertexArray(VAO1);
        glBindBuffer(GL_ARRAY_BUFFER, VBO1);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices1), vertices1, GL_STATIC_DRAW);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *) nullptr);
        glEnableVertexAttribArray(0);

        glBindVertexArray(VAO2);
        glBindBuffer(GL_ARRAY_BUFFER, VBO2);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices2), vertices2, GL_STATIC_DRAW);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *) nullptr);
        glEnableVertexAttribArray(0);

        // Render Loop
        // while loop until explicitly told to stop
        // until explicitly told to stop, the application will keep drawing iamges and handling user inputs
        while (!glfwWindowShouldClose(window)) {
            // input
            processInput(window);

            // rendering commands
            glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);

            // Use shader program when rendering
            glUseProgram(shaderProgram);

            glBindVertexArray(VAO1);
            glDrawArrays(GL_TRIANGLES, 0, 3);

            glBindVertexArray(VAO2);
            glDrawArrays(GL_TRIANGLES, 0, 3);

            // Swap color buffer used to render
            glfwSwapBuffers(window);
            // Check if any events are triggered (ex) keyboard, mouse, ...
            glfwPollEvents();
        }

        glDeleteVertexArrays(1, &VAO1);
        glDeleteBuffers(1, &VBO1);
        glDeleteVertexArrays(1, &VAO2);
        glDeleteBuffers(1, &VBO2);
        glDeleteProgram(shaderProgram);

        glfwTerminate();
        return 0;
    }
}