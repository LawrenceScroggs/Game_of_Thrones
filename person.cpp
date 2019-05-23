// Lawrence Scroggs 05/12/2019 CS202 Program #3

// This will implement the functions for my classes.
// The person will be the abstract base class.  It will hold the virtual
// functions that can be used throughout the sub classes.  
// This will also hold the last name subclass that ties the characters
// together via last name. First name will be the class objects that are 
// used throughout game.

#include "person.h"




/************************************first_name**********************************************/


// operator for +=
first_name & first_name::operator+=(const first_name & a_name){

  this->hit_points = this->hit_points + a_name.hit_points;

  return *this;

}
// operator for -= 
first_name & first_name::operator-=(const first_name& a_name){

  this->hit_points = this->hit_points - a_name.atk_points;
  ++this->count_dwn;

  if(a_name.count_dwn == 10 && power == true){

    cout << "POWER UP: ";

  }

  return *this;

}
// connects the proper script object to proper first obj
int first_name::use_script(){


  int i = rand() % 6;

  cout << script->show_speech(i);

  cout << endl << endl;

}
// gets name for the speech class to tie script to name
char * first_name::view_name(){

  return first;

}
// shows the stats of your character
void first_name::stats(){

  cout << "Name: " << first << endl;
  cout << "Last: " << last << endl;
  cout << "Health: " << hit_points << endl;
  cout << "Attack: " << atk_points << endl;
  cout << endl << endl;

}
// sets first name data
first_name::first_name(char * a_first, char * a_last):last_name(a_last){

  cout << "first called" << endl;

  int i = 0;
  
  while(i < strlen(a_first)){

    a_first[i] = toupper(a_first[i]);
    ++i;

  }

  first = new char[strlen(a_first)+1];
  strcpy(first,a_first);

  char * file;
 
  if(strcmp(first,"JON") == 0){

    file = new char[strlen("jon.txt")+1];
    strcpy(file,"jon.txt");
    power = true;

  }
  else if(strcmp(first,"ARYA") == 0){

    file = new char[strlen("arya.txt")+1];
    strcpy(file,"arya.txt");
    power = true;

  }
  script = new speech(first,file);

}
// constructor for  first
first_name::first_name(){

  first = new char[100];

  power = false;

}
// destructor for first
first_name::~first_name(){

  delete first;

}
/************************************last_name***********************************************/

// gives additional boost to hp or atk
int last_name::set_special(){

  if(!activate){
    if(strcmp(last,"LANNISTER") == 0){

      atk_points += 5;
      activate = true;

    }
    else if(strcmp(last,"STARK") == 0){

      hit_points += 5;
      activate = true;

    }
    else if(strcmp(last,"TARGARYEN") == 0){

      atk_points += 5;
      hit_points += 5;
      activate = true; 

    }
    else{

    cout << "No special attributes attained" << endl;
    return -1;
    }

    return 1;
  }
}
// sets last name data
last_name::last_name(char * a_last):person(a_last){

  cout << "last called" << a_last << endl;
  bool check = true;

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
  activate = false;

}
// destructor for last
last_name::~last_name(){

  delete last;

}

/*******************************************Person******************************************/


// gets hp for battles
int person::see_hp(){

  return hit_points;

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
      i = 0;
        while(i < strlen(a_last)){

          a_last[i] = toupper(a_last[i]);
          ++i;
        }

      check = true;
  }

  hit_points = hp;
  atk_points = atk;
  victories = 0;
  count_dwn = 0;

  speech_on = true;

  }
}
// person constructor
person::person(){

  hit_points = 0;
  atk_points = 0;
  victories = 0;
  count_dwn = 0;

  speech_on = false;

}
//  destructor
person::~person(){


}
