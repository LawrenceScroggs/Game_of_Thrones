// Lawrence Scroggs 05/12/2019 CS202 Program #3

// This file will hold all the funtions for the battle
// class and event.  We will use these fucntions to build 
// a battle scenario in which the to people will battle 
// and determine the outcome of the battle.  Which will 
// eventually determine who will rule the iron throne


#include "event.h"


/************************battle*************************************************************/

int battle::has_battle(first_name & ob1, first_name & ob2){

  if(!root)
    return -1;

  has_battle(ob1,ob2,root);

  return 0;

}
int battle::has_battle(first_name & ob1, first_name & ob2, event *& root){

  if(!root){
    return 1;
  }

  //has_battle(ob1,ob2,root->go_right());
  //has_battle(ob1,ob2,root->go_left());

  else
  return 0;

}
int battle::start_game(first_name & ob1, first_name & ob2, first_name & ob3,first_name & ob4, first_name & ob5, first_name & ob6){

  
  cout << "Choose the two characters you want to battle. " << endl;
 
  

}
int battle::display_battles(){

  if(!root)
    return -1;

  display_battles(root);

  cout << endl;
 
  return 0;

}
int battle::display_battles(event * root){

  if(!root){

    return 0;
  }

  else{
    display_battles(root->go_left());
    cout << "Battle of " << root->show_info();
    cout << endl;
    display_battles(root->go_right());
  }

}
int battle::build_battles(char * temp){

  if(!temp){
    cout << "not working" << endl;
    return -1;
  }

  else
    build_battles(root,temp);
}
int battle::build_battles(event *& root,char * temp){

  if(!root){

    root = new event(temp);
  }

  else if(temp[0] < root->compare())
    build_battles(root->go_left(),temp);

  else
    build_battles(root->go_right(),temp);

}
int battle::battles_in(){

  ifstream file_in;
  file_in.open("battles.txt");

    if(file_in){

      if(file_in.peek() == -1) return -1;

      while(file_in && !file_in.eof()){

        if(file_in.peek() == -1){
                                
          file_in.clear();
          file_in.close();
          return -1;
        }

            char * temp = new char[100];
            file_in.get(temp,100,'\n');
            file_in.ignore(100,'\n');

            build_battles(temp);

            delete temp;
          }
    }

  file_in.clear();
  file_in.close();

}
battle::battle(){

  root = NULL;

}
battle::~battle(){

  delete root;

}

/*******************************event********************************************************/

char * event::show_info(){

  return event_name;

}
event *& event::go_right(){

  return right;

}
event *& event::go_left(){

  return left;
}
char event::compare(){

  return event_name[0];
}
event::event(char * a_event){

  event_name = new char[strlen(a_event)];
  strcpy(event_name,a_event);

  //head = NULL;
  
  left = NULL;
  right = NULL;

}
event::event(){

  event_name = new char[100];

  //head = NULL;

  left = NULL;
  right = NULL;

}
event::~event(){
  

//  delete left;
 // delete right;

}


