// Lawrence Scroggs 05/12/2019 CS202 Program #3

// This will implement the functions for my classes.
// The person will be the abstract base class.  It will hold the virtual
// functions that can be used throughout the sub classes.  
// This will also hold the last name subclass that ties the characters
// together via last name. First name will be the class objects that are 
// used throughout game.

#include "person.h"




// shows the stats of your character
void first_name::stats(){

  cout << "Name: " << first << endl;
  cout << "Last: " << last << endl;
  cout << "Health: " << hit_points << endl;
  cout << "Attack: " << atk_points << endl;

}
// sets first name data
first_name::first_name(char * a_first, char * a_last):last_name(a_last){

  cout << "first called" << endl;
  first = new char[strlen(a_first)+1];
  strcpy(first,a_first);
}
// constructor for  first
first_name::first_name(){

  first = new char[100];

}
// destructor for first
first_name::~first_name(){

  delete first;

}
// sets last name data
last_name::last_name(char * a_last):person(a_last){

  cout << "last called" << a_last << endl;
  bool check = true;

  int i = 0;



  while(check){
    if(strcmp(a_last,"LANNISTER") == 0){

      check = false;

    }
    else if(strcmp(a_last,"STARK") == 0){

      check = false;

    }
    else if(strcmp(a_last,"TARGARYEN") == 0){

      check = false; 

    }
    else{

    cout << "Not a Game Character." << endl;
    cout << "Please re-enter last name. " << endl;
    cin.get(a_last,100);
    cin.ignore(100,'\n');

    check = true;

    }

  }
  last = new char[strlen(a_last)+1];
  strcpy(last,a_last);

}
// constructo for last name
last_name::last_name(){

  last = new char[100];

}
// destructor for last
last_name::~last_name(){

  delete last;

}
// sets data for person
person::person(char * a_last){

  cout << "person called " << a_last << endl;
  bool check = true;

  int i = 0;
  int hp;
  int atk;
  
  while(i < strlen(a_last)){

    a_last[i] = toupper(a_last[i]);
    ++i;

  }


  while(check){
    if(strcmp(a_last,"LANNISTER") == 0){

      hp = 150;
      atk = 15;

      check = false;

    }
    else if(strcmp(a_last,"STARK") == 0){

      hp = 200;
      atk = 10;

      check = false;

    }
    else if(strcmp(a_last,"TARGARYEN") == 0){

      hp = 175;
      atk = 20;

      check = false; 

    }
    else{

    cout << "Not a Game Character." << endl;
    cout << "Please re-enter last name. " << endl;
    cin.get(a_last,100);
    cin.ignore(100,'\n');

    check = true;
    /*  cout << "Not a special character no special attributes. \n\n";
      hp = 100;
      atk = 10;

      check = false;*/

    }
  hit_points = hp;
  atk_points = atk;
  speech_on = true;

  }
}
// person constructor
person::person(){

  hit_points = 0;
  atk_points = 0;

  speech_on = false;

}
//  destructor
person::~person(){


}
