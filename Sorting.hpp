template<typename T> class Sorting{
	public:
		T *arr;
		int size;
		void selectionsort(T data[], int size){
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
		}
		void insertionsort(T* data, int size){
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
		void quicksort(T arr[], int low, int right) {
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
		void fillArray(T arr[], int n, int arrKind){
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
		}
};