#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <math.h>
#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);

// settings
const unsigned int SCR_WIDTH = 600;
const unsigned int SCR_HEIGHT = 600;

int main()
{
    // inicialização e configuração da GLFW 
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    // criação da janela
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }    

    // configuração da câmera
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-30.0, 30.0, -30.0, 30.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    while (!glfwWindowShouldClose(window)) {

        processInput(window);

        glClearColor(0.1f, 0.1f, 0.1f, 0.1f);
        glClear(GL_COLOR_BUFFER_BIT);

        // desenha os eixos
        glBegin(GL_LINES);
        glVertex2f(-20.0f, 0.0f);
        glVertex2f(20.0f, 0.0f);
        glVertex2f(0.0f, -20.0f);
        glVertex2f(0.0f, 20.0f);
        glEnd();

        // desenha o círculo
        glBegin(GL_LINE_LOOP);
        for (int ang = 0; ang < 360; ang+=10) {
            float x, y, rad;
            rad = ang * M_PI / 180.0;
            x = 5 * cos(rad);
            y = 5 * sin(rad);
            glVertex2f(x, y);
        }
        glEnd();
        
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

void processInput(GLFWwindow *window) {
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}
