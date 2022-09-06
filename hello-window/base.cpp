#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "../common.h"

namespace hello_window {
    void processInput(GLFWwindow *window);

    int render() {
        init_glfw();

        GLFWwindow* window = window_setting();
        if (!window) {
            return -1;
        }

        // Load the address of function pointers by glad
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
            std::cout << "Failed to initialize GLAD" << std::endl;
            return -1;
        }

        // Render Loop
        // while loop until explicitly told to stop
        // until explicitly told to stop, the application will keep drawing iamges and handling user inputs
        while (!glfwWindowShouldClose(window))
        {
            // input
            processInput(window);

            // rendering commands
            glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);

            // Swap color buffer used to render
            glfwSwapBuffers(window);
            // Check if any events are triggered (ex) keyboard, mouse, ...
            glfwPollEvents();
        }

        glfwTerminate();
        return 0;
    }

    void processInput(GLFWwindow *window)
    {
        // Check if escape key is pressed
        // GLFW_RELEASE - not pressed
        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            // set WindowShouldClose property to true
            glfwSetWindowShouldClose(window, true);
    }
}