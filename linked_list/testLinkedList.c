#include "linkedList.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <assert.h>

int main(int argc, char* argv[]) {
    printf("implement testLinkedList.c!\n");
    
    struct linkedList *lst;
    lst = createLinkedList();
    
    printf("isEmptyList?%i\n", isEmptyList(lst));
    
    printf("\nTesting add links (3),5,6,9,8\n");
    addList(lst, 5);
    printf("addList 5:%i\n", frontList(lst));
    addBackList(lst, 6);
    printf("backList 6:%i\n", backList(lst));
    addBackList(lst, 9);
    printf("backList 9:%i\n", backList(lst));
    
    addFrontList(lst,3);
    printf("frontList 3:%i\n", frontList(lst));
    
    addBackList(lst, 8);
    printf("backList 8:%i\n\n", backList(lst));
    
    printf("frontList 3:%i\n", frontList(lst));
    printf("backList 8:%i\n\n", backList(lst));
    
    printf("remove the front(3) and back(8)...\n");
    removeFrontList(lst);
    printf("frontList should now be 5:%i\n", frontList(lst));
    removeBackList(lst);
    printf("backList should now be 9:%i\n", backList(lst));
    
    printf("contains 5?%i\n",containsList(lst,5));
    printf("removing 5...");
    removeFrontList(lst);
    printf("contains 5?%i\n",containsList(lst,5));
    
    printf("removing 6...");
    removeList(lst,6);
    printf("frontList? 9:%i", frontList(lst));
    printf("isEmptyList?%i\n", isEmptyList(lst));
    
    return 0;
}



