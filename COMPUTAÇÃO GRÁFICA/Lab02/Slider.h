#ifndef SLIDER_H
#define SLIDER_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <Rectangle.h>
#include <iostream>

class Slider : public Rectangle {
public:
    char colorType;
    float *valueToUpdate;    

    Slider(float left, float right, float bottom, float top, char type, float* valuePtr)
        : Rectangle(left, right, bottom, top, 0, 0, 0) {
        colorType = type;
        valueToUpdate = valuePtr;
    }

    void draw() {
        // guarda a cor da direita do slider
        float r = 0.0f, g = 0.0f, b = 0.0f;

        if (colorType == 'r') {
            r = 1.0f;
        } else if (colorType == 'g') {
            g = 1.0f;
        } else { 
            b = 1.0f;
        }

        glBegin(GL_QUADS);
            // vértices da esquerda são sempre pretos
            glColor3f(0.0f, 0.0f, 0.0f);
            glVertex2f(this->x_left, this->y_bottom);
            glVertex2f(this->x_left, this->y_top);

            // os vértices da direita usam as variáveis r, g, b
            glColor3f(r, g, b);
            glVertex2f(this->x_right, this->y_top);
            glVertex2f(this->x_right, this->y_bottom);
        glEnd();
    }

    void updateValue(double mouseX) {
    float newValue = (mouseX - this->x_left) / (this->x_right - this->x_left);

    // atualiza a variável global que o slider controla
    // valueToUpdate (ponteiro para gRed, gGreen, ou gBlue)
    *(this->valueToUpdate) = newValue;
    }


    void drawSelector() {
        float colorValue = *(this->valueToUpdate);
        float totalWidth = this->x_right - this->x_left;
        float colorSelectorX = this->x_left + (colorValue * totalWidth);
        
        float selectorWidth = 0.5f;
        float leftEdge = colorSelectorX - (selectorWidth / 2.0f);
        float rightEdge = colorSelectorX + (selectorWidth / 2.0f);

        glColor3f(1.0f, 1.0f, 1.0f);
        glBegin(GL_QUADS);
            glVertex2f(leftEdge, this->y_bottom);
            glVertex2f(rightEdge, this->y_bottom);
            glVertex2f(rightEdge, this->y_top);
            glVertex2f(leftEdge, this->y_top);
        glEnd();
    }
};

#endif