// Lawrence Scroggs 05/12/2019 CS202 Program #3

// This file will hold all the funtions for the battle
// class and event.  We will use these fucntions to build 
// a battle scenario in which the to people will battle 
// and determine the outcome of the battle.  Which will 
// eventually determine who will rule the iron throne


#include "event.h"


/************************battle*************************************************************/

// deletes event after battle takes place
int battle::delete_battle(event *& root){

  // @ leaf
  if(!root->go_left() && !root->go_right()){

    delete root;
    root = NULL;
    return 1;

  }
  // left is null
  else if(!root->go_left()){

    event * temp = root;
    root = root->go_right();
    delete temp;
    return 1;

  }
  // right is null
  else if(!root->go_right()){

    event * temp = root;
    root = root->go_left();
    delete temp;
    return 1;

  }
  // left and right are not null// delete and reconnect
  else{

    if(!root->go_right()->go_left()){

      event * temp = root;
      event * current = root;
      current = root->go_right();
      root = current;
      root->go_left() = temp->go_left();
      delete temp;

      return 1;

    }
    else{
      event * prev = root;
      event * current = root->go_right();
      while(current){
        prev = current;
        current = root->go_left();
      }
      root = current;
      prev->go_left() = root->go_right();

      delete current;
    }
  }

}
// sets the battle for user to choose
int battle::has_battle(first_name & ob1, first_name & ob2){

  if(!root)
    return -1;

  char * temp = new char[100];

  int i = 0;

  cout << "Enter the name of the battle the you want the two characters to fight. \n";
  cout << "Battle of : ";
  cin.get(temp,100);
  cin.ignore(100,'\n');

  char * b_name = new char[strlen(temp) + 1];
  strcpy(b_name,temp);


  while(i < strlen(temp)){
    b_name[i] = toupper(b_name[i]);
    ++i;
    }

  delete [] temp;
  cout << b_name << endl;

  has_battle(b_name,ob1,ob2,root);

  return 0;

}
// finds correct battle recursively
int battle::has_battle(char * b_name, first_name & ob1, first_name & ob2, event *& root){

  if(!root){
    return 1;
  }

  if(strcmp(b_name,root->show_info()) == 0){

    cout << "The battle of " << root->show_info();
    cout << " begins. \n\n";

    while(ob1.see_hp() > 0 && ob2.see_hp() > 0){

      ob1 -= ob2;
      ob2 -= ob1;
    }
    if(ob1.see_hp() > 0){

      cout << "Winner is " << ob1.view_name();
      cout << endl;
      ob1.use_script();
      ob1.set_win();

    }
    else{

      cout << "Winner is " << ob2.view_name();
      cout << endl;
      ob2.use_script();
      ob2.set_win();
    }

    ob1.reset();
    ob2.reset();

    delete_battle(root);

    return 0;
  }

  has_battle(b_name,ob1,ob2,root->go_right());
  has_battle(b_name,ob1,ob2,root->go_left());

}
// displays battles
int battle::display_battles(){

  if(!root)
    return -1;

  display_battles(root);
 
  return 0;

}
// displays battles thru recursion
int battle::display_battles(event * root){

  if(!root){

    return 1;
  }

    display_battles(root->go_left());
    cout << "Battle of " << root->show_info();
    cout << endl;
    display_battles(root->go_right());

    return 0;

}
// builds battle tree from file
int battle::build_battles(char * temp){

  if(!temp){
    cout << "not working" << endl;
    return -1;
  }

  else
    build_battles(root,temp);
}
// recursive build
int battle::build_battles(event *& root,char * temp){

  if(!root){

    root = new event(temp);
  }

  else if(temp[0] < root->compare())
    build_battles(root->go_left(),temp);

  else
    build_battles(root->go_right(),temp);

}
// loads up battles from file
int battle::battles_in(){

  ifstream file_in;
  file_in.open("battles.txt");

  char * temp = new char[100];
    if(file_in){

      if(file_in.peek() == -1) return -1;

      while(file_in && !file_in.eof()){

        if(file_in.peek() == -1){
                                
          file_in.clear();
          file_in.close();
          return -1;
        }

            file_in.get(temp,100,'\n');
            file_in.ignore(100,'\n');

            build_battles(temp);

          }
    }

  delete [] temp;
  file_in.clear();
  file_in.close();

}
// defaults constructor
battle::battle(){

  root = NULL;

}
// destructor
battle::~battle(){

    delete root;
    root = NULL;

}

/*******************************event********************************************************/

// show name of event/battle
char * event::show_info(){

  return event_name;

}
// goes right
event *& event::go_right(){

  return right;

}
// goes left
event *& event::go_left(){

  return left;
}
// returns first letter of event for bst
char event::compare(){

  return event_name[0];
}
// builds event with name arg
event::event(char * a_event){

  event_name = new char[strlen(a_event) + 1];
  strcpy(event_name,a_event);

  int i = 0;

  while(i < strlen(a_event)){

    event_name[i] = toupper(event_name[i]);
    ++i;
  }
  
  left = NULL;
  right = NULL;

}
// copy constructor
event::event(const event & obj){

  event_name = new char[strlen(obj.event_name) + 1];
  strcpy(event_name,obj.event_name);

  left = obj.left;
  right = obj.right;

}
// default constructor
event::event(){

  event_name = new char[100];

  left = NULL;
  right = NULL;

}
// destructor
event::~event(){
 
  delete [] event_name;

  left = NULL;
  right = NULL;


}


