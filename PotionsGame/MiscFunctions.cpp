#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include "String.h"
#include "DynamicArray.h"

#include "MiscFunctions.h"

const int MAX_COINS = 99;
const int MAX_CHARS = 100;

/****************INPUT POTION COUNT**************************************
* Purpose:
*	This function will prompt the user for a number to use as the size of
*	the dynamic array of potions (m_array). If the user inputs a negative
*	or a 0, the function will re-prompt for input.
* Precondition:
*	This function is given an integer, passed by reference, which the user
*	will change the value of by inputting the desired size of their
*	potion array.
* Postcondition:
*	After this function runs, the value of potion_count should be greater than
*	0.
************************************************************************/
void InputPotionCount(int& potion_count)
{
	do
	{
		cout << "How many potions would you like to create? -> ";
		cin >> potion_count;

	} while (potion_count <= 0); //can't make an array of 0 potions...

}

/****************INPUT POTION DATA**************************************
* Purpose:
*	Allow the user to input a name, description, potency value,
*	and cost of each potion in the array
* Precondition:
*	The array should have at least 1 potion in it, in order for the
*	for-loop to run
* Postcondition:
*	After this function is run, all of the potions in the array should
*	have non-default data in the parameters (unless the user just re-
*	entered the default data).
************************************************************************/
void InputPotionData(DynamicArray* potion_array, int& copperCoin, int& silverCoin, int& goldCoin, int& platCoin)//hmm
{
	Potion tempPotion;
	String potency;


	char temp[100]{ 0 };

	cin.ignore(cin.rdbuf()->in_avail());
	cin.getline(temp, 100);
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());

	tempPotion.setName(temp); //set the name

	cout << "| Description: ";
	cin.ignore(cin.rdbuf()->in_avail());
	cin.getline(temp, 100);
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());

	tempPotion.setDesc(temp);

	cout << "| Strength: ";
	cin.ignore(cin.rdbuf()->in_avail());
	cin.getline(temp, 100);
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());


	tempPotion.setPotency(potency.StringUpper(temp));


	tempPotion.setPotency(temp);


	cout << "| Cost in copper, silver, gold, and platinum (input in the following format: copper.silver.gold.platinum): ";
	cin.ignore(cin.rdbuf()->in_avail());
	cin.getline(temp, 100);
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());

	tempPotion.setCost(temp);

	CostStrToFloat(temp, copperCoin, silverCoin, goldCoin, platCoin);

	//call insert after all fields of the temp object are filled out

	potion_array->Insert(tempPotion); //pass the current potion into the insert function to add to the array

}

/******************STRING-TO-FLOAT*************************************
* Purpose:
*	Convert the values in the current potion's "cost" parameter from
*	String values into float values, so that they may then be summed
*	 and converted if necessary.
* Precondition:
*	Requires the data inside of m_cost to be input in a valid format,
*	as the tokenizing algorithm requires a "." delimiter to function
*	properly.
* Postcondition:
*	After this function runs, the values of the coin variables should
*	reflect the newly-added cost values from the current potion. Ex:
*	a potion costing 2 copper coins should have its copper cost conve
*	ted to a float and then added to the copperCoin variable, which
*	holds the total of all copperCoins in the potionArray.
************************************************************************/
void CostStrToFloat(String cost, int& copperCoin, int& silverCoin, int& goldCoin, int& platCoin)//pass the coin types by reference to save the sum values after this fn executes
{
	//converts the cost member from string to float...

	int coin = 0;
	int currencyCount = 0;
	int costs_converted = 0;
	float conversionRate = 0.0F;
	char* str;
	char temp[MAX_CHARS]{ 0 };//max_chars = 100
	String str_cost;

	//use my_str() to convert a string type into a char *

	strcpy(temp, cost.my_str());


	str = strtok(temp, ".");

	while (str != NULL)
	{
		coin = atoi(str);

		switch (currencyCount)
		{
		case 0:
			copperCoin += coin;
			break;

		case 1:
			silverCoin += coin;
			break;

		case 2:
			goldCoin += coin;
			break;

		case 3:
			platCoin += coin;
			break;

		default:
			cout << "uh oh" << endl;
		}

		str = strtok(NULL, "."); //take next number out of the cost string
		++currencyCount; //move to the next coin (copper/silver/gold/plat)

	}

}

/*******************FORMAT TOTAL*****************************************
* Purpose:
*	This function will take the summed copper, silver, gold, and plat
*	values, determine if they are greater than the max (99), and if so
*	it will convert the maxed out value to the next-highest denomination
*	by multiplying the excess times the conversion rate
* Precondition:
*	In order for this function to be properly utilized, it must be called
*	after AA of the potion costs have been summed, to ensure that the total
*	is being formatted
* Postcondition:
*	After this function runs, the total values for copperCoin/silverCoin/etc
*	should reflect their converted values. Ex: If the total cost for 2
*	potions was 150 copper, this function will instead convert and format
*	the total to result in a cost of 99 copper and 25.5 silver
************************************************************************/
void FormatTotal(int copperCoin, int silverCoin, int goldCoin, int platCoin)
{
	cout << "\nPURCHASE ALL: ";

	if (copperCoin > MAX_COINS)
	{

		CurrencyConversion(copperCoin, silverCoin);

	}
	if (silverCoin > MAX_COINS)
	{
		CurrencyConversion(silverCoin, goldCoin);

	}

	if (goldCoin > MAX_COINS)
	{
		CurrencyConversion(goldCoin, platCoin);

	}

	if (platCoin > MAX_COINS)
	{
		platCoin = MAX_COINS; //cap the cost at the max value for coins
	}

	cout << "To buy all potions, you will need " << copperCoin << " Copper, " << silverCoin << " Silver, " << goldCoin << " Gold, and " << platCoin << " Platinum." << endl;
	cout << " *Default Conversion between plat/gold/silver/copper*\n"
		<< "1 Copper = .5 Silver, 1 Silver = .5 Gold, 1 Gold = .5 Plat\n" << endl;

}

/*****************CURRENCY CONVERSION*************************************
* Purpose:
*	This function will take the coin sum that is to be converted, reduce,
*	multiply it by the appropriate conversion rate, and ensure that the
*	coin sum reflects this converted value.
* Precondition:
*	In order for this function to be utilized properly, it must be called
*	and the correct parameters must be given to it. If you want to convert
*	from silver to gold, you must give the function those parameters in
*	the correct order (coinToConvert = silver, convertToThis = gold)
* Postcondition:
*	After this function runs, the value of coinToConvert should reflect its
*	newly-reduced and converted state, while the convertToThis value should
*	include the amount converted from coinToConvert, plus its previous value
************************************************************************/
void CurrencyConversion(int& coinToConvert, int& convertToThis)
{
	float conversionRate = .50F;

	do
	{
		coinToConvert -= MAX_COINS; //subtract max_val from the value to convert
		convertToThis += coinToConvert; //add difference to higher val sum


	} while (coinToConvert > MAX_COINS);


	convertToThis *= conversionRate; //multiply the higher val's sum by the conversion rate

}