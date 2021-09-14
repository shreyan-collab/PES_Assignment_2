# PES_Assignment_2
Code for Assignment 2 for PES, ECEN 5813, Fall 21 

Tools used: Gcc Compiler and Cygwin (installed in windows) 
Download: https://www.cygwin.com/ 
Command to run code: 1) gcc main.c -Wall -Werror 2) ./a.exe

The repository consists of 
1) Source files - main.c, test_llfifo.c, llfifo.c, test_llfifo.c, llfifo.c
2) Header files - test_llfifo.h, llfifo.h, test_llfifo.h, llfifo.h
3) And a make file

The main. c files call the test functions implemented in test_cbfifo.c and test_llfifo.c and return 1/0 based on the test function results
The test_cbfifo.c and test_llfifo.c calls their respective source files with different input scenarios. Returns 1 if all cases pass or return 0

The llfifo.c implements a dynamically growing FIFO implementation through a linked list
The llfifo is is implemented through create(), enqueue(), dequeue(), destroy(), length() and capacity() functions

The cbfifo.c implements a Fixed FIFO implementation through a 128 byte circular buffer(array)
The cbfifo is is implemented through enqueue(), dequeue() length() and capacity() functions

Command to Run the make file 

Enter the following commands in a terminal to run the make file
1) make 
2) ./hellomake.exe (hellomake is the name of the application I have given)
