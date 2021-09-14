/**
* @file cbfifo.c
* @brief Source file consists of implementation functions of cbfifo
*
* @author Shreyan Dhananjayan (shdh7090@colorado.edu)
* @date September 13,2021
* @Tools used Gcc compiler (Use cygwin incase of Windows)
* @References, citations 
* 
* 1) https://www.youtube.com/watch?v=okr-XE8yTO8&t=1s
* To understand the concept circular buffer
* 2) Howdy's Presentation 4 at 2nd September,2021
* To understand a approach of finding length, front, rear pointer for a queue
*/

#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<stdbool.h>
#include"cbfifo.h"

#define MAX_SIZE (128)
#define ZERO (0)

#define NOT_SET (0)
#define SET (1)

int front=0;	/* Variable to point the head of the queue */
int rear=0;		/* Variable to point the tail of the queue */
bool queueFull=0;/* Variable to know the queue status Full/Not full */
bool queueEmpty=0;/* Variable to know the queue status Empty/Not Empty */
uint8_t data[MAX_SIZE];/* Statically initialized array (queue) */

/*Functions documentation is available in cbfifo.h header file*/

bool checkQueueIsEmpty()
{
	if((rear==front) && (queueFull==NOT_SET) /*Rear==Front is occuring for both, queue full*/
		&& (queueEmpty == SET)) 		    /*and empty, differentiating them using flags*/
																
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool checkQueueIsFull()
{
	if((queueFull == SET) && (rear==front))/*Rear==Front is occuring for both, queue full*/
	{									/*and empty, differentiating them using flags	*/
		return true;
	}
	else
	{
		return false;
	}
}

size_t cbfifo_capacity()
{
	return MAX_SIZE; /*Returning 128 as it is a statically allocated queue*/
}

size_t cbfifo_length()
{
	if(checkQueueIsFull()) /*Condition to calculate length when queue is empty*/
	{
		return MAX_SIZE;
	}
	return ((rear-front) & (MAX_SIZE - 1));
}

size_t cbfifo_dequeue(void *buf, size_t nbyte)
{
	int i=0; /*local variable to increment till n byte */
	int j=0; /*local variable to increment buffer index 
				where dequeued data is stored */
	if(nbyte == ZERO) /*when no of bytes to be dequeued is zero */
	{
		return 0;
	}
	for(;i<nbyte;i++,j++)
	{
		if(checkQueueIsEmpty() == true) /*Dequeueing a empty data 
										buffer result in zero*/
		{
			return 0;
		}
		if(checkQueueIsEmpty() != true)/*Dequeue and copy the data to buffer*/
		{
			*((uint8_t *)buf+j)= data[front];
			data[front]='\0';
			front=(front+1) & (MAX_SIZE-1);	
			if(rear==front)	/*When Queue is empty*/ 
			{
				queueEmpty=1;
				queueFull=0;
				return i+1;
			}
		}
	}
	return i;
}

size_t cbfifo_enqueue(void *buf, size_t nbyte)
{
	int i=0; /*local variable to increment till n byte*/
	uint8_t *tempdata= (uint8_t *)buf;
	if(buf == NULL) /*When enqueueing a null value */
	{
		return -1;
	}
	if(nbyte == ZERO) /*when no of byted to be enqueued is zero*/
	{
		return 0;
	}
	for(;i<nbyte;i++)
	{	
			
		if(checkQueueIsFull()==true)
		{
			return 0;				/*Enqueued bytes is zero, as buffer is full*/
		}
		if(checkQueueIsFull() != true)
		{
			data[rear]=*(tempdata+i);
			rear=(rear+1) & (MAX_SIZE-1);
			if(rear==front)		/*When queue is full*/
			{
				queueFull=1;
				return i+1;
			}
		}	
	}
	return i;
}


