#include <iostream>
using namespace std;

template <typename T>
struct Node {
  T data;
  Node<T> *left, *right;
  Node(T data_) : data(data_), left(nullptr), right(nullptr) {}
};

template <typename T>
void InOrder(Node<T>* temp) {
  if (!temp) return;

  InOrder(temp->left);
  cout << temp->data << " ";
  InOrder(temp->right); 
}

template <typename T>
void PreOrder(Node<T>* temp) {
  if (!temp) return;

  cout << temp->data << " ";
  PreOrder(temp->left);
  PreOrder(temp->right);
}

template <typename T>
void PostOrder(Node<T>* temp) {
  if (!temp) return;

  PostOrder(temp->left);
  PostOrder(temp->right);
  cout << temp->data << " ";
}


int main () {
  Node<char> *root = new Node<char>('A');

  root->left = new Node<char>('B');
  root->right = new Node<char>('I');
  root->left->left = new Node<char>('C');
  root->left->right = new Node<char>('F');
  root->left->left->left = new Node<char>('D');
  root->left->left->right = new Node<char>('E');

  InOrder(root);
  cout << "\n";
  PreOrder(root);
  cout << "\n";
  PostOrder(root);
  
  return 0;
}
