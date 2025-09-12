#ifndef RECTANGLE_H 
#define RECTANGLE_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

class Rectangle {
public:
    float x_left, x_right, y_bottom, y_top;
    float r, g, b;

    Rectangle(float left, float right, float bottom, float top, float red, float green, float blue) {
        x_left = left;
        x_right = right;
        y_bottom = bottom;
        y_top = top;
        r = red;
        g = green;
        b = blue;
    }

    void draw() {
        glColor3f(r, g, b);
        glBegin(GL_QUADS);
            glVertex2f(x_left, y_bottom);
            glVertex2f(x_right, y_bottom);
            glVertex2f(x_right, y_top);
            glVertex2f(x_left, y_top);
        glEnd();
    }

    void drawBorder() {
        glColor3f(0.3f, 0.3f, 0.3f); 
        glLineWidth(2.0f);
        glBegin(GL_LINE_LOOP);
            glVertex2f(x_left, y_top);
            glVertex2f(x_right, y_top);
            glVertex2f(x_right, y_bottom);
            glVertex2f(x_left, y_bottom);
        glEnd();
        glLineWidth(1.0f); 
    }

    bool isClicked(double mouseX, double mouseY) {
        return (mouseX >= this->x_left && mouseX <= this->x_right && 
                mouseY >= this->y_bottom && mouseY <= this->y_top);
    }
};

#endif