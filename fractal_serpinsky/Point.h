#pragma once
class Point
{
public:
	Point(int x = 0, int y = 0) {
		this->x = x;
		this->y = y;
	}
	int get_x() { return x; }
	int get_y() { return y; }

	void set_x(int x) { 
		this->x = x; 
	}
	void set_y(int y) { 
		this->y = y; 
	}

private:
	int x;
	int y;
};
