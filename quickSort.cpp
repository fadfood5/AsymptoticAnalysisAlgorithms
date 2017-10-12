/*
Arguments:
	data: list of elements to sort
	size: number of elements in data
	low: index of first element in array (0 initially)
	right: index of last element in array (size of array initially)
*/
using namespace std;

template<class T> inline void swap(T& v1,T& v2){
  T temp=v2;
  v2=v1;
  v1=temp;
}

template <class T> int partitionArray(T data[], int lo, int hi){
    int i, p;
    T t;
    p=data[lo];
	while(lo<hi){
    	while(data[lo]<p){
    		lo++;
    	}
        while(data[hi]>p)
            hi--;
        if(lo<hi){
            t=data[lo];
            data[lo]=data[hi];
            data[hi]=t;
        }else{
            t=p;
            p=data[lo];
            data[lo]=t;
            break;
        }
     }
     return hi;  
}

template <class T>
void quicksort(T data[], int lo, int hi){
  	int index,i;
  	if(lo<hi){
		index = partitionArray(data, lo, hi);
		quicksort(lo, index-1, data);
		quicksort(index+1, hi, data);
	}
}