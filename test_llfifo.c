/**
* @file test_llfifo.c
* @brief Source file consists of test function of llfifo and
* return the status of text function execution to the main function
* @author Shreyan Dhananjayan (shdh7090@colorado.edu)
* @date September 13,2021
* @Tools used Gcc compiler (Use cygwin incase of Windows)
*/

/*
* Scenarios checked:
* S0: Creating an empty queue and check if data is enqueued through malloc
* S1: Checking multiple instances
* S2: Enqueue process and length,capacity value when length<=capacity
* S3: Enqueue process and length,capacity value when length>capacity
* S4: Check dequeue process and value of length,capacity
* S5: Dequeue till buffer empty and adding node
* S6: Check all empty nodes are used; Post Dequeue, enqueue length>capacity
* S7: Check negative value for capacity
* S8: Trying to enqueue NULL
* S9: Dequeue before enqueue
*/

#include"assert.h"
#include"test_llfifo.h"
#include<string.h>

/*Functions documentation is available in test_llfifo.h header file*/

bool test_llfifo()
{
	int length=0;
	void *data;
	int capacity=0;
	
	printf("\n Scenarios to be checked\n");
	printf("\nS0: Creating an empty queue and check if data is enqueued through malloc");
	printf("\nS1:Checking multiple instances");
	printf("\nS2:Enqueue process and length,capacity value when length<=capacity");
	printf("\nS3:Enqueue process and length,capacity value when length>capacity");
	printf("\nS4:Check dequeue process and value of length,capacity");
	printf("\nS5:Dequeue till buffer empty and adding node");
	printf("\nS6:Check all empty nodes are used; Post Dequeue, enqueue length>capacity");
	printf("\nS7: Check negative value for capacity");
	printf("\nS8:Trying to enqueue NULL");
	printf("\nS9:Dequeue before enqueue\n");
	
    /*S0: Creating an empty queue and check if data is enqueued through malloc*/
    
    printf("\nS0: Creating an empty queue and check if data is enqueued through malloc");
	llfifo_t *firstfifo1=llfifo_create(0);
	length=llfifo_enqueue(firstfifo1,"hi");
	length=llfifo_enqueue(firstfifo1,"bye");
	length=llfifo_enqueue(firstfifo1,"node");
	capacity=llfifo_capacity(firstfifo1);
	printf("\nExpected Enqueued Length:%d Capacity:%d",length,capacity);
	printf("\nActual Enqueued length:%d Capacity:%d",length,capacity);
	if((length == 3) && (capacity == 3))
	{
		printf("\n Test Case passed\n");
	}
	else
	{
		printf("\n Test case failed");
		return 0;
	}
    
    /*S1: Checking multiple instances*/
	/*S2: Check enqueue process and value of length 
	,capacity when length<=capacity*/
	printf("\nS1:Checking Multiple instances");
	printf("\nS2:Enqueue process and length,capacity value when length<=capacity");
	llfifo_t *firstfifo=llfifo_create(5);
	length=llfifo_enqueue(firstfifo,"Sleepy");
	length=llfifo_enqueue(firstfifo, "Shreyan");
	capacity=llfifo_capacity(firstfifo);
	printf("\nExpected Enqueued Length:%d Capacity:%d",length,capacity);
	printf("\nActual Enqueued Length:%d Capacity:%d",length,capacity);
	if(length == 2 && capacity == 5)
	{
		printf("\n Test Case passed\n");
	}
	else
	{
		printf("\n Test case failed");
		return 0;
	}
	
	/*S3: Check enqueue process and value of length 
	,capacity when length>capacity*/
	printf("\nS3:Enqueue process and length,capacity value when length>capacity");
	length=llfifo_enqueue(firstfifo, "Happy"); 
	length=llfifo_enqueue(firstfifo, "Bashful");
	length=llfifo_enqueue(firstfifo, "Grumpy");
	length=llfifo_enqueue(firstfifo, "Prabhu");
	capacity=llfifo_capacity(firstfifo);
	printf("\nExpected Enqueued Length:%d Capacity:%d",length,capacity);
	printf("\nActual Enqueued Length:%d Capacity:%d",length,capacity);
	if(length == 6 && capacity == 6)
	{
		printf("\n Test Case passed\n");
	}
	else
	{
		printf("\n Test case failed");
		return 0;
	}
	
	/*S4: Check dequeue process and value of length,capacity */
	printf("\nS4:Check dequeue process and value of length,capacity");
	data=llfifo_dequeue(firstfifo);
	length=llfifo_length(firstfifo);
	capacity=llfifo_capacity(firstfifo);
	printf("\nExpected Dequeued data:Sleepy,Length:%d Capacity:%d",length,capacity);
	printf("\nActual Dequeued data:%s,Length:%d Capacity:%d",(char *)data,length,capacity);
	if((strcmp(data,"Sleepy")==0) && (capacity == 6) && (length==5))
	{
		printf("\n Test Case passed\n");
	}
	else
	{
		printf("\n Test case failed");
		return 0;
	}
	
	/*S5 Dequeue till buffer empty and adding node*/
	int queueLength=0;
	printf("\nS5:Check dequeue process and value of length,capacity");
	data=llfifo_dequeue(firstfifo);
	data=llfifo_dequeue(firstfifo);
	data=llfifo_dequeue(firstfifo);
	data=llfifo_dequeue(firstfifo);
	data=llfifo_dequeue(firstfifo);
	length=llfifo_length(firstfifo);
	capacity=llfifo_capacity(firstfifo);
	queueLength=llfifo_enqueue(firstfifo, "queue");
	queueLength=llfifo_enqueue(firstfifo, "stack");
	printf("\nL after Dequeue:%d Capacity:%d,L after Enqueue:%d",length,capacity,queueLength);
	printf("\nL after Dequeue :%d Capacity:%d,L after Enqueue:%d",length,capacity,queueLength);
	if((capacity == 6) && (length==0) && (queueLength == 2))
	{
		printf("\n Test Case passed\n");
	}
	else
	{
		printf("\n Test case failed");
		return 0;
	}
	
	/*S6: Check all empty nodes are used; Post Dequeue, enqueue length>capacity*/
	printf("\nCheck all empty nodes are used; Post Dequeue, enqueue length>capacity");
	queueLength=llfifo_enqueue(firstfifo, "Pass");
	queueLength=llfifo_enqueue(firstfifo, "Fail");
	queueLength=llfifo_enqueue(firstfifo, "Embedded");
	queueLength=llfifo_enqueue(firstfifo, "system");
	queueLength=llfifo_enqueue(firstfifo, "Digital");
	capacity=llfifo_capacity(firstfifo);
	printf("\nCapacity:%d,L after Enqueue:%d",capacity,queueLength);
	printf("\nCapacity:%d,L after Enqueue:%d",capacity,queueLength);
	if(queueLength == 7 )
	{
		printf("\n Test Case passed\n");
	}
	else
	{
		printf("\n Test case failed");
		return 0;
	}
	
	/*S7: Check negative value for capacity*/
	printf("\nS7: Check negative value for capacity");
	llfifo_t *firstfifo2=llfifo_create(-1);
	printf("\nExpected Output: NULL");
	printf("\nActual Output: NULL");
	if(firstfifo2 == NULL)
	{
		printf("\n Test Case passed\n");
	}
	else
	{
		printf("\n Test case failed");
		return 0;
	}
	
	/*S8:Trying to enqueue NULL*/
	int *enqueueData=NULL;
	printf("\nS8:Trying to enqueue NULL");
	queueLength=llfifo_enqueue(firstfifo,enqueueData);
	printf("\nExpected Output: %d",queueLength);
	printf("\nActual Output: %d",queueLength);
	if(queueLength == -1)
	{
		printf("\n Test Case passed\n");
	}
	else
	{
		printf("\n Test case failed");
		return 0;
	}
	
	/*S9:Dequeue before enqueue*/
	printf("\nS9:Dequeue before enqueue");
	llfifo_t *firstfifo3=llfifo_create(3);
	data=llfifo_dequeue(firstfifo3);
	if(data == NULL)
	{
		printf("\n Test Case passed\n");
	}
	else
	{
		printf("\n Test case failed");
		return 0;
	}
	
	llfifo_destroy(firstfifo);
	return 1; /*All test cases passes*/
}



