#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <math.h>
#include <Rectangle.h>
#include <Slider.h>
#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);
void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);


const unsigned int SCR_WIDTH = 500;
const unsigned int SCR_HEIGHT = 500;

float gRed = 0.0;
float gGreen = 0.0f;
float gBlue = 0.0;
float gZoom = 30.0f;
bool isPressed = false;

Rectangle resetButton(5.0f, 15.0f, -10.0f, -6.0f, 0.5f, 0.5f, 0.5f);
Rectangle resultBox(-15.0f, -5.0f, -10.0f, -6.0f, gRed, gGreen, gBlue);
Slider redSlider(-20.0f, 20.0f, 16.0f, 20.0f, 'r', &gRed);
Slider greenSlider(-20.0f, 20.0f, 8.0f, 12.0f, 'g', &gGreen);
Slider blueSlider(-20.0f, 20.0f, 0.0f, 4.0f, 'b', &gBlue);

int main() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "RGB Color Picker", NULL, NULL);
    if (window == NULL) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSetMouseButtonCallback(window, mouse_button_callback);
    glfwSetCursorPosCallback(window, cursor_position_callback);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }    

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-30.0, 30.0, -30.0, 30.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    while (!glfwWindowShouldClose(window)) {

        glClearColor(0.1f, 0.1f, 0.1f, 0.1f);
        glClear(GL_COLOR_BUFFER_BIT);

        redSlider.draw();
        redSlider.drawBorder();
        redSlider.drawSelector();

        greenSlider.draw();
        greenSlider.drawBorder();
        greenSlider.drawSelector();

        blueSlider.draw();
        blueSlider.drawBorder();
        blueSlider.drawSelector();

        resultBox.r = gRed;
        resultBox.g = gGreen;
        resultBox.b = gBlue;

        resultBox.draw();
        resultBox.drawBorder();
        
        resetButton.draw();
        resetButton.drawBorder();

        processInput(window);
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

void cursor_position_callback(GLFWwindow* window, double xpos, double ypos) {
    if (isPressed == true) {
        // pega a posição e converte para coordenadas do mundo
        double worldX = -gZoom + (xpos / SCR_WIDTH) * (2 * gZoom);
        double worldY = gZoom - (ypos / SCR_HEIGHT) * (2 * gZoom);
        
        if (redSlider.isClicked(worldX, worldY)) {
            redSlider.updateValue(worldX);
        }
        else if (greenSlider.isClicked(worldX, worldY)) {
            greenSlider.updateValue(worldX);
        }
        else if (blueSlider.isClicked(worldX, worldY)) {
            blueSlider.updateValue(worldX);
        }
    }
}

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods) {
    if (button == GLFW_MOUSE_BUTTON_LEFT) {
        if (action == GLFW_PRESS) {
            isPressed = true;

            // pega a posição e converte para coordenadas do mundo
            double xpos, ypos, worldX, worldY;
            glfwGetCursorPos(window, &xpos, &ypos);
            worldX = -gZoom + (xpos / SCR_WIDTH) * (2 * gZoom);
            worldY = gZoom - (ypos / SCR_HEIGHT) * (2 * gZoom);

            // pergunta pra cada objeto se ele foi clicado
            if (redSlider.isClicked(worldX, worldY)) {
                redSlider.updateValue(worldX);
            }
            else if (greenSlider.isClicked(worldX, worldY)) {
                greenSlider.updateValue(worldX);
            }
            else if (blueSlider.isClicked(worldX, worldY)) {
                blueSlider.updateValue(worldX);
            }
            else if (resetButton.isClicked(worldX, worldY)) {
                gRed = 0.0f; 
                gGreen = 0.0f; 
                gBlue = 0.0f;
            }
        }
        else if (action == GLFW_RELEASE) {
            isPressed = false;
            
            int redInt = gRed * 255;
            int greenInt = gGreen * 255;
            int blueInt = gBlue * 255;
            std::cout << "RGB: (" << redInt << ", " << greenInt << ", " << blueInt << ")" << std::endl;
        }
    }
}



