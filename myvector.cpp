#include "myvector.h"
#include <iostream>
using namespace std;

int main(int argc, char **argv) {
    int n = 100;
    Vector<int> vec(n);
    cout<<"vector default size = "<<vec.size<<endl;
    for(int i=0; i<n; i++){
        vec.set(i,i);
        cout<<vec.get(i)<<" ";
    }
    cout<<endl;
    vec.set(29, 119);
    //cout<<"vector new size "<<vec.capacity<<endl;
    cout<<"vector[9] = "<<vec.get(9)<<endl;
    vec.clear();
    cout<<"After clear, vector size = "<<vec.size<<endl;
    for(int i=0; i<20; i++){
        vec.append(i*2);
        cout<<vec.get(i)<<" ";
    }
    cout<<endl;
    cout<<"vector size = "<<vec.size<<endl;
    return 0;
}