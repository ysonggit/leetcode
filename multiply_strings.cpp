#include "utils.h"
#include <gtest/gtest.h>

using namespace std;
/*
  idea:
  represent each string number as a vector of integers (refer add-one)
  for example store "9876732" as
               _______________
               |9|8|7|6|7|3|2|
               ---------------
  
  for a[0..n-1] and b[0..m-1]
  r[i] is the i~th digit of the product from right to left
  r[i] = c + sum_of(a[j] * b[k])
             j+k = i
               
 */

// use lambda function: [capture](param) --> return type {body}
// example: [] (int x, int y) -> int {return x+y;}
// assume input string does not contain any invalid characters
vector<int> bigInt(const string & num){
    vector<int> bignum;
    for_each(num.begin(), num.end(), [&bignum](char c){
            bignum.push_back((int) c-'0');
        } );
    reverse(bignum.begin(), bignum.end());
    return bignum;
}

string bigStr(const vector<int>& bignum){
    stringstream ss;
    for_each(bignum.begin(), bignum.end(), [&ss](int i){
            ss<<i;
        });
    string s = ss.str();
    size_t first_nonzero = s.find_first_not_of("0");
    if(first_nonzero == string::npos) return string("0");
    return s.substr(first_nonzero);
}

vector<int> multiplyBigInts(const vector<int> & a,
    const vector<int> & b){
    vector<int> product(a.size()+b.size(), 0);
    for(int i=0; i<a.size(); i++){
        for(int j=0; j<b.size(); j++){
            product[i+j] += a[i] * b[j];
            product[i+j+1] += product[i+j]/10; // plus carry out
            product[i+j] %= 10;
        }
    }
    reverse(product.begin(), product.end());
    return product;
}

string multiply(string num1, string num2) {
    vector<int> product = multiplyBigInts(bigInt(num1), bigInt(num2));
    return bigStr(product);
}

TEST(MulitplyStrings, I){
    string num1("32");
    string num2("26");
    const char * prod = multiply(num1, num2).c_str();
    const char * res = "832";
    ASSERT_STREQ(res, prod);
}

TEST(MulitplyStrings, II){
    string num1("0");
    string num2("0");
    const char * res = "0";
    const char * prod =multiply(num1, num2).c_str();
    ASSERT_STREQ(res, prod);
}

int main(int argc, char *argv[]){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

