#include <stdio.h>
#include <stdlib.h>
#include "dll.h"

int main()
{
    printf(" ---------- DLL DEMONSTRATION ---------- \n");

    /** ---------- DATA DEFINITIONS ---------- **/

    DLLPointer *list;
    DLLData data;
    char input[BUFFER];
    int id;
    char option;

    /** ---------- DATA OPERATIONS ---------- **/

    list = initializeList();

    /* Gets node data from the user and inserts in the DLL: */
    do{
        getData(&data);
        list = insertNodeInOrder(list, data);
        printf("\n\t-> Continue? (y/n): ");
        option = getchar();
        fflush(stdin);
    } while (option == 'y' || option == 'Y');

    printf("\n -> Print list? (y/n): ");
    option = getchar();

    if (option == 'y' || option == 'Y')
        printList(list);

    fflush(stdin);

    printf("\n -> Print list in reverse order? (y/n): ");
    option = getchar();
    fflush(stdin);

    if (option == 'y' || option == 'Y')
        printListReverse(list);

    /* Removes nodes from the list: */
    do{
        printf("\n -> Remove node from the list? (y/n): ");
        option = getchar();
        fflush(stdin);
        if (option == 'y' || option == 'Y'){
            printf("\n\t -> Enter node ID: ");
            fgets(input, BUFFER, stdin);
            sscanf(input, "%d", &id);
            fflush(stdin);
            list = removeNodeByID(list, id);
            printList(list);
        }
    } while (option == 'y' || option == 'Y');

    printf("\n -> Destroy list? (y/n): ");
    option = getchar();
    fflush(stdin);

    if (option == 'y' || option == 'Y')
        list = destroyList(list);

    return 0;
}
