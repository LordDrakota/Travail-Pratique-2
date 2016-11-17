// Main.cpp
// Jonathan Bouchard & Pierre-Anthony Houle
// 04 novembre 2016
// Cr�er une file de clients

#include "Constantes.h"
#include "Quincaillerie.h"
#include "ClientParticulier.h"
#include "ClientPrivil�gi�.h"
#include "ClientCommercial.h"
#include "SourceLecture.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>


void DemanderFichier(bool i, SourceLecture& flecture, ofstream& fecriture);
void LireFichier(bool i, SourceLecture& fichier, Quincaillerie& magasin, vector<Client*>& vecClient);
void CreerClient(vector<string> vectorElems, vector<Client*>& vecClient);
<<<<<<< HEAD
void ExecuterOperations(vector<string> vectorElems, Quincaillerie& magasin, vector<Client*> vecClient);
=======
void ExecuterOp�rations(vector<string> vectorElems, Quincaillerie& magasin, vector<Client*> vecClient);
void �crireRapport(Quincaillerie& magasin, ofstream& flux);
>>>>>>> refs/remotes/origin/JO



/**Je vais peut etre bouger ste fonction la dans Quincaillerie**/
void �crireRapport(Quincaillerie& magasin, ofstream& flux)
{
	int index;
	for (int i = 0; i < magasin.GetVectorCaisse().size(); i++)
	{
		flux << "******************** Caisse " << i + 1 << " ********************" << endl;
		magasin.GetCaisse(i).AfficherCaisse(flux);
		flux << "**************************************************" << endl;
	}
	flux << "@@@@@@@@@@@@@@@@@@@@@@STATS@@@@@@@@@@@@@@@@@@@@@@@" << endl;
	index = distance(magasin.GetVectorCaisse().begin(), magasin.GetCaissePlusClients()) + 1;
	flux << "Caisse qui a eu le plus grand nombre de clients: Caisse " << index << endl;
	index = distance(magasin.GetVectorCaisse().begin(), magasin.GetCaissePlusAttente()) + 1;
	flux << "Caisse o� il y a eu le plus d�attente: Caisse " << index << endl;
	index = distance(magasin.GetVectorCaisse().begin(), magasin.GetCaissePlusArgent()) + 1;
	flux << "Caisse qui � encaiss� le plus d�argent: Caisse " << index << endl;
	flux << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
}


void CreerClient(vector<string> vectorElems, vector<Client*>& vecClient)
{
	if (vectorElems.at(1) == TYPEPARTICULIER) vecClient.push_back(new ClientParticulier(stoi(vectorElems.at(0)), vectorElems.at(1), vectorElems.at(2)));
	else if (vectorElems.at(1) == TYPEPRIVILEGIE) vecClient.push_back(new ClientPrivil�gi�(stoi(vectorElems.at(0)), vectorElems.at(1), vectorElems.at(2), vectorElems.at(3)));
	else if (vectorElems.at(1) == TYPECOMMERCIAL) vecClient.push_back(new ClientCommercial(stoi(vectorElems.at(0)), vectorElems.at(1), vectorElems.at(2), vectorElems.at(3), vectorElems.at(4), vectorElems.at(5), stoi(vectorElems.at(6))));
}

void ExecuterOperations(vector<string> vectorElems, Quincaillerie& magasin, vector<Client*> vecClient)
{
<<<<<<< HEAD
	Caisse* plusRapide;
	if (vectorElems.at(0) == OUVRIRCAISSE)
		if (magasin.GetCaisse(stoi(vectorElems.at(1)) - 1).GetStatus() == FERM�)
			magasin.SetCaisse((stoi(vectorElems.at(1)) - 1)).OuvrirCaisse();
		else
			throw exception("La caisse �tait d�j� ouverte!");
	else if (vectorElems.at(0) == AJOUTERCLIENT)
	{
		//// Ajoute le temps d'attente dans le client
		vecClient.at(stoi(vectorElems.at(1)) - 1)->SetTempsClient(magasin.ConvertirMinuteEnSeconde(vectorElems.at(2)));
		//// Modifie la caisse (ajoute un client / ajoute le temps d'attente / **faire quelque chose avec le montant**)
		if (vecClient.at(stoi(vectorElems.at(1)) - 1)->GetTypeClient() == TYPECOMMERCIAL)
			plusRapide = magasin.GetCaissePlusRapide(true);
		else
			plusRapide = magasin.GetCaissePlusRapide(false);
		plusRapide->AjouterClientFile(vecClient.at(stoi(vectorElems.at(1)) - 1), stof(vectorElems.at(3)));
=======
	Caisse* PlusRapide;
	if (vectorElems.at(0) == OUVRIRCAISSE)
	{
		Magasin.SetCaisse((stoi(vectorElems.at(1)) - 1)).OuvrirCaisse();
		Magasin.SetCaisse((stoi(vectorElems.at(1)) - 1)).Set�t�Ouvert(true);
	}
	else if (vectorElems.at(0) == AJOUTERCLIENT)
	{
		//// Ajoute le temps d'attente dans le client
		vecClient.at(stoi(vectorElems.at(1)) - 1)->SetTempsClient(Magasin.ConvertirMinuteEnSeconde(vectorElems.at(2)));

		//// Modifie la caisse (ajoute un client / ajoute le temps d'attente / **faire quelque chose avec le montant**)
		if (vecClient.at(stoi(vectorElems.at(1)) - 1)->GetTypeClient() == TYPECOMMERCIAL) PlusRapide = Magasin.GetCaissePlusRapide(true);
		else PlusRapide = Magasin.GetCaissePlusRapide(false);

		PlusRapide->AjouterClientFile(vecClient.at(stoi(vectorElems.at(1)) - 1), stof(vectorElems.at(3)));
>>>>>>> refs/remotes/origin/JO
	}
	else if (vectorElems.at(0) == QUITTERCAISSE)
	{
		magasin.GetCaisse(stoi(vectorElems.at(1)) - 1).RetirerClientFile();
	}
	else if (vectorElems.at(0) == FERMERCAISSE) magasin.SetCaisse((stoi(vectorElems.at(1)) - 1)).FermerCaisse();
	else cout << "Type d'op�ration inconnu..." << endl;
}

void DemanderFichier(bool i, SourceLecture& fichier, ofstream& fecriture)
{
	string nomFichier; // Variable qui retient le nom du fichier
	do
	{
		cout << "------------------------------------" << endl;
		if (i == CLIENT) cout << "Entrez un nom de fichier de clients: " << endl;
		else if (i == OP�RATIONS) cout << "Entrez un nom de fichier d'op�rations: " << endl;
		cout << "------------------------------------" << endl;
		cin >> nomFichier;
		fichier.SetNomSourceLecture(nomFichier);
	} while (!fichier.EstCapableDeLire());
	if (i == OP�RATIONS) fecriture.open("Journal_" + nomFichier);
}

void LireFichier(bool i, SourceLecture& fichier, Quincaillerie& magasin, vector<Client*>& vecClient)
{
	do
	{
		try
		{
			vector<string> vecElems;
			fichier.Lire(vecElems);
			if (i == CLIENT) CreerClient(vecElems, vecClient);
			else if (i == OP�RATIONS) ExecuterOperations(vecElems, magasin, vecClient);
		}
		catch (exception e) { cout << e.what() << endl; }

	} while (fichier.PeutEncoreLire());
}

int main()
{
	locale::global(locale("")); // Permet les charact�res fran�ais
	vector<Client*> vecClients;
	SourceLecture fichierClients;
	SourceLecture fichierOp�rations;
	Quincaillerie magasin(NBCAISSES);
	ofstream fichierEcriture;

	DemanderFichier(CLIENT, fichierClients, fichierEcriture);
	LireFichier(CLIENT, fichierClients, magasin, vecClients);

	DemanderFichier(OP�RATIONS, fichierOp�rations, fichierEcriture);
	LireFichier(OP�RATIONS, fichierOp�rations, magasin, vecClients);

	�crireRapport(magasin, FichierEcriture);
}