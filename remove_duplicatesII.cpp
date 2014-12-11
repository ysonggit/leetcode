#include "utils.h"

using namespace std;
// given sorted array
// duplicates are allowed at most twice
int removeDuplicates(int A[], int n) {
    if(n<=2) return n;
    int index = 1; //trick
    int count = 1;
    for(int i=1; i<n; i++){
        if(A[i] == A[i-1]){
            count++;
        }else{
            // reset count
            count=1;
        }
        if(count<=2){
            // pass by duplicates by copying
            // numbers shown only once or twice
            A[index] = A[i];
            index++;
        }
    }
    return index;
}


int main(){
    int A[6] ={
        1,1,1,2,2,3
    };
    cout<<removeDuplicates(A, 6)<<endl;
    return 0;
}
