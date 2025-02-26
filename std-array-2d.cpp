#include<iostream>
#include<vector>
#include<array>
#include<cstdint>
using namespace std;

#define M 4
#define N 4

void printMat(const array<array<int,N>,M> &mat) {
	for (uint16_t i {0}; i<M ; i++ ) {
		for (uint16_t j{0}; j<N ; j++ ) {
			//cout << matrix[i][j] << ' ';
			cout << (mat.at(i)).at(j) << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}

// for sum, matrix must be square matrix
// thus can use M for both M and N
int sumMat(const array<array<int,N>,M> &mat) {
	int sumBackSlash {0}, sumForSlash {0} ; 

	for (uint16_t i {0}; i<M ; i++ ) {
		sumBackSlash += (mat.at(i)).at(i);
	}
	cout << "backward slash type sum " << sumBackSlash << '\n';

	for (uint16_t i {0}; i<M ; i++ ) {
		sumForSlash += (mat.at(i)).at(N-1-i);
		// cout << "adding " << (mat.at(i)).at(N-1-i) << '\n' ;
	}
	cout << "forward slash type sum " << sumForSlash << '\n';

	return sumForSlash + sumBackSlash ;
}
	


int main() {

	// const uint16_t m = 4;
	// const uint16_t n = 5;

	array<int,N> column;
	column.fill(0);
	array<array<int,N>,M> matrix;
	matrix.fill(column);

	matrix[2].fill(20);

	printMat(matrix);

	matrix[0][0] = 1;
	matrix[1][1] = 5;
	matrix[2][2] = 1;
	matrix[3][3] = 9;

	matrix[0][3] = -1;
	matrix[1][2] = 100;
	matrix[2][1] = -10;
	matrix[3][0] = -30;

	printMat(matrix);

	int sum = sumMat(matrix) ;
	cout << "matrix sum is : " << sum << '\n' ;

	return 0;
}
