#include<iostream>
#include<list>
using namespace std;

template <typename T>
struct Node {
  T data;
  Node<T>* down;
  Node(T data_) : data(data_), down(nullptr) {}
};

template <typename T>
class Stack {
  public:
  Stack() : top(nullptr) {}

  T Top() {
    if (top) return top->data;
    
	return static_cast<T>(NULL);
	//throw runtime_error("No data");
  }

  void Push(T data) {
	Node<T>* new_stack = new Node<T>(data);
    if (top == nullptr) {
      top = new_stack; 
	} else {
      new_stack->down = top;
	  top = new_stack;
	}
  }

  void Pop() {
    if (top == nullptr) return;

	Node<T>* to_delete = top;
	top = top->down;
	delete to_delete;
  }

  private:
    Node<T>* top;
};



int main() {
  Stack<int>* my_stack = new Stack<int>();
  my_stack->Push(1);
  my_stack->Push(2);
  cout << my_stack->Top() << " "; 
  my_stack->Pop();
  cout << my_stack->Top() << " "; 
  my_stack->Pop();
  my_stack->Pop();
  cout << my_stack->Top() << " "; 
  cout << my_stack->Top() << " "; 
}
