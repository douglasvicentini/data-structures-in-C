#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sll.h"

SLLPointer* initializeList(void)
{
    return NULL;
}

SLLPointer* insertNodeInOrder(SLLPointer *listPt, SLLData data)
{
    SLLPointer* new_node;
    SLLPointer* prev = NULL; /* stores previous node when traversing */
    SLLPointer* auxPt = listPt; /* auxiliary pointer for list traversing */

    new_node = (SLLPointer*) malloc(sizeof(SLLPointer));
    new_node->data = data;

    /* Searches position for insertion: */
    while (auxPt && auxPt->data.id < data.id)
    {
        prev = auxPt;
        auxPt = auxPt->next;
    }

    /* Inserts node: */
    new_node->next = auxPt;

    /* Chains node accordingly: */
    if (prev == NULL) /* node was inserted in the first position */
        listPt = new_node;
    else
        prev->next = new_node; /* node was inserted either in the middle or at the end */

    return listPt; /*  returns updated list */
}

SLLPointer *removeNodeByID(SLLPointer *listPt, int id)
{
    SLLPointer *auxPt = listPt; /* auxiliary pointer for list traversing */
    SLLPointer* prev = NULL; /* auxiliary pointer for previous pointer to auxPt */

    while (auxPt && auxPt->data.id != id){
        prev = auxPt;
        auxPt = auxPt->next;
    }

    if (auxPt == NULL){
        printf("\n\t\t\tERROR! Given ID not found in list.\n");
        return listPt;
    }

    if (prev == NULL)
        listPt = auxPt->next;
    else
        prev->next = auxPt->next;

    return listPt;
}

void getData(SLLData *data)
{
    char input[BUFFER];

    printf("\n --> Enter node data:\n");

    printf("\n\tID: ");
    fgets(input, BUFFER, stdin);
    sscanf(input, "%d", &data->id); /* transfers data to 'id' attribute */
    fflush(stdin);

    printf("\tContent: ");
    fgets(input, BUFFER, stdin);
    strcpy(data->content, input); /* transfers data to 'content' attribute */
    fflush(stdin);

    return;
}

void printList(SLLPointer *listPt)
{
    SLLPointer *auxPt; /* auxiliary pointer for list traversing */

    /* If the list is empty: */
    if (listPt == NULL){
        printf("\n\t\t\t The list is empty.\n");
        return;
    }

    /* Else, traverses the list and prints each node data: */
    printf("\n\t\t\t ------------ ORDERED LIST DATA ------------\n");
    for (auxPt = listPt; auxPt; auxPt = auxPt->next){
        printf("\n\t\t\t |ID: %hu", auxPt->data.id);
        printf("\n\t\t\t |Content: %s", auxPt->data.content);
    }

    return;

}

SLLPointer *destroyList(SLLPointer *listPt)
{
    SLLPointer *auxPt; /* auxiliary pointer for list traversing */

    /* Traverses the list and frees allocated memory: */
    while (listPt != NULL)
    {
        auxPt = listPt;
        listPt = listPt->next;
        free(auxPt);
    }

    free(listPt);

    return NULL;
}
