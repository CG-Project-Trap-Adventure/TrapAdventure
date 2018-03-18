#include <GL/glut.h>
#include "components/trapadv.h"
// #include "components/inst_screen/inst_screen.h"
// #include <GL/glut.h>
// #include <stdio.h>
#include <map>

Spike spike = Spike();
IntroScreen introScreen = IntroScreen();
InstScreen instScreen = InstScreen();
GLint x = 20, y = 20;
GLint length = 20, height = 20;
GLfloat color[3] = {1.0, 0.0, 0.0};

int speed = 7;
float win_w = 1366.0;
float win_h = 768.0;

map <int, bool> key_map;

enum ScreenStates {
	_intro_screen = 0,
	_inst_screen,
	_game_screen
};

float win_x = 0.0;
float win_y = 0.0;

ScreenStates screen = _inst_screen;

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	// glMatrixMode(GL_MODELVIEW);
	// glLoadIdentity();
	// glTranslatef(x, y, 0);
	// spike.drawSpike(x, y);
	// printf("Spike Printed (%d, %d)\n",x,y);
	//glutSwapBuffers();
	// glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, 'A');
	// glMatrixMode(GL_PROJECTION);
	// glLoadIdentity();
	// glOrtho(0.0, win_w, 0.0, win_h, -10.0, 10.0);
	// glMatrixMode(GL_MODELVIEW);
	// glLoadIdentity();
	switch(screen) {
		case _intro_screen:
		introScreen.drawScreen();
		break;
		case _inst_screen:
		instScreen.drawScreen();
		break;
		case _game_screen:
			if(key_map[GLUT_KEY_RIGHT]) win_x+=speed;
			if(key_map[GLUT_KEY_LEFT]) win_x-=speed;
			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();
			glOrtho(win_x, win_x + win_w, 0.0, win_h, -10.0, 10.0);
			glMatrixMode(GL_MODELVIEW);
			glLoadIdentity();
			drawLevel();
		break;

	}
	glutSwapBuffers();
	// glFlush();
}

void myinit() {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glEnable(GL_DEPTH_TEST);
	glOrtho(0.0, win_w, 0.0, win_h, -10.0 , 10.0);
}

void mouse(int btn, int state, int xx, int yy) {
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
	// switch(screen) {
	// case _intro_screen:
	//     switch(key) {
	//     case GLUT_
	//     }
	// }
	cout << xx << ", " << yy << "\n";
	switch(screen) {
		case _intro_screen:
		switch(btn) {
			case GLUT_LEFT_BUTTON:
			if(xx >= 300*win_w/1366 && xx <= 500*win_w/1366 && yy >= 658*win_h/768 && yy <= 693*win_h/768) {
				screen = _inst_screen;
			}
			else {
				cout << "Outside button\n";
			}
			break;
		}
		break;

		case _inst_screen:
			if(btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
				if(xx >= 300*win_w/1366 && xx <= 500*win_w/1366 && yy >= 658*win_h/768 && yy <= 693*win_h/768) {
					screen = _game_screen;
				}
			}
			break;
	}
	display();
}

void keys(int key, int xx, int yy) {
	if(screen == _game_screen)
		key_map[key] = true;
}

void keys_up(int key, int xx, int yy) {
	if(screen == _game_screen)
		key_map[key] = false;
}

void moveSpike() {
	x+=2;
	glutPostRedisplay();
}

void myReshape(int w, int h) {
	printf("(%d,%d)\n", w, h);
	win_h = h;
	win_w = w;
	glViewport(0,0,w,h);
	glutPostRedisplay();
}

void myidle() {
	glutPostRedisplay();
}

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("Spike maker");
	glutDisplayFunc(display);
	glutSpecialFunc(keys);
	glutSpecialUpFunc(keys_up);
	glutMouseFunc(mouse);
	glutIdleFunc(myidle);		// Whenever you put GLUT_DOUBLE Please put this line
	myinit();
	glutReshapeFunc(myReshape);
	glutFullScreen();
	glutMainLoop();
}
