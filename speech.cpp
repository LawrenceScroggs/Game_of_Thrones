// Lawrence Scroggs 05/12/2019 CS202 Program #3

// This will hold the functions to implement
// the speech class.  This will tie the characters
// to their "script" so they will have dialogue
// during the battle.  


#include "speech.h"




// returns the script with set int x sent in by first
char * speech::show_speech(int i){


  return speech_txt[i];

}
speech::speech(const speech & a_ob){

  speech * ptr;
  int i = 0;

  while(i < lines){

    ptr->speech_txt[i] = a_ob.speech_txt[i];
    ++i;
  }

}
speech::speech(char * name, char * file){

  cout << "speech called" << endl;
  s_name = new char[strlen(name)+1];
  strcpy(s_name,name);

  lines = 5;

  speech_txt = new char * [lines];

  for(int x = 0; x < lines; ++x){

    speech_txt[x] = NULL;
  }


  const char * all[] = {file};

  int i = 0;

  ifstream obj;
  obj.open(all[i]);
  if(obj){

      if(obj.peek() == -1){
        obj.clear();
        obj.close();
      }

      while(obj && !obj.eof() && obj.peek() != -1){

      /*  if(obj.peek() == -1){
                              
          cout << "exit 3 " << endl;
          obj.clear();
          obj.close();
          
          return -1;
        }*/

            char * temp = new char[500];
            obj.get(temp,500,'\n');
            obj.ignore(500,'\n');

            speech_txt[i] = new char[strlen(temp) + 1];
            strcpy(speech_txt[i],temp);
            ++i;

            delete temp;
          }
    }
    
      obj.clear();
      obj.close();



}
/*speech::speech(){

  s_name = new char[100];

  lines = 5;
 
  speech_txt = new char * [lines];

  for(int x = 0; x < lines; ++x){

    speech_txt[x] = NULL;
  }
}*/
speech::~speech(){

  int i = 0;

  delete s_name;

  while(i < lines){
    delete speech_txt[i];
    i++;
  }

}
