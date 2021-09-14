/*
*@file main.c
*@brief Calls the testing function implemented for cbfifo.c & llfifo.c
*
* This source file calls the test functions implemented in test_cbfifo.c 
* and test_llfifo.c and displays the status of test function execution
* @author Shreyan Dhananjayan
* @date September 13,2021
* @Tools Gcc compiler, Use cygwin terminal for Windows
*/


#include"test_llfifo.h"
#include"test_cbfifo.h"

/**
* @brief Calls the test functions implemented in test_cbfifo.c 
* and test_llfifo.c, displays the status of test function execution
*
* @return 0
*/

int main()
{
	bool llfifoResult; /*Variable for checking status of llfifo test functions*/
	bool cbfifoResult; /*Variable for checking status of cbfifo test functions*/
	
	printf("\n-------------------cbfifo test function starts -------------------- \n");
	cbfifoResult=test_cbfifo();
	printf("\n-------------------cbfifo test function ends ----------------------\n");
	if(cbfifoResult==1)
	{
		printf("\n All 10 different scenarios cbfifo test functions are passed\n");
	}
	else
	{
		printf("\n Failure in above test case");
	}

	printf("\n-------------------llfifo test function starts -------------------- \n");
	llfifoResult=test_llfifo();
	printf("\n-------------------llfifo test function ends ----------------------\n");
	if(llfifoResult==1)
	{
		printf("\n All 10 different scenarios llfifo test functions are passed\n");
	}
	else
	{
		printf("\n Failure in above test case");
	}
	return 0;
}

