#include "listchar.h"


int main() {
	char c;
	bool quit = false;
	listchar l = newListe();

	// On desactive le buffer qui attend un appui sur ENTREE
	system("/bin/stty raw");
	system("clear");

	do{
		c = getchar();
		
		switch (c) {
		case 127: // Retour arriere
			delCurrent(&l);
			break;
		case 13:
			addCharNext(&l, '\n');
			
			break;
		case 27: // retourne un truc genre 279168 en 3 char ici le 27
			
				getchar(); // la le 91
				char tmp = getchar(); // enfin je test
		
				if(tmp == 68){ // Gauche
					mvPrev(&l);
					
				}else if(tmp == 67){ // Droite
					mvNext(&l);
				
				}else if(tmp == 51){ // Suppr
					mvNext(&l);
					delCurrent(&l);
					getchar();
					
				}
			break;
		
		default:
			addCharNext(&l, c);
			break;
		}
		
		system("clear");
		printList(l);


	}while(c != '.');


	// On reactive le buffer
	system("/bin/stty cooked");
	system("clear");

	return 0;
}
