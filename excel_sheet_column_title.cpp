#include "utils.h"

using namespace std;

string toChar(int n){
    // n is in[0, 25]
    string alphabet("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    return alphabet.substr(n,1);
}

string convertToTitle(int n) {
    if(n<=0) return string("");
    string result;
    int remainder = (n-1) % 26;
    if(n - 1 - remainder  ==0  ) {
        return  toChar(n-1);
    }else{
        int rest = (n -1 - remainder) / 26;
        result = convertToTitle(rest) + toChar(remainder);
    }
    return result;
}

int main(int argc, char *argv[]){
    for(int i=1; i<=53; i++){
        //cout<<toChar(i)<<endl;
        cout<<convertToTitle(i)<<endl;
    }
    return 0;
}

