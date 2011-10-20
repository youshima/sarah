#include "StdAfx.h"
#include "Browser.h"

RechercheInfo::RechercheInfo(STR mot)
{
	strcpy(this->mot, mot.getString());
	//Par defaut, le constructeur définira les regle de parsing et le site visé
}

RechercheInfo::~RechercheInfo()
{
}

HRESULT RechercheInfo::rechercheEtAjout()
{
	//Le parseur sera ici.

	//L'ajout du mot dans la Database se fera ici.

	return S_OK;
}

int RechercheInfo::strrch (char * string, char * recherche)
{
	int i,j;
	int max1 = (strlen(string) - strlen(recherche));//Calcule une fois pour toutes les longueurs de string et de recherche
	int max2 = strlen(recherche);//                   pour ne pas avoir à les recalculer à chaques tours de boucles

	for (i = 0 ; i <= max1 ; i ++)
	{
		for (j = 0 ; j < max2 ; j ++)
		{
			if (string[i + j] != recherche[j])
			{
				break;
			}
		}
		if (j == max2)
		{
			return i;
		}
	}
	return -1;
}

int RechercheInfo::taille_corps(char *reponse)
{
	int corps = 0;
	char * str;
	strcpy(str, strstr(reponse, "\r\n\r\n"));//Coupe le header de la réponse qui se termine forcement par "\r\n\r\n" (mais laisse la chaine "\r\n\r\n")

	while (str[corps + 4] != '\0')//On doit donc calculer la longueur du corps à partir de la fin de la chaine "\r\n\r\n" soit 4 caracteres plus loin
	{
		corps++;
	}
	return corps;
}

char * RechercheInfo::http_get(char * url_path, char * url_server)
{
	//Envoie la requête donnée en paramètre et retourne la réponse du serveur
	SOCKET s;
	char reponse[64000];
	char buffer[64000];
	char requete[64000] = "GET ";
	int n, corps;

	s = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);//Création de la socket
	if (s == INVALID_SOCKET)//Erreur d'initialisation de la socket
	{
		printf("La fonction socket a echoue.\n");//		* A CHANGER EN FONCTION DE L'INTERFACE !!!
		system("pause");//								* EXCEPTION ??
		return "0";//									*
	}
	else//La socket est correctement initialisée
	{
		SOCKADDR_IN server;
		struct hostent *remoteHost = gethostbyname(url_server);//Fait une requete DNS pour avoir l'adresse IP du serveur

		if (remoteHost->h_addr_list[0] == 0)//La requete DNS a echouée
		{
			printf("Erreur de connexion au DNS...\n");//		* A CHANGER EN FONCTION DE L'INTERFACE !!!
			system("pause");//								* EXCEPTION ??
			return "0";//									* MEME CHOSE...
		}
	            
		server.sin_family = AF_INET;
		server.sin_addr.s_addr = *(u_long *) remoteHost->h_addr_list[0];//IP du serveur
		server.sin_port = htons(80);//Port de communication 80
		memset(&server.sin_zero, '\0', sizeof(server.sin_zero));
	            
		if (connect(s, (SOCKADDR *)&server, sizeof(server)) == SOCKET_ERROR)//Connection au serveur
		{
			printf("Impossible de se connecter au serveur !\n");//		* A CHANGER EN FONCTION DE L'INTERFACE !!!
			system("pause");//								* EXCEPTION ??
			return "0";//									* MEME CHOSE...
		}
		else//On est connecté au serveur
		{
			strcat(requete, url_path);//Construction de la requete HTTP...
			strcat(requete, " HTTP/1.1\r\nHost: ");
			strcat(requete, url_server);
			strcat(requete, "\r\nUser-Agent: Mozilla/5.0 (Windows NT 6.0; rv:6.0.1) Gecko/20100101 Firefox/6.0.1\r\nAccept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8\r\nAccept-Language: fr,fr-fr;q=0.8,en-us;q=0.5,en;q=0.3\r\nAccept-Charset: ISO-8859-1,utf-8;q=0.7,*;q=0.7\r\nConnection: keep-alive\r\n\r\n");
			
			send(s, requete, (int)strlen(requete), 0);//Envoi de la requete HTTP
			n = recv(s, reponse, sizeof(reponse) - 1, 0);//Reception de la reponse HTTP
			reponse[n] = '\0';
			corps = this->taille_corps(reponse);//Calcul de la taille du corps de la reponse
			if (strrch(reponse, "Transfer-Encoding: chunked") != -1)//Reception de la suite de la reponse si elle est en encodage "chunked"
			{
				do
				{
					n = recv(s, buffer, sizeof(buffer) - 1, 0);//reception d'une partie de la reponse
					buffer[n] = '\0';
					strcat(reponse, buffer);//Concatenation de la partie de la reponse
					n = strrch(buffer, "0\r\n\r\n");
				}
				while ((n != 0) && (n != strlen(buffer) - 5));//On boucle tant qu'on a pas reçu entierement la reponse
			}
			else if (corps == 0)//Si la reponse ne contient que l'entête (le header) alors on attend le corps...
			{
				n = recv(s, buffer, sizeof(buffer) - 1, 0);///reception du corps de la reponse...
				buffer[n] = '\0';
				strcat(reponse, buffer);//Concatenation du corps de la reponse
			}
			closesocket(s);//Fermeture de la socket
			if (n != SOCKET_ERROR)
			{
				return reponse;
			}
			else
			{
				printf("Pas de connexion reseau.\n");//		* A CHANGER EN FONCTION DE L'INTERFACE !!!
				system("pause");//							* EXCEPTION ??
				return "0";//								* MEME CHOSE...
			}
		}
	}
	return "0";
}
