#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

BSTPointer* initializeBST(void)
{
    return NULL;
}

BSTPointer* consultBST(BSTPointer* root, Info new_key)
{
    if (root == NULL)
        return NULL; /* the tree is empty. */
    else {
        if (root->key == new_key)
            return root; /* returns the corresponding node. */
        else if (root->key > new_key)
            return consultBST(root->left, new_key); /* recursive call to consult left subtree. */
        else
            return consultBST(root->right, new_key); /* recursive call to consult right subtree. */
    }

}

BSTPointer* insertNode(BSTPointer* root, Info new_key)
{
    if (root == NULL) /* if the node points to NULL, allocates memory for new node. */
    {
        root = (BSTPointer*) malloc(sizeof(BSTPointer));
        root->key = new_key;
        root->left = NULL;
        root->right = NULL;
    } else {
        if (root->key > new_key)
            root->left = insertNode(root->left, new_key);/* recursive call to insert in left subtree. */
        else if (root->key < new_key)
            root->right = insertNode(root->right, new_key); /* recursive call to insert in right subtree. */
        else if (root->key == new_key){
            printf("\n\t Oops! This key already exists. \n");
            return root;  /* returns node without insertion. */
        }
    }

    return root;
}

int countNodes(BSTPointer* root)
{
    int counter = 1;

    if (root->left)
        counter += countNodes(root->left); /* recursive call to count nodes in left subtree. */

    if (root->right)
        counter += countNodes(root->right); /* recursive call to count nodes in right subtree. */

    return counter;
}

void printBST(BSTPointer* root)
{
    if (root == NULL)
        return;
    else {
        printf(" %d", root->key); /* prints the node key */
        printBST(root->left);
        printBST(root->right);
    }
}

