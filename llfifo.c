/**
* @file llfifo.h
* @brief Source file for implementing FIFO through linked list
*
* This source file consists of function definitions to implement
* a dynamically growing FIFO
* @author Shreyan Dhananjayan (shdh7090@colorado.edu)
* @date September 13,2021
* @Tools used Gcc compiler (Use cygwin incase of Windows)
* @Reference, Citations
* 1) https://www.geeksforgeeks.org/queue-linked-list-implementation/
* Line 28 - 33 creating structures to create multiple instances
* 2) Howdy's Presentation 4 at 2nd September,2021
* To unerstand the malloc and structure syntax
*/


#include<stdio.h>
#include<stdlib.h>
#include"llfifo.h"


typedef struct node /*A structure to access the nodes of every fifo instance*/
{
	void *data;
	struct node* next;
}node;

typedef struct llfifo_s/*A Strcuture to access multiple instances of a fifo object */
{
	node* front;
	node* rear;
	int length;
}llfifo_t;


llfifo_t *llfifo_create(int capacity)
{

	llfifo_t *firstfifo = (llfifo_t *) malloc(sizeof(llfifo_t));
	if(capacity<0)	/*Capacity cannot be a negative value*/
	{
		return NULL;	
	}
	if(capacity==0)				/*Capacity=zero return fifo object
								to enqueue element through malloc*/
	{
		firstfifo->front=NULL;
		firstfifo->rear=NULL;
		firstfifo->length=0;
		return firstfifo;
	}
	firstfifo->front=NULL;
	firstfifo->rear=NULL;
	firstfifo->length=0;
	struct node *headNode=NULL, *currentNode=NULL, *tempNode=NULL;
	int i=0;					/*Local variable to increment till capacity*/
	for (;i<capacity;i++)		/*Creating nodes of capacity size*/
	{
		currentNode= (node *)malloc(sizeof(node)); 
		if(i==0)
		{
			headNode=tempNode=currentNode;
		}
		else
		{
			tempNode->next=currentNode;
			tempNode=currentNode;	
		}
	}
	tempNode->next=NULL;
	tempNode=headNode; 
	while (tempNode != NULL)		/*Traversing through all nodes and 
									assign head and tail pointer for queue*/
   	{
        tempNode = tempNode->next;
    }
	firstfifo->front=headNode;
	firstfifo->rear=currentNode;
	firstfifo->length=0;
	
	return firstfifo;
	
}

int llfifo_enqueue(llfifo_t *fifo, void *element)
{
int i=1;						/*Variable to traverse the nodes having data*/
int queueIndex=(fifo->length)+1; /*QueueIndex to point to the node wwhere a 
								valid data is enqueued, different from rear ptr*/
node *tempNode=fifo->front;
if(element == NULL)				/*Error case: Enqueueing a null value*/
{
	return -1;
}
if(fifo->front == NULL)			/*If case when enqueue is done with create(0)*/
{
	tempNode = (node *) malloc(sizeof(node));
	tempNode->next=NULL;
	tempNode->data=element;
	fifo->front=tempNode;		/*Assigning front and rear pointers to mark the
								boundaries of queue*/
	fifo->rear=tempNode;
	++(fifo->length);
	return fifo->length;
	
}
if(fifo->length == 0)			/*If case when create function is called for a set 
								number of nodes and front is not pointing to NULL*/
{
	tempNode->data=element;
	++(fifo->length);
	return fifo->length;
}

for(;((i< queueIndex) && (tempNode->next != NULL));i++)
{
	tempNode=tempNode->next; /*Traversing through the nodes to find the node
							where a valid data is enqueued*/
}
if(i == queueIndex)			/*The next node after which the last valid data is 
							enqueued and the element will be enqueued*/
{
	tempNode->data=element;
	++(fifo->length);
	return fifo->length;
}

if(tempNode->next == NULL) /*If case when length > capacity, creating a new node
							through malloc*/
{
	node* tempNode2 = (node *)malloc(sizeof(node));
	tempNode->next=tempNode2;
	tempNode=tempNode->next;
	tempNode->data=element;
	tempNode2->next=NULL;
	++(fifo->length);
	fifo->rear=tempNode;
	return fifo->length;
}
return fifo->length;             
}

void *llfifo_dequeue(llfifo_t *fifo)
{
if(fifo->length <= 0)			/*Error case when dequeue command with no elements
								 in the buffer*/
{
	return NULL;
}
node *tempNode=fifo->front;
void *buffer;
buffer=tempNode->data;
tempNode->data=NULL;
fifo->rear->next=tempNode;
fifo->rear=fifo->front;		/*The rear pointer is adjusted to point to the last dequeued
							byte which is stored at the end of nodes*/
fifo->front=fifo->front->next;
tempNode->next=NULL;
--(fifo->length);
return buffer;

}

int llfifo_length(llfifo_t *fifo)
{
	return fifo->length;
}

int llfifo_capacity(llfifo_t *fifo)
{
	int count=0;
	node *tempNode=fifo->front;
	while(tempNode != NULL)		/*Traversing the whole queue and increment a variable
								till null is reached to give capacity*/
	{
		tempNode=tempNode->next;
		count ++;
	}
	return count;
}

void llfifo_destroy(llfifo_t *fifo)
{

	node *tempNode;
	while(fifo->front !=NULL)		/*Traversing through the whole queue till null
									is reached and freeing up each node*/
	{
		tempNode=fifo->front;
		fifo->front=fifo->front->next;
		free(tempNode);
	}
	free(fifo);					/*Freeing up the fifo instance*/
	fifo=NULL;
}

