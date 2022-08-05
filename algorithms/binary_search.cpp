#include <iostream>
using namespace std;
// real indexes
void binary_search(int A[], int p,int r) {
  // if (
  if(p < r) {  
    int q = p + (r - p) / 2;
  	cout << "p: " << p << ", r:" << r << "\n";
    binary_search(A, p, q);
	// as we are using real index, q is already taken by
	// left side of the array so we add +1 at right.
	// Can we decrement q at the left side (A, p, q-1) and use q 
	// at the right side? No, it will generate a infinite loop
	// ex p=4, q=5
	// q = 4.5 -> 4
	// left (4, 4-1) it will break the condition p < r
    // right (4, 5)  same as the original input
	// if we want use -1 at left, we need to ceil the q
    binary_search(A, q+1, r);
  }
}

int bs(int A[], int p, int r, int key) {
  // bs (A, p, q-1, key) conditional : 
  // bs (A, p, q, key) conditional : !(p < r) we are flooring the k
  if (!(p <= r)) { return -1; }  
  int q = p + (r-p)/2;
  if (key == A[q]) {
    return q;
  }else if (key < A[q]) {
    return bs(A, p, q-1, key);
  } else {
    return bs(A, q+1, r, key);
  }
}

int main() { 
  int A[] = {0,1, 2, 3, 4};
  int n = sizeof(A) / sizeof(A[0]);
  int key;
  cin >> key;
  cout << bs(A, 0, n, key);
}
