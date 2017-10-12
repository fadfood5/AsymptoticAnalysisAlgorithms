/*
Arguments:
	data: list of elements to sort
	size: number of elements in data
	low: index of first element in array (0 initially)
	right: index of last element in array (size of array initially)
*/
using namespace std;

template <typename T> void selectionsort(T data[], int size){
	cout << "selectionsort" << endl;
    int i,j,t;
	for(i=0;i<size;i++){
        for(j=i+1;j<size;j++){
        	if(data[j]<data[i]){
				t=data[i];
            	data[i]=data[j];
                data[j]=t;
        	}
        }
    }
    cout << "selectionsort finished" << endl;
}