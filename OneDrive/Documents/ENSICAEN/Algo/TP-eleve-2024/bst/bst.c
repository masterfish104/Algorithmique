/**
 * \file bst.c
 * \brief Implementation of classical functions for BST
 * \author Loïck LHOTE
 * \version 0.1
 * \date janvier 2023
 *
 * Source code of the functions declared in bst.h.
 * Thes functions are to manipulate binary search trees.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "bst.h"


/**
 * @brief Create an empty binary search tree.
 * @return A pointer to the root of the new empty tree (NULL pointer).
 */
BinarySearchTree createEmptyBST() {
    BinarySearchTree bst;
    bst=NULL;
    return bst;
}

/**
 * @brief Free the memory of a binary search tree.
 * @param tree Pointer to the root of the tree.
 */
void freeBST(BinarySearchTree tree) {
    if (tree==NULL) {
    	return;
    }
    if (tree->leftBST!=NULL){
    	freeBST(tree->leftBST);
    }
    if (tree->rightBST!=NULL){
    	freeBST(tree->rightBST);
    }
    free(tree);
    return;
}


/**
 * @brief Add a value to a binary search tree.
 * @param tree Pointer to the root of the tree.
 * @param value The value to add.
 * @return A pointer to the root of the modified tree.
 */
BinarySearchTree addToBST(BinarySearchTree tree, int value) {
    NodeBST n;
    if (tree==NULL) {
   	tree=(BinarySearchTree) malloc (sizeof(NodeBST));
	n.value=value;
    	n.leftBST=NULL;
    	n.rightBST=NULL;
	*tree=n;
    	return tree;
    }
    if (value>tree->value) {
	tree->rightBST=addToBST(tree->rightBST,value);
    } else {
	tree->leftBST=addToBST(tree->leftBST,value);
    }
    return tree;
}


/**
 * @brief Compute the height of a binary search tree.
 * @param tree Pointer to the root of the tree.
 * @return The height of the tree.
 */
int heightBST(BinarySearchTree tree) {
    int h1,h2;
    if (tree==NULL){
    	return 0;
    }
    h1=heightBST(tree->leftBST)+1;
    h2=heightBST(tree->rightBST)+1;
    return (h1>h2)?h1:h2;
}


/**
 * @brief Search for a value in a binary search tree.
 * @param tree Pointer to the root of the tree.
 * @param value The value to search for.
 * @return A pointer to the node containing the value, or NULL if the value is not in the tree.
 */
BinarySearchTree searchBST(BinarySearchTree tree, int value) {
    BinarySearchTree cur;
    cur=tree;
    while (cur!=NULL && value!=cur->value) {
    	if (value>cur->value) {
	    cur=cur->rightBST;
	} else {
	    cur=cur->leftBST;	
	}
    }
    return cur;
}


/**
 * @brief Delete the root of a binary search tree.
 * @param tree Pointer to the root of the tree.
 * @return A pointer to the root of the modified tree.
 */
BinarySearchTree deleteRootBST(BinarySearchTree tree) {
    int value;
    BinarySearchTree Rcur,Lcur;
    if (tree==NULL){
    	return tree;
    }
    Lcur=tree->leftBST;
    Rcur=tree->rightBST;
    while (Lcur!=NULL){
	value=Lcur->value;
	Lcur=deleteRootBST(Lcur);
	Rcur=addToBST(Rcur,value);
    }
    return Rcur;
}


/**
 * @brief Delete a value from a binary search tree.
 * @param tree Pointer to the root of the tree.
 * @param value The value to delete.
 * @return A pointer to the root of the modified tree.
 */
BinarySearchTree deleteFromBST(BinarySearchTree tree, int value) {
    BinarySearchTree cur,cur2;
    cur=tree;

    while (cur!=NULL && cur->value!=value){
    	if (cur->value<value){
	    cur2=cur;
	    cur=cur->rightBST;
	} else {
	    cur2=cur;
	    cur=cur->leftBST;
	}
    }
    cur=deleteRootBST(cur);
    if (cur2->value<value){
	cur2->rightBST=cur;
    } else {
	cur2->leftBST=cur;
    }	
    return tree;
}

/**
 * @brief Build a binary search tree from a given permutation.
 * @param permutation Array of integers representing the permutation
 * @param n size of the array
 * @return A binary such tree built by successively inserting the elements of permutation.
 */
BinarySearchTree buildBSTFromPermutation(int *permutation,size_t n) {
    BinarySearchTree bst;
    bst=createEmptyBST();
    for (int i=0;i<n;i++){
    	bst=addToBST(bst,permutation[i]);
    }
    return bst;
}


/**
 * @brief Print the elements of a binary search tree in a pretty format.
 * @param tree Pointer to the root of the tree.
 * @param space Space to be printed before the current element.
 */
void prettyPrintBST(BinarySearchTree tree, int space) {
    if (tree == NULL) {
        return;
    }
    space += 10;

    prettyPrintBST(tree->rightBST, space);

    printf("\n");
    for (int i = 10; i < space; i++) {
        printf(" ");
    }
    printf("%d\n", tree->value);

    prettyPrintBST(tree->leftBST, space);
}

/**

Quelles conclusions pouvez-vous tirer des résultats d’expériences que vous obtenez ?

... Répondre ici.


*/
