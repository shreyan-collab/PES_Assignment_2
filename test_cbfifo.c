/**
* @file test_cbfifo.c
* @brief Source file consists of test function of cbfifo
*
* @author Shreyan Dhananjayan (shdh7090@colorado.edu)
* @date September 13,2021
* @Tools used Gcc compiler (Use cygwin incase of Windows)
*/


/*
* Scenarios checked:
* S0: Dequeue when empty
* S1: Checking when nbytes (Argument 2) is more than the actual buffer length to be enqueued
* S2: Checking enqueue is not done once buffer is full
* S3: Dequeueing more than 128 bytes at a time 
* S4: Dequeueing once buffer is empty
* S5: Trying to enqueue NULL 
* S6: Checking enqueue and dequeue when n bytes is zero
* S7: Checking queue is working for different data types
* S8: Trying to dequeue 30 bytes from 24 bytes buffer length
* S9: Rollover Enqueue 128 bytes ->dequeue 7 bytes ->Enqueue 7 bytes
*/


#include"test_cbfifo.h"

/*Functions documentation is available in test_cbfifo.h header file*/

/* Macros */

#define ZERO 0
#define ARRAY_SIZE_1 (128)
#define ARRAY_SIZE_2 (1024) //Used for dump function
bool test_cbfifo()
{

	int size=0;  /* Size Enqueued or dequeued */
	int length=0;/* Length of queue */
	
	uint8_t tempbuf[ARRAY_SIZE_1]; /* Used to copy queue elements */
	char tempb[ARRAY_SIZE_2];  /* Used as an input to dump function */
	
	int b0=2147483647;
	int c0=0;
	float d=32.66;
	float e=0;
	
	printf("\n Scenarios to be checked\n");
	printf("\n S0: Dequeueing before enqueuing");
	printf("\n S1: When bytes to enqueued is more than actual size");
	printf("\n S2: Trying to enqueue once buffer is full & check length");
	printf("\n S3: Trying to dequeue 128 bytes");
	printf("\n S4: Trying to dequeue once buffer is empty and check length");
	printf("\n S5: Trying to enqueue NULL value");
	printf("\n S6 Checking enqueue and dequeue when n bytes is zero");
	printf("\n S7 Checking queue and dequeue is working for different data types");
	printf("\n S8 Trying to dequeue 30 bytes when length is 24 bytes");
	printf("\n S9 Rollover Enqueue 128 bytes ->dequeue 7 bytes ->Enqueue 7 bytes\n");
	
	/*S0: Dequeue when empty */
	
	printf("\n S0: Dequeueing before enqueuing");
	size=cbfifo_dequeue(tempbuf,0);
	length=cbfifo_length();
	printf("\nExpected dequeued size :%d Expected fifo length:%d",size, length);
	printf("\nActual dequeued size :%d Actual fifo length:%d",size, length);
	if(size == ZERO && length == ZERO)
	{
		printf("\n Test Case passed\n");
	}
	else
	{
		printf("\n Test case failed");
		return 0;
	}

	/* S1: Checking when nbytes (Argument 2) is more than 
	the actual buffer length to be enqueued */
	
	printf("\n S1: When bytes to enqueued is more than actual size");
	size=cbfifo_enqueue("hitler",20); //nbytes more than the actual size required
	length=cbfifo_length();
	printf("\nInput: Hitler, Expected enqueued size :%d Expected fifo length:%d",size, length);
	printf("\nInput: Hitler, Actual enqueued size :%d Actual fifo length:%d",size, length);
	if(size == 20 && length ==20)
	{
		printf("\n Test Case passed\n");
	}
	else
	{
		printf("\n Test case failed");
		return 0;
	}
	size=cbfifo_dequeue(tempb,20);
	
	/*S2: Checking enqueue is not done once buffer is full */
	
	printf("\n S2: Trying to enqueue once buffer is full & check length");
	size=cbfifo_enqueue("embedded",128); 
	length=cbfifo_length();
	size=cbfifo_enqueue("em",2); 
	printf("\nExpected enqueued size :%d Expected fifo length:%d",size, length);
	printf("\nActual enqueued size :%d Actual fifo length:%d",size, length);
	if(size == ZERO && length ==128)
	{
		printf("\n Test Case passed\n");
	}
	else
	{
		printf("\n Test case failed");
		return 0;
	}
	
	/*S3: Dequeueing more than 128 bytes at a time */
	
	printf("\n S3: Trying to dequeue 128 bytes");
	size=cbfifo_dequeue(tempbuf,130); 
	length=cbfifo_length();
	printf("\nExpected dequeued size :%d Expected fifo length:%d",size, length);
	printf("\nActual  dequeued size :%d Actual fifo length:%d",size, length);
	if(size == 128 && length == ZERO)
	{
		printf("\n Test Case passed\n");
	}
	else
	{
		printf("\n Test case failed");
		return 0;
	}
	
	/* S4: Dequeueing once buffer is empty */
	
	printf("\n S4: Trying to dequeue once buffer is empty and check length");
	size=cbfifo_dequeue(tempbuf,128); 
	length=cbfifo_length();
	printf("\nExpected dequeued size :%d Expected fifo length:%d",size, length);
	printf("\nActual  dequeued size :%d Actual fifo length:%d",size, length);
	if(size == ZERO && length == ZERO)
	{
		printf("\n Test Case passed\n");
	}
	else
	{
		printf("\n Test case failed");
		return 0;
	}
	
	/*S5: Trying to enqueue NULL */
	int *h=NULL;
	printf("\n S5: Trying to enqueue NULL value");
	size=cbfifo_enqueue(h,1); 
	printf("\nExpected Result:%d",size);
	printf("\nActual Result:%d",size);
	if(size == -1)
	{
		printf("\n Test Case passed\n");
	}
	else
	{
		printf("\n Test case failed");
		return 0;
	}
	
	/*S6: Checking enqueue and dequeue when n bytes is zero */
	int size1=0,size2=0;
	printf("\n S6 Checking enqueue and dequeue when n bytes is zero");
	size=cbfifo_enqueue("hitler",6);
	size1=cbfifo_enqueue("Hi",0);
	size2=cbfifo_dequeue(tempbuf,0);
	printf("\nExpected Result:%d",size);
	printf("\nActual Result:%d",size);
	if((size1 == ZERO) && (size2 == ZERO))
	{
		printf("\n Test Case passed\n");
	}
	else
	{
		printf("\n Test case failed");
		return 0;
	}
	size=cbfifo_dequeue(tempbuf,128);
	
	/* S7: Checking queue is working for different data types */
	size=cbfifo_dequeue(tempbuf,128);
	printf("\n S7 Checking queue and dequeue is working for different data types");
	size1=cbfifo_enqueue(&d,sizeof(float));//check enqueue is happening for float integer
	size2=cbfifo_dequeue(&e,sizeof(float));//check dequeue is happening for float integer
	printf("\nFloat data type Expected Result:%.2f",d);
	printf("\nFloat data type Actual Result:%.2f",e);
	if(d == e)
	{
		printf("\n Test case passed");
	}
	else
	{
		printf("\n Test case Failed");
		return 0;
	}
	size1=cbfifo_enqueue(&b0,sizeof(int));
	size2=cbfifo_dequeue(&c0,sizeof(int));
	printf("\nInteger data type Expected Result:%d",b0);
	printf("\nInteger data type Actual Result:%d",c0);
	if(b0 == c0)
	{
		printf("\n Integer data type Test case passed\n");
	}
	else
	{
		printf("\n Integer data type Test case Failed");
		return 0;
	}
	
	/*S8: Trying to dequeue 30 bytes from 24 bytes buffer length */
	size=cbfifo_dequeue(tempbuf,128);
	printf("\n S8 Trying to dequeue 30 bytes when length is 24 bytes");
	size=cbfifo_enqueue("hello",24);
	size=cbfifo_dequeue(tempb,30);
	length=cbfifo_length();
	printf("\nExpected dequeued size :%d Expected fifo length:%d",size, length);
	printf("\nActual  dequeued size :%d Actual fifo length:%d",size, length);
	if(size == 24 && length == ZERO)
	{
		printf("\n Test case passed\n");
	}
	else
	{
		printf("\n Test case Failed");
		return 0;
	}
	
	/* S9: Rollover Enqueue 128 bytes ->dequeue 7 bytes ->Enqueue 7 bytes */
	size=cbfifo_dequeue(tempbuf,128);
	printf("\n S9 Rollover Enqueue 128 bytes ->dequeue 7 bytes ->Enqueue 7 bytes");
	size=cbfifo_enqueue("hello",128);
	size=cbfifo_dequeue(tempb,5);
	size=cbfifo_enqueue("hello",5);
	length=cbfifo_length();
	if(size == 5 && length == 128)
	{
		printf("\n Test case passed\n");
	}
	else
	{
		printf("\n Test case Failed");
		return 0;
	}
	
	printf("\n All test cases for cbfifo function is passed successfully \n");
	return 1;
}

