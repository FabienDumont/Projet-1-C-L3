#include "listchar.h"


int main() {
	char c;
	listchar l = newListe();

	// On desactive le buffer qui attend un appui sur ENTREE
	system("/bin/stty raw");

	while ((c = getchar()) != 27) {
		system("clear");

		printf("%d", c);
		switch (c) {
		case 127: // Retour arriere
			delCurrent(&l);
			break;
		case 13:
			addCharNext(&l, '\n');
			addCharNext(&l, 13);
			break;
		case 37: // Gauche
			mvPrev(&l);
			break;
		default:
			addCharNext(&l, c);
			break;
		}

		printList(l);


	}


	// On reactive le buffer
	system("/bin/stty cooked");

	return 0;
}
