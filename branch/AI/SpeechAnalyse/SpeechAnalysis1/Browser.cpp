#include "StdAfx.h"
#include "Browser.h"

using namespace AI;
using namespace AI::BROWSER;

Browser::Browser(void)
:
db()
{
	Source * src = new DictionaryReference();
	this->SourceList.insert(this->SourceList.end(), src);
}

Browser::~Browser(void)
{
	this->db.~Database();
}

DBWORD * Browser::find(std::string word)
{
	if (this->db.Exist(word))//Si le mot recherché existe dans la bdd, alors on le retourne.
	{
		return db.Getword(word);//On le retourne
	}
	else//Sinon on cherche ses infos sur internet.
	{
		DBWORD * w;
		DBVERB * v;
		DBWORD * wtemp;
		DBVERB * vtemp;
		AI::TYPE t = TYPE_NONE;
		
		//On cherche ses infos sur internet.
		for (UINT i=0; i < this->SourceList.size(); i++)
		{
			wtemp = this->SourceList[i]->Getword(word);

			if (w == 0)
			{
				if ((int)wtemp->getType() == (int)VERB)
				{
					v = new DBVERB(word);
					t = *wtemp->getType();
					v->setType(t);
				}
				else if ((w != 0) && ((int)wtemp->getType() != (int)TYPE_NONE))
				{
					w = new DBWORD(word);
					t = *wtemp->getType();
					w->setType(t);
					if (wtemp->getDef()->size() >= 1)
					{
						w->setDef(*wtemp->getDef());
						return w;
					}
				}

				if (t == VERB)
				{
					vtemp = (DBVERB *) wtemp;
					if ((v->getDef()->size() >= 1) || (vtemp->getDef()->size() >= 1))//On a la définition
					{
						if (v->getDef()->size() < 1)
							v->setDef(*vtemp->getDef());

						if (v->isIrregular() != vtemp->isIrregular())//On vérifie si le verbe est irrégulier ou pas
							v->setIrregular(vtemp->isIrregular());

						UINT val = vtemp->getFormCount();
						UINT i, j;

						for(i = 0; i < val; i++)//On compare les formes trouvées et on ajoute les nouvelles
						{
							for (j = 0 ; j < v->getFormCount() ; j ++)
							{
								if (vtemp->getForm(i) == v->getForm(j))
									break;
							}
							if (j != v->getFormCount() - 1)
								v->AddForm(*vtemp->getForm(i));
						}
						if (i == val - 1)//Il n'y a plus de nouvelles formes donc on a toutes les infos
							return (DBWORD *)v;
					}
				}
				wtemp->~DBWORD();//Destruction du mot temporaire (on garde les infos importantes dans w)
			}
		}
		if (t == VERB)//On retourne le mot mais il ne contient pas toutes les infos
			return (DBWORD *)v;
		else
			return w;
	}
}
