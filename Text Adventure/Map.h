#pragma once
#include "Strings.h"
#include <iostream>
const int mapMaxY = 5;
const int mapMaxX = 5;
int random(int min, int max) {
	return rand() % max + min;
}
class Map
{
protected:
	int m_x, m_y;
public:
	Map();
	~Map();
	void move(int x, int y) {
		if (x >=0 && x < mapMaxX && y >= 0 && y < mapMaxY)
		{
			if (random(1, 100) <= 10) {
				//battle
			}
			else {
				m_x = x; m_y = y;
			}
			
		}
	}
	void printEvent(int event) {

	}
};

