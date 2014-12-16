#include "utils.h"

using namespace std;
/*
  question overflow? YES: see"0.9.9.9.9.9.9.9.9.9.9"
  illegal input checking? for example: many dots 32...243?
  Can not convert string to integer for, exampe, "1.1"<"1.10"

  idea:
  put each non-dot toke into a list of strings
  compare the most important bit (the first bit where two numbers are different)
*/ 
struct Version{
    Version(vector<string> n, int v): num(n), valid(v){ }
    vector<string> num;
    bool valid;
    inline int length() {return num.size();}
    void appendZeros(int k){
        for(int i=0; i<k; i++){
            num.push_back(string("0"));
        }
    }
};

Version convertStr(string vs){
    bool v=true;
    vector<string> n;
    if(vs.empty()) {v = false;}
    for(int i=0; i<vs.length()-1; i++){
        if(vs[i]=='.' && vs[i+1]=='.'){
            v = false;
        }
    }
    char * dup = strdup(vs.c_str());
    char * token = std::strtok(dup, ".");
    while(token != NULL){
        //cout<<token<<endl;
        int tmp = stoi(string(token)); // 01 -> 1
        string s = std::to_string(tmp);
        n.push_back(s);
        // http://en.cppreference.com/w/cpp/string/byte/strtok
        // If str == NULL, the call is treated as a subsequent calls to strtok:
        // the function continues from where it left in previous invocation.
        // The behavior is the same as if the previously stored pointer is passed as str. 
        token = std::strtok(NULL, ".");
    }
    // free dup
    free(dup);
    return Version(n, v);
}

ostream & operator << (ostream & lhs, const Version & v){
    lhs << "Version \n";
    for(int i=0; i< v.num.size()-1; i++){
        lhs << v.num[i] << "." ;
    }
    lhs << v.num.back() << "\n";
    return lhs;
}


int compareVersion(string version1, string version2) {
    Version v1 = convertStr(version1);
    Version v2 = convertStr(version2);
    if(v1.valid && v2.valid){
        //cout<<v1<<v2<<endl;
        if(v1.length()> v2.length()){
            v2.appendZeros(v1.length()-v2.length());
        }else{
            v1.appendZeros(v2.length()-v1.length());
        }
        int most_important_bit = -1;
        for(int i=0; i<v1.num.size(); i++){
            if(!(v1.num[i] == v2.num[i])){
                most_important_bit = i;
                break;
            }
        }
        if(most_important_bit < 0) return 0;
        if(stoi(v1.num[most_important_bit]) > stoi(v2.num[most_important_bit])) return 1;
        if(stoi(v1.num[most_important_bit]) < stoi(v2.num[most_important_bit])) return -1;
    }
    return 0;
}

void test(string v1, string v2, int expectation){
    if(compareVersion(v1, v2)== expectation){
        cout<<"Correct output!"<<endl;
    }else{
        cout<<"Wrong output!"<<endl;
    }
}

int main(int argc, char *argv[]){
    string vs[] = {"01", "1", "1", "0", "1.0", "1.1", "0.1", "0.0.1", "0.9.9.9.9.9.9.9.9.9.9.9.9", "1.0", "1.1", "1.10"};
    int exps[] = {0, 1, -1, 1, -1, -1};
    int n= getArrayLength(exps);
    for(int i=0; i<n; i++){
        test(vs[i*2], vs[i*2+1], exps[i]);
    }
    return 0;
}

