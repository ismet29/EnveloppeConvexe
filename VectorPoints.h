#pragma once
#include"VectorPoints.h"
#include"Point.h"
#include"Vecteur.h"
#include<iostream>
#include<vector>

using namespace std;
class VectorPoints
{
public:
	VectorPoints();
	void ajouterPoint(Point p);
	void supprimerPoint(Point p);
	void sortVecteurPoint();
	VectorPoints operator = (VectorPoints vec);
	Point premierPoint();
	void afficher();
	void supprimer(int x);
	int  posPoint(Point p);
	bool operator() (Point p1,Point p2);
	~VectorPoints();

	vector<Point> vecteur;
	vector<Point>::iterator it;
};

