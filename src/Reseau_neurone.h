#pragma once


#include "stdafx.h"
#include <fstream>

class Pomme;

class Reseau_neurone
{
public:
	Reseau_neurone(int fNb_entree);


	long double getEntree(int fInput, Pomme& fPomme);
	void trouver_poids(Pomme& fpomme);


	vector<Neurone*> m_tab_neurone;

private:
	int m_nb_entree;
	int m_nb_sortie;


 // fichier texte de sortie
	ofstream m_fichier;
};