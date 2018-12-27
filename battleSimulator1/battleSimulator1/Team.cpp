#include <iostream>
#include <string>
#include <vector>
#include "Team.h"

using namespace std; 

Team::Team(string nameHolder)
{
	name = nameHolder;
}

string Team::getName()
{
	return name;
}

void Team::setName(string newName)
{
	name = newName;

	return;
}