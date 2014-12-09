#include <stack>
#include <sstream>
#include "utils.h"

using namespace std;
bool isOperator(string c){
    if(!c.compare("+") || !c.compare("-") || !c.compare("*") || !c.compare("/")) return true;
    return false;
}
int stringToInt(string s){
    stringstream ss;
    int i;
    ss<<s;
    ss>>i;
    return i;
}
int compute(int a, int b, string op){
    //cout<<a<<op<<b<<" = \n";
    if(op=="+") return a+b;
    if(op=="-") return a-b;
    if(op=="*") return a*b;
    return int(a/b); // divide by 0?
}
int evalRPN(vector<string> &tokens) {
    if(tokens.size()==0) return 0;
    stack<int> operands;
    for(int i=0; i<tokens.size(); i++){
        string token = tokens.at(i);
        if(!isOperator(token)){
            operands.push(stringToInt(token));  
        }else{
            // pop two values 
            // do arithmetic operation
            // push to stack
            int c1 = operands.top();
            operands.pop();
            int c2 = operands.top();
            operands.pop();
            operands.push(compute(c2, c1, token));
        }
    }
    return operands.top();
}
int main(){
    vector<string> tokens;
    tokens.push_back("-2");
    tokens.push_back("-1");
    tokens.push_back("+");
    tokens.push_back("3");
    tokens.push_back("*");
    cout<<evalRPN(tokens)<<endl;
    vector<string> tokens1;
    tokens1.push_back("0");
    tokens1.push_back("3");
    tokens1.push_back("/");
    cout<<evalRPN(tokens1)<<endl;
    vector<string> tokens2;
    tokens2.push_back("4");
    tokens2.push_back("13");
    tokens2.push_back("5");
    tokens2.push_back("/");
    tokens2.push_back("+");
    cout<<evalRPN(tokens2)<<endl;
    return 0;
}
