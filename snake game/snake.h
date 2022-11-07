#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include <string>
#include "food.h"

using namespace std;

#define WIDTH 50
#define HEIGHT 25



class Snake
{
private:
	pair<int, int> pos;
	int length;
	string direction;
	vector<pair<int, int>> body;
	pair<int, int> lastRemovedPair;

public:
	Snake();
	void move();
	bool checkIfCollided();
	bool checkFood(Food food);
	void grow();
	void changeDirection(const string &dir);
	pair<int,int> getPos();
	pair<int, int> getLastRemovedPair();
};


#endif //SNAKE_H

