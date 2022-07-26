#include <iostream>
#include <vector>

using namespace std;

// sorting from right to left
void insertion_sort_nonincreasing(vector<int>& v) {
  int N = v.size();
  for (int i = N - 2; i >= 0; --i) {
    int key = v[i];
	int j = i + 1;
	// inserting key into sorte array (j..N-1)
	while(j < N && key < v[j]) {
      v[j - 1] = v[j];
	  j = j + 1;
	}
	v[j - 1] = key;
  } 
}

// sorting from left to rigth
void isn(vector<int>& v) {
  int N = v.size();
  for (int j = 1; j < N; ++j) {
	int key = v[j];
	int i = j - 1;
	while(i >= 0 && key > v[i]) {
		v[i + 1] = v[i];
		i = i - 1;
	}
	v[i + 1] = key;
  } 
}

int main() {
  //            i  j
  vector<int> v{32,1,21,4,56,66,33,3,923,232,323};
  isn(v);

  for (auto element : v) {
    cout << element << " ";
  }
}
