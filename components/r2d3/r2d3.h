#include <GL/glut.h>
#include <iostream>

using namespace std;

class R2D3 {
    private:
    float radius;
    float cap_radius;
    float arm_l;
	int lastKey;
    float rangle;

    public:
    R2D3();
    void draw(float x, float y, float z);
	void setKey(int key);
};
