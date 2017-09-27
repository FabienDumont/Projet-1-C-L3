#include "listchar.h"

listchar newListe() {
	return NULL;
}

//-----------------------------------------------

void mvNext(listchar *curs);

//-----------------------------------------------

void mvPrev(listchar *curs);

//-----------------------------------------------

void gotoFirst(listchar *curs);

//-----------------------------------------------

void gotoLast(listchar *curs);

//-----------------------------------------------

void addCharNext(listchar *curs);

//-----------------------------------------------

void addCharPrev(listchar *curs);

//-----------------------------------------------

void delCurrent(listchar *curs);

//-----------------------------------------------

void erase(listchar *curs);

//-----------------------------------------------

bool isEmpty(listchar curs);

//-----------------------------------------------

void printList(listchar curs);


//COMMENTAIRE !!!