#pragma once


#include "stdafx.h"

class Reseau_neurone;
class Pomme;

class Neurone
{
public:
	Neurone(Reseau_neurone* fReseau_neurone, int fEntree);
	Neurone(Reseau_neurone* fReseau_neurone, int fPremiere_entree, int fDerniere_entree);


	void trouver_poids(Pomme& fPomme, long double fSortie_voulue);

	long double getSortie(Pomme& fPomme);



private:
	Reseau_neurone* m_reseau_neurone;

	std::list<struct_lien> m_list_lien;
};

