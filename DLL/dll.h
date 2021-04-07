#ifndef DLL_H_INCLUDED
#define DLL_H_INCLUDED

#define MAX_CONTENT 40
#define BUFFER 256

/** ---------- DATA DEFINITIONS ----------*/

struct DLL_Data{
    int id;
    char content[MAX_CONTENT];
};

typedef struct DLL_Data DLLData;

struct DLL_Pointer{
    DLLData info;
    struct DLL_Pointer* previous;
    struct DLL_Pointer* next;
};

typedef struct DLL_Pointer DLLPointer;

/** ---------- DATA OPERATIONS ----------*/

/* DLL = Doubly Linked List*/

DLLPointer *initializeList(void);
/* Initializes a DLL. */

DLLPointer *insertNodeInOrder(DLLPointer *listPt, DLLData data);
/* Inserts a node in the DLL pointed by listPt, in ascending order of 'id' attribute.
   The function returns the updated list.*/

DLLPointer *removeNodeByID(DLLPointer *listPt, int id);
/* Removes a node from the DLL pointed by listPt, based on its 'id' attribute and returns
the updated list.*/

void printList(DLLPointer *listPt);
/* Prints all nodes in the DLL pointed by 'listPt', in its original logical order. */

void printListReverse(DLLPointer *listPt);
/* Prints all nodes in the DLL pointed by 'listPt', in its reversed logical order. */

void getData(DLLData *data);
/* Gets data from the user for a DLL node. */

DLLPointer *destroyList(DLLPointer *listPt);
/* Frees all the memory allocated for the DLL. */

#endif
