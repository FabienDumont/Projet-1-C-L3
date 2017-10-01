#include "listchar.h"

int main() {

	listchar curseur = NULL;

	curseur = newListe();

	addCharNext(&curseur, 'a'); //Il faut donner l'adresse du pointeur pour créer le pointeur de pointeur de la fonction
	addCharNext(&curseur, 'b');
	addCharNext(&curseur, 'c');
	printList(curseur); //Renvoie abc
	
	erase(&curseur);
	printList(curseur); //Renvoie une double saut à la ligne car curs est vide

	system("pause");
}

//Je pense que le newList, addCharNext, mvNext, le printList et le erase sont OK