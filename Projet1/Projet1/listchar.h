#include <stdio.h>
#include <stdbool.h>

// ================================================
// Definition des types
// ================================================

struct cell {
	char c;
	struct cell *suiv;
	struct cell *prec;
};

typedef struct cell * listchar;


// ================================================
// Definition des operations
// ================================================

listchar newListe();
void mvNext(listchar *curs);
void mvPrev(listchar *curs);
void gotoFirst(listchar *curs);
void gotoLast(listchar *curs);
void addCharNext(listchar *curs);
void addCharPrev(listchar *curs);
void delCurrent(listchar *curs);
void erase(listchar *curs);
bool isEmpty(listchar curs);
void printList(listchar curs);


// Commentaire ajouté