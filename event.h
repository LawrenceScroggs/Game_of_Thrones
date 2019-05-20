// Lawrence Scroggs 05/12/2019 CS202 Program #3

// This will be the event classes.  This class
// will be the data structure of the program.
// The data structure implemented will be a binary
// tree.  The event class will be the base class
// this will hold info related to the battle scenario
// and will determine the winner.


#include "person.h"


class event{

  public:
    event(char * a_event);
    event();
    ~event();

    event *& go_left();
    event * go_right();
    char compare();

  protected:
    
    char * event_name;

    first_name * head;

    event * left;
    event * right;

};
class battle{

  public:
    battle();
    ~battle();

    int battles_in(event *& root); // reads in names of battles
    int build_battles(char * temp);
    int has_battle(first_name & ob1, first_name & ob2);

  protected:

    int build_battles(event *& root,char * temp);

    event * root;

};
