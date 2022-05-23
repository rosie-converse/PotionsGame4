/******************POTION CLASS*****************
This class contains the m_name, m_description, m_cost, and
m_potency data members. Its member functions consist of
setters and getters for all of the data members, as well as
a default constructor, 4 arg constructor, destructor, copy
constructor, and an operator-equals function.*/

#pragma once

#include "String.h"

class Potion
{
public:
	Potion(); //default ctor
	Potion(String name, String desc, String potency, String cost); //overloaded ctor

	Potion(const Potion& PotionToCopy);//copy ctor
	Potion& operator=(const Potion& RightHandPotion);//copy assignment operator/op-equals

//setters and getters
	void setName(String name);
	String getName() const;

	void setDesc(String desc);
	String getDesc() const;

	void setPotency(String potency);
	String getPotency() const;

	void setCost(String cost);
	String getCost() const;

	~Potion();

private:
	String m_name;
	String m_description;
	String m_potency;
	String m_cost;
};

