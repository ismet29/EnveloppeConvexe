#include "stdafx.h"
#include "Polygon.h"
#include <algorithm>
#include <iostream>

using namespace std;
struct myclass4 {
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
Polygon::Polygon()
{
}

void Polygon::ajoutVecteur(VectorPoints v) {
	this->vecteur.vecteur=v.vecteur;
}
void Polygon::ajouterPoint(Point p) {
	this->vecteur.vecteur.push_back(p);
}
void Polygon::afficherPoly() {
	
		this->vecteur.afficher();
	
}
void Polygon::afficherConvex() {
	
		this->vecteurPointConvex.afficher();
}

void Polygon::AlgoGraham() {
	Point point;
	//trie de tout les point du plus petit au plus grand
	this->vecteur.sortVecteurPoint();
	this->afficherPoly();
	point = this->vecteur.vecteur.at(0);
	std::cout << endl;
	std::cout << "Point initial selectione : ";
	point.afficher();
	std::cout << endl;

	vector<Vecteur> coordPolair;
	// les cordonnée polaire de coordPolair contient les association entre le point initial et les autre points
	// (P1,P2);(P1,P3)...(P1,PN)
	for (int i = 1; i < this->vecteur.vecteur.size(); i++) {
		Vecteur vec(point, this->vecteur.vecteur.at(i));
		coordPolair.push_back(vec);
	}
	// trié les cordonnée polaire par couple du plus proche au plus eloigné
	std::cout << "mes coordonee polaire trier : "<<endl;
	sort(coordPolair.begin(), coordPolair.end());

	// afficher chaque couple trié
	for (int i = 0; i < coordPolair.size(); i++) {
		coordPolair.at(i).afficher();
	}
	// ajouter tout les point a mon vecteur de point de mon polygone puisquils ont trié (P1,P2,...PN)
	vecteur.vecteur.at(0).setX(coordPolair.at(0).premierPoint().getX());
	vecteur.vecteur.at(0).setY(coordPolair.at(0).premierPoint().getY());
	for (int i = 0; i < coordPolair.size(); i++) {
		vecteur.vecteur.at(i+1).setX(coordPolair.at(i).secondPoint().getX());
		vecteur.vecteur.at(i+1).setY(coordPolair.at(i).secondPoint().getY());
	}
	// construction de mon polygone (vecteur de point)
	std::cout << "---------------polygone------------" << endl;
	// afficher mon polygone de l'ensemble de point
	vecteur.afficher();
	std::cout << endl;
	// lancement de Graham Algo
	std::cout << "Let's Go Graham Solution " << endl;

	int j = 0;
	int k = 0;
	// calculer la puissance pour prendre seulement les point qui sont a droite le resultat est dans vecteurPointConvex
	while(j != vecteur.vecteur.size()) {
		std::cout << endl;
		std::cout << "je suis a la position: "<< j << endl;
		std::cout << "nombre de point: " << vecteur.vecteur.size() << endl;
		// si j==0 on prend seulement les deux premiers point et on les ajoutes
		if (j == 0) 
		{
			cout << "premiere iteration je prend les deux premier pois je les ajoutes" << endl;
			Point p = vecteur.vecteur.at(j);
			vecteurPointConvex.vecteur.push_back(p);
			Point p1 = vecteur.vecteur.at(j+1);
			vecteurPointConvex.vecteur.push_back(p1);
			cout << "les point ajouter" << endl;
			p.afficher();
			p1.afficher();
			j += 1;
		}
		else {
			// si on n'est pas au niveau des deux derniers points
			if (j + 2 < vecteur.vecteur.size()) {
				// construire le vecteur entre PN et PN+2
				Vecteur vec(vecteur.vecteur.at(j), vecteur.vecteur.at(j + 2));
				// if PN+1 est a droite
				if (vec.puissance(vecteur.vecteur.at(j + 1)) > 0)
				{
					cout << "le point a la position " << j+1 << " est a droite donc on le prend" <<endl;
					Point p = vecteur.vecteur.at(j + 1);
					vecteurPointConvex.vecteur.push_back(p);
					cout << "le point ajouter" << endl;
					p.afficher();
					j += 1;
				}
				else {
					cout << "point pos: " << j+1 << " est a gauche donc on ne le prend pas, on prend le point a la position "  << j+2 << endl;
					Point p = vecteur.vecteur.at(j + 2);
					vecteurPointConvex.vecteur.push_back(p);
					cout << "Le point ajouter" << endl;
					p.afficher();
					j += 2;
					//k += 2;
				}

			}
			else 
				if (j + 1 == vecteur.vecteur.size()) 
				{
					break;
				} 
			else
				{
					cout << "dernier element on ajoute le dernier element" << endl;
					Point p = vecteur.vecteur.at(j+1);
					vecteurPointConvex.vecteur.push_back(p);
					p.afficher();
					break;
				}
		}
	}
	std::cout << endl;
	std::cout << "les point du polygonne" << endl;
	this->afficherPoly();
	std::cout << endl;
	std::cout << "les point de l'enveloppe convexe" << endl;
	this->afficherConvex();
	std::cout << endl;
}
Polygon::~Polygon()
{
}
