/*
Arguments:
	data: list of elements to sort
	size: number of elements in data
	low: index of first element in array (0 initially)
	right: index of last element in array (size of array initially)
*/
using namespace std;

template <typename T> void insertionsort(T* data, int size){
	cout << "insertionsort" << endl;
	
	int i, j, tmp;
      for (i = 1; i < size; i++) {
            j = i;
            while (j > 0 && data[j - 1] > data[j]) {
                  tmp = data[j];
                  data[j] = data[j - 1];
                  data[j - 1] = tmp;
                  j--;
            }
      }
}
