#pragma once
class Point
{
public:
	Point(int x = 0, int y = 0, int color = 0) {
		this->x = x;
		this->y = y;
		this->color = color;
	}
	int get_x() { return x; }
	int get_y() { return y; }
	int get_color() { return color; }


	void set_x(int x) {
		this->x = x;
	}
	void set_y(int y) {
		this->y = y;
	}
	void set_color(int color) {
		this->color = color;
	}

private:
	int x;
	int y;
	int color;
};
