#pragma once

#include<iostream>
#include<math.h>
using namespace std;

class Point
{
public:
	Point();
	Point(int x, int y);
	void afficher();
	int getX();
	void setX(int x);
	int getY();
	void setY(int y);
	float distance(Point p);
	bool operator < (Point p);
	bool operator > (Point p);
	bool operator == (Point p);
	Point operator = (Point p);

	~Point();



	int x;
	int y;



};

