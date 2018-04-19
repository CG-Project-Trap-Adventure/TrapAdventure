#include <GL/glut.h>
#include <iostream>

using namespace std;

static int lastKey = GLUT_KEY_RIGHT;

static int level1_loaded = 0;

static int relative_constant = 5; // A constant value to decide spacing of objects and other things
                                  // Many movements depend on its value
static int speed = 2 * relative_constant;
static int jump_speed = 2 * relative_constant;
extern float win_x;
extern float win_y;		// Just for now.... Later thinking of using an array with x and y values of every change in height
static int dir = 0;		// 0 : UP, 1: DOWN
static int min_y = 225;
static int max_y = 350;

enum ScreenStates {
	_intro_screen = 0,
	_inst_screen,
	_game_screen
};
extern ScreenStates screen;

static int death_state = 0;	// 1-activated 0-deactivated
