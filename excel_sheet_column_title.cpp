#include "utils.h"

using namespace std;
/*
  iterative version
  given a number n = 52 should output AZ
  n % 26 = 0 --> get 'Z'
  n /= 26  -> n = 2, since reminder is 0, n should minus 1
  n-- --> get 'A'
*/
string convertToTitle(int n) {
    string title;
    if(n<=0) return title;
    while(n>0){
        int reminder = n % 26;
        n /= 26;
        if(reminder == 0){
            // append Z
            title.append("Z");
            n--;
        }else{
            char c = (char) (reminder + (int) 'A' - 1); 
            title += string(1,c);
        }
    }
    reverse(title.begin(), title.end());
    return title;
}

/*
  recursive version
 */
/*
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
    }*/

int main(int argc, char *argv[]){
    for(int i=1; i<=53; i++){
        //cout<<toChar(i)<<endl;
        cout<<convertToTitle(i)<<endl;
    }
    return 0;
}

