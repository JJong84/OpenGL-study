#include <iostream>

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "../utils/common.h"
#include "../utils/stb_image.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace coordinate_systems {
    void processInput(GLFWwindow *window) {
        // Check if escape key is pressed
        // GLFW_RELEASE - not pressed
        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            // set WindowShouldClose property to true
            glfwSetWindowShouldClose(window, true);
    }

    const float vertices[] = {
            -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
            0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
            0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
            0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
            -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
            -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

            -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
            0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
            0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
            0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
            -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
            -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

            -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
            -0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
            -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
            -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
            -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
            -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

            0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
            0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
            0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
            0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
            0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
            0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

            -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
            0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
            0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
            0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
            -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
            -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

            -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
            0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
            0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
            0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
            -0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
            -0.5f,  0.5f, -0.5f,  0.0f, 1.0f
    };

    // world space positions of our cubes
    glm::vec3 cubePositions[] = {
            glm::vec3( 0.0f,  0.0f,  0.0f),
            glm::vec3( 2.0f,  5.0f, -15.0f),
            glm::vec3(-1.5f, -2.2f, -2.5f),
            glm::vec3(-3.8f, -2.0f, -12.3f),
            glm::vec3( 2.4f, -0.4f, -3.5f),
            glm::vec3(-1.7f,  3.0f, -7.5f),
            glm::vec3( 1.3f, -2.0f, -2.5f),
            glm::vec3( 1.5f,  2.0f, -2.5f),
            glm::vec3( 1.5f,  0.2f, -1.5f),
            glm::vec3(-1.3f,  1.0f, -1.5f)
    };

    const unsigned int SCR_WIDTH = 800;
    const unsigned int SCR_HEIGHT = 600;

    int render() {
        init_glfw();

        GLFWwindow *window = window_setting(SCR_WIDTH, SCR_HEIGHT);
        if (!window) {
            return -1;
        }

        // Load the address of function pointers by glad
        if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
            std::cout << "Failed to initialize GLAD" << std::endl;
            return -1;
        }

        // Enable Depth Test
        glEnable(GL_DEPTH_TEST);

        Shader shader("../6_coordinate-systems/base_vs.glsl", "../6_coordinate-systems/base_fs.glsl");
        unsigned int VBO, VAO;

        // Generate Array and Buffers
        glGenVertexArrays(1, &VAO);
        glGenBuffers(1, &VBO);

        // Bind
        glBindVertexArray(VAO);

        // Bind and Copy vertices
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

        // position attribute
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void *) nullptr);
        glEnableVertexAttribArray(0);
        // texture coord attribute
        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void *) (3 * sizeof(float)));
        glEnableVertexAttribArray(1);

        // Texture
        // Generate Texture Object and Bind
        unsigned int texture1, texture2;

        // Load Texture 1

        glGenTextures(1, &texture1);
        glBindTexture(GL_TEXTURE_2D, texture1);

        // Set Wrapping / Filtering Options
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        // Load Image for Texture
        int width, height, nrChannels;
        stbi_set_flip_vertically_on_load(true); // tell stb_image.h to flip loaded texture's on the y-axis.

        unsigned char *data = stbi_load("../images/container.jpeg", &width, &height, &nrChannels, 0);
        if (data) {
            // Generate Texture Image
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
            // Generate Mipmap
            glGenerateMipmap(GL_TEXTURE_2D);
        } else {
            std::cout << "Failed to load texture" << std::endl;
        }
        // Free Data
        stbi_image_free(data);

        // Load Texture 2

        glGenTextures(1, &texture2);
        glBindTexture(GL_TEXTURE_2D, texture2);

        // Set Wrapping / Filtering Options
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);


        data = stbi_load("../images/awesomeface.png", &width, &height, &nrChannels, 0);
        if (data) {
            // Generate Texture Image
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
            // Generate Mipmap
            glGenerateMipmap(GL_TEXTURE_2D);
        } else {
            std::cout << "Failed to load texture" << std::endl;
        }
        // Free Data
        stbi_image_free(data);

        // Use shader program when rendering
        shader.use();

        // setting glUniform1i
        shader.setInt("texture1", 0);
        shader.setInt("texture2", 1);

        while (!glfwWindowShouldClose(window)) {
            // input
            processInput(window);

            // rendering commands
            glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

            // Bind Texture
            glActiveTexture(GL_TEXTURE0); // Activate the texture unit
            glBindTexture(GL_TEXTURE_2D, texture1); // Bind texture to active texture unit
            glActiveTexture(GL_TEXTURE1); // Activate the texture unit
            glBindTexture(GL_TEXTURE_2D, texture2); // Bind texture to active texture unit

            shader.use();

            // create transformations
            glm::mat4 view          = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
            glm::mat4 projection    = glm::mat4(1.0f);
            projection = glm::perspective(glm::radians(45.0f), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
            view       = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));

            // pass transformation matrices to the shader
            shader.setMat4("projection", projection); // note: currently we set the projection matrix each frame, but since the projection matrix rarely changes it's often best practice to set it outside the main loop only once.
            shader.setMat4("view", view);

            glBindVertexArray(VAO);
            // render boxes
            glBindVertexArray(VAO);
            for (unsigned int i = 0; i < 10; i++)
            {
                // calculate the model matrix for each object and pass it to shader before drawing
                glm::mat4 model = glm::mat4(1.0f);
                model = glm::translate(model, cubePositions[i]);
                float angle = 30.0f * (float) i;
                if (i % 3 == 0)
                    angle += (float) glfwGetTime() * 25;
                model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
                shader.setMat4("model", model);

                glDrawArrays(GL_TRIANGLES, 0, 36);
            }

            // Swap color buffer used to render
            glfwSwapBuffers(window);
            // Check if any events are triggered (ex) keyboard, mouse, ...
            glfwPollEvents();
        }

        glDeleteVertexArrays(1, &VAO);
        glDeleteBuffers(1, &VBO);

        glfwTerminate();
        return 0;
    }
}