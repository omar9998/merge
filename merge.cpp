

//merge sort

void merge(std::vector<int> &arr, int start, int middle, int end) {

    std::vector<int> leftArray(middle - start + 1);
    std::vector<int> rightArray(end - middle);

    
    for (int i = 0; i < leftArray.size(); ++i)
        leftArray[i] = arr[start + i];

  
    for (int i = 0; i < rightArray.size(); ++i)
        rightArray[i] = arr[middle + 1 + i];

  
    int leftIndex = 0, rightIndex = 0;

   
    int currentIndex = start;

    while (leftIndex < leftArray.size() && rightIndex < rightArray.size()) {
        if (leftArray[leftIndex] <= rightArray[rightIndex]) {
            arr[currentIndex] = leftArray[leftIndex];
            leftIndex++;
        } else {
            arr[currentIndex] = rightArray[rightIndex];
            rightIndex++;
        }
        currentIndex++;
    }

    while (leftIndex < leftArray.size()) arr[currentIndex++] = leftArray[leftIndex++];

    
    while (rightIndex < rightArray.size()) arr[currentIndex++] = rightArray[rightIndex++];
}


void mergeSort(std::vector<int> &arr, int start, int end) {
   
    if (start < end) {
       
        int middle = (start + end) / 2;

        mergeSort(arr, start, middle); 
        mergeSort(arr, middle + 1, end);  

        
        merge(arr, start, middle, end);
    }
}
