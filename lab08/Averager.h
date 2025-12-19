template <class DataType>
class Averager{
    public:
    int count = 0;
    DataType sum = 0.0;
    void add2collection(DataType val);
    DataType average();
};

template <class DataType>
void Averager<DataType>::add2collection(DataType val){
    count++;
    sum  = sum + val;
}

template <class DataType>
DataType Averager<DataType>::average(){
    DataType avg = sum/count;
    return avg;
}