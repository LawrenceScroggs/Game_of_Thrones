// Lawrence Scroggs 05/12/2019 CS202 Program #3

// This will be the main file of the program.  It is here that 
// the game will be played and the user will pass in the objects
// throughout the binary tree that will determine who gets the 
// Iron Throne

#include "event.h"


int main(){

  char * a_last = new char[100];



  first_name player1(read_first(),read_last());
  player1.set_special();
  speech p1(player1.view_name());
  player1.set_script(p1);
      
  first_name player2(read_first(),read_last());
  player2.set_special();
  speech p2(player2.view_name());
  player2.set_script(p2);


  player1.stats();


  player2.stats();


  battle the_war;

  the_war.battles_in();

  the_war.display_battles();





  return 0;

}

