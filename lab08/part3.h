class Averager{
    public:
    int count = 0;
    double sum = 0.0;
    void add2collection(double val);
    double average();
};

void Averager::add2collection(double val){
    count++;
    sum  = sum + val;
}

double Averager::average(){
    double avg = sum/double(count);
    return avg;
}