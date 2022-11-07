#include "snake.h"

Snake::Snake() {
	pos.first = WIDTH / 2; //25
	pos.second = HEIGHT / 2; //12;
	length = 1;
	direction = "none";
	lastRemovedPair = { -1,-1 };
}

void Snake::move() {
	if (direction == "none")return;
	body.push_back(pos);
	if (direction == "up")pos.second--;
	else if (direction == "right")pos.first++;
	else if (direction == "down")pos.second++;
	else if (direction == "left")pos.first--;

	if (body.size() > length) {
		lastRemovedPair = body.front();
		body.erase(body.begin());
	}
	else {
		lastRemovedPair = { -1,-1 };
	}
}

bool Snake::checkIfCollided() {
	if (pos.first > WIDTH - 1 || pos.first<0 || pos.second>HEIGHT - 1 || pos.second < 0)return true;
	for (int i = 0; i < length-1; i++) {
		if (pos.first == body[i].first && pos.second == body[i].second)return true;
	}
	return false;
}

bool Snake::checkFood(Food food) {
	pair<int, int> foodPos = food.getPos();
	if (foodPos.first == pos.first && foodPos.second == pos.second)return true;
	return false;
}

void Snake::grow() {
	length++;
}

void Snake::changeDirection(const string& dir) {
	if (direction == "up" && dir == "down")return;
	if (direction == "down" && dir == "up")return;
	if (direction == "left" && dir == "right")return;
	if (direction == "right" && dir == "left")return;
	direction = dir;
}

pair<int,int> Snake::getPos() {
	return pos;
}


pair<int, int> Snake::getLastRemovedPair() {
	return lastRemovedPair;
}