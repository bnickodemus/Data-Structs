#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "hashMap.h"
#include <ctype.h>

/*
 the getWord function takes a FILE pointer and returns you a string which was
 the next word in the in the file. words are defined (by this function) to be
 characters or numbers seperated by periods, spaces, or newlines.
 when there are no more words in the input file this function will return NULL.
 this function will malloc some memory for the char* it returns. it is your job
 to free this memory when you no longer need it.
 */
char* getWord(FILE *file);

int main (int argc, const char * argv[]) {
    const char* filename;
    struct hashMap *hashTable;
    int tableSize = 10;
    clock_t timer;
    FILE *fileptr;
    /*
     this part is using command line arguments, you can use them if you wish
     but it is not required. DO NOT remove this code though, we will use it for
     testing your program.
     if you wish not to use command line arguments manually type in your
     filename and path in the else case.
     */
    if(argc == 2)
        filename = argv[1];
    else
        filename = "input1.txt"; /*specify your input text file here*/
    
    printf("opening file: %s\n", filename);
    
    timer = clock();
    
    hashTable = createMap(tableSize);
    
    /*... concordance code goes here ...*/
    
    char *word;
    int *value;
    int nTimes;
    
    fileptr = fopen(filename, "r");
    
    do {
        word = getWord(fileptr);
        if (word != NULL && (containsKey(hashTable, word) != 0)) { // key already exists
            value = atMap(hashTable, word);  // find the value at the key
            // inc size of hasmap?
            *value = *value + 1;
            // insertMap(hashTable, word, *value);
            
        }
        else {
            if (word != NULL) { // key is not in the table
                insertMap(hashTable, word, 1);
                value = malloc(sizeof(int));
                *value = 1;
            }
        }
         //printf("%s:%d\n", word, *value);
        printf("-> key: %s | val: %d\n", word, *value);
    }
    while(word != NULL);
    
    /*
    for (int i = 0; i < capacity(hashTable); i++) {
        if (hashTable != 0) {
            printf("Buckets index:%d\n", i);
        }
        while (hashTable !=0) {
            printf("Key:%s ", hashTable->key);
            printf("Key:%d ", hashTable->value);
        }
    }
    */
 
    //_setTableSize(hashTable, 5);
    
    fclose(fileptr);
    
    /*... concordance code ends here ...*/
    
    printMap(hashTable);
    timer = clock() - timer;
    printf("\nconcordance ran in %f seconds\n", (float)timer / (float)CLOCKS_PER_SEC);
    printf("Table emptyBuckets = %d\n", emptyBuckets(hashTable));
    printf("Table count = %d\n", size(hashTable));
    printf("Table capacity = %d\n", capacity(hashTable));
    printf("Table load = %f\n", tableLoad(hashTable));
    
    printf("Deleting keys\n");
    
    removeKey(hashTable, "and");
    removeKey(hashTable, "me");
    removeKey(hashTable, "the");
    printMap(hashTable);
    
    deleteMap(hashTable);
    printf("\nDeleted the table\n");
    return 0;
}

void printValue(ValueType v) {
    printf("Value:%i", v);
}

char* getWord(FILE *file)
{
    int length = 0;
    int maxLength = 16;
    char character;
    
    char* word = malloc(sizeof(char) * maxLength);
    assert(word != NULL);
    
    while( (character = fgetc(file)) != EOF)
    {
        character = tolower(character);  /* In should be the same as in ..so force all to lowercase */
        if((length+1) > maxLength)
        {
            maxLength *= 2;
            word = (char*)realloc(word, maxLength);
        }
        if((character >= '0' && character <= '9') || /*is a number*/
           (character >= 'A' && character <= 'Z') || /*or an uppercase letter*/
           (character >= 'a' && character <= 'z') || /*or a lowercase letter*/
           character == 39) /*or is an apostrophy*/
        {
            word[length] = character;
            length++;
        }
        else if(length > 0)
            break;
    }
    
    if(length == 0)
    {
        free(word);
        return NULL;
    }
    word[length] = '\0';
    return word;
}

