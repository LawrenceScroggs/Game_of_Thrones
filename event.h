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
    event(const event & obj);
    event(char * a_event);
    event();
    ~event();

    event *& go_left();
    event *& go_right();

    char compare();
    char * show_info();

    event * get_root();

  protected:
    
    char * event_name;

    event * left;
    event * right;

};
class battle{

  public:
    battle();
    ~battle();

    int display_battles();
    int battles_in(); // reads in names of battles
    int build_battles(char * temp);
    int has_battle(first_name & ob1, first_name & ob2);

  protected:

/************recursive function**************************************************/
    
    int delete_battle(event *& root);
    int has_battle(char * b_name, first_name & ob1, first_name & ob2,event *& root);
    int display_battles(event * root);
    int build_battles(event *& root,char * temp);

    event * root;

};
