#include "stdafx.h"
#include "VectorPoints.h"
#include "Point.h"
#include "Vecteur.h"
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct myclass3 {
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
VectorPoints::VectorPoints()
{	

}
void VectorPoints::ajouterPoint(Point p) {
	
	this->vecteur.push_back(p);
	
}


Point VectorPoints::premierPoint() {
	return this->vecteur.at(0);
}

void VectorPoints::sortVecteurPoint() 
	{
	sort(this->vecteur.begin(),this->vecteur.end(),myobject);
	}

void VectorPoints::supprimer(int x) {

	this->vecteur.erase(this->vecteur.begin() + x);
	cout << "supprimer " << endl;
}

int VectorPoints::posPoint(Point x)
{
	int idx = 0;
	int a = x.getX();
	int b = x.getY();
	for (it = this->vecteur.begin(); it != vecteur.end(); it++) {
		if ((it->getX() == a) && (it->getY() == b)) {
			return idx;
		}
		idx++;
	}
	return idx;
}

VectorPoints VectorPoints::operator=(VectorPoints vec) {
	int i = 0;
		for (it = vec.vecteur.begin(); this->it != vec.vecteur.end(); it++) {
			this->vecteur.at(i) = *it;
			i += 1;
		}
		vec.vecteur.erase(vec.vecteur.begin(), vec.vecteur.end());
		return *this;
	}

void VectorPoints::afficher() {
	Point p;
	for (it = vecteur.begin(); it < vecteur.end(); it++) {
		p = *it;
		p.afficher();
	}
	
}


VectorPoints::~VectorPoints()
{
}

