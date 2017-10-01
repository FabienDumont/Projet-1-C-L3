#ifndef DEF_LISTCHAR
#define DEF_LISTCHAR

#include <stdio.h>
#include <stdbool.h>

// ================================================
// Definition des types
// ================================================

struct cell;
typedef struct cell *listchar;


// ================================================
// Definition des operations
// ================================================

listchar newListe();
void mvNext(listchar *curs);
void mvPrev(listchar *curs);
void gotoFirst(listchar *curs);
void gotoLast(listchar *curs);
void addCharNext(listchar *curs, char c);
void addCharPrev(listchar *curs, char c);
void delCurrent(listchar *curs);
void erase(listchar *curs);
bool isEmpty(listchar curs);
void printList(listchar curs);

#endif