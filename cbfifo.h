/**
* @file cbfifo.h
* @brief Header file for cbfifo.c source file (implementation functions)
*
* This source file consists of function prototypes of functions used in cbfifo.c
* @author Shreyan Dhananjayan (shdh7090@colorado.edu)
* @date September 13,2021
* @Tools used Gcc compiler (Use cygwin incase of Windows)
* @References, citations 
* 
* 1) https://www.geeksforgeeks.org/queue-linked-list-implementation/
* 2) https://www.youtube.com/watch?v=okr-XE8yTO8&t=1s
* 3) Howdy's Presentation 4 at 2nd September,2021 
*/

#ifndef _CBFIFO_H_
#define _CBFIFO_H_

#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<stdbool.h> // for size_t

/*Function Prototypes*/

/**
* @brief To check if queue is full 
*
*
* @return 1 if queue is full or 0 if queue is not full
*/
bool checkQueueIsFull();

/**
* @brief To check if queue is empty
*
* @return 1 if queue is empty or 0 if queue is not empty
*/
bool checkQueueIsEmpty();


/*
 * Enqueues data onto the FIFO, up to the limit of the available FIFO
 * capacity.
 *
 * Parameters:
 *   buf      Pointer to the data
 *   nbyte    Max number of bytes to enqueue
 * 
 * Returns:
 *   The number of bytes actually enqueued, which could be 0. In case
 * of an error, returns -1.
 */
size_t cbfifo_enqueue(void *buf, size_t nbyte);


/*
 * Attempts to remove ("dequeue") up to nbyte bytes of data from the
 * FIFO. Removed data will be copied into the buffer pointed to by buf.
 *
 * Parameters:
 *   buf      Destination for the dequeued data
 *   nbyte    Bytes of data requested
 * 
 * Returns:
 *   The number of bytes actually copied, which will be between 0 and
 * nbyte. 
 * 
 * To further explain the behavior: If the FIFO's current length is 24
 * bytes, and the caller requests 30 bytes, cbfifo_dequeue should
 * return the 24 bytes it has, and the new FIFO length will be 0. If
 * the FIFO is empty (current length is 0 bytes), a request to dequeue
 * any number of bytes will result in a return of 0 from
 * cbfifo_dequeue.
 */
size_t cbfifo_dequeue(void *buf, size_t nbyte);


/*
 * Returns the number of bytes currently on the FIFO. 
 *
 * Parameters:
 *   none
 * 
 * Returns:
 *   Number of bytes currently available to be dequeued from the FIFO
 */
size_t cbfifo_length();


/*
 * Returns the FIFO's capacity
 *
 * Parameters:
 *   none
 * 
 * Returns:
 *   The capacity, in bytes, for the FIFO
 */
size_t cbfifo_capacity();

/**
* @brief Display memory values starting from a address location 
*
* With the passed address as offset, the functions display hex 
* values stored in memory location from the offset address
*
* @param str  - The values will be stored in a string
* @param size - The size of the string
* @param *loc - The starting address from where hex values will be printed
* @param nbytes -  Total lenghth in byted of the input buffer
*
* @return string consisting of the offset location and the values
*/

char *hexdump(char *str, size_t size, const void *loc, size_t nbytes);
#endif // _CBFIFO_H_
