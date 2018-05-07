#include "platform.h"
#include "../draw/draw.h"
#include "../../states.h"

Platform::Platform() {
}

Platform::Platform(int x, int y, int z, int l, int h, int id) {
	length = l;
	height = h;
	xx = x;
	yy = y;
	zz = z;
	pid = id;
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

void Platform::platformCollision() {

	

}

int Platform::sectorCode() {
	int code = 0;
	if((r2d3_y - 21) > (yy + height)) {
		code |= TOP;
	}
	else if((r2d3_y + 38.7415) < yy) {
		code |= BOTTOM;
	}

	if((r2d3_x - 25) > (xx + length)) {
		code |= RIGHT;
	}
	else if((r2d3_x + 25) < xx) {
		code |= LEFT;
	}

	return code;
}
