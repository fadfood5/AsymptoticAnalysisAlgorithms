#include <iostream>
#include <sys/resource.h>
#include <chrono>
typedef std::chrono::high_resolution_clock Clock;
using namespace std;
#include "Sorting.cpp"

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
	if ( argc != 4 ) // argc should be 3 for correct execution
    	cout<<"usage: "<< argv[0] <<" <filename>\n";
  	else {
  		const rlim_t kStackSize = 16 * 1024 * 1024;   // min stack size = 16 MB
	    struct rlimit rl;
	    int result;

	    result = getrlimit(RLIMIT_STACK, &rl);
	    if (result == 0)
	    {
	        if (rl.rlim_cur < kStackSize)
	        {
	            rl.rlim_cur = kStackSize;
	            result = setrlimit(RLIMIT_STACK, &rl);
	            if (result != 0)
	            {
	                fprintf(stderr, "setrlimit returned result = %d\n", result);
	            }
	        }
	    }
  		//Get user input
		char* algoType = argv[1];
		int n = atoi(argv[2]);

		//Initialize array
		Sorting<int> temp(n);
		int typeArray = atoi(argv[3]); //0 for sorted array, 1 for constant array, 2 for random array
		temp.fillArray(temp.arr, n, typeArray);

		//Print array to test output before sort
		// for(int i =0; i < n; i++){
		// 	cout << arr[i] << endl;
		// }

		//Choose algorithm based on user input
		auto t1 = Clock::now();
		auto t2 = Clock::now();
		switch(algoType[0]){
			case 's':
				temp.selectionsort(temp.arr, temp.size);
    			t2 = Clock::now();
				//doubleCheckSort(temp.arr, temp.size);
				break;
			case 'i':
				temp.insertionsort(temp.arr, temp.size);
    			t2 = Clock::now();
				//doubleCheckSort(temp.arr, temp.size);
				break;
			case 'q':
				temp.quicksort(temp.arr, 0, temp.size);
    			t2 = Clock::now();
				//doubleCheckSort(temp.arr, temp.size);
				break;
		}
		std::cout << "Time for " << temp.size << " " << algoType[0] << " in " <<  typeArray << ": "
              << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count()
              << " nanoseconds" << std::endl;
	}
	return 0;
}