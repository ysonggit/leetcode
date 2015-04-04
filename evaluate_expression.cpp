#include <gtest/gtest.h>
#include "utils.h"
using namespace std;
// infix to postfix is overkill
// TODO: simple version

bool higherPrecedence(char op1, char op2){
    if(op1=='*' || op1=='/') return (op2=='+'|| op2=='-') ? true : false;
    if(op1=='+' || op1=='-') return (op2=='*' || op2=='/') ? false : true;
    return true;
}

string infixToPostfix(string infix){
    string postfix;
    stack<char> operators;
    for(int i=0; i<infix.length(); i++){
        char token = infix[i];
        if(isdigit(token)) {
            postfix.push_back(token);
        }else{
            if(operators.empty()){
                operators.push(token);
            }else{
                // compare precedence with stack toperators
                char op = operators.top();
                while(higherPrecedence(op, token)){
                    operators.pop();
                    postfix.push_back(op);
                    if(operators.empty()) break;
                    op = operators.top();
                }
                operators.push(token);
            }
        }
    }
    while(!operators.empty()){
        postfix.push_back(operators.top());
        operators.pop();
    }
    return postfix;
}

int compute(int a, int b, char op){
    if(op=='+') return a+b;
    if(op=='-') return a-b;
    if(op=='*') return a*b;
    return a/b;
}

int evalExpr(string expr){
    string postfix = infixToPostfix(expr);
    stack<int> operands;
    for(int i=0; i<postfix.length(); i++){
        char token = postfix[i];
        if(!isdigit(token)){
            // compute and push to stack
            int b = operands.top();
            operands.pop();
            int a = operands.top();
            operands.pop();
            operands.push(compute(a, b, token));
        }else{
            operands.push((int)token-'0');
        }
    }
    return operands.top();
}

TEST(EvalExpr, I){
    string expr("3+2*2");
    int res = 7;
    ASSERT_EQ(res, evalExpr(expr));
}


TEST(EvalExpr, II){
    string expr("2*3-4/5");
    int res = 6;
    ASSERT_EQ(res, evalExpr(expr));
}

// TEST(EvalExpr, III){
//     string expr("-4"); // invalid input
//     int res = -4;
//     ASSERT_EQ(res, evalExpr(expr));
// }

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


