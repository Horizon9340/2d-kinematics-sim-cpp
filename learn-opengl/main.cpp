#include <iostream>

#include "glad/glad.h"
#include <GLFW/glfw3.h>

int main() {
  // Initialize GLFW window
  if(!glfwInit()){
    std::cerr << "Failed to initialize GLFW\n";
    return 1;
  }

  // ask for OpenGL context.
  // macOS supports up to 4.1, core profile.
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  // Required on macOS for core profile contexts:
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);

  // Create a window (also creates OpenGL context)
  GLFWwindow* window = glfwCreateWindow(800,600, "Learn OpenGL - Clear Screen", nullptr, nullptr);
  if (!window) {
    std::cerr << "Failed to create GLFW window\n";\
    glfwTerminate();
    return 1;
  }

  //Make this window's context the current one
  glfwMakeContextCurrent(window);


  // Load OpenGL functions using GLAD
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    std::cerr << "Failed to initialize GLAD\n";
    glfwDestroyWindow(window);
    glfwTerminate();
    return 1;
  }

  // Tell OpenGL what part of the window it should draw into
  glViewport(0, 0, 800, 600);

  // Print the OpenGL version it actually gets
  std::cout << "OpenGL Version: " << glGetString(GL_VERSION);
  std::cout << "Renderer: " << glGetString(GL_RENDERER);

  // Main loop: clear screen, show it, handle events
  while (!glfwWindowShouldClose(window)) {
    // Clear to a dark color
    glClearColor(0.08f, 0.10f, 0.15f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // Show frame
    glfwSwapBuffers(window);

    // Process input/events
    glfwPollEvents();
  }

  // Cleanup
  glfwDestroyWindow(window);
  glfwTerminate();

  return 0;
}


// VERY MUCH UNFINISHED