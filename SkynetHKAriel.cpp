/*
Lucas Kucharski
June 1, 2021
Skynet-HK Ariel assignment
*/

//Declaring the libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
//declaring namespace
using namespace std;
//Main
int main()
{ //declaring variables for the code. 
	int searchGridLowNumber = 1;
	int searchGridHighNumber = 64;
	srand(static_cast<unsigned int>(time(0)));
	int secretNumber = rand() % 64 + 1;

	int targetLocationPrediction =
		((searchGridHighNumber - searchGridLowNumber) / 2) + searchGridLowNumber;
	int tries = 0;
	//Program text.
	cout << "The targeted enemy is hiding in a house in a subdivision shaped in an 8x8 grid.\n";
	cout << "The target is in house number " << secretNumber << ".";
	cout << "We must start up the program and begin our search.\n";
	cout << "Skynet HK-Ariel Initializing software...\n";
	//This is a do while loop that runs the algorith for the game. 
	do
	{   // This is incrementing the number of tries for each cycle. 
		++tries;
		cout << "Loading.......................\n";
		cout << "HK-Ariel Radar sending out ping number" << tries << "\n";
		//The search algorithm for this program.
		targetLocationPrediction = ((searchGridHighNumber - searchGridLowNumber) / 2) + searchGridLowNumber;
		//This is ran only if the target prediction was higher than the secret number. 
		if (targetLocationPrediction > secretNumber)
		{
			cout << "The target location prediction of " << targetLocationPrediction << " was higher than the correct location.\n";
			searchGridHighNumber = targetLocationPrediction;
			cout << "The new searchGridHighNumber " << searchGridHighNumber << "\n";
		}//This runs only if the target prediction is lower than the secret number. 
		else if (targetLocationPrediction < secretNumber)
		{
			cout << "The target location prediction of " << targetLocationPrediction << " was lower than the correct location.\n";
			searchGridLowNumber = targetLocationPrediction;
			cout << "The new searchGridLowNumber " << searchGridLowNumber << "\n";
		}
		else //this is the win condition.
		{
			cout << "Enemy was hiding in house number " << secretNumber << "\n";
			cout << "Target was found at location number " << targetLocationPrediction << "\n";
			cout << "Skynet HK-Ariel software took " << tries << " predictions to find the target.\n";
		}
	} 	
	while (targetLocationPrediction != secretNumber);
	return 0;
}