/**
*	@Brad Andrews
*	@11/3/18
*	@file test.cpp
*	@LinkedList tester
*/
#include "Test.h"
#include <iostream>

using namespace std;

Test::Test()
{
	my_list = new LinkedListOfInts;
	cout << "List initialized." << endl;
}

//delete list and re-initialize a replacement list
void Test::clearList()
{
	delete my_list;
	my_list = new LinkedListOfInts;
}

//Handles Tests
void Test::startTests()
{
	emptyOnInit(); //Test 1
	emptySize(); //Test 2
	isEmpty(); //Test 3
	search(); //Test 4
	AddFront(); //Test 5
	AddBack(); //Test 6
	removeFront(); //Test 7
	removeBack(); //Test 8
}

//Prints Test State of result (Passed/Failed) for given method
void Test::testState(bool test) const
{
	if (test == true)
	{
		cout << "PASSED" << endl;
	}
	//test == false
	else
	{
		cout << "FAILED" << endl;
	}
}

//Checks for empty list, should be empty upon start
void Test::emptyOnInit() const
{
	cout << "Test 1: List is initially empty: ";
		if(my_list->isEmpty())
		{
			testState(true);
		}
		else
		{
			testState(false);
		}
}

//Checks list size (non-zero/zero), should be zero at start
void Test::emptySize() const
{
	cout << "Test 2: List size initially 0: ";
		if(my_list->size() == 0)
		{
			testState(true);
		}
		else
		{
			testState(false);
		}
}

//Add a value to list and check that the value is saved.
void Test::isEmpty()
{
	cout << "Test 3: List is not empty when given a value: ";
	my_list->addFront(0);
		if (my_list->isEmpty() == true)
		{
			testState(false);
		}
		else
		{
			testState(true);
		}
	clearList(); //Prepare list for another tests
}

//Add a value to the list and look for value, if found search works (passes), else  does not (failed)
void Test::search()
{
	cout << "Test 4: Searching the list for entry: ";
	bool passed = true;
	int n=0;
		while (n<100)
		{
			my_list->addFront(n);
			if (my_list->search(n) == false) //If value was not found
			{
				passed = false;
				n=99;
			}
			n++;
		}
	testState(passed);
	clearList(); //Prepare list for another tests
}

//Check the list at each addition to see if the size of the list scales with the additions
void Test::AddFront()
{
	cout << "Test 5: Size of list matches additions to the front (Of List): ";
	bool passed = true;
	int n=1;
		while (n<100)
		{
			my_list->addFront(n);
			if (my_list->size() != n) // If the size does not match
			{
				passed = false;
				n=99;
			}
			n++;
		}
	testState(passed);
	clearList(); //Prepare list for another tests
}

//Check the list at each addition to see if the size of the list scales with the additions
void Test::AddBack()
{
	cout << "Test 6: Size of list matches additions to the back (Of List): ";
	bool passed = true;
	int n=1;
		while (n<100)
		{
			my_list->addBack(n);
			if (my_list->size() != n) //IF the size does not match
			{
				passed = false;
				n=99;
			}
			n++;
		}
	testState(passed);
	clearList(); //Prepare list for another tests
}

//Add a value to the front of the list and then remove it to test that the action completes
void Test::removeFront()
{
	bool passed = true;
	cout << "Test 7: RemoveFront (Of List) functions properly: ";
	int n=0;
		while (n<100)
		{
			my_list->addFront(n);
			my_list->removeFront();
			if (my_list->size() == true) //List has a size > 0
			{
				passed = false;
				n=99;
			}
			n++;
		}
	testState(passed);
	clearList(); //Prepare list for another tests
}

//Add a value to the back of the list and then remove it to test that the action completes
void Test::removeBack()
{
	cout << "Test 8: RemoveBack (Of List) functions properly: ";
	bool passed = true;
	int n=0;
		while (n<100)
		{
			my_list->addBack(n);
			my_list->removeBack();
			if (my_list->size() == true) //List has a size > 0
			{
				passed = false;
				n=99;
			}
			n++;
		}
	testState(passed);
	clearList(); //Prepare list for another tests
}

//Destructor
Test::~Test()
{
	delete my_list;
	my_list = nullptr;
}
