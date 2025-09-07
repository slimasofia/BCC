#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <math.h>
#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);
void drawCircle();

const unsigned int SCR_WIDTH = 600;
const unsigned int SCR_HEIGHT = 600;

float gZoom = 30.0f;

int main() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }    

    while (!glfwWindowShouldClose(window)) {
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(-gZoom, gZoom, -gZoom, gZoom, -1.0, 1.0);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
 
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

        // desenha o triângulo
        glBegin(GL_LINE_LOOP);
        glVertex2f(-5.0f, 5.0f);
        glVertex2f(5.0f, 5.0f);
        glVertex2f(0.0f, -5.0f);
        glEnd();

        // move o sistema de coordenadas, desloca o ponto (0, 0)
        // e desenha os 3 círculos

        glTranslatef(5.0f, 5.0f, 0.0f);
        drawCircle();

        glTranslatef(-10.0f, 0.0f, 0.0f);
        drawCircle();

        glTranslatef(5.0f,-10.0f, 0.0f);
        drawCircle();


        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

void processInput(GLFWwindow *window) {

    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);


    if (glfwGetKey(window, GLFW_KEY_O) == GLFW_PRESS) {
        if(gZoom > 1.0f){
            gZoom--;
        }
    }

    if(glfwGetKey(window, GLFW_KEY_P) == GLFW_PRESS) {
        gZoom++;
    }
}


void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

void drawCircle() {
        glBegin(GL_LINE_LOOP);
        float x, y, rad;
        for (int ang = 0; ang < 360; ang+=10) {
            rad = ang * M_PI / 180.0;
            x = 5 * cos(rad);
            y = 5 * sin(rad);
            glVertex2f(x, y);
        }
        glEnd();
}