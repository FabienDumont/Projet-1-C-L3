#include "listchar.h"

listchar newListe() {
	return NULL;
}

//-----------------------------------------------

void mvNext(listchar *curs) {
	curs = (*curs)->suiv;
}

//-----------------------------------------------

void mvPrev(listchar *curs) {
	curs = (*curs)->prec;
}

//-----------------------------------------------

void gotoFirst(listchar *curs) {
	while ((*curs)->prec != NULL) {
		mvPrev(curs);
	}
}

//-----------------------------------------------

void gotoLast(listchar *curs) {
	while ((*curs)->suiv != NULL) {
		mvNext(curs);
	}
}

//-----------------------------------------------

void addCharNext(listchar *curs);

//-----------------------------------------------

void addCharPrev(listchar *curs);

//-----------------------------------------------

void delCurrent(listchar *curs);

//-----------------------------------------------

void erase(listchar *curs);

//-----------------------------------------------

bool isEmpty(listchar curs) {
	return curs == NULL;
}

//-----------------------------------------------

void printList(listchar curs);