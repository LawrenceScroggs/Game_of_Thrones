// Lawrence Scroggs 05/12/2019 CS202 Program #3

// This will be the main file of the program.  It is here that 
// the game will be played and the user will pass in the objects
// throughout the binary tree that will determine who gets the 
// Iron Throne

#include "event.h"


int main(){


  char * read_first();
  char * read_last();


// up to six players last names must be Stark, Lannister or Targaryen
// picking the right first names add additional bonuses.
  first_name player1(read_first(),read_last());
  player1.set_special();
  player1.use_script();

  first_name player2(read_first(),read_last());
  player2.set_special();
  player2.use_script();
  

  first_name player3(read_first(),read_last());
  player3.set_special();
  player3.use_script();

  first_name player4(read_first(),read_last());
  player4.set_special();
  player4.use_script();
  
  first_name player5(read_first(),read_last());
  player5.set_special();
  player5.use_script();

  first_name player6(read_first(),read_last());
  player6.set_special();
  player6.use_script();
  

  battle the_war;
//sets battles
  the_war.battles_in();
  the_war.display_battles();




// set up the battles how you want
  the_war.has_battle(player1,player2);
  the_war.display_battles();
  the_war.has_battle(player1,player3);
  the_war.display_battles();
  the_war.has_battle(player3,player2);
  the_war.display_battles();
  the_war.has_battle(player1,player6);
  the_war.display_battles();
  the_war.has_battle(player6,player2);
  the_war.display_battles();
  the_war.has_battle(player1,player4);
  the_war.display_battles();
  the_war.has_battle(player1,player2);
  the_war.display_battles();
  the_war.has_battle(player5,player2);
  the_war.display_battles();


  the_war.display_battles();

  player1.stats();

  player2.stats();

  player3.stats();
  
  player4.stats();

  player5.stats();

  player6.stats();


  return 0;

}


// gets first name 
char * read_first(){

  cout << "Use Jon, Daenerys, Arya, Sansa, Cersei or Jamie for bonus.\n";
  cout << "Please enter your characters FIRST name: ";
  char * a_first = new char[100];
  cin.get(a_first,100);
  cin.ignore(100,'\n');

  cout << endl;

  return a_first;
  delete [] a_first;

}
// gets last name
char * read_last(){

  cout << "Stark, Lannister or Targaryen.\n";
  cout << "Please enter your characters LAST name: ";
  char * a_last = new char[100];
  cin.get(a_last,100);
  cin.ignore(100,'\n');

  return a_last;
  delete [] a_last;

}
