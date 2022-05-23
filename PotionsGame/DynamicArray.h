//*********************DYNAMIC ARRAY*******************/
/*This class contains the m_array (Potion *) and m_elements (int)
data members. Its member functions consist of a default CTOR and a DTOR,
copy ctor, operator equals, move assignment operator, move constructor,
getter for m_elements, Display, find, and insert/delete functions that
will either add or remove a specified potion from m_array.
The Find member function is private, while the rest are public member
functions. Methods that do not alter the data members possess the const
tag.*/

#pragma once
#include "Potion.h"
#include "String.h"
class DynamicArray
{

public:
	DynamicArray();
	~DynamicArray();

	DynamicArray(const DynamicArray& copy);
	DynamicArray& operator=(const DynamicArray& rhs);

	DynamicArray(DynamicArray&& obj); //move constructor
	DynamicArray& operator=(DynamicArray&& rhs); //move assignment 


	int GetElements() const;

	void Insert(const Potion& to_add);
	void Delete(const Potion& to_delete);
	void Display(int cur_potion) const;


private:
	int Find(const Potion& target) const;
	Potion* m_array;
	int m_elements;

};

