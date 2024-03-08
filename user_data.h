// Bryce Diedrich
// bryc3@pdx.edu
// CS163 Program #3
//
// This file implements UserData class. We have the following public interface 
// - init: takes all data needed by the object as input and creates an instance of the class with those values
// - display: displays data values of an instance of the clas

// error code defintions
const int SUCCESS = 0;
const int UNINIT_TREE = 1;
const int NO_MATCH = 2;
const int EMPTY_TREE = 3;
const int EMPTY_INPUT = 4;
const int UNINIT_INPUT = 5;
const int NON_UNIQ = 6;
const int UNKNOWN = 7;

const int MAX_STR_LENGTH = 50;
  
class UserData
{
   public:
    UserData();
    ~UserData();
    int init(char* name, 
            char** directors, 
            char** genres, 
            int use_age, 
            char* user_gender, 
            char* user_location,
            float user_rating,
            int user_watch_time,
            int num_directors,
            int num_genres);
    int display();

    char* name;
    char** directors;
    char** genres;
    int user_age;
    char * user_gender;
    char * user_location;
    float user_rating;
    int user_watch_time;
    int num_directors;
    int num_genres;
};

