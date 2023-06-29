    void quickSort(int arr[], int low, int high)
    {
        //when only single element array is called
        if(low>=high){
            return;
        }
        int i=low-1;
        int j=low;
        //last element of array as pivot
        int pivot=high;
        while(j<pivot){
            //if j is less than pivot then increment i swap i and j and then increment j
            //if j is greater than pivot then just increment j
            if(arr[j]<arr[pivot]){
                ++i;
                swap(arr[i],arr[j]);
            }
            ++j;
        }
        //increment i to get the correct position of the pivot element
        ++i;
        //place pivot element in the correnct position and then recursively call for the left and right parts
        swap(arr[i],arr[pivot]);
        quickSort(arr,low,i-1);
        quickSort(arr,i+1,high);
    }
    