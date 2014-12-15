#include "utils.h"

using namespace std;

/*
  if next char of p is NOT '*', it must match current char of s.
  continue matching s+1 and p+1

  if next char of p is '*':
  p[j] | p[j+1] | p[j+2] | ...
  x(.) |  *     |  y(.)  | ...   
  means current s[i].. s[i+k] may match p[j]
  then recursively matching
  match s[i], s[i+1], ... s[i+k] with p[j+2],
  until we could not find the matching

  question: two empty char return true or false?
 */
bool isMatch(const char *s, const char *p) {
    if(*p=='\0') return *s=='\0';
    if(*(p+1) != '*'){
        // tricky: must have  both *s !='\0' &&  *p != '.'
        // otherwise, case s = “abcbcd”, p = “a.*c.*d” can not be correctly judged
        if(!(*s == *p || (*s!='\0' && *p=='.'))) return false;
        return isMatch((s+1), (p+1)) ;
    }
    // next char of p is '*'
    while((*s != '\0' && *p=='.') || (*s == *p) ){
        // recursively check s[i]...s[i+k] with p[j+2]
        // backtracking method
        if(isMatch(s, p+2)) return true;
        s++;
    }
    return isMatch(s, p+2); // case s="aa", p=".*"
}

void test(const char *s, const char *p, bool expectation){
    if(isMatch(s, p) == expectation){
        cout<<"Correct Output!"<<endl;
    }else{
        cout<<"Wrong output!"<<endl;
    }
}
    
int main(int argc, char *argv[]){
    const char *s[] = {"abbbc", "ac", "abc", "aaa", "aa", "ab", "aab", "abcbcd", "abcd", "aaa"};
    const char *p[] = {"ab*c", "ab*c", "abc", "aa", ".*", ".*", "c*a*b", "a.*c.*d", "d*", "aaaa"};
    bool exps[] = {true, true, true, false, true, true, true, true, false, false};
    int n = getArrayLength(exps);
    for(int i=0; i<n; i++){
        test(s[i], p[i], exps[i]);
    }
   
    return 0;
}
