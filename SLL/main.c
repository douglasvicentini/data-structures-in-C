#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sll.h"

int main()
{
    printf("\n\t\t\t ------------------ SLL DEMONSTRATION ------------------\n");

    SLLPointer *list; // SLL used in program
    SLLData node; // node information
    char input[BUFFER];
    char option;
    int id; // 'id' node value for node removal

    /* List initialization: */
    list = initializeList();

    /* Node information reading (from stdin): */
    do{
        getData(&node);
        list = insertNodeInOrder(list, node);
        printf("\n\t-> Insert another node? (y/n): ");
        option = getchar();
        fflush(stdin);
    } while (option == 'y' || option == 'Y');

    printf("\n\tPrint list data? (y/n): ");
    option = getchar();
    fflush(stdin);
    if (option == 'y' || option == 'Y')
        printList(list);

    /* Node removal from list: */
    do{
        printf("\n\t-> Remove node? (y/n): ");
        option = getchar();
        fflush(stdin);

        if (option == 'y' || option == 'Y')
        {
            printf("\n\t\t-> Enter node ID: ");
            fgets(input, BUFFER, stdin);
            sscanf(input, "%d", &id);
            list = removeNodeByID(list, id);

            printf("\n\t\t-> Print list data? (y/n): ");
            option = getchar();
            fflush(stdin);

            if (option == 'y' || option == 'Y')
                printList(list);
        }
    } while(option == 'y' || option == 'Y');

    /* List destruction: */
    printf("\n -> Destroy list? (y/n): ");
    option = getchar();
    fflush(stdin);

    if (option == 'y' || option == 'Y'){
        list = destroyList(list);
        printList(list);
    }

    return 0;
}
