#include <iostream>
#include "selectionSort.cpp"
#include "insertionSort.cpp"
#include "quickSort.cpp"
using namespace std;

int main(int argc, char *argv[]){
	cout << "Hello world\n";
	char* type = argv[1];
	int n = (int)(argv[2][0] - '0');
	int tempArray[n];
	switch(type[0]){
		case 'q':
			selectionsort(tempArray, n);
			break;
		case 'i':
			insertionsort(tempArray, n);
			break;
		case 's':
			quicksort(tempArray, 0, n);
			break;
	}
	return 0;
}