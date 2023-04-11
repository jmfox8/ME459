#include <stdlib.h>
#include <stdio.h>


#include "dllist.h"

// Prints all elements of a DLL exactly once, beginning with head,
// in forward order
void PrintDLLForward(ListNode* head)
{ 
	ListNode *curr = head; // Idenfity the current node as the input head node
	ListNode *start = head; //Identify the input head node as the starting node
	int curval = curr -> data; //Initialize and print value stored in data of the current node 
	printf("%i\n",curval);
	curr = curr -> next; //move current node to be the node stored as next in the input node
	while (curr != start) //loop through printing the values of the nodes and setting curr to be the next node until the current node is equal to the input head node, then exit
	{
		curval = curr->data;
		printf("%i\n",curval);
		curr = curr -> next;
	}
}
// Prints all elements of a DLL exactly once, beginning with head,
// in reverse order
void PrintDLLReverse(ListNode* head)
{
	ListNode *curr = head; // Idenfity the current node as the input head node
	ListNode *start = head;  //Identify the input head node as the starting node
	int curval = curr -> data;  //Initialize and print value stored in data of the current node
	printf("%i\n",curval);
	curr = curr -> prev;  //move current node to be the node stored as prev in the input node
	while (curr != start)  //loop through printing the values of the nodes and setting curr to be the prev node until the current node is equal to the input head node, then exit
	{
		curval = curr->data;
		printf("%i\n",curval);
		curr = curr -> prev;
	}
}
