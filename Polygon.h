#pragma once
#include"VectorPoints.h"
#include"Point.h"
#include"VectorPoints.h"
#include<iostream>
#include<vector>

using namespace std;
class Polygon
{
protected:
	VectorPoints vecteur;
	VectorPoints vecteurPointConvex;
public:
	Polygon();
	void ajoutVecteur(VectorPoints v);
	void ajouterPoint(Point p);
	void afficherPoly();
	void afficherConvex();
	void AlgoGraham();
	~Polygon();
};

