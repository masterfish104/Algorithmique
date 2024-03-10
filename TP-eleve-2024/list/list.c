/**
 * @file list.c
 * @brief Implementation file for a linked list
 *
 * This file contains the implementation of the linked list data structure
 * and its associated functions.
 *
 * @author Loïck Lhote
 * @date February 2023
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

/**
 * @brief Creates a new linked list
 *
 * @return A pointer to the newly created linked list
 */
List newList() {
    List L;
    L=NULL;
    return L;
}

/**
 * @brief Frees the memory used by a linked list
 *
 * @param L Pointer to the linked list to be freed
 */
void freeList(List L) {
    if (L==NULL){
    	return;
    }
    freeList(L->nextCell);
    free(L->nextCell);
    L=NULL;
    return;
}

/**
 * @brief Prints the contents of a linked list
 *
 * @param L Pointer to the linked list to be printed
 * @param type If type==0, prints only the values, otherwise print the couples (key,vlaue)
 *
 * Prints the linked list in the following way if k!=0:
 * [(key 1, value 1),(key 2, value 2), … ,(key k, value k)]
 * Prints the linked list in the following way if k==0:
 * [value 1,value 2,…,value k]
 */

void printList(List L, int type) {
    Cell* cur;
    if (L==NULL) {
        printf("[]");
        return;
    }
    printf("[");
    cur=L;
    while (cur->nextCell!=NULL) {
        if (type!=0){
            printf("(%s,%d);",cur->key,cur->value);
        } else {
            printf("%d,",cur->value);
        }
        cur=cur->nextCell;
    }
    if (type!=0){
            printf("(%s,%d)]\n",cur->key,cur->value);
        } else {
            printf("%d]\n",cur->value);
        }
    return;
}

/**
 * @brief Finds a key in a linked list
 *
 * @param L Pointer to the linked list to search in
 * @param key Key to search for
 *
 * @return A pointer to the first cell containing the key, or NULL if the key is not found
 */
Cell* findKeyInList(List L, string key) {
    Cell * cur;
    cur=L;
    while (cur!=NULL && sameKey(cur->key,key)!=0){
        cur=cur->nextCell;
    }
    return cur;
}

int sameKey(string s1,string s2){
    	if (s1==NULL) {
		if (s2==NULL) {
			return 0;
		}
		return 1;
	} 
	if (s2==NULL) {
		return 1;
	}
	return strcmp(s1,s2);
}	

/**
 * @brief Deletes a key from a linked list
 *
 * @param L Pointer to the linked list to search in
 * @param key Key to delete
 *
 * @return A pointer to the modified linked list
 * Only the first occurrence of the key is deleted.
 */

/*
List delKeyInList(List L, string key) {
    Cell *cur,*tmp;
    cur=findKeyInList(L,key);
    if (cur!=NULL){
        cur->value=cur->nextCell->value;
        cur->key=cur->nextCell->key;
        tmp=cur->nextCell->nextCell;
        free(cur->nextCell);
        cur->nextCell=tmp;
    }
    return L;
}*/

List delKeyInList(List L, string key) {
    Cell *cur,*tmp;
    cur=L;
    if (cur==NULL){
    	return L;
    }
    if (sameKey(cur->key,key)==0){
        tmp=L->nextCell;
        free(L);
        return tmp;
    }
    while (cur->nextCell!=NULL && sameKey(cur->nextCell->key,key)!=0){
        cur=cur->nextCell;
    }
    if (cur->nextCell!=NULL){
        tmp=cur->nextCell->nextCell;
        free(cur->nextCell);
        cur->nextCell=tmp;
    }
    return L;
}

/**
 * @brief Adds a key-value pair to a linked list
 *
 * @param L Pointer to the linked list to add to
 * @param key Key to add
 * @param value Value to add
 *
 * @return A pointer to the modified linked list
 *
 * The key-value pair is added at the beginning of the list
 */

List addKeyValueInList(List L, string key, int value) {
    List L2;
    L2=newList();
    L2=(List) malloc(sizeof(Cell));
    L2->nextCell=L;
    L2->key=key;
    L2->value=value;
    return L2;
}


