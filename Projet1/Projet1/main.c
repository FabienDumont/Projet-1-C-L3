#include "listchar.h"

int main() {

	listchar curseur;
	curseur = newListe();

	printf("%d \n", isEmpty(curseur)); // Une nouvelle liste est vide 

	addCharNext(&curseur, 'a'); // Il faut donner l'adresse du pointeur pour créer le pointeur de pointeur de la fonction
	addCharNext(&curseur, 'b');
	addCharNext(&curseur, 'c');
	printList(curseur); // Affiche abc

	mvPrev(&curseur); // Se deplace sur b
	addCharNext(&curseur, 'n');
	printList(curseur); // Affiche abnc

	mvPrev(&curseur); // Se deplace sur b
	addCharPrev(&curseur, 'n');
	printList(curseur); // Affiche anbnc

	
	gotoFirst(&curseur); // Test de gotoFirst
	addCharPrev(&curseur, 'n');
	printList(curseur); // Affiche nanbnc

	delCurrent(&curseur); // Test de en debut de chaine
	printList(curseur); // Affiche anbnc

	gotoLast(&curseur); 
	delCurrent(&curseur); // Test de en fin de chaine
	printList(curseur); // Affiche anbn

	mvPrev(&curseur);
	delCurrent(&curseur); // Test de en millieu de chaine
	printList(curseur); // Affiche ann

	
	erase(&curseur);
	printList(curseur); //Renvoie une double saut à la ligne car curs est vide

}
