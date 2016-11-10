#pragma once
#include "Client.h"
#include <deque>
#include "Constantes.h"
#include <iostream>

class Caisse
{
	// Attributs
	deque<Client*> file;
	bool status;
	int tempsFile;

public:
	// Constructeur
	Caisse();
	
	// Accesseurs
	bool GetStatus() const { return status; }
	int GetTempsFile() const { return tempsFile; }

	// Methodes
	int ConvertirMinute(string Min);
	void OuvrirCaisse() { status = OUVERT;
	cout << "Ouvrir" << endl;
	}
	void FermerCaisse() { status = FERM�; 
	cout << "Fermeture" << endl;
	}
	void AjouterTempsFile(int t) { tempsFile += t; }
	void AjouterClientFile(string typeClient);
};