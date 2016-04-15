#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "hashMap.h"

struct hashLink {
    KeyType key; /*the key is what you use to look up a hashLink*/
    ValueType value; /*the value stored with the hashLink, a pointer to int in the case of concordance*/
    struct hashLink * next; /*notice how these are like linked list nodes*/
};
typedef struct hashLink hashLink;

struct hashMap {
    hashLink ** table; /*array of pointers to hashLinks*/
    int tableSize; /*number of buckets in the table*/
    int count; /*number of hashLinks in the table*/
};
typedef struct hashMap hashMap;

/*the first hashing function you can use*/
int stringHash1(char * str)
{
    int i;
    int r = 0;
    for (i = 0; str[i] != '\0'; i++)
        r += str[i];
    return r;
}

/*the second hashing function you can use*/
int stringHash2(char * str)
{
    int i;
    int r = 0;
    for (i = 0; str[i] != '\0'; i++)
        r += (i+1) * str[i]; /*the difference between stringHash1 and stringHash2 is on this line*/
    return r;
}

/* initialize the supplied hashMap struct*/
void _initMap (struct hashMap * ht, int tableSize)
{
    int index;
    if(ht == NULL)
        return;
    ht->table = (hashLink**)malloc(sizeof(hashLink*) * tableSize);
    ht->count = 0;
    ht->tableSize = tableSize;
    for(index = 0; index < tableSize; index++)
        ht->table[index] = NULL;
}

/* allocate memory and initialize a hash map*/
hashMap *createMap(int tableSize) {
    assert(tableSize > 0);
    hashMap *ht;
    ht = malloc(sizeof(hashMap));
    _initMap(ht, tableSize);
    return ht;
}

/*
 Free all memory used by the buckets.
 Note: Before freeing up a hashLink, free the memory occupied by key and value
 */
void _freeMap (struct hashMap * ht)
{
    hashLink *tempLink;
    hashLink *nextLink;
    for (int i = 0; i < ht->tableSize; i++) { //tableSize == # of buckets
        tempLink = ht->table[i];
        while (tempLink != 0) {
            nextLink = tempLink->next;
            free(tempLink);
            tempLink = nextLink;
        }
    }
}

/* Deallocate buckets and the hash map.*/
void deleteMap(hashMap *ht) {
    assert(ht!= 0);
    /* Free all memory used by the buckets */
    _freeMap(ht);
    /* free the hashMap struct */
    free(ht);
}

/*
 Resizes the hash table to be the size newTableSize
 */
void _setTableSize(struct hashMap * ht, int newTableSize)
{
    /*write this*/
    hashLink *tempLink;
    hashMap *newHash = createMap(newTableSize);
    
    for (int i = 0; i < ht->tableSize; i++) {
        if (ht->table[i] != NULL) {
            tempLink = ht->table[i];
        }
        while (tempLink != 0) {
            insertMap(newHash, tempLink->key, tempLink->value);
            tempLink = tempLink->next;
        }
    }
    _freeMap(ht);
    free(ht->table);
    ht->tableSize = newTableSize;
    ht->table = newHash->table;
    
}

/*
 insert the following values into a hashLink, you must create this hashLink but
 only after you confirm that this key does not already exist in the table. For example, you
 cannot have two hashLinks for the word "taco".
 
 if a hashLink already exists in the table for the key provided you should
 replace that hashLink--this requires freeing up the old memory pointed by hashLink->value
 and then pointing hashLink->value to value v.
 
 also, you must monitor the load factor and resize when the load factor is greater than
 or equal LOAD_FACTOR_THRESHOLD (defined in hashMap.h).
 */
void insertMap (struct hashMap * ht, KeyType k, ValueType v)
{
    /*write this*/
    int index = 0;
    if (HASHING_FUNCTION == 1) {
        index = stringHash1(k) % ht->tableSize;
    }
    else if (HASHING_FUNCTION == 2) {
        index = stringHash2(k) % ht->tableSize;
    }
    if (ht->table[index] == 0) { //we're empty
        hashLink *newLink = malloc(sizeof(struct hashLink));
        newLink->key = k;
        newLink->value = v;
        ht->count = 1;
    }
    else {
        hashLink *curLink = malloc(sizeof(struct hashLink));
        while (strcmp(curLink->key, k) != 0 && curLink->next != 0) {
            curLink = curLink->next;
        }
        if (curLink->next == 0 && strcmp(curLink->key, k) != 0) {
            hashLink *newL = malloc(sizeof(struct hashLink));
            newL->key = k;
            newL->value = v;
            curLink->next = newL;
            ht->count++;
        }
        else {
            curLink->value = v;
        }
    }
    if(tableLoad(ht) >= LOAD_FACTOR_THRESHOLD) {
        _setTableSize(ht, (ht->tableSize)*2);
    }
}

/*
 this returns the value stored in a hashLink specified by the key k.
 
 if the user supplies the key "taco" you should find taco in the hashTable, then
 return the value member of the hashLink that represents taco.
 
 if the supplied key is not in the hashtable return NULL.
 */
ValueType atMap (struct hashMap * ht, KeyType k)
{
    /*write this*/
    int index = 0;
    hashLink *curLink = ht->table[index];
    
    if (HASHING_FUNCTION == 1) {
        index = stringHash1(k) % ht->tableSize;
    }
    else if (HASHING_FUNCTION == 2) {
        index = stringHash2(k) % ht->tableSize;
    }
    if (ht->table[index] != 0) {
        int true = 1;
        while (true) {
            if (curLink->next == 0){
                break;
            }
            else if (strcmp(curLink->key, k) == 0) {
                return curLink->value;
            }
            else {
                curLink = curLink->next;
            }
        }
        return curLink->value;
    }
    return 0;
}

/*
 a simple yes/no if the key is in the hashtable.
 0 is no, all other values are yes.
 */
int containsKey (struct hashMap * ht, KeyType k)
{
    /*write this*/
    int index = 0;
    hashLink *curLink = ht->table[index];
    
    if (HASHING_FUNCTION == 1) {
        index = stringHash1(k) % ht->tableSize;
    }
    else if (HASHING_FUNCTION == 2)
        index = stringHash2(k) % ht->tableSize;
    
    if (ht->table[index] == 0)
        return 0;
    else {
        curLink = ht->table[index];
        while (curLink != 0) {
            // printf("found currentLinks key: %s \n", curLink->key);
            if (strcmp(curLink->key, k) == 0)
                return 1;
        }
        return 0;
    }
    return 0;
}

/*
 find the hashlink for the supplied key and remove it, also freeing the memory
 for that hashlink. it is not an error to be unable to find the hashlink, if it
 cannot be found do nothing (or print a message) but do not use an assert which
 will end your program.
 */
void removeKey (struct hashMap * ht, KeyType k)
{
    /*write this*/
    int index = 0;
    hashLink *curLink;
    
    if (HASHING_FUNCTION == 1) {
        index = stringHash1(k) % ht->tableSize;
    }
    else if (HASHING_FUNCTION == 2)
        index = stringHash2(k) % ht->tableSize;
    
    if (ht->table[index] != 0) {
        curLink = ht->table[index];
        if (strcmp(curLink->key, k) == 0) { // if first value is a match
            hashLink *tmp = curLink;
            ht->table[index] = tmp->next;
            free(tmp);
            ht->count--;
            return;
        }
        int true = 1;
        while (true){
            if (curLink->next == 0) {
                break;
            }
            else if (strcmp(curLink->next->key, k) == 0) {
                break;
            }
            else {
                curLink = curLink->next;
            }
        }
        if (curLink->next == 0)
            return;
        else {
            hashLink *tmp = curLink->next;
            curLink->next = tmp->next;
            free(tmp);
            ht->count--;
        }
    }
}

/*
 returns the number of hashLinks in the table
 */
int size (struct hashMap *ht)
{
    /*write this*/
    return ht->count;
}

/*
 returns the number of buckets in the table
 */
int capacity(struct hashMap *ht)
{
    /*write this*/
    return ht->tableSize;
}

/*
 returns the number of empty buckets in the table, these are buckets which have
 no hashlinks hanging off of them.
 */
int emptyBuckets(struct hashMap *ht)
{
    /*write this*/
    int numEmptyBucks = 0;
    
    for (int i = 0; i < ht->tableSize; i++) {
        if (ht->table == 0)
            numEmptyBucks++;
    }
    return numEmptyBucks;
}

/*
 returns the ratio of: (number of hashlinks) / (number of buckets)
 
 this value can range anywhere from zero (an empty table) to more then 1, which
 would mean that there are more hashlinks then buckets (but remember hashlinks
 are like linked list nodes so they can hang from each other)
 */
float tableLoad(struct hashMap *ht)
{
    /*write this*/
    return (float)ht->count/ht->tableSize;
}

/* print the hashMap */
void printMap (struct hashMap * ht)
{
    int i;
    hashLink *temp;
    for(i = 0;i < capacity(ht); i++){
        temp = ht->table[i];
        if(temp != 0) {
            printf("\nBucket Index %d -> ", i);
        }
        while(temp != 0){
            printf("Key:%s|", temp->key);
            printf("Key:%d|",temp->value);
            printf(" -> ");
            temp=temp->next;
        }
    }
}
