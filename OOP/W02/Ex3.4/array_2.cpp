#include "array2.h"

Array::Array(){
    length = 0;
}

Array::Array(int n) {
    length = n;
}

Array::Array(int arr[] , int n) {
    length = n;
    for (int i = 0 ; i < n ; i++) {
        a[i] = arr[i];
    }
}

Array::Array(const Array& a1) {
    length = a1.length;
    
    for (int i = 0 ; i < length; i++) {
        a[i] = a1.a[i];
    }
}
  

