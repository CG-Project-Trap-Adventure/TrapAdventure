#include "spike.h"

Spike::Spike() {
    length = 20;    //Keep this as a multiple of 2
    height = 20;
    color[0] = 1.0;
    color[1] = 0.0;
    color[2] = 0.0;
}

Spike::Spike(int l, int h){
    length = l;
    height = h;
}

/*
    (x+(length/2), y+height)
                *
               * * 
              *   *
             *     *
            *       *
           *         *
          *           *
   (x,y) ***************  (x+length, y)

*/
void Spike::drawSpike(int x, int y) {
    // glColor3fv(color);
    GLfloat vertices[3][2];
    vertices[0][0] = (GLfloat)(x);
    vertices[0][1] = (GLfloat)(y);
    vertices[1][0] = (GLfloat)(x+length);
    vertices[1][1] = (GLfloat)(y);
    vertices[2][0] = (GLfloat)(x+length/2);
    vertices[2][1] = (GLfloat)(y+height);
    glBegin(GL_TRIANGLES);
        glVertex2fv(vertices[0]);
        glVertex2fv(vertices[1]);
        glVertex2fv(vertices[2]);
    glEnd();
}