#include <iostream>
#include <string>

#include "glad/glad.h"
#include <GLFW/glfw3.h>

// Frame buffer or whatever
static void framebuffer_size_callback(GLFWwindow* window, int width, int height){
  (void)window;
  glViewport(0, 0, width, height);
}

// Getting shaders and stuff
static GLuint compileShader(GLenum type, const char* src){
  GLuint shader = glCreateShader(type);
  glShaderSource(shader, 1, &src, nullptr);
  glCompileShader(shader);

  // Error for shader compile
  GLint ok = 0;
  glGetShaderiv(shader, GL_COMPILE_STATUS, &ok);
  if (!ok) {
    GLint len = 0;
    glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &len);
    std::string log(len, '\0');
    glGetShaderInfoLog(shader, len, nullptr, log.data());
    std::cerr << "Shader compile failed:\n" << log << "\n";
    glDeleteShader(shader);
    return 0;
  }
  return shader;
}

// Making the program for shaders
static GLuint createProgram(const char* vsSrc, const char* fsSrc) {
  GLuint vs = compileShader(GL_VERTEX_SHADER, vsSrc);
  if (!vs) {
    return 0;
  }
  GLuint fs = compileShader(GL_FRAGMENT_SHADER, fsSrc);
  if (!fs) {
    glDeleteShader(vs);
    return 0;
  }

  // Actually make program
  GLuint prog = glCreateProgram();
  glAttachShader(prog, vs);
  glAttachShader(prog, fs);
  glLinkProgram(prog);

  glDeleteShader(vs);
  glDeleteShader(fs);

  // Error for program link
  GLint ok = 0;
  glGetProgramiv(prog, GL_LINK_STATUS, &ok);
  if (!ok) {
    GLint len = 0;
    glGetProgramiv(prog, GL_INFO_LOG_LENGTH, &len);
    std::string log(len, '\0');
    glGetProgramInfoLog(prog, len, nullptr, log.data());
    std::cerr << "Program link failed" << log << "\n";
    glDeleteProgram(prog);
    return 0;
  }
  return prog;
}

// The room where it happens
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
  GLFWwindow* window = glfwCreateWindow(800,600, "Learn OpenGL - Five Dots I Guess", nullptr, nullptr);
  if (!window) {
    std::cerr << "Failed to create GLFW window\n";
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

  glfwSetFramebufferSizeCallback(window, framebuffer_size_callback); // Genuinely might be the longest function name I've seen

  // Print the OpenGL version it actually gets
  std::cout << "OpenGL Version: " << glGetString(GL_VERSION) << "\n";
  std::cout << "Renderer: " << glGetString(GL_RENDERER) << "\n";

  // --- 1) Shaders (absolute minimum) ---
  const char* vertexShaderSrc = R"GLSL(
    #version 410 core
    layout (location = 0) in vec2 aPos; //position
    layout (location = 1) in vec3 aColor; //colors

    out vec3 vColor;

    void main () {
      gl_Position = vec4(aPos.x, aPos.y, 0.0, 1.0);
      gl_PointSize = 18.0;
      vColor = aColor;
    }
  )GLSL";

  const char* fragmentShaderSrc = R"GLSL(
    #version 410 core
    in vec3 vColor;
    out vec4 FragColor;

    void main () {
      FragColor = vec4(vColor, 1.0); //allows for individual colors
    }
  )GLSL";

  GLuint program = createProgram(vertexShaderSrc, fragmentShaderSrc);
  if (!program) {
    glfwDestroyWindow(window);
    glfwTerminate();
    return 1;
  }

  // --- 2) Vertex data: literally one point at the center of the screen ---
  float point[] = {
    // Each row is a point. Each point has floats (x, y, r, g, b)
    // x and y are positions, r, g, and b control color
    -0.3f, 0.0f, 1.0f, 0.0f, 0.0f,
    0.3f, 0.0f, 0.0f, 1.0f, 0.0f,
    0.0f, -0.3f, 0.0f, 0.0f, 1.0f,
    0.0f, 0.3f, 1.0f, 1.0f, 0.0f,
    0.0f, 0.0f, 0.33f, 0.10f, 0.55f,
  };

  // --- 3) VAO and VBO setup stuff ---
  GLuint vao = 0, vbo = 0;
  glGenVertexArrays(1, &vao);
  glGenBuffers(1, &vbo);

  glBindVertexArray(vao);

  glBindBuffer(GL_ARRAY_BUFFER, vbo);
  glBufferData(GL_ARRAY_BUFFER, sizeof(point), point, GL_STATIC_DRAW);

  // Position (location 0): 2 floats, stride 5 floats, offset 0
  glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);

  // Color (location 1): 3 floats, stride 5 floats, offset 2 floats
  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(2 * sizeof(float)));
  glEnableVertexAttribArray(1);

  glBindBuffer(GL_ARRAY_BUFFER, 0);
  glBindVertexArray(0);

  // Needed for point size in the shader to work
  glEnable(GL_PROGRAM_POINT_SIZE);

  // --- 4) MAIN LOOP ---
  while (!glfwWindowShouldClose(window)) {
    // Clear to a dark color
    glClearColor(0.08f, 0.10f, 0.15f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glUseProgram(program);
    glBindVertexArray(vao);
    glDrawArrays(GL_POINTS, 0, 5); // <-- FUNNY PLACE WHERE STUFF IS DISPLAYED (DOTS)
    glBindVertexArray(0);
    
    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  // Cleanup
  glDeleteBuffers(1, &vbo);
  glDeleteVertexArrays(1, &vao);
  glDeleteProgram(program);

  glfwDestroyWindow(window);
  glfwTerminate();
  return 0;
}


// VERY MUCH UNFINISHED