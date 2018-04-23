#include "level1.h"
#include "../draw/draw.h"
#include "../platform/platform.h"
#include "../spike/spike.h"
#include "../../states.h"

const int nSpike = 100;
const int nPlatform = 1;
static Platform platform[nPlatform];
static Spike spike[nSpike];

unordered_map <int, vector <int>> spike_pos;

void setLevel() {
	for(int i = 0; i < nSpike; i++) {
		int sx = i * 200 + 30;
		spike[i] = Spike(sx, 200, -1.0, i);
		spike_pos[sx / 1000].push_back(i);
	}
	for(int i = 0; i < nPlatform; i++) {
		platform[i] = Platform(0.0, 0.0, 0.0, 10000.0, 200.0);	// Main Platform
	}
}

void drawLevel() {
	//Platform platform = Platform(0.0, 0.0, 0.0, 10000.0, 200.0);
	glColor3f(0.545, 0.271, 0.075);     //SaddleBrown
	// draw.drawBox(0.0, 0.0, 0.0, 10000.0, 200.0);
	for(int i = 0; i < nPlatform; i++) {
		platform[i].drawPlatform();
	}
	glColor3f(0.663, 0.663, 0.663);     //DarkGray
	for(int i = 0; i < nSpike; i++) {
		spike[i].drawSpike();
	}
	// cout<<"Drawing the level"<<endl;
}

void level1CollisionDetection() {
	// Collision detection for all the assets (platform and spike) is called here
	// This function is called by the glutIdleFunc()
	// Because it is called by glutIdleFunc there might be some delay in actual collision and its detection

	// for(int i = 0; i < nSpike; i++) {
	// 	spike[i].spikeCollision();
	// }
	// cout << "Level 1 " << r2d3_x << ", " << r2d3_y << "\n";
	// spike[0].spikeCollision();

	int r2d3_pos = r2d3_x / 1000;
	cout << r2d3_x << "\t" << r2d3_pos << "\t";
	for(auto vit : spike_pos[r2d3_pos]) {
		cout << vit << " ";
		spike[vit].spikeCollision();
	}
	cout << "\n";
	for(int i = 0; i < nPlatform; i++) {
		platform[i].platformCollision();
	}
}
