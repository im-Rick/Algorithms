#include <iostream>
#include <limits>
using namespace std;

void print(int A[], int n) {
  for (int i = 0; i < n; ++i) {
    cout << A[i] << " "; 
  }
  cout << "\n";
}

/* // Implementation indexing from zero to n where
      n is not inclusive
void merge(int A[], int p, int q, int r) {
  int n1 = q - p;
  int n2 = r - q;

  int L[n1 + 1];
  int R[n2 + 1];
  for (int i = 0; i < n1; ++i) {
    L[i] = A[p+i];
  }
  for (int j = 0; j < n2; ++j) {
    R[j] = A[q+j];
  }
  // insert sentinels
  L[n1] = std::numeric_limits<int>::max();
  R[n2] = std::numeric_limits<int>::max();

  //print(L, n1);
  //print(R, n2);
  int i = 0, j = 0;
  for (int k = p; k < r; ++k) {
    L[i] <= R[j] ? A[k] = L[i++] : A[k] = R[j++]; 
  }
}

void merge_sort(int A[], int p, int r) {
  // cout << "p: " << p << ", r: " << r << "\n";
  if ((r -p) > 1) { 
    int q = 0;
     q = (p + r)  / 2;
    merge_sort(A, p, q);
    merge_sort(A, q, r);
	merge(A, p, q, r);
  } 
}
*/

// implementation indexing from 0 to n inclusive
// to do

int main() {
  int A[] = {1, 1, 0};
  //int n = sizeof(A) / sizeof(A[0]);
  int n = sizeof(A) / sizeof(A[0]);
  merge_sort(A, 0, n - 1);
  print(A, n);
  
  return 0;
}
