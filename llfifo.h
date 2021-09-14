/**
* @file llfifo.h
* @brief Header file for llfifo.c source file
*
* This Header file consists of function prototypes used in llfifo.c
* a dynamically growing FIFO
* @author Shreyan Dhananjayan (shdh7090@colorado.edu)
* @date September 13,2021
* @Tools used Gcc compiler (Use cygwin incase of Windows)
*/


#ifndef _LLFIFO_H_
#define _LLFIFO_H_

#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<stdbool.h>

 // WRITE FUNCTION DEFINITION
/* 
 * The llfifo's main data structure. 
 *
 * Defined here as an incomplete type, in order to hide the
 * implementation from the user. 
 */
typedef struct llfifo_s llfifo_t;


/*
 * Creates and initializes the FIFO
 *
 * Parameters:
 *   capacity  the initial size of the fifo, in number of elements
 * 
 * Returns: A pointer to a newly-created llfifo_t instance, or NULL in
 *   case of an error.
 */
llfifo_t *llfifo_create(int capacity);


/*
 * Enqueues an element onto the FIFO, growing the FIFO by adding
 * additional elements, if necessary
 *
 * Parameters:
 *   fifo    The fifo in question
 *   element The element to enqueue, which cannot be NULL
 * 
 * Returns:
 *   The new length of the FIFO on success, -1 on failure. It is an error to attempt 
 * to enqueue the NULL pointer.
 */
int llfifo_enqueue(llfifo_t *fifo, void *element);


/*
 * Removes ("dequeues") an element from the FIFO, and returns it
 *
 * Parameters:
 *   fifo  The fifo in question
 * 
 * Returns:
 *   The dequeued element, or NULL if the FIFO was empty
 */
void *llfifo_dequeue(llfifo_t *fifo);


/*
 * Returns the number of elements currently on the FIFO. 
 *
 * Parameters:
 *   fifo  The fifo in question
 * 
 * Returns:
 *   The number of elements currently on the FIFO
 */
int llfifo_length(llfifo_t *fifo);


/*
 * Returns the FIFO's current capacity
 *
 * Parameters:
 *   fifo  The fifo in question
 * 
 * Returns:
 *   The current capacity, in number of elements, for the FIFO
 */
int llfifo_capacity(llfifo_t *fifo);


/*
 * Teardown function: Frees all dynamically allocated
 * memory. After calling this function, the fifo should not be used
 * again!
 *
 * Parameters:
 *   fifo  The fifo in question
 * 
 * Returns: none -1)
 */
void llfifo_destroy(llfifo_t *fifo);

#endif // _LLFIFO_H_
