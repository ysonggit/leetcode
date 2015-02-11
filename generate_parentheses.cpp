#include "utils.h"

using namespace std;

vector<string> generateParenthesis(int n) {
    if(n==0) return vector<string>(1, "");
    if(n==1) return vector<string>(1,"()");
    vector<string> results;
    for(int i=0; i<n; i++){
        for(string inner: generateParenthesis(i)){
            for(string outer: generateParenthesis(n-1-i)){
                results.push_back("("+inner+")"+outer);
            }
        }
    }
    return results;
}

int main(int argc, char *argv[])
{
    vector<string> results = generateParenthesis(3);
    printVector(results);
    return 0;
}


