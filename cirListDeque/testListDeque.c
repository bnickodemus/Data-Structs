#include "cirListDeque.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
	printf("implement testListDeque.c!\n");
    
    struct cirListDeque *cld;
    cld = createCirListDeque();
    
    printf("isEmptyCirListDeque?%d\n", isEmptyCirListDeque(cld));
    
    printf("\nTesting add links (3),5,6,9,8\n");
    addFrontCirListDeque(cld, 5);
    printf("frontCirListDeque 5:%f\n", frontCirListDeque(cld));
    addBackCirListDeque(cld, 6);
    printf("backCirListDeque 6:%f\n", backCirListDeque(cld));
    addBackCirListDeque(cld, 9);
    printf("backCirListDeque 9:%f\n", backCirListDeque(cld));
    
    addFrontCirListDeque(cld,3);
    printf("frontCirListDeque 3:%f\n", frontCirListDeque(cld));
    
    addBackCirListDeque(cld, 8);
    printf("backCirListDeque 8:%f\n\n", backCirListDeque(cld));
    
    printf("frontCirListDeque 3:%f\n", frontCirListDeque(cld));
    printf("backCirListDeque 8:%f\n\n", backCirListDeque(cld));
    
    printf("remove the front(3) and back(8)...\n");
    removeFrontCirListDeque(cld);
    printf("frontCirListDeque should now be 5:%f\n", frontCirListDeque(cld));
    removeBackCirListDeque(cld);
    printf("backCirListDeque should now be 9:%f\n", backCirListDeque(cld));
    
    printf("cirListDeque should now print (5,6,9) \n");
    printCirListDeque(cld);
    printf("\n");

    reverseCirListDeque(cld);
    printf("cirListDeque should now print (9,6,5) \n");
    
    printCirListDeque(cld);
    printf("\n");
    printf("isEmptyCirListDeque?%d\n", isEmptyCirListDeque(cld));
    
    return 0;

    
}
