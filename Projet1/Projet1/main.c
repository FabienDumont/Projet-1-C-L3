#include "listchar.h"


int main() {

	listchar curseur;
	listchar listeVide = newListe();


	// Test de new Liste
	curseur = newListe();
	printf("Liste vide : %d \n", isEmpty(curseur)); // Une nouvelle liste est vide 


	// Test addCharNext
	addCharNext(&curseur, 'a'); // Quand liste vide
	addCharNext(&curseur, 'c'); // En fin de chaine
	mvPrev(&curseur);
	addCharNext(&curseur, 'b'); // En millieu de chaine
	printList(curseur); // Attendu : abc


	// Test erase
	erase(&curseur);
	printf("Liste vide : %d \n", isEmpty(curseur)); // Une liste que l'on efface est vide


	// Test addCharPrev
	addCharPrev(&curseur, 'c'); // Quand liste vide
	addCharPrev(&curseur, 'a'); // En debut de liste
	mvNext(&curseur);
	addCharPrev(&curseur, 'b'); // En millieu de liste
	printList(curseur); // Attendu : abc


	// Test gotoFirst
	gotoFirst(&listeVide); // Pas d'erreur sur une liste vide
	gotoFirst(&curseur); // Curseur sur a
	addCharPrev(&curseur, 'n');
	printList(curseur); // Attendu : nabc


	// Test gotoLast
	gotoLast(&listeVide); // Pas d'erreur sur une liste vide
	gotoLast(&curseur); // Curseur sur c
	addCharNext(&curseur, 'n');
	printList(curseur); // Attendu : nabcn

	// Test delCurrent 
	delCurrent(&listeVide); // Pas d'erreur sur une liste vide
	mvPrev(&curseur); // Curseur sur c
	delCurrent(&curseur); // Test de en millieu de liste
	printList(curseur); // Attendu : nabn

	gotoLast(&curseur); // Curseur sur n
	delCurrent(&curseur); // Test de en fin de liste
	printList(curseur); // Attendu : nab

	gotoFirst(&curseur); // Curseur sur n
	delCurrent(&curseur); // Test de en debut de liste
	printList(curseur); // Attendu : ab

	delCurrent(&curseur); 
	printList(curseur); // Attendu : b

	delCurrent(&curseur); // Test sur liste d'un element
	printf("Liste vide : %d \n", isEmpty(curseur)); // La liste est maintenant vide 
	
	system("pause");

}
