// Lawrence Scroggs 05/12/2019 CS202 Program #3

// This will be the speech class of the program.
// I will used this class to implement speech between
// the two characters.  This will not be an deciding
// factor in the battle but more for a fun collection 
// of quotes from my favorite characters that will 
// be used through the battle.



#include <cstring>
#include <cctype>
#include <iostream>
#include <fstream>

using namespace std;

class speech{

  public:
    speech(char * name);
    speech();
    ~speech();

    int set_speech(char * s_name);

  protected:

    char ** speech_txt; // array to hold dialogue
    
    char * s_name;  // holds the name to match script with character
    
    int lines;

    char * dialogue;

};

