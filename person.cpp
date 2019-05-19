// Lawrence Scroggs 05/12/2019 CS202 Program #3

// This will implement the functions for my classes.
// The person will be the abstract base class.  It will hold the virtual
// functions that can be used throughout the sub classes.  
// This will also hold the last name subclass that ties the characters
// together via last name. First name will be the class objects that are 
// used throughout game.

#include "person.h"


// constructor for  first
first_name::first_name(){

  first = new char[100];

}
// constructo for last name
last_name::last_name(){

  last = new char[100];

}
// destructor for last
last_name::~last_name(){

  delete last;

}
// virtual destructor
person::~person(){


}
