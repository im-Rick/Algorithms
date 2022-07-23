#include <iostream>
using namespace std;

template <typename T>
struct Node {
  T data;
  Node<T>* next; // nullptr <-B <-A
  Node(T data_) : data(data_), next(nullptr) {}
};

template <typename T>
struct Queue {
  public:
  Queue() : head(nullptr), tail(nullptr) {}

  void Push(T data) {
    if (head == nullptr && tail == nullptr) {
      head = tail = new Node<T>(data);
	} else {
      tail->next = new Node<T>(data);
	  tail = tail->next;
	}
  }
  
  void Pop() {
    if (head == nullptr) return;

	head = head->next;
	if (head == nullptr) tail = nullptr;
  }

  T Top() {
    if (head) return head->data;

	return static_cast<T>(NULL);
  }
	

  private:
    Node<T>* head;
    Node<T>* tail;
};


int main () {
  Queue<int>* my_queue = new Queue<int>();

  my_queue->Push(1);
  cout << my_queue->Top() << " ";
  my_queue->Pop();
  my_queue->Pop();
  my_queue->Push(1);
  my_queue->Push(2);
  cout << my_queue->Top() << " ";
  my_queue->Pop();
  cout << my_queue->Top() << " ";
  my_queue->Pop();
  my_queue->Pop();
  my_queue->Pop();
  cout << my_queue->Top() << " ";
  cout << my_queue->Top() << " ";

  
  return 0;
}
