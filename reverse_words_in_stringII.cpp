#include "utils.h"

using namespace std;

/*
  Note:
  The input string does not contain leading or trailing spaces and the words are always separated by a single space.
  idea : search from back to front
  question :whitespace only or empty string?
 */
void reverseWord(string &s, int start, int end){
    while(start<end){
        swap(s[start], s[end]);
        start++;
        end--;
    }
}

void reverseWords(string &s) {
    if(s.empty()) return;
    // check if string contains only whitespaces
    if(s.find_first_not_of(" ") == std::string::npos) return;
    // if now space contains, means the string is actually a word
    if(s.find_first_of(" ") == std::string::npos) return;
    int n = s.length();
    reverse(s.begin(), s.end());
    int slow =0, fast =0;
    while(fast<n){
        if(!isspace(s[fast]) && !isspace(s[slow]) ){
            // both slow and fast are not spaces
            fast++;
        }
        if(!isspace(s[slow]) && (isspace(s[fast]) || fast==n-1)){
            int end = (fast==n-1)? n-1 : fast-1;
            reverseWord(s, slow, end);
            fast++;
            slow= fast;
        }
    }
}

int main(int argc, char *argv[]){
    string s("the sky is blue");
    reverseWords(s);
    cout<<s<<endl;
    string t("   ");
    reverseWords(t);
    cout<<t<<endl;
    string a("hi!");
    reverseWords(a);
    cout<<a<<endl;
    return 0;
}

