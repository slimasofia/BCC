#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <math.h>
#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);
void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
void drawSlider(float y_bottom, float y_top, char color);
void drawEdge(float x_left, float x_right, float y_bottom, float y_top);
void drawSelector(float colorValue, float y_bottom, float y_top);
void drawButton(float x_left, float x_right, float y_bottom, float y_top, float r, float g, float b);
float calculateColorValue(double worldX);

const unsigned int SCR_WIDTH = 500;
const unsigned int SCR_HEIGHT = 500;

float gRed = 0.0;
float gGreen = 0.0f;
float gBlue = 0.0;
float gZoom = 30.0f;

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

        processInput(window);

        glClearColor(0.1f, 0.1f, 0.1f, 0.1f);
        glClear(GL_COLOR_BUFFER_BIT); 

//  ---------- DESENHA OS SLIDERS E AS BORDAS ---------- 

        // RED
        drawSlider(16.0f, 20.0f, 'r');
        drawEdge(-20.0f, 20.0f, 16.0f, 20.0f);

        // GREEN
        drawSlider(8.0f, 12.0f, 'g'); 
        drawEdge(-20.0f, 20.0f, 8.0f, 12.0f);

        // BLUE
        drawSlider(0.0f, 4.0f, 'b');
        drawEdge(-20.0f, 20.0f, 0.0f, 4.0f);

//  ---- DESENHA O BOTÃO DE RESETAR A COR E COR RESULTANTE ---- 

        // mostra a cor resultante
        drawButton(-15.0f, -5.0f, -10.0f, -6.0f, gRed, gGreen, gBlue);
        drawEdge(-15.0f, -5.0f, -10.0f, -6.0f);

        // resetar a cor
        drawButton(15.0f, 5.0f, -10.0f, -6.0f, 0.5f, 0.5f, 0.5f);
        drawEdge(15.0f, 5.0f, -10.0f, -6.0f);

//  ---------- DESENHA OS SELETORES ----------

        drawSelector(gRed, 16.0f, 20.0f);
        drawSelector(gGreen, 8.0f, 12.0f);
        drawSelector(gBlue, 0.0f, 4.0f);

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

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods) {
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {
        double x_pos, y_pos, worldX, worldY;
        glfwGetCursorPos(window, &x_pos, &y_pos);

        worldX = -gZoom + (x_pos / SCR_WIDTH) * (2 * gZoom);
        worldY = gZoom - (y_pos / SCR_HEIGHT) * (2 * gZoom);

        // o clique foi dentro do slider vermelho
        if (worldX >= -20.0f && worldX <= 20.0f && worldY >= 16.0f && worldY <= 20.0f) {
            gRed = calculateColorValue(worldX);
        }

        // o clique foi dentro do slider verde
        else if (worldX >= -20.0f && worldX <= 20.0f && worldY >= 8.0f && worldY <= 12.0f) {
            gGreen = calculateColorValue(worldX);
        } 

        // o clique foi dentro do slider azul
        else if (worldX >= -20.0f && worldX <= 20.0f && worldY >= 0.0f && worldY <= 4.0f) {
            gBlue = calculateColorValue(worldX);
        }

         // o clique foi dentro do botão de resetar a cor
        else if (worldX >= 5.0f && worldX <= 15.0f && worldY >= -10.0f && worldY <= -6.0f) {
            // reseta a cor para preto
            gRed = 0.0f;
            gBlue = 0.0f;
            gGreen = 0.0f;
        }

        // converter pra escala 0-255 para imprimir no formato RGB
        int redInt = gRed * 255;
        int greenInt = gGreen * 255;
        int blueInt = gBlue * 255;

        std::cout << "RGB: (" << redInt << ", " << greenInt << ", " << blueInt << ")" << std::endl;      
    }
}


void drawSlider(float y_bottom, float y_top, char color) {
    // guarda a cor da direita do slider
    float r = 0.0f, g = 0.0f, b = 0.0f;

    if (color == 'r') {
        r = 1.0f;
    } else if (color == 'g') {
        g = 1.0f;
    } else { 
        b = 1.0f;
    }

    glBegin(GL_QUADS);
        // vértices da esquerda são sempre pretos
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(-20.0f, y_bottom);
        glVertex2f(-20.0f, y_top);

        // os vértices da direita usam as variáveis r, g, b
        glColor3f(r, g, b);
        glVertex2f(20.0f, y_top);
        glVertex2f(20.0f, y_bottom);
    glEnd();
}

void drawEdge(float x_left, float x_right, float y_bottom, float y_top) {
        glColor3f(0.3f, 0.3f, 0.3f); // cor
        glLineWidth(2.0f);           // espessura  
        glBegin(GL_LINE_LOOP); 
            glVertex2f(x_left, y_top);
            glVertex2f(x_right, y_top);
            glVertex2f(x_right, y_bottom);
            glVertex2f(x_left, y_bottom);
        glEnd();
}

void drawSelector(float colorValue, float y_bottom, float y_top) {
    float colorSelectorX = -20.0f + (colorValue * 40.0f);   // ponto de partida + distância que precisa andar
    float selectorWidth = 0.5f;
    // calcular os valores do seletor pra estar centrado no colorSelectorX
    float leftEdge = colorSelectorX - (selectorWidth / 2.0f);
    float rightEdge = colorSelectorX + (selectorWidth / 2.0f);

    // define a cor do seletor
    glColor3f(1.0f, 1.0f, 1.0f);
    // desenha o seletor usando as bordas
    glBegin(GL_QUADS);
        glVertex2f(leftEdge, y_bottom);  
        glVertex2f(rightEdge, y_bottom);
        glVertex2f(rightEdge, y_top); 
        glVertex2f(leftEdge, y_top);  
    glEnd();

}

void drawButton(float x_left, float x_right, float y_bottom, float y_top, float r, float g, float b) {
    glColor3f(r, g, b);
        glBegin(GL_QUADS);
            glVertex2f(x_left, y_bottom);  
            glVertex2f(x_right, y_bottom); 
            glVertex2f(x_right, y_top);   
            glVertex2f(x_left, y_top);  
        glEnd();
}

float calculateColorValue(double worldX) {
    // calcula a distância do clique para o início do slider
    // e divide pelo tamanho total dele
    return (worldX + 20.0f)/ 40.0f;
}