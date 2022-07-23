// Implementation of a binary seach tree without balance function
#include <iostream>
#include <vector>
using namespace std;
 
template <typename T> 
struct Node {
  T data;
  Node<T> *left, *right;
  Node(T data_) : data(data_), left(nullptr), right(nullptr) {}
};
  
template <typename T> 
class BST {
  public:
  BST() : root(nullptr) {}

  // Non recursive function
  bool Insert(T data) {
    if (root == nullptr) {
      root = new Node<T>(data);
	} else {
      Node<T> *curr = root, *parent = nullptr;
	  while(curr) {
        parent = curr;
        if (data == curr->data) {
		  return false;  // key already present, no duplicates
		} else if (data < curr->data) {
		  curr = curr->left;
		} else {
		  curr = curr->right;
		}
	  }

	  // Inserts data according to the key and parent
	  if (data < parent->data) {
        parent->left = new Node<T>(data);
	  } else {
        parent->right = new Node<T>(data);
	  }
	}
    return true; 
  }

  
  void InOrder(Node<T>* dummy) {
    if (dummy == nullptr) return; 

    InOrder(dummy->left);
	cout << dummy->data << " ";
	InOrder(dummy->right);
  }

  Node<T>*& GetRoot() {
    return root;
  }

  Node<T>* GetRoot2() {
    return root;
  } 

  bool InsertRecursive(T data) {
    return InsertRecursive(root, data); 
  }

  private:
  Node<T> *root;
  
  // Insert using recursion
  bool InsertRecursive(Node<T>*& parent, T data) {
    if (parent == nullptr) {
      parent = new Node<T>(data);
	  return true;
	} else {
      if (data == parent->data) {
        return false;   // key alreay present
	  } else if (data < parent->data) {
	    return InsertRecursive(parent->left, data);
	  } else if (data > parent->data) {
	    return InsertRecursive(parent->right, data);
	  }
	}
  }


};

int main () {
  BST<int>* m_tree = new BST<int>();
  BST<int>* r_tree = new BST<int>();
  vector<int> data = {19, 7, 78, 782, 32, 1, 31, 77, 0, 2, 0};

  for (auto d : data) {
    cout << m_tree->Insert(d) << " ";
  }
  cout << "\n";
  Node<int>* parent = r_tree->GetRoot2();
  
  for (auto d : data) {
    cout << r_tree->InsertRecursive(d) << " ";
  }
  cout << "\n";
  m_tree->GetRoot2()->left->data = 222;
  m_tree->InOrder(m_tree->GetRoot());
  r_tree->InOrder(r_tree->GetRoot());
 
  return 0;
}
