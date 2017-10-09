#include "listchar.h"


// ==========================================
// Structure de données (cachée)
// ==========================================

typedef struct cell {
	char c;
	struct cell *suiv;
	struct cell *prec;
}cell;


// ==========================================
// Liste des fonctions
// ==========================================


listchar newListe() {
	return NULL;
}

// ==========================================

void mvNext(listchar *curs) {
	if (!isEmpty(*curs) && (*curs)->suiv != NULL) {
		(*curs) = (*curs)->suiv;
	}
}

// ==========================================

void mvPrev(listchar *curs) {
	if (!isEmpty(*curs) && (*curs)->prec != NULL) {
		(*curs) = (*curs)->prec;
	}
}

// ==========================================

void gotoFirst(listchar *curs) {
	if (!isEmpty(*curs)) {
		while ((*curs)->prec != NULL) {
			mvPrev(curs);
		}
	}
}

// ==========================================

void gotoLast(listchar *curs) {
	if (!isEmpty(*curs)) {
		while ((*curs)->suiv != NULL) {
			mvNext(curs);
		}
	}
}

// ==========================================

void addCharNext(listchar *curs, char c) {
	//On creer une cellule
	cell* tmp = (cell *)malloc(sizeof(cell));
	tmp->c = c; 

	if (isEmpty(*curs)) {
		tmp->prec = NULL;
		tmp->suiv = NULL;
		*curs = tmp;
	}
	else if ((*curs)->suiv == NULL) {
		tmp->prec = *curs;
		tmp->suiv = NULL;

		(*curs)->suiv = tmp;
		mvNext(curs);
	}
	else {
		tmp->prec = *curs;
		tmp->suiv = (*curs)->suiv;
		((*curs)->suiv)->prec = tmp;
		(*curs)->suiv = tmp;
		mvNext(curs);
	}
}

// ==========================================

void addCharPrev(listchar *curs, char c) {
	//On creer une cellule
	cell* tmp = (cell *)malloc(sizeof(cell));
	tmp->c = c;

	if (isEmpty(*curs)) {
		tmp->prec = NULL;
		tmp->suiv = NULL;
		*curs = tmp;
	}
	else if ((*curs)->prec == NULL) {
		tmp->prec = NULL;
		tmp->suiv = *curs;

		(*curs)->prec = tmp;
		mvPrev(curs);
	}
	else {
		tmp->suiv = *curs;
		tmp->prec = (*curs)->prec;
		((*curs)->prec)->suiv = tmp;
		(*curs)->prec = tmp;
		mvPrev(curs);
	}
}

// ==========================================

void delCurrent(listchar *curs) {
	cell * tmp = *curs;

	if (!isEmpty(*curs)) {
		// Une cellule 
		if ((*curs)->prec == NULL && (*curs)->suiv == NULL) {
			free(*curs);
			*curs = NULL;	
		} // Premier de la liste
		else if ((*curs)->prec == NULL) {
			((*curs)->suiv)->prec = NULL;
			mvNext(curs);
			free(tmp);
		} // Dernier de la liste
		else if ((*curs)->suiv == NULL) {
			((*curs)->prec)->suiv = NULL;
			mvPrev(curs);
			free(tmp);
		}
		else {
			((*curs)->prec)->suiv = (*curs)->suiv;
			((*curs)->suiv)->prec = (*curs)->prec;
			mvPrev(curs);
			free(tmp);
		}
	}
}

// ==========================================

void erase(listchar *curs) {
	if (!isEmpty(*curs)) {
		while (!isEmpty(*curs)) {
			delCurrent(curs);
		}
	}
}

// ==========================================

bool isEmpty(listchar curs) {
	return curs == NULL;
}

// ==========================================

void printList(listchar curs) {
	listchar curseur = curs;
	
	if (!isEmpty(curs)) {
		gotoFirst(&curs);
		while (curs != NULL) {
			printf("%c", (*curs).c);
			
			if (curs == curseur) {
				printf("_");
			}
			
			curs = (*curs).suiv;
	
		}
		printf("\n");
	}

}
