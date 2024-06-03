/*
* FILE : f1.cpp
* PROJECT : SENG1050 - Focused #1
* PROGRAMMER : Behzad Afrasiabi
* FIRST VERSION : 2024-05-17
* DESCRIPTION :
*	This program asks the user to provide a number (10) of date-destination pairs as flight information. 
*	The info from each of these pairs are recorded onto appropriate memory sizes, using dynamic memory allocation.
*	The struct FlightInfo is used as a means to record memory addresses associated with each pair member.
*	Using an array of this struct, the user's input data is recorder onto appropriately sized memory blocks;
*	And finally represented at the end in formatted strings.
*/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Global Constants
#define STRING_LENGTH 31 //included 1 element for null termination
#define PAIRS 10
//Return Codes
#define SUCCESS 0
#define MEMORY_ALLOCATION_ERROR -1
#define USER_INPUT_ERROR -2

//Struct
struct FlightInfo
{
	char* destination;
	char* date;
	float* fare;
};

//Function Prototypes
int createFlightInfo(FlightInfo* flightInfo, char date[], char destination[]);
void printFlightInfo(FlightInfo flightInfo[]);
void replaceNewLineCharacter(char text[]);


//MAIN
int main(void)
{
	char enteredDate[STRING_LENGTH] = { " " };
	char enteredDestination[STRING_LENGTH] = { " " };
	char enteredFair[STRING_LENGTH] = { " " };

	printf("Please enter %d date and destination pairs: \n", PAIRS);
	for (int i = 0; i < PAIRS; i++)
	{
		printf("----------------------------------------------\n");
		printf("Pair %d\n", i + 1);

		printf("Please enter the date: ");
		if (fgets(enteredDate, STRING_LENGTH - 1, stdin) == NULL) //getting date input
		{//exception
			printf("Error recording user input - date");
			return USER_INPUT_ERROR;
		}
		replaceNewLineCharacter(enteredDate);

		printf("Please enter the destination: "); 
		if (fgets(enteredDestination, STRING_LENGTH - 1, stdin) == NULL) //getting destination input
		{//exception
			printf("Error recording user input - destination");
			return USER_INPUT_ERROR;
		}
		replaceNewLineCharacter(enteredDestination);

		printf("Please enter the fare: ");
		if (fgets(enteredFair, STRING_LENGTH - 1, stdin) == NULL) //getting destination input
		{//exception
			printf("Error recording user input - fare");
			return USER_INPUT_ERROR;
		}
		replaceNewLineCharacter(enteredFair);


		//sort and add here

	}

	//printFlightInfo(allFlightInfo); // changes due to printing two linked lists
   
	////Freeing Memory
	//for (int i = 0; i < PAIRS; i++)
	//{
	//	free(allFlightInfo[i].date);
	//	free(allFlightInfo[i].destination);
	//}

	return SUCCESS;
}//MAIN END


//
// FUNCTION :  createFlightInfo
// DESCRIPTION :
//	This function takes a pointer to a FightInfo struct object, and allocates memory for its'
//  three fields. The function also takes two char arrays and one float to fill the FlightInfo fields' 
//  allocated memory blocks. These memory blocks are allocated according to the size of the provided 
//  C-style strings, and the float.
// PARAMETERS :
//	FlightInfo* flightInfo : Pointer to the FlightInfo struct object 
//  char date[] : C-style string, intended for the date field within the flightInfo struct object
//  char destination[] : C-style string, intended for the destination field within the flightInfo struct object
//  float fare: float intended for the fare field within the flightInfo struct object
// RETURNS :
//	int: return code used to communicate errors or successful execution
//
int createFlightInfo(FlightInfo* flightInfo, char date[], char destination[], float fare)
{
	int dateSize = strlen(date) + 1; //required size for the date field
	int destinationSize = strlen(destination) + 1; //required size for the destination field
	int fareSize = sizeof(float);

	flightInfo->date = (char*)malloc(dateSize);
	if (flightInfo->date == NULL)
	{//exception
		printf("error allocating memory for the date.");
		return MEMORY_ALLOCATION_ERROR;
	}

	flightInfo->destination = (char*)malloc(destinationSize);
	if (flightInfo->destination == NULL)
	{//exception
		printf("error allocating memory for the destination.");
		return MEMORY_ALLOCATION_ERROR;
	}

	
	flightInfo->date = (char*)malloc(dateSize);
	if (flightInfo->date == NULL)
	{//exception
		printf("error allocating memory for the date.");
		return MEMORY_ALLOCATION_ERROR;
	}

	strcpy_s(flightInfo->date, dateSize, date);
	strcpy_s(flightInfo->destination, destinationSize, destination);
	
	return SUCCESS;
}


//
// FUNCTION :  printFlightInfo
// DESCRIPTION :
//	This function takes an array of FlightInfo struct objects, and prints the contents of each
//	object's field within a formatted string.
// PARAMETERS :
//	FlightInfo flightInfo[] : The array of FlightInfo struct objects.
// RETURNS :
//	void: This function returns nothing.
//
void printFlightInfo(FlightInfo flightInfo[])
{
	printf("\n----------------------------------------------\n");
	printf("%-35s%-35s\n", "Destination", "Date");
	printf("----------------------------------------------\n");

	for (int i = 0; i < PAIRS; i++)
	{
		printf("%-35s%-35s\n", flightInfo[i].destination, flightInfo[i].date);
	}
}


//
// FUNCTION :  replaceNewLineCharacter
// DESCRIPTION :
//	This function takes in a C-style string and checks whether it ends with
//	a new line character. If the new line character is found, it is replaced
//  with a null terminator throgh derefrencing, so that the C-style strings 
//  becomes usable in the program.
// PARAMETERS :
//	char text[] : The C-style string.
// RETURNS :
//	void: This function returns nothing.
//
void replaceNewLineCharacter(char text[])
{
	//removing new line character and replacing it with a null terminator
	char* newLine = strchr(text, '\n');
	if (newLine != NULL)
	{
		*newLine = '\0';
	}
}

