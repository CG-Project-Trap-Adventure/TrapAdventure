#include "components/trapadv.h"
// #include <GL/glut.h>
// #include <stdio.h>

Spike spike = Spike();
IntroScreen introScreen = IntroScreen();
GLint x = 20, y = 20;
GLint length = 20, height = 20;
GLfloat color[3] = {1.0, 0.0, 0.0};

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    // glMatrixMode(GL_MODELVIEW);
    // glLoadIdentity();
    // glTranslatef(x, y, 0);
    // spike.drawSpike(x, y);
    // printf("Spike Printed (%d, %d)\n",x,y);
    //glutSwapBuffers();
    // glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, 'A');
    introScreen.drawScreen();
    glFlush();
}

void myinit() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    gluOrtho2D(0.0, 1366.0, 0.0, 768.0);
}

void keys(int key, int xx, int yy) {
    switch(key) {
    case GLUT_KEY_LEFT:
        x-=5;
        printf("HELLO");
        // glTranslatef(-4.0, 0.0, 0.0);
        break;
    case GLUT_KEY_RIGHT:
        x+=5;
        // glTranslatef(+4.0, 0.0, 0.0);
        break;
    }
    display();
}

void moveSpike() {
    x+=2;
    glutPostRedisplay();
}

void myReshape(int w, int h) {
    printf("(%d,%d)", w, h);
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("Spike maker");
    glutFullScreen();
    glutDisplayFunc(display);
    glutSpecialFunc(keys);
    myinit();
    glutMainLoop();
}
