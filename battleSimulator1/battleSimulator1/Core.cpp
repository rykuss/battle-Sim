#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <windows.h>
#include "Team.h"

using namespace std;

//FUNCTION PROTOTYPES
void loadingSim();
int userMenu();
void addTeam();
void selectTeam();
void deleteTeam();

//GLOBAL VARIABLES
vector<Team> teamList;
int currentSelectedTeam = -1;


//CORE PROGRAM
int main()
{
	int choice;
	bool runningSetup = true;

	while (runningSetup)
	{
		choice = userMenu();
		switch (choice)
		{
			//ADD TEAM
			case 1:
			{
				addTeam();
			}
			break;
			//SELECT TEAM
			case 2:
			{
				selectTeam();
			}
			break;
			//EDIT A TEAM
			case 3:
			{

			}
			break;
			//DELETE A TEAM
			case 4:
			{
				deleteTeam();
			}
			break;
			//ADD A UNIT TO CURRENT SELECTED TEAM
			case 5:
			{

			}
			break;
			//EDIT A UNIT ON THE CURRENT SELECTED TEAM
			case 6:
			{

			}
			break;
			//DELETE A UNIT FROM THE CURRENT SELECTED TEAM
			case 7:
			{

			}
			break;
			//VIEW REPRESENTATION OF BATTLE MATCH UP
			case 8:
			{
				cout << "\nTEAMS:\n";
				for (Team teamHolder : teamList)
				{
					cout << teamHolder.getName() << endl;
				}
			}
			break;
			//QUIT SIMULATION PROGRAM
			case 9:
			{

			}
			break;
			//START SIMULATION PROGRAM
			case 10:
			{

			}
			break;
			default:
			{

			}
		}
	}


	return 0;
}




//FUNCTION DEFINITIONS
void loadingSim()
{
	cout << endl << endl;
	for (int i = 0; i <20; i++)
	{
		Sleep(50);
		cout << ".";
	}

	return;
}


int userMenu()
{
	string holder;
	int choice;

	system("CLS");

	if (currentSelectedTeam != -1)
	{
		cout << "Current Selected Faction: " << teamList[currentSelectedTeam].getName() <<endl <<endl;
	}
	cout << "1:  Add a team\n"
		<< "2:  Select a team\n"
		<< "3:  Edit a team\n"
		<< "4:  Delete a team\n"
		<< "5:  Add a unit\n"
		<< "6:  Edit a unit\n"
		<< "7:  Delete a unit\n"
		<< "8:  View representation\n"
		<< "9:  Quit Simulation\n"
		<< "10: Start Simulation\n\n";
	cout << "Enter choice here: ";
	getline(cin, holder);
	stringstream choiceHolder(holder);
	choiceHolder >> choice;

	return choice;
}


void addTeam()
{
	string nameHolder;

	system("CLS");
	cout << "What is the name of the faction you wish to add?\n";
	getline(cin, nameHolder);
	Team teamHolder(nameHolder);
	teamList.push_back(teamHolder);

	currentSelectedTeam = teamList.size()-1;
	cout<< endl << teamHolder.getName() << " Successfully added!";
	
	loadingSim();

	return;
}


void selectTeam()
{
	system("CLS");
	if (teamList.size() > 0)
	{
		int counter = 1;
		string selectedTeamHolder;

		cout << "Of the Factions listed below, which do you choose to select? [choose number]\n";
		for (Team teamHolder : teamList)
		{
			cout << counter++ << ": " << teamHolder.getName() << endl;
		}

		cout << "\nFaction Select Number: ";
		getline(cin, selectedTeamHolder);
		stringstream sTHP(selectedTeamHolder);
		sTHP >> counter;
		if (counter > teamList.size() || counter < 1)
		{
			cout << "Invalid Faction Number selected";
		}
		else
		{
			currentSelectedTeam = counter-1;
			cout << "\nTeam " << teamList[currentSelectedTeam].getName() << " successfully selected!";
		}
	}
	else
	{
		cout << "No Factions exist to select from";
	}

	loadingSim();

	return;
}


void deleteTeam()
{
	system("CLS");

	if (teamList.size() > 0)
	{
		int counter = 1;
		string selectedTeamHolder;

		cout << "Of the Factions listed below, which would you like to delete? [choose number]\n";
		for (Team teamHolder : teamList)
		{
			cout << counter++ << ": " << teamHolder.getName() << endl;
		}

		cout << "\nFaction Select Number: ";
		getline(cin, selectedTeamHolder);
		stringstream sTHP(selectedTeamHolder);
		sTHP >> counter;
		if (counter > teamList.size() || counter < 1)
		{
			cout << "Invalid Faction Number selected";
		}
		else
		{
			Team tempHolder = teamList[counter - 1];

			if (tempHolder.getName() == teamList[currentSelectedTeam].getName())
			{
				currentSelectedTeam = -1;
			}
			else if ((counter - 1) < currentSelectedTeam)
			{
				currentSelectedTeam--;
			}
			teamList.erase(teamList.begin() + (counter - 1));

			cout << "\nTeam " << tempHolder.getName() << " successfully deleted!";
		}
	}
	else
	{
		cout << "No Factions exist to select from";
	}

	loadingSim();

	return;
}