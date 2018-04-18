// For now it is empty

static int lastKey = GLUT_KEY_RIGHT;

static int speed = 7;

enum ScreenStates {
	_intro_screen = 0,
	_inst_screen,
	_game_screen
};

static ScreenStates screen = _game_screen;
