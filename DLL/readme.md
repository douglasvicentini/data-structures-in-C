## DOUBLY LINKED LIST (DLL)

A DLL consists of a list in which each node contains 2 pointers:
* __previous__: points to the previous node in the DLL
* __next__: points to the next node in the DLL

Here, we'll be sorting the DLL in ascending order based on an '__id__' integer number attribute contained in each node. 

As an example:

Let dll be a Doubly Linked List with 3 nodes:
* __n1__: 'id' = 1;
* __n2__: 'id' = 2;
* __n3__: 'id' = 3.

> 	n1->previous will point to NULL, as it's the first node;
	n1->next will point to n2.

>	n2->previous will point to n1;
	n2->next will point to n3.

>	n3->previous will point to n2;
	n3->next will point to NULL, as it's the last node.