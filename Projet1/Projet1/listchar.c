#include "listchar.h"

typedef struct cell {
	char c;
	struct cell *suiv;
	struct cell *prec;
}cell;

listchar newListe() {
	listchar curseur = malloc(sizeof(cell));
	curseur->c = NULL;
	curseur->prec = NULL;
	curseur->suiv = NULL;
	return curseur;
}

//-----------------------------------------------

void mvNext(listchar *curs) {
	listchar tmp;
	tmp = (*curs);
	if ((*curs)->suiv == NULL) {
		listchar nxt = NULL;
		nxt = newListe(nxt);
		(*curs)->suiv = nxt;
	}
	(*curs) = (*curs)->suiv;
	(*curs)->prec = tmp;
}

//-----------------------------------------------

void mvPrev(listchar *curs) {
	(*curs) = (*curs)->prec;
}

//-----------------------------------------------

void gotoFirst(listchar *curs) {
	if (!isEmpty(curs)) {
		while ((*curs)->prec != NULL) {
			mvPrev(curs);
		}
	}
}

//-----------------------------------------------

void gotoLast(listchar *curs) {
	while ((*curs)->suiv != NULL) {
		mvNext(curs);
	}
}

//-----------------------------------------------

void addCharNext(listchar *curs, char c) {
	listchar tmp;
	if (isEmpty((*curs))) {
		tmp = (*curs);
		(*curs)->c = c;
		mvNext(curs);
		(*curs)->prec = tmp;
	}
	else {
		(*curs)->c = c;
		mvNext(curs);
	}
}

//-----------------------------------------------

void addCharPrev(listchar *curs, char c);

//-----------------------------------------------

void delCurrent(listchar *curs);

//-----------------------------------------------

void erase(listchar *curs) {
	listchar tmp = (*curs)->suiv;
	gotoFirst(curs);
	while ((*curs) != NULL) {
		free((*curs));
		(*curs) = tmp;
		if (!isEmpty(tmp))
			tmp = (*tmp).suiv;
	}
}

//-----------------------------------------------

bool isEmpty(listchar curs) {
	return curs == NULL;
}

//-----------------------------------------------

void printList(listchar curs) {
	if (!isEmpty(curs)) {
		gotoFirst(&curs);
		while (curs != NULL) {
			printf("%c", (*curs).c);
			curs = (*curs).suiv;
		}
		printf("\n\n");
	}
	else {
		printf("\n\n");
	}
}