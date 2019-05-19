// Lawrence Scroggs 05/12/2019 CS202 Program #3

// This will hold the person class.  Person will be the 
// base class of this heirarchy.  It will hold virtual functions that 
// will be used throughout the implementation of the characters. The subclass
// will be last name.  This will hold another data boost that is associated
// with the last name.  The final subclass will be the first name subclass.
// This will implement additional data attributes associated with the name.


#include "speech.h"


class person{

  public:

    virtual int set_hp();
    virtual int set_atk();
    virtual bool set_speech();

  protected:

    virtual ~person();
    int hit_points;
    int atk_points;
    bool speech_on;

};
class last_name: public person{

  public:

    last_name();
    ~last_name();

    int set_hp();
    int set_atk();
    bool set_speech();
    int set_special(); 
  
  protected:

    int special; // boost to hp or atk
    char * last;

};
class first_name: public last_name{

  public:

    first_name();
    ~first_name();

    bool set_pwr();
    int attack();
    int read_attack();

  protected:

    bool power;  //sets power for additional boost
    char * first;

};





















