#include "StdAfx.h"
#include "Pomme.h"
#include "Affichage.h"


Pomme::Pomme()
{
	m_tachete = random(0,5);


	// initialisation tableau
	for (int i= 0; i<1000; i++)
	{
		m_couleur[i] = 0;
	}
}


// génère des images aléatoires
void Pomme::creation_image()
{
	int _pomme = random(0, 4);

	m_image.create(Affichage::getInstance()->m_image_base[_pomme].getSize().x, Affichage::getInstance()->m_image_base[_pomme].getSize().y, Color::White);
	m_image.copy(Affichage::getInstance()->m_image_base[_pomme], 0, 0, sf::IntRect(0, 0, 0, 0), true);

	for (int i=0; i<m_tachete; i++)
	{
		int _image = random(9, 14);

		long double _angle = random(1.0L, 6.28L);
		long double _distance = random(0.0, (long double)m_image.getSize().x / 2.0 -15.0);
		long double _position_x = _distance * cos(_angle);
		long double _position_y = _distance * sin(_angle);

		m_image.copy(Affichage::getInstance()->m_image_base[_image], _position_x + (long double)m_image.getSize().x / 2.L, _position_y + (long double)m_image.getSize().y / 2.L, sf::IntRect(0, 0, 0, 0), true);
	}

	trouver_couleur();

	m_texture.loadFromImage(m_image);

}


// indexe les couleurs dans un tableau
void Pomme::trouver_couleur()
{
	for (int x=0; x<m_image.getSize().x; x++)
	{
		for (int y=0; y<m_image.getSize().y; y++)
		{
			int _rouge = (int) (((long double)m_image.getPixel(x, y).r) / 25.6f);
			int _vert = (int) (((long double)m_image.getPixel(x, y).g) / 25.6f);
			int _bleu = (int) (((long double)m_image.getPixel(x, y).b) / 25.6f);

			// on évite le fond blanc
			if (_rouge!=0 && _vert!=0 && _bleu!=0)
			{
				m_couleur[_rouge+10*_vert+100*_bleu]++;
			}

		}
	}

}
