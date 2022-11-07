#include "food.h"


Food::Food() {}

void Food::foodPos() {
	pos.first = rand()%WIDTH;
	pos.second = rand()% HEIGHT;
}

pair<int,int> Food::getPos() {
	return pos;
}
