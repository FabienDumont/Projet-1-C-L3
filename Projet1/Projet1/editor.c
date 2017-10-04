#include "listchar.h"

int main() {
  char c;
  listchar l = newListe();
  
  /*for(int i=0; i<255; i++) {
    printf("totoutu %d %c ",i,i);
    getchar();
  }*/
  
  
  system ("/bin/stty raw");
  while((c=getchar())!= 27) {
    system ("clear");
    
    printf("%d",c);
    switch(c){
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
    
    //printf("%c",13);
    //printf("%c     %c",c,13);
    //addCharNext(&l, c);
    printList(l);
    //printf("%d\n",c);
    
  }
 
  
  
  /* use system call to set terminal behaviour to more normal behaviour */
  system ("/bin/stty cooked");
  
	return 0; 
}
