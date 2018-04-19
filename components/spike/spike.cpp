#include "spike.h"

Spike::Spike() {
    length = 20;    //Keep this as a multiple of 2
    height = 20;
    color[0] = 1.0;
    color[1] = 0.0;
    color[2] = 0.0;
}

Spike::Spike(int x, int y, int z, int l, int h){
    xx = x;
    yy = y;
    zz = z;
    length = l;
    height = h;
}

Spike::Spike(int x, int y, int z){
    xx = x;
    yy = y;
    zz = z;
    length = 20;
    height = 20;
}

/*
Shape of you(r spike)
    (x+(length/2), y+height)
                *
               ***
              *****
             *******
            *********
           ***********
          *************
   (x,y) ***************  (x+length, y)

*/
void Spike::drawSpike() {
    // glColor3fv(color);
    GLfloat vertices[3][3];
    vertices[0][0] = (GLfloat)(xx);
    vertices[0][1] = (GLfloat)(yy);
    vertices[0][2] = zz;
    vertices[1][0] = (GLfloat)(xx+length);
    vertices[1][1] = (GLfloat)(yy);
    vertices[1][2] = zz;
    vertices[2][0] = (GLfloat)(xx+length/2);
    vertices[2][1] = (GLfloat)(yy+height);
    vertices[2][2] = zz;
    glBegin(GL_TRIANGLES);
        glVertex3fv(vertices[0]);
        glVertex3fv(vertices[1]);
        glVertex3fv(vertices[2]);
    glEnd();
}

// void Spike::spikeCollision() {
//     // Collision detection logic
// }
