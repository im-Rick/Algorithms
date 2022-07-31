#include <iostream>
using namespace std;

void print(int A[], int n) {
  for (int i = 0; i < n; ++i) {
    cout << A[i] << " ";
  }
  cout << "\n";
}

void selection_sort(int A[], int n) {
  for (int i = 0; i < n - 1; ++i) {
  	int smallest = i;
	for (int j = i + 1; j < n; ++j) {
	  if (A[j] < A[smallest]) {
		smallest = j;
	  }
	}
	swap(A[i], A[smallest]);
  }
}


// testing selection-sort
int main() {
  int A[] = {32, 3, 1, 1, 0, 21, 22};
  int n = sizeof(A) / sizeof(A[0]);
  selection_sort(A, n);
  print(A, n);
  
}
