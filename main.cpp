// AlgorithmieGeo.cpp : Définit le point d'entrée pour l'application console.
// Ismet

#include "stdafx.h"
#include "Point.h"
#include "Vecteur.h"
#include "VectorPoints.h"
#include "Polygon.h"
#include <iostream>
#include <algorithm>


using namespace std;

struct myclass2 {
	bool operator() (Point pt1, Point pt2) {

		if (pt1.x < pt2.x) {
			if (pt1.y < pt2.y)
			{
				return true;
			}
		}
		if (pt1.x < pt2.x) {
			return true;
		}
		if (pt1.x < pt2.x) {
			return true;
		}
		else {
			return false;
		}
	}
}myobject;

int main() {

	Point p1(2, 3);
	Point p2(3, 5);
	Point p3(8, 2);
	Point p4(1, 2);
	Point p5(4, 2);
	Point p6(0, 4);
	Point p7(1, 4);
	Point p8(7, 1);
	Point p9(1, 1);
	Vecteur v(p1, p2);

	cout << "afficher tout les points" << endl;
	VectorPoints vec2;
	vec2.ajouterPoint(p1);
	vec2.ajouterPoint(p2);
	vec2.ajouterPoint(p3);
	vec2.ajouterPoint(p4);
	vec2.ajouterPoint(p5);
	vec2.ajouterPoint(p6);
	vec2.ajouterPoint(p7);
	vec2.ajouterPoint(p8);
	vec2.ajouterPoint(p9);

	vec2.afficher();
	cout << endl;
	
	Polygon poly;
	poly.ajoutVecteur(vec2);
	poly.AlgoGraham();

	system("PAUSE");
	return 0;
}

