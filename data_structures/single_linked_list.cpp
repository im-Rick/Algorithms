#include <iostream>
using namespace std;

template <typename T>
struct ListNode {
  T data;
  ListNode<T>* next;
  ListNode(T data_) : data(data_), next(nullptr) {}
};

template <typename T>
class List {
  public:
  List() : head(nullptr) {}

  bool Empty() {
    return head == nullptr ? true : false;
  } 

  void EmplaceFront(T data) {
    if (head == nullptr) {
      head = new ListNode<T>(data);
	} else {
      ListNode<T>* new_head = new ListNode<T>(data);
	  new_head->next = head;
	  head = new_head;
	} 
  }
  

  // Inserts new node after node
  void EmplaceAfter(ListNode<T>* node, T data) {
    ListNode<T>* new_node = new ListNode<T>(data);
	new_node->next = node->next;
	node->next = new_node;
  }


  // removes the 1st element
  void PopFront() {
    if (head == nullptr) return;

	ListNode<T>* new_head = head->next;
	delete head;
	head = new_head;
  }

  // removes the element past this node
  // asumes the node it is not the last element
  void EraseAfter(ListNode<T>* node) {
    node->next = (node->next)->next;   
  }
  
  // memory
  ListNode<T>* Begin() {
    return head;
  }
  
  void Transversal() {
    ListNode<T>* current_node = head;
	cout << "data: ";
    while(current_node) {
      cout << current_node->data << " ";
	  current_node = current_node->next;
	}
	cout << "\n";
  }

  private:
	ListNode<T>* head;
     
};

int main() {
  List<int>* my_list = new List<int>();
  my_list->Transversal();
  cout << "empty? " << my_list->Empty() << "\n";
  my_list->EmplaceFront(4);
  my_list->EmplaceFront(3);
  my_list->EmplaceFront(1);
  my_list->EmplaceAfter(my_list->Begin(), 2);
  my_list->PopFront();
  my_list->EraseAfter(my_list->Begin());
  my_list->Transversal(); 
  cout << "empty? " << my_list->Empty() << "\n";
  


  return 0;
}
