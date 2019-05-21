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
int speech::set_speech(char * s_name){

  ifstream speech_in;

  if(strcmp(s_name,"JON") == 0){
    cout << "jon script" << endl;
    speech_in.open("jon.txt");
  }
  else if(strcmp(s_name,"ARYA") == 0){
    cout << "arya script" << endl;
    speech_in.open("arya.txt");
  }
  else if(strcmp(s_name,"SANSA") == 0){
    cout << "sansa script" << endl;
    speech_in.open("sansa.txt");
  }
  else{
    cout << "Character has no dialogue" << endl;
    return -1;
  }

  int i = 0;

  if(speech_in){

      if(speech_in.peek() == -1) return -1;

      while(speech_in && !speech_in.eof()){

        if(speech_in.peek() == -1){
                                
          speech_in.clear();
          speech_in.close();
          return -1;
        }

            char * temp = new char[500];
            speech_in.get(temp,500,'\n');
            speech_in.ignore(500,'\n');

            speech_txt[i] = new char[strlen(temp)+1];
            strcpy(speech_txt[i],temp);
            ++i;

            delete temp;
          }
    }
      speech_in.clear();
      speech_in.close();

}
speech::speech(char * name){

  s_name = new char[strlen(name)+1];
  strcpy(s_name,name);

  cout << s_name << endl;

  set_speech(s_name);

}
speech::speech(){

  s_name = new char[100];

  dialogue = new char[500];
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
