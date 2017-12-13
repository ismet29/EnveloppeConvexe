#include "stdafx.h"
#include "Vecteur.h"
#include<iostream>
#include "math.h"

using namespace std;
Vecteur::Vecteur()
{
}
Vecteur::Vecteur(Point p1, Point p2) {
	this->vecteurPoint[0]=p1;
	this->vecteurPoint[1]=p2;
	
}

void Vecteur::afficher() {
	vecteurPoint[0].afficher();
	vecteurPoint[1].afficher();
}

Point Vecteur::produitSclaire() {
	Point p;
	p.setX((this->vecteurPoint[1].getX()) - (this->vecteurPoint[0].getX()));
	p.setY((this->vecteurPoint[1].getY()) - (this->vecteurPoint[0].getY()));
	return p;
}

float Vecteur::produitScalaire2(Vecteur v) {
	Point p = v.produitSclaire();
	Point p2 = this->produitSclaire();
	float f = (p.getX()*(p2.getX())) + ((p.getY())*(p2.getY()));
	return f;
}
          
float Vecteur::determinant() {
	Point p = this->produitSclaire();
	return sqrt(pow(p.getX(), 2) - pow(p.getY(), 2));
}
float Vecteur::puissance(Point p) {
	Point p1 = this->produitSclaire();
	//dy(x_p - x_a) - dx(y_p - y_a)
	return p1.getY()*(p.getX() - this->vecteurPoint[0].getX()) - p1.getX()*(p.getY() - this->vecteurPoint[0].getY());

}
float Vecteur::angle() {
	return atan2(vecteurPoint[1].getY() - vecteurPoint[0].getY(), vecteurPoint[1].getX() - vecteurPoint[0].getX());
}

bool Vecteur::operator<(Vecteur v) {
	if (this->angle() < v.angle()) {
		return true;
	}
	else {
		if (this->angle() == v.angle()) {
			if (this->determinant() < v.determinant()) {
				return true;
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}
	}
}

Vecteur Vecteur::operator=(Vecteur v) {
	
	this->vecteurPoint[0] = v.vecteurPoint[0];
	this->vecteurPoint[1] = v.vecteurPoint[1];
	return *this;
}

Point Vecteur::premierPoint() {
	return this->vecteurPoint[0];
}

Point Vecteur::secondPoint() {
	return this->vecteurPoint[1];
}
Vecteur::~Vecteur()
{

}
