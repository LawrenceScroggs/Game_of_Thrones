// Lawrence Scroggs 05/12/2019 CS202 Program #3

// This will be the main file of the program.  It is here that 
// the game will be played and the user will pass in the objects
// throughout the binary tree that will determine who gets the 
// Iron Throne

#include "event.h"


int main(){


  char * read_first();
  char * read_last();



  first_name player1(read_first(),read_last());
  player1.set_special();
      

  first_name player2(read_first(),read_last());
  player2.set_special();


  player1.stats();

  player2.stats();


  battle the_war;

  the_war.battles_in();

  the_war.display_battles();

  the_war.has_battle(player1,player2);





  return 0;

}


// gets first name 
char * read_first(){


  cout << "Please enter your characters first name: ";
  char * a_first = new char[100];
  cin.get(a_first,100);
  cin.ignore(100,'\n');

  return a_first;
  delete a_first;

}
// gets last name
char * read_last(){


  cout << "Please enter your characters last name: ";
  char * a_last = new char[100];
  cin.get(a_last,100);
  cin.ignore(100,'\n');

  return a_last;
  delete a_last;

}
