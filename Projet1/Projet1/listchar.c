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
	(*curs) = (*curs)->suiv;
}

//-----------------------------------------------

void mvPrev(listchar *curs) {
	(*curs) = (*curs)->prec;
}

//-----------------------------------------------

void gotoFirst(listchar *curs) {
	if ((*curs) != NULL) {
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
	if (isEmpty((*curs))) {
		(*curs)->c = c;
	}
	else {
		listchar tmp = (*curs)->suiv;
		listchar nxt = newListe();
		nxt->prec = (*curs);
		nxt->suiv = tmp;
		nxt->c = c;
		(*curs)->suiv = nxt;
		mvNext(curs);
	}
}

//-----------------------------------------------

void addCharPrev(listchar *curs, char c);

//-----------------------------------------------

void delCurrent(listchar *curs);

//-----------------------------------------------

void erase(listchar *curs) {
	gotoFirst(curs);
	listchar tmp = (*curs)->suiv;
	while ((*curs) != NULL) {
		free((*curs));
		(*curs) = tmp;
		if (tmp != NULL)
			tmp = tmp->suiv;
	}
}

//-----------------------------------------------

bool isEmpty(listchar curs) {
	gotoFirst(&curs);
	if (curs == NULL)
		return true;
	else {
		if (curs->c != NULL)
			return false;
		while (curs->suiv != NULL) {
			if (curs->c != NULL) {
				return false;
			}
			mvNext(&curs);
		}
		return true;
	}
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