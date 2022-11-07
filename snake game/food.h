
#ifndef FOOD_H
#define FOOD_H

#include <vector>

using namespace std;

#define WIDTH 50
#define HEIGHT 25


class Food
{
private:
	pair<int, int> pos;
public:
	Food();
	void foodPos();
	pair<int,int> getPos();
	
};

#endif