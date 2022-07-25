#include <iostream>
#include <vector>
using namespace std;

void insertion_sort(vector<int>& v)
{
  for (int j = 1; j < v.size(); ++j) {
	int key = v[j];
	int i = j - 1;
    // Insert v[j] into the sorted sequence v[1..j-1]
	while (v[i] >= 0 && v[i] > key) {
	  v[i + 1] = v[i];
	  i = i - 1;
	}
	v[i + 1] = key;
  }
}


int main() {
  vector<int> v{5, 2, 4, 6, 1, 3};
  insertion_sort(v);
  for (auto value : v) {
  	cout << value << " ";
  }
}
