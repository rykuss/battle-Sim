#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std; 

class Team
{
	private:
		string name;

	public:
		Team(string);
		string getName();
		void setName(string);
};
