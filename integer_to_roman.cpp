#include "utils.h"

using namespace std;

/*
  I  - 1
  V  - 5
  X  - 10
  L  - 50
  C  - 100
  D  - 500
  M  - 1000

  4 =  1 substracted by 5 : IV
  9 =  1 .. 10 : IX
  40 = 10 .. 50 : XL
  90 = 10 .. 100 : XC
  400 = 100 .. 500 : CD
  900 = 100 substracted by 1000 : CM

  given a number N, greedy algorithm:
  every time search the max Roman letter it can cover (-)
  and connect each Roman letter

  for example, 531 = 500 + 10 + 10 + 10 + 1 = DXXXI

  constrain: input must be 1 - 3999
*/
string intToRoman(int num) {
    string roman [] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
    int arabic [] = {1,4,5,9,10,40,50,90,100,400,500,900,1000};
    int n = sizeof(arabic)/sizeof(*arabic);
    string result;
    while(num>0){
        int max_i = -1;
        for(int i=n-1; i>=0; i--){
            if( num >= arabic[i] && i > max_i ){
                max_i = i;
            } 
        }
        result.append(roman[max_i]);
        num -= arabic[max_i];
    }
    return result;
    
}

int main(int argc, char *argv[])
{
    cout<<intToRoman(531)<<endl;
    cout<<intToRoman(900)<<endl;
    return 0;
}
