// Lawrence Scroggs 05/12/2019 CS202 Program #3

// This will be the event classes.  This class
// will be the data structure of the program.
// The data structure implemented will be a binary
// tree.  The event class will be the base class
// this will hold info related to the battle scenario
// and will determine the winner.


#include "person.h"


class node{

  public:
    node();
    ~node();

  protected:

    node * left;
    node * right;

};
class battle: public node{

  public:
    battle();
    ~battle();

    int build_battles();
    int has_battle(first_name & ob1, first_name & ob2);

  protected:

    node * root;


};
