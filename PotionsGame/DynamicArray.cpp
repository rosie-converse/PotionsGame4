
#include "DynamicArray.h"
#include "Potion.h"
#include <iostream>
using std::endl;
using std::cout;

#include <exception>
using std::bad_alloc;

/****************DEFAULT CTOR**************************************
* Purpose:
*	This member function will initialize the m_array to nullptr and
*	m_elements to 0, so that the default object containso known values
* Precondition:
*	This function is called automatically during the instantiation of
*	a DynamicArray object
* Postcondition:
*	After this function executes, the DynamicArray object's m_array
*	and m_elements members should be these default values (nullptr and
*	0, respectively).
************************************************************************/
DynamicArray::DynamicArray() : m_elements(0), m_array(nullptr) //...oh
{
}

/****************DTOR**************************************
* Purpose:
*	This is the destructor for the DynamicArray class, when a Dynamic
*	array object is no longer needed, this dtor will be automatically called.
* Precondition:
*	This function is called automatically during the destruction of a copy
*	or original DynamicArray object. In order for this function to be called,
*	there must have been at least one DynamicArray object construct
* Postcondition:
*	After this function runs, m_array should be again set to nullptr and
*	m_elements should be reverted back to 0. In addition, the Potion member
*	(m_array) will call the string class's dtors and reset those to their
*	default values.
************************************************************************/
DynamicArray::~DynamicArray()//dtor 
{

	m_elements = 0;

	delete[] m_array;
	m_array = nullptr;

}

/****************COPY CTOR**************************************
* Purpose:
*	This function is used to initialize a DynamicArray object when a
*	copy of an existing object must be created.
* Precondition:
*	The object being copied should contain valid data and will likely
*	be an object passed to a function by value.
* Postcondition:
*	After this function runs, the value of m_array should be equal to the
*	copy's m_array, and the m_elements member should equal the m_elements
*	member of the copy.
************************************************************************/
DynamicArray::DynamicArray(const DynamicArray& copy) : m_array(copy.m_array), m_elements(copy.m_elements)
{
}

/****************OPERATOR EQUALS**************************************
* Purpose:
*	This function is used to assign the "right hand side (rhs)" values of
*	one DynamicArray object to the members of a lhs DynamicArray object.
*	(ex: DynamicArr1 = DynamicArr2)
* Precondition:
*	In order for this function to run, both objects must be valid DynamicArray
*	objects, and there must be a command assigning one DynamicArray to another
*	(shown above)
* Postcondition:
*	After this function runs, the lhs DynamicArray should have the same
*	m_array and m_elements values as the rhs DynamicArray object.
************************************************************************/
DynamicArray& DynamicArray::operator=(const DynamicArray& rhs)
{
	//creates a copy of rhs, so you end up with two object having the same data

	if (this != &rhs)
	{
		m_array = rhs.m_array;
		m_elements = rhs.m_elements;

	}


	return *this;

}

/****************MOVE CONSTRUCTOR**************************************
* Purpose:
*	This function will transfer the contents of one DynamicArray object
*	to the corresponding members of another DynamicArray object. After
*	the transfer is complete, it will delete the orignal DynamicArray
*	object and reset its m_elements back to 0.
* Precondition:
*	The compiler will decide whether to use the move ctor or copy ctor
*	based on whether or not the parameter given to a function is an r-value.
*	The parameter must be an r-value in order for this function to be called.
* Postcondition:
*	After this function runs, the "copy" should contain the data of the original
*	object, and the original object should be destroyed (deleted and m_elements reset).
************************************************************************/
DynamicArray::DynamicArray(DynamicArray&& obj)
{
	//perform a shallow copy of 
	m_array = obj.m_array;
	m_elements = obj.m_elements;

	delete[] obj.m_array;
	obj.m_array = nullptr;
	obj.m_elements = 0;
}

/****************MOVE ASSIGNMENT**************************************
* Purpose:
*	Checks for self-assignment, and if none is detected, then the program
*	will perform a deep copy + cleanup, moving the rhs values into the "copy"
*	members and then deleting the rhs object.
* Precondition:
*	The move assignment operator will be called if an object must be duplicated,
*	such as when passing by value to a function.
* Postcondition:
*	After this function executes, the rhs value should contain only default values,
*	for m_array and m_elements, as this function will move the data from the
*	rhs object into a lhs object of the same type, and then delete the rhs
*	data.
************************************************************************/
DynamicArray& DynamicArray::operator=(DynamicArray&& rhs)
{
	//copies the data from rhs, and then deletes rhs, so that there is one object containing the data that was in rhs
	if (this != &rhs) //check for self assignment
	{

		m_array = rhs.m_array;
		m_elements = rhs.m_elements;

		delete[] rhs.m_array;
		rhs.m_array = nullptr;
		rhs.m_elements = 0;

	}

	return *this;
}

/****************GET ELEMENTS**************************************
* Purpose:
*	This function returns m_elements, which are the number of potions
*	contained in the array of potions, m_array.
* Precondition:
*	This function must be called in order for it to execute, nothing is
*	passed as a parameter.
* Postcondition:
*	After this function completes, the value of m_elements should have been
*	returned and captured in an integer variable.
************************************************************************/
int DynamicArray::GetElements() const 
{
	//return the number of elements in m_array
	return m_elements;
}


/****************INSERT**************************************
* Purpose:
*	This function is used to add a Potion object to the m_array data
*	member of the DynamicArray class.
* Precondition:
*	The function must be explicitly called and given an object of the
*	Potion data type to add to the m_array member.
* Postcondition:
*	After this function runs, m_array should contain the to_add data
*	in a Potion object at the end of the array. Temp should be deleted
*	and the vale of m_elements should have been increased by 1.
************************************************************************/
void DynamicArray::Insert(const Potion& to_add)
{
	try //Try this stuff?
	{
		Potion* temp = new Potion[m_elements + 1];

		for (int i = 0; i < m_elements; ++i)
		{

			*(temp + i) = *(m_array + i);
		}

		*(temp + m_elements) = to_add;

		delete[] m_array;

		m_array = temp;

		++m_elements;
	}

	catch (bad_alloc err) 
	{
		cout << "Error during creation of temp array: " << err.what() << endl;

	}

}

/****************DELETE**************************************
* Purpose:
*	This function will take the name of a potion to be deleted, and
*	call a search function determine if the potion exists in the array.
*	If the value returned from the search function is a valid index,
*	then the Delete function will copy over all Potion except the one
*	stored at that index.
* Precondition:
*	In order for a deletion to be done, this function must receive a
*	potion object whose name member matches at least one other potion's
*	name in the array. The search function stops searching at the first
*	occurrence of the specified name, so cases where there are potions with
*	the same name are handled by deleting the Potion first encountered with
*	the specified name.
* Postcondition:
*	After this function runs, the specified potion will either have been
*	deleted (and m_elements decremented) or, if the potion was not located,
*	a message will be printed and no deletion or decrementations will be done.
************************************************************************/
void DynamicArray::Delete(const Potion& to_delete)
{
	int target_slot = Find(to_delete); //see if the potion exists, and if it does then find out where it is
	int slots_copied = 0;

	Potion* temp = new Potion[m_elements - 1];

	if (target_slot != -1)
	{
		cout << "Deleting ";
		to_delete.getName().getString().Display();
		cout << " from slot #" << target_slot + 1 << " . . ." << endl;

		//DELETION

		if (target_slot > 0) //if the potion is NOT the first one in the array
		{
			while (slots_copied < target_slot)
			{
				*(temp + slots_copied) = *(m_array + slots_copied); //copy over into temp until the target potion is reached
				++slots_copied;
			}


			//start copying from the next potion in the array
			while (slots_copied < (m_elements - 1))
			{
				*(temp + slots_copied) = *(m_array + (slots_copied + 1)); //skip over
				++slots_copied;
			}

		}

		else
		{
			while (slots_copied < (m_elements - 1)) //skip over the first element and copy over all but 1
			{
				*(temp + slots_copied) = *(m_array + (slots_copied + 1)); //skip over
				++slots_copied;
			}
		}

		delete[] m_array;

		m_array = temp;

		--m_elements;

	}


	else
	{
		cout << "Could not find that potion in inventory!" << endl;
	}


}

/****************FIND**************************************
* Purpose:
*	This function will take a Potion object whose name specifies which
*	potion the user wants to delete. The function will iterate over the
*	array of potions (m_array), stopping iteration if a match is found
*	or when all of the potions have been checked.
* Precondition:
*	This function must receive a Potion object whose name member will compared
*	to the other names in m_array.
* Postcondition:
*	After this function runs, the index/target_slot returned will either be
*	a valid index or be -1, which indicates that the potion was not found
*	in the array.
************************************************************************/
int DynamicArray::Find(const Potion& target) const
{
	int potions_checked = 0;
	int location = -1;

	Potion findThis = target;

	//compare the current potion and the target potion's name
	while (potions_checked < m_elements && location != potions_checked)
	{
		if (*m_array[potions_checked].getName().getString().my_str() == *findThis.getName().getString().my_str())
		{
			//if there's a match:
			location = potions_checked;

		}

		else
		{
			++potions_checked;

		}


	}

	return location;

}

/****************DISPLAY**************************************
* Purpose:
*	This function will chain function calls to access the display
*	function for the string class. The name, description, potency,
*	and cost for the potion stored at the given index will be
*	printed out.
* Precondition:
*	This function will receive an integer that (hopefully) corresponds
*	to a valid index in m_array. If the integer given is larger than
*	the current number of elements in m_array, an error message will
*	be printed to avoid accessing undefined data.
* Postcondition:
*	After this function runs, the data members of the potion class
*	should be printed out .
************************************************************************/
void DynamicArray::Display(int cur_potion) const //pass in current element to Display
{
	if (cur_potion < m_elements) //check to ensure element given is within range...
	{
		cout << "[]----------------------------\n";
		cout << "[] " << char(16);
		m_array[cur_potion].getName().getString().Display();
		cout << endl;
		cout << "[] " << char(16);
		m_array[cur_potion].getDesc().getString().Display();
		cout << endl;
		cout << "[] " << char(16);
		m_array[cur_potion].getPotency().getString().Display();
		cout << endl;
		cout << "[] " << char(16);
		m_array[cur_potion].getCost().getString().Display();
		cout << endl;
		cout << "[]----------------------------\n";
		cout << endl;

	}

	else
	{
		cout << "Error! You should not be trying to print stuff outside of the array's range!" << endl;
	}

}