/**
*	@Brad Andrews
*	@11/3/18
*	@file test.h
*	@LinkedList tester
*/
#ifndef TEST_H
#define TEST_H

#include "LinkedListOfInts.h"

class Test
{
  public:
  Test();
  ~Test();
  void startTests();

  private:
  LinkedListOfInts *my_list;
    void clearList(); //Reset the list to null and size to zero

    void testState(bool test) const; //Handles Tests
      void emptyOnInit() const; //Test 1
      void emptySize() const; //Test 2
      void isEmpty(); //Test 3
      void search(); //Test 4
      void AddFront(); //Test 5
      void AddBack(); //Test 6
      void removeFront(); //Test 7
      void removeBack(); //Test 8
};

#endif
