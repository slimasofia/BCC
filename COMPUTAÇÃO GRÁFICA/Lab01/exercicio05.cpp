#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <math.h>
#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);
void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);

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
    if (window == NULL) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSetMouseButtonCallback(window, mouse_button_callback);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }    

    while (!glfwWindowShouldClose(window)){
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(-gZoom, gZoom, -gZoom, gZoom, -1.0, 1.0);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
   
        processInput(window);
      
        glClearColor(0.1f, 0.1f, 0.1f, 0.1f);
        glClear(GL_COLOR_BUFFER_BIT);

        glBegin(GL_LINES);
        glVertex2f(-20.0f, 0.0f);
        glVertex2f(20.0f, 0.0f);
        glVertex2f(0.0f, -20.0f);
        glVertex2f(0.0f, 20.0f);
        glEnd();

        glBegin(GL_LINE_STRIP);

        float raio = 0.1f;
        for (int ang = 0; ang < 1080; ang+=10) {
                float x, y, rad;
                rad = ang * M_PI / 180.0;
                x = raio * cos(rad);
                y = raio * sin(rad);
                glVertex2f(x, y);
                raio += 0.1f;
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

    if (glfwGetKey(window, GLFW_KEY_O) == GLFW_PRESS) {
        if(gZoom > 1.0f){
            gZoom--;
        }
    }

    if(glfwGetKey(window, GLFW_KEY_P) == GLFW_PRESS){
        gZoom++;
    }
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods) {
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {
        double x_pos, y_pos, worldX, worldY;
        glfwGetCursorPos(window, &x_pos, &y_pos);

        worldX = -gZoom + (x_pos / SCR_WIDTH) * (2 * gZoom);
        worldY = gZoom - (y_pos / SCR_HEIGHT) * (2 * gZoom);
        std::cout << "Coordenadas do Mundo: (" << worldX << ", " << worldY << ")" << std::endl;
    }
}