// Bryce Diedrich
// CS163 Program 4
// 03/08/2024
//
// <- header comments here

#include "user_data.h"

class Node
{
 public:
  // constructor
  Node(UserData* data) {
    this->data = data;
    left = nullptr;
    right = nullptr;
  }
  //destructor
  ~Node()
  {
    if (this->data != nullptr) 
      delete data;
  }

  // child pointers
  Node* left;
  Node* right;
  // user data
  UserData* data;
};

class BST
{
 public:
  BST();
  ~BST();
  int insert(UserData & insert_data);
  int remove(char* name);
  int retrieve(char* name, UserData & out_data);
  int display(char* name);
  int displayByGenre(char* genre);
  int displayAll();
 private:
  // recursive helper methods for public interface
  void destructor(Node* root);
  Node* insert(UserData* to_insert, Node*& root);
  Node* remove(char* name, Node* root);
  void displayAll(Node* root);
  // utility methods 
  Node* searchByName(char* name, Node* root);
  Node* searchByGenre(char* search_str, Node* root);
  void displayNames(Node* root);

  // BST root ptr
  Node* root;
};
