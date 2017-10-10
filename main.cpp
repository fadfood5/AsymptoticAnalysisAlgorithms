#include <iostream>
#include "selectionSort.cpp"
#include "insertionSort.cpp"
#include "quickSort.cpp"
using namespace std;

class DataArray{
	public: 
		DataArray(int t, int n); 
		int size;
		int arr[];
};

DataArray::DataArray(int type, int size){
	int arr[size];
}

int main(int argc, char *argv[]){
	if ( argc != 3 ) // argc should be 3 for correct execution
    	cout<<"usage: "<< argv[0] <<" <filename>\n";
  	else {
  		//Get user input
		char* algoType = argv[1];
		int n = atoi(argv[2]);

		//Initialize array
		int arr[n];
		int arrKind = 2;

		//Build the array
		if(arrKind == 0){
			for(int i=0; i<n; i++){
				arr[i] = i;
			}
		}else if(arrKind == 1){
			for(int i=0; i<n; i++){
				arr[i] = 0;
			}
		}else if(arrKind == 2){
			for(int i=0; i<n; i++){
				arr[i] = rand() % 10;
			}
		}

		//Print array to test output before sort
		// for(int i =0; i < n; i++){
		// 	cout << arr[i] << endl;
		// }

		//Choose algorithm based on user input
		switch(algoType[0]){
			case 's':
				selectionsort(arr, n);
				break;
			case 'i':
				insertionsort(arr, n);
				break;
			case 'q':
				quicksort(arr, 0, n);
				break;
		}
	}
	return 0;
}