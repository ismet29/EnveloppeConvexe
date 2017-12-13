#include "stdafx.h"
#include "Point.h"
#include<iostream>
#include<math.h>

using namespace std;
Point::Point()
{
	this->setX(0);
	this->setY(0);
}
Point::Point(int a, int b) {
	this->x = a;
	this->y = b;
}

Point::~Point()
{
}

void Point::afficher() {
	cout << "X: " << this->x << " Y: " << this->y;
	cout << endl;
}

int Point::getX() {
	return this->x;
}

int Point::getY() {
	return this->y;
}

void Point::setX(int a) {
	this->x=a;
}

void Point::setY(int b) {
	this->y=b;
}

float Point::distance(Point p) {
	return sqrt(pow(p.getX() - x,2) + pow(p.getY() - y,2));
}
bool Point::operator<(Point p) {
	if (this->getX() < p.getX()) {
		if (this->getY() < p.getY()) {
			return true;
		}else {
			return true;
		}
	}
	else {
		if (this->getY() < p.getY()) {
			return true;
		}
		else {
			return false;
		}
	}
}

bool Point::operator>(Point p) {
	if (this->getX() > p.getX()) {
		if (this->getY() > p.getY()) {
			return true;
		}
		else {
			return true;
		}
	}
	else {
		if (this->getY() > p.getY()) {
			return true;
		}
		else {
			return false;
		}
	}
}

Point Point::operator=(Point p) {
	this->setX(p.getX());
	this->setY(p.getY());
	return *this;
}
