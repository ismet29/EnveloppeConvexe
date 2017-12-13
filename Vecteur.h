#pragma once
#include"Point.h"
#include<iostream>

using namespace std;
class Vecteur
{
protected:
	Point vecteurPoint[2];
	

public:
	Vecteur();
	Vecteur(Point p1, Point p2);
	void afficher();
	Point premierPoint();
	Point secondPoint();
	Point produitSclaire();
	float produitScalaire2(Vecteur v);
	float determinant();
	float puissance(Point p);
	bool operator < (Vecteur v);
	Vecteur operator = (Vecteur v);
	float angle();

	~Vecteur();
};

