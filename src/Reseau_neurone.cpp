#include "stdafx.h"
#include "Neurone.h"
#include "Reseau_neurone.h"
#include "time.h"
#include "Affichage.h"
#include "Pomme.h"



int _tmain()
{
	//Initialisation 
	printf("INIT \n");
	srand((int)time(NULL));


	//Pommes
	list<Pomme*> _list_pomme;
	Pomme* _pomme = new Pomme();
	_pomme->creation_image();
	_list_pomme.push_back(_pomme);

	//Reseau
	Reseau_neurone* _reseau = new Reseau_neurone(1000);



	bool _fin = 0;
	bool _bouton = 0;

	while (_fin==0)
	{
		// Gestion de la fenêtre
		Affichage::getInstance()->m_ecran.clear();

		Event event;
		while (Affichage::getInstance()->m_ecran.pollEvent(event))
		{
			switch (event.type)
			{
			// si la fenêtre est fermée
			case Event::Closed:
				_fin = true;
				break;

			case Event::Resized:

				break;

			default:
				break;

			}
		}


		// Clic souris
		if ((Mouse::isButtonPressed(Mouse::Left) && _bouton == 0) || Mouse::isButtonPressed(Mouse::Right))
		{
			Pomme* _pomme = new Pomme();
	
			_pomme->creation_image();
	
			_list_pomme.push_back(_pomme);


			// envoyer dans le reseau
			_reseau->trouver_poids(*_pomme);
		}

		_bouton = Mouse::isButtonPressed(Mouse::Left);



		Affichage::getInstance()->affichage_pomme(*_list_pomme.back());


		Affichage::getInstance()->m_ecran.display();
	}



	return 0;
}


// Constructeur réseau de neurones
Reseau_neurone::Reseau_neurone(int fNb_entree) : m_nb_entree(fNb_entree)
{
	m_nb_sortie = 3;

	//entrée
	for (int i=0; i<=m_nb_entree-1; i++)
	{
		Neurone* _neurone = new Neurone(this, -i-1);
		m_tab_neurone.push_back(_neurone);
	}

	// sortie
	for (int i=m_nb_entree; i <= m_nb_entree +m_nb_sortie -1; i++)
	{
		Neurone* _neurone = new Neurone(this, 0, m_nb_entree-1);
		m_tab_neurone.push_back(_neurone);
	}

	//fichier
	m_fichier.open("resultat.txt");
	m_fichier.clear();
}


// Renvoie l'entrée
long double Reseau_neurone::getEntree(int fEntree, Pomme& fPomme)
{
	if (fEntree<1000)
		return (long double)fPomme.m_couleur[fEntree];
	else
		return 0.L;
}


// Calcul les poids des neurones 
void Reseau_neurone::trouver_poids(Pomme& fpomme)
{
	
	Neurone* _neurone = m_tab_neurone[m_nb_entree];

	long double _sortie = _neurone->getSortie(fpomme);
	printf("%4.4f    ", _sortie);


	static int _cycle = 0;
	static int _resultat = 0;

	if (fpomme.m_tachete > 0) // tacheté
	{
		if (_sortie > 0.5L)
			_resultat ++; // bonne sortie

	}
	else // pas tacheté
	{
		if (_sortie < 0.5L)
			_resultat ++; // bonne sortie

	}
	

	// on met les resultats dans un fichier texte
	_cycle ++;
	if (_cycle >= 20)
	{
		_cycle = 0;

		m_fichier<<_resultat<<endl;

		_resultat = 0;
	}


	_neurone->trouver_poids(fpomme, (long double)fpomme.m_tachete / 4.L);

	
}


