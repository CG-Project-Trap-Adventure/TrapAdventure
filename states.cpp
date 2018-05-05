#include "states.h"

// static int lastKey;

// enum ScreenStates {
// 	_intro_screen = 0,
// 	_inst_screen,
// 	_game_screen
// };
//
ScreenStates screen = _game_screen;

float win_w = 1366.0;
float win_h = 768.0;
float win_x = 0.0;
float win_y = 221.0;		// Just for now.... Later thinking of using an array with x and y values of every change in height
int min_y = 200;
int max_y = min_y + 125;
int level1_loaded = 0;
int relative_constant = 1; // A constant value to decide spacing of objects and other things
int speed = 5 * relative_constant;
int jump_speed = 5 * relative_constant;
bool down_dir = false;
bool block_r = false;
bool block_l = false;
