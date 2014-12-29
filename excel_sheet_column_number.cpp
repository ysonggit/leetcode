#include "utils.h"

using namespace std;

/* idea:
   number = 0
   for each char in s:
       number *= 26
       number += (int) s[i]-'A' +1

   question: overflow? illegal input check?
 */
int titleToNumber(string s) {
    int number = 0;
    int n = s.length();
    for(int i= 0; i < n; i++){
        number *= 26;
        int cur_num = (int) s[i] - 'A' + 1;
        number +=  cur_num;
    }
    return number;
}

int main(int argc, char *argv[])
{
    string s[] = {"A","B","C","D","E","F","G","Z","AA", "AB", "AZ", "BA", "BZ"};
    for (int i=0; i<13; i++){
        cout<<titleToNumber(s[i])<<endl;
    }
    return 0;
}

