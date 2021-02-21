#ifndef NIVEAU_H
#define NIVEAU_H

#include "Point2D.h"
#include "Creature.h"
#include "constantes.h"
#include <string>

class Niveau
{
private:
	// Un tableau d'entiers � 1 dimension repr�sentant une carte carr�e
	// Les murs (infranchissables) sont des 1
	// Le cases libres pour le d�placement sont des 0
	// La position de la cr�ature est un -1
	int* m_carte; 
	// Un pointeur vers la cr�ature
	Creature* m_creature;
	// Une fonction interne pour avoir l'index du tableau correspondant au point2d
	int getIndexCarte(Point2D position); 
public:
	// Constructeur, re�oit un tableau pour repr�senter l'ar�ne de jeu, le nom de la cr�ature et sa position initiale
	Niveau(int* carte, std::string nomCreature, Point2D positionDepart);
	// Destructeur selon l'utilisation d'allocation dynamique de m�moire
	~Niveau();
	// Retourne la carte de jeu pour l'affichage
	int* getCarte();
	// Retourne le nom de la cr�ature pour l'affichage
	std::string getNomCreature();
	// Re�oit un tableau de 4 bool
	// Modifie le tableau pour savoir dans quelles directions on peut se d�placer
	void getDeplacementPossible(bool* tabDeplacements);
	// Change la position de la cr�ature selon la direction choisie
	void deplacerCreature(constantes::Direction direction);
};

#endif

