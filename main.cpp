#include <GL/glut.h>
#include <map>
#include "components/trapadv.h"
#include "states.h"

// Spike spike = Spike();
IntroScreen introScreen = IntroScreen();
InstScreen instScreen = InstScreen();
DeathScreen deathScreen = DeathScreen();
R2D3 r2d3 = R2D3();
// static int lastKey = GLUT_KEY_RIGHT;

GLint x = 20, y = 20;
GLint length = 20, height = 20;
GLfloat color[3] = {1.0, 0.0, 0.0};

int window_id;
// int speed = 7;
// int dir = 0;		// 0 : UP, 1: DOWN
float win_w = 1366.0;
float win_h = 768.0;
float win_x = 0.0;
float win_y = 225.0;		// Just for now.... Later thinking of using an array with x and y values of every change in height

float r2d3_x;
float r2d3_y;

map <int, bool> key_map;

// enum ScreenStates {
// 	_intro_screen = 0,
// 	_inst_screen,
// 	_game_screen
// };

// float win_x = 0.0;
// float win_y = 0.0;

ScreenStates screen = _game_screen;

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	switch(screen) {
		case _intro_screen:
		introScreen.drawScreen();
		break;

		case _inst_screen:
		instScreen.drawScreen();
		break;

		case _game_screen:
		if(key_map[GLUT_KEY_RIGHT]) win_x += speed;
		if(key_map[GLUT_KEY_LEFT]) win_x -= speed;

		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(win_x, win_x + win_w, 0.0, win_h, -10.0, 10.0);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		if(level1_loaded == 0){
			setLevel();
			level1_loaded = 1;
		}
		drawLevel();

		if(key_map[GLUT_KEY_UP] == false) {
			r2d3.draw(win_x + win_w / 2.0, 225.0, 0);
		} else {
			r2d3.draw(win_x + win_w / 2.0, win_y, 0);
		}
		break;

		case _death_screen:
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(0.0, win_w, 0.0, win_h, -10.0, 10.0);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		deathScreen.drawScreen();
	}

	r2d3_x = win_x + 1366.0 / 2.0;
	r2d3_y = win_y;

	glutSwapBuffers();
}

void mouse(int btn, int state, int xx, int yy) {
	// cout << xx << ", " << yy << "\n";
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

void kbd(unsigned char key, int xx, int yy) {
	if(key == 'q') {		// Press q to quit
		glutDestroyWindow(window_id);
	}
}

void keys(int key, int xx, int yy) {
	if(screen == _game_screen) {
		key_map[key] = true;
		if(key == GLUT_KEY_RIGHT || key == GLUT_KEY_LEFT) {
			r2d3.setKey(key);
		}
		if(key == GLUT_KEY_UP) {
			// cout << "UP pressed\n";
		}
	}
}

void keys_up(int key, int xx, int yy) {
	if(screen == _game_screen && key != GLUT_KEY_UP) {
		key_map[key] = false;
	}
}

void myReshape(int w, int h) {
	// printf("(%d,%d)\n", w, h);
	win_h = h;
	win_w = w;
	glViewport(0,0,w,h);
	glutPostRedisplay();
}

void myidle() {

	// To calculate the jumping of r2d3
	if(key_map[GLUT_KEY_UP] == true) {
		// cout << "UP key true\n";
		if(win_y >= max_y) {
			dir = 1;
		}

		if(dir == 0) {
			win_y += jump_speed;
		} else {
			win_y -= jump_speed;
		}
		// cout << (win_x + win_w / 2.0) << ", " << win_y << "\n";

		if(win_y == min_y) {
			key_map[GLUT_KEY_UP] = false;
			dir = 0;
		}
	}

	// Collision detection of the level1
	level1CollisionDetection();

	glutPostRedisplay();
}

void myinit() {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glEnable(GL_DEPTH_TEST);
	glOrtho(0.0, win_w, 0.0, win_h, -10.0 , 10.0);
}

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1366, 768);
	window_id = glutCreateWindow("Trap Adventure");
	glutDisplayFunc(display);
	glutKeyboardFunc(kbd);
	glutSpecialFunc(keys);
	glutSpecialUpFunc(keys_up);
	glutMouseFunc(mouse);
	glutIdleFunc(myidle);		// Whenever you put GLUT_DOUBLE Please put this line
	myinit();
	glutReshapeFunc(myReshape);
	glutFullScreen();
	glutMainLoop();
}
