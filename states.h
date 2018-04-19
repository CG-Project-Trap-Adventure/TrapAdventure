#include <GL/glut.h>
#include <iostream>

using namespace std;

static int lastKey = GLUT_KEY_RIGHT;

static int level1_loaded = 0;

static int relative_constant = 5; // A constant value to decide spacing of objects and other things
                                  // Many movements depend on its value
static int speed = 2 * relative_constant;
static int jump_speed = 2 * relative_constant;
static float win_w = 1366.0;
static float win_h = 768.0;
static float win_x = 0.0;
static float win_y = 225.0;		// Just for now.... Later thinking of using an array with x and y values of every change in height
static int dir = 0;		// 0 : UP, 1: DOWN

static float r2d3_x = win_x + win_w / 2.0;
static float r2d3_y = win_y;

enum ScreenStates {
	_intro_screen = 0,
	_inst_screen,
	_game_screen
};

static int death_state = 0;	// 1-activated 0-deactivated

static ScreenStates screen = _game_screen;
