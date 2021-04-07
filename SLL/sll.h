#ifndef DEFINITIONS_H_INCLUDED
#define DEFINITIONS_H_INCLUDED

#define MAX_CONTENT 40
#define BUFFER 256

/** -------------- DATA DEFINITIONS --------------*/

struct SLL_Data{
    int id;
    char content[MAX_CONTENT];
};

typedef struct SLL_Data SLLData;    //

struct SLL_Pointer{
    SLLData data;
    struct SLL_Pointer *next;
};

typedef struct SLL_Pointer SLLPointer;

/** -------------- DATA OPERATIONS --------------*/

/* SLL = Simply Linked List */

SLLPointer *initializeList(void);
/* Initializes a SLL by returning NULL to the calling pointer. */

SLLPointer *insertNodeInOrder(SLLPointer *listPt, SLLData node_data);
/* Inserts a node in the SLL pointed by 'listPt', in ascending order of 'id' attribute.
   The function returns the updated list. */

SLLPointer *removeNodeByID(SLLPointer *listPt, int id);
/* Removes a node from the SLL pointed by 'listPt' based on its 'id' attribute and returns
the updated list. */

void getData(SLLData *node_data);
/* Gets data from the user for a SLL node. */

void printList(SLLPointer *listPt);
/* Prints all nodes in the SLL pointed by 'listPt'. */

SLLPointer *destroyList(SLLPointer *listPt);
/* Frees all the memory allocated for the SLL. */

#endif


