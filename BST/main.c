#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

int main()
{
    printf("  ---- BINARY SEARCH TREES DEMONSTRATION ---- \n");

    /** --- Variables definitions: --- */

    BSTPointer *bst; /* user-defined BST */
    int key;
    int node_amount;
    char option;
    char input[10];

    /** --- Operations: --- */
    /* Initializing Tree: */
    bst = initializeBST();

    /* Filling the Tree: */
    do{
        printf("\n -> Node key: ");
        fgets(input, 10, stdin);
        sscanf(input, "%d", &key);
        fflush(stdin);

        bst = insertNode(bst, key); /* inserts node with specified key*/

        printf("\n\t Continue? (y/n): ");
        option = getchar();
        fflush(stdin);
    } while (option == 'y' || option == 'Y');

    printf("\n --> BST: ");
    printBST(bst);
    printf("\n");

    node_amount = countNodes(bst);

    printf("\n --> Amount of nodes in the BST: %d \n", node_amount);

    return 0;
}
