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

template <typename T> void doubleCheckSort(T data[], int size){
	int temp = 0;
	for(int i=1; i < size; i++){
		if(data[i] < data[i-1]){
			temp = 1;
			cout<< "Sorting is false" << endl;
			break;
		}
	}
	if(temp == 0)
		cout<< "Sorting is correct" << endl;
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
				doubleCheckSort(arr, n);
				break;
			case 'i':
				insertionsort(arr, n);
				doubleCheckSort(arr, n);
				break;
			case 'q':
				quicksort(arr, 0, n);
				doubleCheckSort(arr, n);
				break;
		}
	}
	return 0;
}