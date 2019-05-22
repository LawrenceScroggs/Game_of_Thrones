// Lawrence Scroggs 05/12/2019 CS202 Program #3

// This will hold the functions to implement
// the speech class.  This will tie the characters
// to their "script" so they will have dialogue
// during the battle.  


#include "speech.h"


// returns the script with set int x sent in by first
char * speech::show_speech(int x){

  return speech_txt[x];

}
// sets the script to the person
int speech::set_speech(char * s_name, char * file){


  cout << "file: " << file;

  const char * all_files[] = {file};


  int i = 0;

  ifstream obj;
  obj.open(all_files[0]);
  if(obj){

      if(obj.peek() == -1){
        cout << "exit 1";
        obj.clear();
        obj.close();
      }

      while(obj && !obj.eof()){

        if(obj.peek() == -1){
                              
          cout << "exit 3 " << endl;
          obj.clear();
          obj.close();
          
          return -1;
        }

            cout << "in here" << i << endl;
            char * temp = new char[500];
            obj.get(temp,500,'\n');
            obj.ignore(500,'\n');

            speech_txt[i] = new char[strlen(temp)+1];
            strcpy(speech_txt[i],temp);
            ++i;

            delete temp;
          }
    }
      cout << "exit 2" << endl;
      obj.clear();
      obj.close();

}
speech::speech(char * name){

  cout << "speech called" << endl;
  s_name = new char[strlen(name)+1];
  strcpy(s_name,name);

  if(strcmp(s_name,"JON") == 0){

      char * file = new char[strlen("jon.txt")+1];
      strcpy(file,"jon.txt");
      set_speech(s_name,file);
      }
  else if(strcmp(s_name,"ARYA") == 0){

    char * file = new char[strlen("arya.txt")+1];
    strcpy(file,"arya.txt");
    set_speech(s_name,file);
  }



  x = 0;


}
speech::speech(){

  s_name = new char[100];

  lines = 5;
 
  int i = 0;
  while(i < lines){
    speech_txt[i] = new char[500];
    ++i;
  }
}
speech::~speech(){

  delete s_name;
}
