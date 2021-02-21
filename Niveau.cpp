#include "constantes.h"
#include "Niveau.h"
#include "Creature.h"
#include <string>

Niveau::Niveau(int* carte, std::string nomCreature, Point2D positionDepart) : m_carte{ carte }
{
	m_creature = new Creature{ nomCreature, positionDepart };
	m_carte[getIndexCarte(*m_creature->getPosition())] = -1;
}

Niveau::~Niveau()
{
	delete m_creature;
	m_creature = 0;
}

int* Niveau::getCarte() { return m_carte; }

std::string Niveau::getNomCreature() { return m_creature->getNom(); }

void Niveau::getDeplacementPossible(bool* tabDeplacements)
{
	bool tabDeplacement[4]{};
	Point2D gauche{ m_creature->getPosition()->getX() - 1, m_creature->getPosition()->getY() };
	Point2D droite{ m_creature->getPosition()->getX() + 1, m_creature->getPosition()->getY() };
	Point2D haut{ m_creature->getPosition()->getX(), m_creature->getPosition()->getY() - 1 };
	Point2D bas{ m_creature->getPosition()->getX(), m_creature->getPosition()->getY() + 1 };

	tabDeplacements[0] = m_carte[getIndexCarte(gauche)] == 0;
	tabDeplacements[1] = m_carte[getIndexCarte(droite)] == 0;
	tabDeplacements[2] = m_carte[getIndexCarte(haut)] == 0;
	tabDeplacements[3] = m_carte[getIndexCarte(bas)] == 0;
}

void Niveau::deplacerCreature(constantes::Direction direction)
{
	m_carte[getIndexCarte(*m_creature->getPosition())] = 0;

	if (direction == constantes::gauche) m_creature->deplacerCreature(m_creature->getPosition()->getX() - 1, m_creature->getPosition()->getY());
	
	if (direction == constantes::droite) m_creature->deplacerCreature(m_creature->getPosition()->getX() + 1, m_creature->getPosition()->getY());

	if (direction == constantes::haut) m_creature->deplacerCreature(m_creature->getPosition()->getX(), m_creature->getPosition()->getY() - 1);

	if (direction == constantes::bas) m_creature->deplacerCreature(m_creature->getPosition()->getX(), m_creature->getPosition()->getY() + 1);

	m_carte[getIndexCarte(*m_creature->getPosition())] = -1;
}

int Niveau::getIndexCarte(Point2D position)
{
	return position.getX() % constantes::dimension + position.getY() * constantes::dimension;
}