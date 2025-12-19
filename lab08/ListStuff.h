#include "List.h"
template <class DataType>
DataType minimum(List<DataType> &L){
    typename List<DataType>::Iterator itr = L.begin();
    DataType minItr = itr.get();
    itr.next();
    while(!itr.equal(L.end())){
        if(itr.get() < minItr){
            minItr = itr.get();
        }
        itr.next();
    }
    return minItr;
}