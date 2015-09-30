#pragma once

#include "stdafx.h"
#include "singleton.h"


class Pomme;

class Affichage : public Singleton<Affichage>
{
public:
	Affichage();
	~Affichage();

	void affichage_pomme(Pomme& fPomme);


	sf::Image m_image_base[30];


// Variable publique
	RenderWindow m_ecran;
};

