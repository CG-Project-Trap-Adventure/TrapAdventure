#include "components/trapadv.h"
// #include "components/inst_screen/inst_screen.h"
// #include <GL/glut.h>
// #include <stdio.h>

state= {
    "inst_screen": true
}

Spike spike = Spike();
IntroScreen introScreen = IntroScreen();
InstScreen instScreen = InstScreen();
GLint x = 20, y = 20;
GLint length = 20, height = 20;
GLfloat color[3] = {1.0, 0.0, 0.0};

enum screen_state = {
    _intro_screen = 0,
    _inst_screen,
    _game_screen
};

int screen = _intro_screen;

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    // glMatrixMode(GL_MODELVIEW);
    // glLoadIdentity();
    // glTranslatef(x, y, 0);
    // spike.drawSpike(x, y);
    // printf("Spike Printed (%d, %d)\n",x,y);
    //glutSwapBuffers();
    // glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, 'A');
    switch(screen) {
    case _intro_screen:
        introScreen.drawScreen();
        break;
    case _inst_screen:
        instScreen.drawScreen();
        break;
    }
    glFlush();
}

void myinit() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glEnable(GL_DEPTH_TEST);
    glOrtho(0.0, 1366.0, 0.0, 768.0, -10.0 , 10.0);
}

void mouse(int xx, int yy) {
    // switch(key) {
    // case GLUT_KEY_LEFT:
    //     x-=5;
    //     printf("HELLO");
    //     // glTranslatef(-4.0, 0.0, 0.0);
    //     break;
    // case GLUT_KEY_RIGHT:
    //     x+=5;
    //     // glTranslatef(+4.0, 0.0, 0.0);
    //     break;
    // }
    switch(screen) {
    case _intro_screen:
        switch(key) {
        case GLUT_
        } 
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
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutCreateWindow("Spike maker");
    glutFullScreen();
    glutDisplayFunc(display);
    //glutSpecialFunc(keys);
    glutMouseFunc(mouse);
    myinit();
    glutMainLoop();
}
