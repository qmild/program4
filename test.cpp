#include "bst.h"
#include "unistd.h"
#include <cstring>
#include <ostream>
#include <iostream>

using namespace std;

int run_insert(BST & test_tree)
{
  int result = 0;
  char again = 'n';
  UserData insert_data;

  char name[MAX_STR_LENGTH];
  int user_age;
  char user_gender[MAX_STR_LENGTH];
  char user_location[MAX_STR_LENGTH];
  float user_rating;
  int user_watch_time;
  int num_directors;
  int num_genres;

  cout << endl
       << "To test inserting data, first we must generate that data!" << endl
       << "Note: test.cpp does not check the data type, so be sure to enter the specified data type for each entry!" << endl;

  do{
    cout << "Enter Name (string): ";
    cin.getline(name, MAX_STR_LENGTH);

    cout << "How Many Directors? (int): ";
    cin >> num_directors;
    cin.ignore();
    char** directors = new char*[num_directors];
    for(int i = 0; i < num_directors; ++i) {
      directors[i] = new char[MAX_STR_LENGTH];
    }
    for(int i = 0; i < num_directors; ++i) {
      cout << "Enter Direcor #" << num_directors <<" (string): ";
      cin.getline(directors[i], MAX_STR_LENGTH);
    }

    cout << "How Many Genres? (int): ";
    cin >> num_genres;
    cin.ignore();
    char** genres = new char*[num_genres];
    for(int i = 0; i < num_genres; ++i) {
      genres[i] = new char[MAX_STR_LENGTH];
    }
    for(int i = 0; i < num_genres; ++i) {
      cout << "Enter Genre #" << num_genres << " (string): ";
      cin.getline(genres[i], MAX_STR_LENGTH); 
    }

    cout << "Enter User Age (int): ";
    cin >> user_age; cin.ignore();


    cout << "Enter User Gender (string): ";
    cin.getline(user_gender, MAX_STR_LENGTH); 

    cout << "Enter User Location (string): ";
    cin.getline(user_location, MAX_STR_LENGTH); 

    cout << "Enter User Rating (float): ";
    cin >> user_rating; cin.ignore();

    cout << "Enter User Watch Time (int): ";
    cin >> user_watch_time; cin.ignore();

    insert_data.init(
        name,
        directors,
        genres, 
        user_age,
        user_gender,
        user_location,
        user_rating,
        user_watch_time,
        num_directors,
        num_genres
        );

    cout << "Calling insert..." << endl;
    //sleep(1);
    result = test_tree.insert(insert_data);

    switch (result) {
      case SUCCESS:
        cout << "Method call returned success!" << endl;
        //sleep(1);
        break;
      case NON_UNIQ:
        cout << "Method aborted with an error value of " << NON_UNIQ << "!" << endl 
          << "This Indicates that the movie data for " << name << "   already exists!" << endl 
          << "Please try again!" 
          << endl;
        //sleep(1);
        break;
      case UNINIT_INPUT:
        cout << "Method aborted with an error value of " << UNINIT_TREE << "!" << endl 
          << "This indicates that one of your input strings is NULL!" << endl 
          << "Please try again!" 
          << endl;
        //sleep(1);
        break;
      case EMPTY_INPUT:
        cout << "Method aborted with an error value of " << EMPTY_INPUT << "!" << endl 
          << "This indicates that one of your inputs are empty!" << endl 
          << "Please try again!" 
          << endl;
        //sleep(1);
        break;
      case UNKNOWN:
        cout << "Unknown error!" << endl 
          << "Please try again!" 
          << endl;
        //sleep(1);
      break;
    }
    for(int i = 0; i < num_directors ;++i) {
      if(directors[i] != nullptr) {
        delete[] directors[i];
      }
    }
    delete[] directors;

    for(int i = 0; i < num_genres ;++i) {
      if(genres[i] != nullptr) {
        delete[] genres[i];
      }
    }
    delete[] genres;
    cout << "Run again? (y/n): ";
    cin >> again; cin.ignore();
  }while (again == 'Y' || again == 'y');

  return 0;
}

int run_remove(BST & test_tree)
{
  int result = 0;
  char again = 'n';
  char name[MAX_STR_LENGTH];

  do {
    cout << "Please enter the name of a show to remove data for: ";
    cin.getline(name, MAX_STR_LENGTH);
    //sleep(1);

    cout << "Calling remove..." << endl;
    //sleep(1);
    result = test_tree.remove(name);

    switch (result) {
      case SUCCESS:
        cout << "Method call returned success!" << endl;
        //sleep(1);
        break;
      case NO_MATCH:
        cout << "Method aborted with an error value of " << NO_MATCH << "!" << endl 
          << "This indicates nothing matching your entered text was found in the tree!" << endl 
          << "Please try again!" 
          << endl;
        //sleep(1);
          break;
      case UNINIT_TREE:
        cout << "Method aborted with an error value of " << UNINIT_TREE << "!" << endl 
          << "This indicates the root pointer of the BST is null!" << endl 
          << "Please try again!" 
          << endl;
        //sleep(1);
        break;
      case UNINIT_INPUT:
        cout << "Method aborted with an error value of " << UNINIT_INPUT << "!" << endl 
          << "This indicates name string you entered was null!" << endl 
          << "Please try again!" 
          << endl;
        //sleep(1);
      case EMPTY_INPUT:
        cout << "Method aborted with an error value of " << EMPTY_INPUT << "!" << endl 
          << "This indicates name string you entered was empty!" << endl 
          << "Please try again!" 
          << endl;
        //sleep(1);
        break;
    }
    cout << "Run again? (y/n): ";
    cin >> again; cin.ignore();
  }while (again == 'Y' || again == 'y');

  return 0;
}

int run_retrieve(BST & test_tree)
{
  int result = 0;
  char again = 'n';
  char name[MAX_STR_LENGTH];
  UserData out_data;

  do {
    cout << "Please enter the name of a show to retrieve data for: ";
    cin.getline(name, MAX_STR_LENGTH);
    //sleep(1);

    cout << "Calling retrieve..." << endl;
    //sleep(1);
    result = test_tree.retrieve(name, out_data);

    switch (result) {
      case SUCCESS:
        cout << "Method call returned success!" << endl;
        //sleep(1);
        break;
      case NO_MATCH:
        cout << "Method aborted with an error value of " << NO_MATCH << "!" << endl 
          << "This indicates nothing matching your entered text was found in the tree!" << endl 
          << "Please try again!" 
          << endl;
        //sleep(1);
          break;
      case UNINIT_TREE:
        cout << "Method aborted with an error value of " << UNINIT_TREE << "!" << endl 
          << "This indicates the root pointer of the BST is null!" << endl 
          << "Please try again!" 
          << endl;
        //sleep(1);
        break;
      case UNINIT_INPUT:
        cout << "Method aborted with an error value of " << UNINIT_INPUT << "!" << endl 
          << "This indicates name string you entered was null!" << endl 
          << "Please try again!" 
          << endl;
        //sleep(1);
      case EMPTY_INPUT:
        cout << "Method aborted with an error value of " << EMPTY_INPUT << "!" << endl 
          << "This indicates name string you entered was empty!" << endl 
          << "Please try again!" 
          << endl;
        //sleep(1);
        break;
    }
    cout << "Data stored in UserData object: out_data" << endl 
         << "Displaying contents of out_data..." << endl;
    //sleep(1);
    out_data.display();
    cout << endl;

    cout << "Run again? (y/n): ";
    cin >> again; cin.ignore();
  }while (again == 'Y' || again == 'y');

  return 0;
}

int run_display(BST & test_tree)
{
  int result = 0;
  char again = 'n';

  do {
    cout << "";
    
    //sleep(1);

    cout << "" << endl;

    switch (result) {
      case SUCCESS:
        cout << "Method call returned success!" << endl;
        //sleep(1);
        break;
        //sleep(1);
        break;
      case UNINIT_TREE:
        cout << "Method call returned with an error value of " << UNINIT_TREE << "!" << endl 
          << "This indicates that your root pointer is NULL!" << endl 
          << "Please try again!" 
          << endl;
        //sleep(1);
        break;
      case UNKNOWN:
        cout << "Method aborted with unknown eorror!" << endl 
          << "Please try again!" 
          << endl;
        //sleep(1);
        break;
    }
    cout << "Run again? (y/n): ";
    cin >> again; cin.ignore();
  }while (again == 'Y' || again == 'y');

  return 0;
}

int run_displayByGenre(BST & test_tree)
{
  int result = 0;
  char again = 'n';

  do {
    cout << "";
    
    //sleep(1);

    cout << "" << endl;

    switch (result) {
      case SUCCESS:
        cout << "Method call returned success!" << endl;
        //sleep(1);
        break;
      case UNINIT_INPUT:
        cout << "Method aborted with an error value of 1!" << endl 
          << "This indicates you tried to perform the operation on an uninitialized tree!" << endl 
          << "Please try again!" 
          << endl;
        //sleep(1);
        break;
      case NO_MATCH:
        cout << "Method aborted with an error value of 1!" << endl 
          << "This indicates nothing matching your entered text was found in the tree!" << endl 
          << "Please try again!" 
          << endl;
        //sleep(1);
        break;
      case EMPTY_TREE:
        cout << "Method aborted with an error value of 1!" << endl 
          << "This indicates you tried to perform the operation on an empty tree!" << endl 
          << "Please try again!" 
          << endl;
        //sleep(1);
        break;
    }
    cout << "Run again? (y/n): ";
    cin >> again; cin.ignore();
  }while (again == 'Y' || again == 'y');

  return 0;
}

int run_displayAll(BST & test_tree)
{
  int result = 0;
  char again = 'n';

  do {
    cout << "Displaying all data in tree..." << endl;;
    //sleep(1);

    result = test_tree.displayAll();

    switch (result) {
      case SUCCESS:
        cout << "Method call returned success!" << endl;
        //sleep(1);
        break;
      case UNINIT_TREE:
        cout << "Method call returned with an error value of " << UNINIT_TREE << "!" << endl 
          << "This indicates that your root pointer is NULL!" << endl 
          << "Please try again!" 
          << endl;
        //sleep(1);
        break;
      case UNKNOWN:
        cout << "Method aborted with unknown eorror!" << endl 
          << "Please try again!" 
          << endl;
        //sleep(1);
        break;
    }
    cout << "Run again? (y/n): ";
    cin >> again; cin.ignore();
  }while (again == 'Y' || again == 'y');

  return 0;
}

int run_getHeight(BST & test_tree)
{
  int result = 0;
  char again = 'n';

  do {
    cout << "";
    
    //sleep(1);

    cout << "" << endl;

    switch (result) {
      case SUCCESS:
        cout << "Method call returned success!" << endl;
        //sleep(1);
        break;
      case UNINIT_INPUT:
        cout << "Method aborted with an error value of 1!" << endl 
          << "This indicates you tried to perform the operation on an uninitialized tree!" << endl 
          << "Please try again!" 
          << endl;
        //sleep(1);
        break;
      case NO_MATCH:
        cout << "Method aborted with an error value of 1!" << endl 
          << "This indicates nothing matching your entered text was found in the tree!" << endl 
          << "Please try again!" 
          << endl;
        //sleep(1);
        break;
      case EMPTY_TREE:
        cout << "Method aborted with an error value of 1!" << endl 
          << "This indicates you tried to perform the operation on an empty tree!" << endl 
          << "Please try again!" 
          << endl;
        //sleep(1);
        break;
    }
    cout << "Run again? (y/n): ";
    cin >> again; cin.ignore();
  }while (again == 'Y' || again == 'y');

  return 0;
}

int main()
{
  BST test_tree;
  int response = 1;


  do {
    cout << endl
      << "\e[0m"   << "------------------------------------------------------------------------------------------------------------------------------" << "\e[0m" << endl
      << "\e[0m"   << "| " 
      << "\e[1;4m" << "Welcome to CS163 Program #4 test routine! Please select from the public methods below by entering the corresponding number"     
      << "\e[0m"   << " |"                                                                                                                              << endl
      << "\e[0m"   << "|                                                                                                                            |" << "\e[0m" << endl
      << "\e[m"    << "| 1. insert(UserData & to_insert)                                                                                            |" << "\e[0m" << endl 
      << "\e[m"    << "| 2. remove(char* name)                                                                                                      |" << "\e[0m" << endl 
      << "\e[m"    << "| 3. retrieve(char* name, UserData & out_data)                                                                               |" << "\e[0m" << endl 
      << "\e[m"    << "| 4. getHeight()                                                                                                             |" << "\e[0m" << endl 
      << "\e[m"    << "| 5. display(char* name)                                                                                                     |" << "\e[0m" << endl 
      << "\e[m"    << "| 6. displayByGenre(char* genre)                                                                                             |" << "\e[0m" << endl 
      << "\e[m"    << "| 7. displayAll()                                                                                                            |" << "\e[0m" << endl 
      << "\e[0m"   << "------------------------------------------------------------------------------------------------------------------------------" << "\e[0m" << endl
      << endl;

    cout << "Response: ";
    cin >> response; cin.ignore();

    switch (response) {
      case 1:
        run_insert(test_tree);
        break;
      case 2:
        run_remove(test_tree);
        break;
      case 3:
        run_retrieve(test_tree);
        break;
      case 4:
        run_getHeight(test_tree);
        break;
      case 5:
        run_display(test_tree);
        break;
      case 6:
        run_displayByGenre(test_tree);
        break;
      case 7:
        cout << "run_displayAll selected" << endl;
        run_displayAll(test_tree);
        break;
    }

  }while(response != 0);

  return 0;
}
