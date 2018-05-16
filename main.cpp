#include <GL/glut.h>
#include <map>
#include <time.h>
#include "components/trapadv.h"
#include "states.h"

// Spike spike = Spike();
IntroScreen introScreen = IntroScreen();
InstScreen instScreen = InstScreen();
DeathScreen deathScreen = DeathScreen();
WinScreen winScreen = WinScreen();
R2D3 r2d3 = R2D3();
Score gameScore = Score();
// static int lastKey = GLUT_KEY_RIGHT;

GLint x = 20, y = 20;
GLint length = 20, height = 20;
GLfloat color[3] = {1.0, 0.0, 0.0};

int window_id;
// int speed = 7;
// int down_dir = 0;		// 0 : UP, 1: DOWN
// float win_w = 1366.0;
// float win_h = 768.0;
// float win_x = 0.0;
// float win_y = 225.0;		// Just for now.... Later thinking of using an array with x and y values of every change in height
// int min_y = 225;
// int max_y = min_y + 125;

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

// ScreenStates screen = _game_screen;

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	switch(screen) {
		case _intro_screen:
		score = 0;
		introScreen.drawScreen();
		break;

		case _inst_screen:
		glutSetCursor(GLUT_CURSOR_LEFT_ARROW);
		score = 0;
		win_x = 0;
		win_y = 325.0;
		min_y = 200;
		max_y = min_y + 124;
		speed = 1 * relative_constant;
		jump_speed = 1 * relative_constant;
		level1_loaded = 0;
		instScreen.drawScreen();
		key_map[GLUT_KEY_LEFT] = false;
		key_map[GLUT_KEY_RIGHT] = false;
		key_map[GLUT_KEY_UP] = false;
		break;

		case _game_screen:
		glutSetCursor(GLUT_CURSOR_NONE);
		if(key_map[GLUT_KEY_RIGHT] && block_r == false) {
			win_x += speed;
			score += score_inc;
			prev_mov_time = 0;
			right_dir = true;
		}
		if(key_map[GLUT_KEY_LEFT] && block_l == false) {
			win_x -= speed;
			score -= score_dec;
			prev_mov_time = 0;
			right_dir = false;
		}
		if(!(key_map[GLUT_KEY_RIGHT] && key_map[GLUT_KEY_LEFT])) {
			// standing still
			if(!(prev_mov_time))
				prev_mov_time = time(NULL);
			if(time(NULL) - prev_mov_time >= mov_delay_time) {
				prev_mov_time = time(NULL);
				score -= score_dec;
			}
		}
		block_r = block_l = false;

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

		cout << win_x + 1364.0 / 2.0 << "\t" << win_y << "\n";
		r2d3.draw(win_x + 1364.0 / 2.0, win_y, 0);
		gameScore.drawScore();

		// Not required !!!!! XD
		// if(key_map[GLUT_KEY_UP] == false) {
		// 	r2d3.draw(win_x + win_w / 2.0, win_y, 0);		// R2D3 main body radius = 21
		// } else {
		// 	cout << win_y << "\n";
		// 	r2d3.draw(win_x + win_w / 2.0, win_y, 0);
		// }
		break;

		case _death_screen:
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(0.0, win_w, 0.0, win_h, -10.0, 10.0);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		deathScreen.drawScreen();

		case _win_screen:
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(0.0, win_w, 0.0, win_h, -10.0, 10.0);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		winScreen.drawScreen();
	}

	r2d3_x = win_x + 1364.0 / 2.0;
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
				// cout << "Outside button\n";
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
	if(screen == _death_screen || screen == _win_screen){
		if(key == 'r') {	// Press r to replay
			screen = _inst_screen;
		}
	}
}

void keys(int key, int xx, int yy) {
	if(screen == _game_screen) {
		key_map[key] = true;
		if(key == GLUT_KEY_RIGHT || key == GLUT_KEY_LEFT) {
			r2d3.setKey(key);
		}
		if(key == GLUT_KEY_UP) {
			// cout << win_y << " UP \n";
			up_key = true;
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
	// cout << win_h << "\t" << win_w << "\n";
	glViewport(0,0,w,h);
	glutPostRedisplay();
}

void myidle() {
	if(screen == _game_screen)
	{	// To calculate the jumping of r2d3
		if(key_map[GLUT_KEY_UP] == true) {
			// cout << "UP key true\n";
			if(win_y >= max_y) {
				// cout << "Down started" << "\n";
				down_dir = true;
			}

			if(down_dir == false) {
				win_y += jump_speed;
			} else {
				win_y -= jump_speed;
			}
			// cout << (win_x + win_w / 2.0) << ", " << win_y << "\n";

			if(win_y - 20 == min_y) {
				key_map[GLUT_KEY_UP] = false;
				down_dir = false;
				up_key = false;
			}

		} else {
			if(win_y - 21 > min_y) {
				// cout << "SPCL case " << win_y << " " << min_y << "\n";
				key_map[GLUT_KEY_UP] = true;
				down_dir = true;
			}
		}

		// Collision detection of the level1
		// safe = false;
		// max_y = min_y + 125;
		min_y = 0;
		level1CollisionDetection();
		// up_key = false;

		// if(win_y > min_y) {
		// 	if(win_y - 25 != min_y)
		// 		key_map[GLUT_KEY_UP] = true;
		// 	down_dir = 1;
		// }
	}
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
