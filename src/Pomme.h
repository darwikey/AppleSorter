#pragma once

#include "stdafx.h"


class Pomme
{
public:
	Pomme();


	void creation_image();

	void trouver_couleur();


	// Variable publique
	int m_tachete;

	sf::Image m_image;
	sf::Texture m_texture;


	int m_couleur [1000];
};

