/*
Arguments:
	data: list of elements to sort
	size: number of elements in data
	loww: index of first element in array (0 initially)
	right: index of last element in array (size of array initially)
*/
using namespace std;

template<class T> inline void swap(T& v1,T& v2){
  T temp=v2;
  v2=v1;
  v1=temp;
}

template <class T> int partitionArray(T data[], int low, int high){
  T x = data[low];
  T temp;
  int i = low;
  int j = high;
  while(i<j){
    while(data[j] > x)
      j--;
    while(data[i] < x)
      i++;
    if(i<j){
      temp = data[i];
      data[i] = data[j];
      data[j] = temp;
    }else{
      temp = x;
      x = data[i];
      data[i] = temp;
    }
  }
  return j;

   //  int i, p;
   //  T t;
   //  p=data[low];
	  // while(low<high){
   //  	while(data[low]<p)
   //  		low++;
   //    while(data[high]>p)
   //      high--;
   //    if(low<high){
   //        t=data[low];
   //        data[low]=data[high];
   //        data[high]=t;
   //    }else{
   //        t=p;
   //        p=data[low];
   //        data[low]=t;
   //        break;
   //    }
   //  }
   //  return high;  
}

template <typename T> void quicksort(T data[], int low, int high){
	int index, i;
	if(low<high){
		index = partitionArray(data, low, high);
		quicksort(data, low, high);
		quicksort(data, index+1, high);
	}
}