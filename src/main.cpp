#include <cstdio>

#include "glad/glad.h"
#include "GLFW/glfw3.h"

int windowWidth = 1920;
int windowHeight = 1080;

GLFWwindow* window;

#define VSYNC 1

int init()
{
    printf("Initializing...\n");
    // Initialize GLFW
    if(glfwInit() < 0)
    {
        const char* error;
        glfwGetError(&error);
        printf("Failed to initialize GLFW: %s.\n", error);
        return -1;
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    
    // Create Window
    window = glfwCreateWindow(windowWidth, windowHeight, "Voxel", nullptr, nullptr);
    if(window == nullptr)
    {
        const char* error;
        glfwGetError(&error);
        printf("Failed to create window: %s.\n", error);
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSwapInterval(VSYNC);

    // Initialize GLAD/OpenGL
    if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress)))
    {
        const char* error;
        glfwGetError(&error);
        printf("Failed to initialize GLAD: %s.\n", error);
        return -1;
    }
    glViewport(0, 0, windowWidth, windowHeight);
    printf("Successfully Initialized. \n");
    return 0;
}

int main(int argc, char* argv[])
{
    if(const int exitCode = init(); exitCode < 0)
    {
        printf("Failed To Initialize. Shutting Down...");
        return exitCode;
    }
    
    while (!glfwWindowShouldClose(window))
    {
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
