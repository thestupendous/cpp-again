
#include<iostream>
#include<vector>
using namespace std;

void rightRotateMera(const vector<int> &vec, int k) {
	k = k % vec.size();
	vector<int> copy(vec.size(),0);

	
	for (int i{0} ; i<vec.size(); i++ ) {
		copy[ (i+k) % vec.size() ] = vec[i];
	}


	for (int i{0} ; i<copy.size(); i++ ) {
		cout << copy[i] << ',';
	}
	cout << '\n';

}


// second approach
// reverse 0-k array, reverse k-len array, then reverse whole 0-len array
void rotateArray(vector<int> arr, int n, int k) {
    if (k == 0) {
        return;
    }

    // rotate the array to the right by one position
    int temp = arr[n - 1];
    for (int i = n - 1; i > 0; i--) {
        arr[i] = arr[i - 1];
    }
    arr[0] = temp;

    // recursively rotate the remaining elements k-1 times
    rotateArray(arr, n, k - 1);
}

int main() {

	vector<int> vec{1,2,3,4,5,6,7,8,9,10};

  rightRotateMera(vec,2);

	return 0;
}

