#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dll.h"

DLLPointer *initializeList(void)
{
    return NULL;
}

DLLPointer *insertNodeInOrder(DLLPointer *listPt, DLLData data)
{
    DLLPointer *auxPt = listPt;
    DLLPointer *new_node;

    new_node = (DLLPointer*) malloc(sizeof(DLLPointer));
    new_node->info = data;

    /* Insertion at beginning: */
    if (listPt == NULL || listPt->info.id > new_node->info.id){
        new_node->next = listPt;
        new_node->previous = NULL;
        if (listPt) /* if list is not empty: */
            listPt->previous = new_node;
        return new_node;
    }

    /* Insertion in the "middle" or at the end: */
    while ((auxPt->next != NULL) && (auxPt->next->info.id < data.id))
        auxPt = auxPt->next;

    /* Chaining of new_node: */
    new_node->previous = auxPt;
    new_node->next = auxPt->next;
    auxPt->next = new_node;

    if (new_node->next)
        new_node->next->previous = new_node;

    return listPt;
}

DLLPointer *removeNodeByID(DLLPointer *listPt, int id)
{
    DLLPointer *auxPt = listPt;

    /* If listPt is empty: */
    if (auxPt == NULL)
        return NULL;

    /* Traverses DLL in search for node with specified ID.*/
    while (auxPt){
        if (auxPt->info.id == id){
            if (auxPt == listPt){ /* If it's the first node : */
                listPt = listPt->next;
            } else if (auxPt->next == NULL){ /* Else if it's the last node: */
                auxPt = auxPt->previous;
                auxPt->next = NULL;
            } else {
                auxPt->previous->next = auxPt->next;
                auxPt->next->previous = auxPt->previous;
            }
        }
        auxPt = auxPt->next;
    }

    return listPt;
}

void printList(DLLPointer *listPt)
{
    DLLPointer *auxPt = listPt;

    if (auxPt == NULL)
        printf("\n\t The list is empty.\n");
    else{
        printf("\n\t\t ----- ORDERED LIST DATA ----- \n");
        while (auxPt){
            printf("\n\t\t| ID: %d", auxPt->info.id);
            printf("\n\t\t| CONTENT: %s", auxPt->info.content);
            auxPt = auxPt->next;
        }
    }

}

void printListReverse(DLLPointer* listPt)
{
    DLLPointer *auxPt = listPt;

    if (auxPt == NULL)
        printf("\n\tLista esta vazia.\n");
    else{
        printf("\n\t\t ----- DADOS DA LISTA EM ORDEM REVERSA ----- \n");

        /* Traverses all DLL: */
        while (auxPt->next)
            auxPt = auxPt->next;

        /* Traverses all DLL backwards and prints each node data: */
        while (auxPt)
        {
            printf("\n\t\t| ID: %d", auxPt->info.id);
            printf("\n\t\t| CONTENT: %s", auxPt->info.content);
            auxPt = auxPt->previous;
        }
    }

    return;
}

void getData(DLLData *data)
{
    char input[BUFFER];

    printf("\n --> Enter node data:\n");

    printf("\n\t ID: ");
    fgets(input, BUFFER, stdin);
    sscanf(input, "%d", &data->id);
    fflush(stdin);

    printf("\t Content: ");
    fgets(input, BUFFER, stdin);
    strcpy(data->content, input);
    fflush(stdin);

}

DLLPointer *destroyList(DLLPointer *listPt)
{
    DLLPointer *auxPt;

    while(listPt != NULL)
    {
        auxPt = listPt;
        listPt = listPt->next;
        free(auxPt);
    }

    free(listPt);

    printf("\n\t The list has been destroyed.\n");
    return NULL;
}



