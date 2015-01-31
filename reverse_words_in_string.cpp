#include "utils.h"

using namespace std;

/*
  idea : search from back to front
         skip any whitespaces
         
         question : contain only letters and whitespaces?
                    any number or other chars?

                    contains only whitespaces? return what?
 */
void reverseWords(string &s) {
    if(s.empty()) return;
    int n = s.length();
    string rev;
    int i=n-1;
    while(i>=0){
        while(s[i]==' ' && i>=0) {
            i--;
        }
        if(i<0) break;
        string word;
        while(s[i]!=' ' && i>=0) {
            word.push_back(s[i]);
            i--;
        }
        reverse(word.begin(), word.end());
        rev += word + string(" ");
    }
    s.clear();
    s = rev.substr(0, rev.length()-1); // last bit is a whitespace
}

int main(int argc, char *argv[]){
    string s("  the sky   is  blue   ");
    reverseWords(s);
    cout<<s<<endl;
    string t("         ");
    reverseWords(t);
    cout<<t<<endl;
    string a("a");
    reverseWords(a);
    cout<<a<<endl;
    return 0;
}

