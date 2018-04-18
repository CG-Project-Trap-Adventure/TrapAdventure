// For now it is empty

static int lastKey = GLUT_KEY_RIGHT;

static int relative_constant = 7; // A constant value to decide spacing of objects and other things
                                  // Many movements depend on its value
static int speed = 1 * relative_constant;
static int jump_speed = 2 * relative_constant;
static float win_x = 0.0;
static float win_y = 225.0;		// Just for now.... Later thinking of using an array with x and y values of every change in height
static int dir = 0;		// 0 : UP, 1: DOWN

enum ScreenStates {
	_intro_screen = 0,
	_inst_screen,
	_game_screen
};

static ScreenStates screen = _game_screen;
