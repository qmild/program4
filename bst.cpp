// Bryce Diedrich
// CS163 Program 4
// 03/08/2024
//
// <- header comments here

#include "bst.h"
#include <cstring>
#include <iostream>
#include <ostream>

using namespace std;

// constructor
BST::BST()
{
  // set root equal to null
  root = nullptr;
}

BST::~BST()
{
  destructor(root);
}

// recursive helper for ~BTree 
void BST::destructor(Node* root)
{
  // when head is null, return
  if(root != nullptr){
  // recursively call in left and right directions
  destructor(root->left);
  destructor(root->right);
  // free memory (calls ~Node)
  delete root;
  }
}

// wrapper for insert
int BST::insert(UserData& to_insert)
{
  // allocate UserData object and initialize with to_insert's data
  UserData* data = new UserData();
  int result = data->init(to_insert.name, 
      to_insert.directors, 
      to_insert.genres, 
      to_insert.user_age, 
      to_insert.user_gender, 
      to_insert.user_location, 
      to_insert.user_rating, 
      to_insert.user_watch_time, 
      to_insert.num_directors, 
      to_insert.num_genres);  
  if (result != SUCCESS) {
    return result;
  }

  // call helper function
  root = insert(data, root);

  // if helper returned a nullptr, return error
  if(root == nullptr) {
    return UNKNOWN;
  }
  // otherwise return success
  return SUCCESS;
}

// recursive helper for insert
Node* BST::insert(UserData* data, Node*& root)
{
  // base case: when root is null, return new node
  if(root == nullptr) {
    return new Node(data);
  }

  // when value to be added is lower than current node, go left
  if (strcmp(data->name, root->data->name) < 0) {
    root->left = insert(data, root->left); 
  }
  // when value to be added is lower than current node, go right 
  else if (strcmp(data->name, root->data->name) > 0) {
    root->right = insert(data, root->right);
  }

  return root;
}

// remove method
int BST::remove(char* name)
{
  // when root is null, return error
  if (root == nullptr) {
    return UNINIT_TREE;
  }

  // name input is null, return error
  if(name == nullptr) {
    return UNINIT_INPUT; 
  }

  // when name input is empty, return error
  if( strlen(name) == 0) {
    return EMPTY_INPUT; 
  }

  // when no match is found, return error
  Node* match = searchByName(name, root);
  if (match == nullptr) {
    return NO_MATCH;
  }

  root = remove(name, root);
  return SUCCESS;
}

Node* BST::remove(char* name, Node* root)
{
  if(root == nullptr) {
    return root;
  }

  // when search key is lower than current node, go left
  if(strcmp(name,root->data->name) < 0) {
    root->left = remove(name, root->left);
  }
  // when search key is higher than current node, go right
  else {
    root->right = remove(name, root->right);
  }

  cout << "node to remove: " << root->data->name << endl;
  
  // case: matching node has zero or one children
  if (root->left == nullptr && root->right == nullptr) {
    delete root;
    return nullptr;
  }
  // when left ptr is null, right child might exist
  if (root->left == nullptr) {
    cout << "case: left is null, deleting match node" << endl;
    // set hold ptr to right child (possibly null)
    Node* hold = root->right;
    // delete node
    cout << "deleting " << root->data->name << " and returning " << hold->data->name << endl;
    delete root;
    // set root to right child (possibly null)
    return hold;
  }
  // when no right child, but left child exists
  else if (root->right == nullptr) {
    cout << "case: right is null, deleting match node" << endl;
    // set hold ptr to left child 
    Node* hold = root->left;
    // delete node
    cout << "deleting " << root->data->name << " and returning " << hold->data->name << endl;
    delete root;
    // set root to left child 
    return hold;
  }
  // case: matching node has two children
  else {
    cout << "case: node has two children" << endl;
    // declare ptr to right subtree
    Node* ios = root->right;
    // go left until we find in order succesor (ios)
    while (ios->left != nullptr) {
      ios = ios->left;
    }
    
    // copy data from ios into matching node
    cout << "copying ios into " << root->data->name << " and deleting " << ios->data->name << endl;
    root->data->init(ios->data->name, 
        ios->data->directors, 
        ios->data->genres, 
        ios->data->user_age, 
        ios->data->user_gender, 
        ios->data->user_location, 
        ios->data->user_rating, 
        ios->data->user_watch_time, 
        ios->data->num_directors, 
        ios->data->num_genres);

    // delete ios
    delete ios;
  }
  return root;
}

// retrieve method
int BST::retrieve(char *name, UserData &out_data)
{
  // when root is null, return error
  if (root == nullptr) {
    return UNINIT_TREE;
  }
  // when name input is null, return error
  if(name == nullptr) {
    return UNINIT_INPUT; 
  }
  // when name input is empty, return error
  if( strlen(name) == 0) {
    return EMPTY_INPUT; 
  }
  // capture matching node in a ptr and return error when no match is found
  Node* to_retrieve = searchByName(name, root);
  if (to_retrieve == nullptr) {
    return NO_MATCH;
  }

  // copy data from matching node into output
  out_data.init(to_retrieve->data->name, 
      to_retrieve->data->directors, 
      to_retrieve->data->genres, 
      to_retrieve->data->user_age, 
      to_retrieve->data->user_gender, 
      to_retrieve->data->user_location, 
      to_retrieve->data->user_rating, 
      to_retrieve->data->user_watch_time, 
      to_retrieve->data->num_directors, 
      to_retrieve->data->num_genres);

  return SUCCESS;
}

// wrapper for displayAll
int BST::displayAll()
{
  if (root == nullptr) {
    return UNINIT_TREE;
  }
  // call and return recursive helper function
  displayAll(root);
  return SUCCESS;
}

// recursive helper for displayAll
void BST::displayAll(Node* root)
{
  cout << "entered display all with root = " << root << endl;
  // when root is null, return
  if (root == nullptr) {
    return;
  }

  // display tree in order
  displayAll(root->left);
  cout << endl << root->data->display() << endl;
  displayAll(root->right);
}

// utility function to search the BST by name
Node* BST::searchByName(char* name, Node* root)
{
  // when root is null or matches search key, return root
  if(root == nullptr || strcmp(root->data->name, name) == 0) {
    return root;
  }

  // when search key is lower than current node, go left
  if(strcmp(name,root->data->name) < 0) {
    return searchByName(name, root->left);
  }
  // when search key is higher than current node, go right
  else {
    return searchByName(name, root->right);
  }
}
