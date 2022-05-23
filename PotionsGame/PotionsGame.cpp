#define _CRTDBG_MAP_ALLOC

#include <iostream>
using std::endl;
using std::cout;
using std::cin;

#include <iomanip>
using std::setfill;
using std::setw;

#include "String.h"
#include "DynamicArray.h"
#include "Potion.h"
#include "MiscFunctions.h"


int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	int copperCoin = 0;
	int silverCoin = 0;
	int goldCoin = 0;
	int platCoin = 0;

	int potions_added = 0; //keeps track of how many potions have been added
	int potion_count = 0; //keep track of how many potions should be added

	Potion to_delete; //use this potion's name to find the target potion to delete
	char temp[100]{ 0 }; //temp array to get input name to to_delete

	//Prompt user for the number of potions in array
	InputPotionCount(potion_count);

	DynamicArray* potion_array = new DynamicArray; //Object created

	while (potions_added < potion_count) //Prompt user for potion data (name, description, cost, potency) until the specified number of potions have been added
	{
		cout << "------------------------------------------" << endl;
		cout << "| Potion #" << potions_added + 1 << " name: ";
		InputPotionData(potion_array, copperCoin, silverCoin, goldCoin, platCoin); //Pass the coins to the input function so that the price of the new potion can be added to the total cost so far
		cout << "------------------------------------------" << endl;
		cout << endl;

		++potions_added;

	}

	for (int i = 0; i < potion_count; ++i)
	{
		potion_array->Display(i); //print the potion's currently in the array.
	}

	//Code to demonstrate functionality of delete functions added

	cout << "Enter the name of the potion you'd like to delete: ";
	cin.ignore(cin.rdbuf()->in_avail());
	cin.getline(temp, 100);		
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());

	to_delete.setName(temp); //only the name field of the temp potion is set, because I only want to search m_array for the target name

	potion_array->Delete(to_delete);

	potion_count = potion_array->GetElements(); //get the new number of elements (just so that we can print the changed array)

	for (int i = 0; i < potion_count; ++i)
	{
		(potion_array)->Display(i); //print the updated array of potions.
	}


	FormatTotal(copperCoin, silverCoin, goldCoin, platCoin);

	delete potion_array;


	return 0;

}