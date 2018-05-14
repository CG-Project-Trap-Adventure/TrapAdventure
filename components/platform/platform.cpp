#include "platform.h"
#include "../draw/draw.h"
#include "../../states.h"
#include <time.h>

Platform::Platform() {
}

Platform::Platform(int x, int y, int z, int l, int h, int id, bool vis, time_t t) {
	length = l;
	height = h;
	xx = x;
	yy = y;
	zz = z;
	pid = id;
	visible = vis;
	show_time = t;
	prev_time = 0;
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

	if(r2d3_y - 22 <= 0.0) {
		screen = _death_screen;
	}
	if(r2d3_x + 24 > xx && r2d3_x + 24 < xx + (length/2) && r2d3_y + 40 >= yy && r2d3_y - 20 <= yy + height) {
		win_x = xx - 24 - (win_w / 2.0);
	}
	// cout<<r2d3_x<<","<<r2d3_y<<endl;
	// cout<<(r2d3_x - 24 < xx + length && r2d3_x - 24 > xx + (length/2) && r2d3_y - 20 <= yy + height && r2d3_y + 40 >= yy)<<endl;
	if(r2d3_x - 24 < xx + length && r2d3_x - 24 > xx + (length/2) && r2d3_y - 20 <= yy + height && r2d3_y + 40 >= yy) {
		win_x = xx + length + 24 - (win_w / 2.0);
		cout<<"Going right!!!"<<endl;
	}

	// Sector 2
	if(r2d3_y - 20 >= yy + height && r2d3_x + 24 >= xx && r2d3_x - 24 <= xx + length) {
		min_y = (min_y < (yy + height)) ? (yy + height) : min_y;
		if(r2d3_y - 20 == yy + height + 1) {
			max_y = min_y + 124;
		}

		if (!(prev_time))
			prev_time = time(NULL);
		if(time(NULL) - prev_time >= show_time) {
			this->visible = true;
		}

		//For Platform 7
		if(pid == 7)
			xx += 0.5 * speed;
	}
	// Sector 4
	else if(r2d3_y + 40 < yy && r2d3_x + 24 > xx && r2d3_x - 24 <= xx + length) {
		max_y = (max_y >= yy - 40) ? yy - 40 : min_y + 124;
	}
}
