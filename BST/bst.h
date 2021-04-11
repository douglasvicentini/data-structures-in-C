#ifndef BST_H_INCLUDED
#define BST_H_INCLUDED

/** ----- DATA DEFINITIONS ----- */

typedef int Info;

struct BST_Pointer {
    Info key;
    struct BST_Pointer *left;
    struct BST_Pointer *right;
};

typedef struct BST_Pointer BSTPointer;

/** ----- DATA OPERATIONS ----- */

BSTPointer* initializeBST(void);
/* Initializes a BST. */

BSTPointer* consultBST(BSTPointer* root, Info key);
/* Receives the root for a BST and a key. If there is a node with that key in the BST, the function
returns this node. Else, it returns NULL. */

BSTPointer* insertNode(BSTPointer* root, Info key);
/* Receives the root for a BST and a key and inserts a new node in the BST, if there is
not a node with that key. */

int countNodes(BSTPointer* root);
/* Receives the root for a BST and counts and returns the number of nodes in that BST.*/

void printBST(BSTPointer* root);
/* Receives the root for a BST and prints all nodes data, with Pre-order traversal.*/

#endif
