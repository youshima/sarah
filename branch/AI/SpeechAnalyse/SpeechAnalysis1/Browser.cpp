#include "StdAfx.h"
#include "Browser.h"

using namespace AI;
using namespace AI::BROWSER;

Browser::Browser(void)
:
db()
{
}

Browser::~Browser(void)
{
	this->db.~Database();
}

DBWORD Browser::findW(STR word)
{
	/*if (this->db.exist(word, TYPE_NONE))
	{
		return this->db.info(word, TYPE_NONE))
	}
	else
	{
		DBWORD infoWord(word);

	}
	*/
}

DBVERB Browser::findV(STR verb)
{
}

TYPE Browser::getType(STR word)
{
}
