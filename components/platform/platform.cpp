#include "platform.h"
#include "../draw/draw.h"
#include "../../states.h"

Platform::Platform() {
}

Platform::Platform(int x, int y, int z, int l, int h) {
	length = l;
	height = h;
	xx = x;
	yy = y;
	zz = z;
}

/*
Shape of you(r platform)
					II
	(xx, yy+h)					 (xx+w, yy+h)
	*****************************
I	*****************************	III
	*****************************
	(xx, yy)					 (xx+w, yy)
					IV
*/

void Platform::drawPlatform() {
	Draw draw = Draw();

	glPushMatrix();
	draw.drawBox(xx, yy, zz, length, height);
	glPopMatrix();
}

void Platform::platformCollision(){
	float x1, y1, x2, y2;	// Points for platform edge
	int flag;

	if(r2d3_y - 21 <= 0.0) {
		screen = _death_screen;
	}
	// Same conditions as below... But doesnt work...
	if(r2d3_x + 25 == xx && r2d3_y + 38.7415 >= yy && r2d3_y - 21 <= yy + height) {
		cout << "Right blocked\n";
		block_r = true;
	}
	if(r2d3_x - 25 == xx + length && r2d3_y - 21 <= yy + height && r2d3_y + 38.7415 >= yy) {
		block_l = true;
	}

	// Sector 2
	if(r2d3_y - 21 > yy && r2d3_x + 25 >= xx && r2d3_x - 25 <= xx + length) {
		// x1 = xx;
		// y1 = yy + ;
		// x2 = xx + w;
		// y2 = yy + h;
		// cout << "Sector 2\n";
		min_y = (min_y < (yy + height)) ? (yy + height) : min_y;
	}
	// Sector 4
	else if(r2d3_y + 38.7415 < yy && r2d3_x + 25 >= xx && r2d3_x - 25 <= xx + length) {
		// x1 = xx;
		// y1 = yy;
		// x2 = xx + length;
		// y2 = yy;
		// cout << "Sector 4\n";
		max_y = (max_y > yy) ? yy : min_y + 125;
	}
	// Sector 1
	else if(r2d3_x + 25 < xx && r2d3_y + 38.7415 >= yy && r2d3_y - 21 <= yy + height) {
		// x1 = xx;
		// y1 = yy;
		// x2 = xx;
		// y2 = yy + height;
		cout << "Sector 1 " << r2d3_x << "\t" << r2d3_y << "\n";
		// if(r2d3_x + 25 == xx) {
		// 	block_r = true;
		// }
		min_y = 0;
		// printf("SECTOR 1 %f,%f\n", r2d3_x, r2d3_y);
	}

	//Sector 3
	else if(r2d3_x - 25 > xx + length && r2d3_y - 21 <= yy + height && r2d3_y + 38.7415 >= yy) {
		// x1 = xx + length;
		// y1 = yy;
		// x2 = xx + length;
		// y2 = yy + height;
		// cout << "Sector 3\n";
		// if(r2d3_x - 25 == xx + length) {
		// 	block_l = true;
		// }
		min_y = 0;
	}
	// else {
	// 	// printf("Mai hoon else!!! %d\n", min_y);
	// 	min_y = 0;
	// }
}
