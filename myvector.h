#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
template<typename T>
class Vector{
public:
    Vector() : size(0) {};
    Vector(int n);
    int size; 
    void clear();
    void append(T );
    void set(int, T);
    T get(int );
    void resize(int );
private:
    T* data;
};

template<typename T>
Vector<T>::Vector(int n){
    size = n;
    data = new T[size];
}

template<typename T>
void Vector<T>::clear(){
    size = 0;
    delete [] data;
}

template<typename T>
void Vector<T>::append(T val){
    data[size++] = val;
}

template<typename T>
void Vector<T>::set(int i, T val){
    while(size<=i){
        append(0);
    } 
    data[i] = val;
    size++;
}

template<typename T>
T Vector<T>::get(int i){
    if(i>= size || i<0) {
        printf("Index %d out of bounds of vector size %d\n", i, size);
        exit(1);
    }
    return data[i];
}

template<typename T>
void Vector<T>::resize(int n){
    if(size==n) return;
    if(n==0) clear();
    T* resize_data = new T[n];
    for(int i=0; i<min(n, size); i++){
        resize_data[i] = data[i];
    }
    delete [] data;
    data = resize_data;
    size = n;
}

