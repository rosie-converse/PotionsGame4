

#include "Potion.h"
#include "String.h"

/**********DEFAULT CTOR**********
This member function will initialize the name,
description, potency, and cost data members to
the default values of the custom string class
(which are all nullptr)*/
Potion::Potion() : m_name(), m_description(), m_potency(), m_cost()
{
	//default ctor
}

/***********OVERLOADED CTOR******
This member function will initialize a potion
object with the provided string data for name,
description, potency, and cost*/
Potion::Potion(String name, String desc, String potency, String cost) : m_name(name), m_description(desc), m_potency(potency), m_cost(cost)
{
	//overloaded ctor
}

/***********COPY CTOR***********
This member function will allow you to initialize
a new object by using the data member values of
another object*/
Potion::Potion(const Potion& PotionToCopy) : m_name(PotionToCopy.m_name), m_description(PotionToCopy.m_description), m_potency(PotionToCopy.m_potency), m_cost(PotionToCopy.m_cost)
{
	//copy ctor
}

/***********OP EQUALS************
This member function will allow you to change the
data member values of one object to those in use by
another object*/
Potion& Potion::operator=(const Potion& RightHandPotion)
{
	if (this != &RightHandPotion)//if "this" is not equal to the address of the RightHandPotion (then we're not trying to copy the same thing onto itself)
	{
		m_name = RightHandPotion.m_name;
		m_description = RightHandPotion.m_description;
		m_potency = RightHandPotion.m_potency;
		m_cost = RightHandPotion.m_cost;

	}

	//op equals

	return *this;
}

/************NAME SETTER************
This member function sets the m_name data member
to the string name passed in*/
void Potion::setName(String name) //: m_name(name) //OK WHAT'S GOING ON HERE
{
	m_name = name;
	//setter for name
}

/************NAME GETTER************
This member function returns the name currently
stored in m_name*/
String Potion::getName() const
{
	return m_name;
	//getter for name
}
/*************DESCRIPTION SETTER****
This member function sets the description of the
object to the description string passed into the
setter*/
void Potion::setDesc(String desc)
{

	m_description = desc;
	//setter for description
}

/*************DESCRIPTION GETTER****
This member function returns the description that
is currently stored in m_description*/
String Potion::getDesc() const
{
	return m_description;
	//getter for description
}

/*************POTENCY SETTER********
This member function sets the m_potency member
to the potency string passed into the setter*/
void Potion::setPotency(String potency)
{
	m_potency = potency;
	//setter for potency
}

/*************POTENCY GETTER********
This member function returns the potency string
stored in m_potency*/
String Potion::getPotency() const
{
	return m_potency;
	//getter for potency
}

/************COST SETTER***********
This member function sets the m_cost member to the
cost string passed into the setter*/
void Potion::setCost(String cost)
{
	m_cost = cost;
	//setter for cost
}

/*************COST GETTER*********
This member function returns the string stored in
m_cost*/
String Potion::getCost() const
{
	return m_cost;
	//getter for cost
}

/************DTOR****************
This is the potion class's destructor, which is empty
but it will call the destructor for the string class*/
Potion::~Potion()
{
	//dtor

}
