/***********MISC FUNCTIONS***********
These are the declarations for miscellaneous functions,
including an input function, string to float conversion,
sum formatting, and a currency conversion function.*/

#pragma once
#include "Potion.h"

void InputPotionCount(int& potion_count);

void InputPotionData(DynamicArray* potion_array, int& copperCoin, int& silverCoin, int& goldCoin, int& platCoin);
void CostStrToFloat(String cost, int& copperCoin, int& silverCoin, int& goldCoin, int& platCoin);
void FormatTotal(int copperCoin, int silverCoin, int goldCoin, int platCoin);
void CurrencyConversion(int& coinToConvert, int& convertToThis);
