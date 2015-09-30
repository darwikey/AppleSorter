#include "StdAfx.h"
#include "Affichage.h"
#include "Pomme.h"


Affichage::Affichage()
{
	// création fenêtre
	m_ecran.create(VideoMode(400, 400, 32), "Enemy Editor", Style::Close);

	//chargement images
	m_image_base[0].loadFromFile("image/fond1.png");
	m_image_base[1].loadFromFile("image/fond2.png");
	m_image_base[2].loadFromFile("image/fond3.png");
	m_image_base[3].loadFromFile("image/fond4.png");
	m_image_base[4].loadFromFile("image/fond5.png");

	m_image_base[5].loadFromFile("image/tache1.png");
	m_image_base[6].loadFromFile("image/tache2.png");
	m_image_base[7].loadFromFile("image/tache3.png");
	m_image_base[8].loadFromFile("image/tache4.png");
	m_image_base[9].loadFromFile("image/tache5.png");
	m_image_base[10].loadFromFile("image/tache6.png");
	m_image_base[11].loadFromFile("image/tache7.png");
	m_image_base[12].loadFromFile("image/tache8.png");
	m_image_base[13].loadFromFile("image/tache9.png");
	m_image_base[14].loadFromFile("image/tache10.png");
}


// Affiche la texture de la pomme sur l'ecran
void Affichage::affichage_pomme(Pomme& fPomme)
{
	Sprite _sprite;
	_sprite.setTexture(fPomme.m_texture);
	_sprite.setPosition(0.L, 0.L);

	m_ecran.draw(_sprite);
}