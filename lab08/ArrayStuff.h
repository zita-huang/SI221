template <class DataType>
DataType minimum(DataType a[], int size){
    DataType minArray = a[0];
    for(int i = 1; i < size; i++){
        if(a[i] < minArray){
            minArray = a[i];
        }
    }
    return minArray;
}