/*
Arguments:
	data: list of elements to sort
	size: number of elements in data
	low: index of first element in array (0 initially)
	right: index of last element in array (size of array initially)
*/
using namespace std;

template <class T> void quicksort(T arr[], int low, int right) {
      int i = low, j = right;
      T tmp;
      T pivot = arr[(low + right) / 2];
      while (i <= j) {
            while (arr[i] < pivot)
                  i++;
            while (arr[j] > pivot)
                  j--;
            if (i <= j) {
                  tmp = arr[i];
                  arr[i] = arr[j];
                  arr[j] = tmp;
                  i++;
                  j--;
            }
      };

      if (low < j)
            quicksort(arr, low, j);
      if (i < right)
            quicksort(arr, i, right);
}
