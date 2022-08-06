#include <iostream>

void bubblesort(int A[], int n) {
  for (int i = 0; i < n; ++i) {
    for (int j = n-1; j >= i+1; --j) {
  	  if (A[j] < A[i]) {
	    std::swap(A[j], A[i]);
	  }
	}
  }
}

int main() {
  int A[] = {-2, 21, 0, 111, 1, 84, 4, 3, 4};
  int n = sizeof(A)/sizeof(A[0]);

  bubblesort(A, n);

  for (int i = 0; i < n; ++i) {
    std::cout << A[i] << " ";
  }
  
}
