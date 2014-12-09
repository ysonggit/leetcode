#include <string>
#include "utils.h"

using namespace std;

string getLetters(char digit){
    string c;
    switch(digit){
    case '1':
        c = string(" ");
        break;
    case '2':
        c= string("abc");
        break;
    case '3':   
        c=string("def");
        break;
    case '4':
        c=string("ghi");
        break;
    case '5':
        c=string("jkl");
        break;
    case '6':
        c=string ("mno");
        break;
    case '7':
        c= string("pqrs");
        break;
    case '8':
        c=string("tuv");
        break;
    case '9':
        c=string("wxyz");
        break;
    default:
        c= string("");
    }
    return c;
}
void dfs(vector<string>& results, string &letters, string digits, int start_idx, int len){
    if(letters.length() == len){
        results.push_back(letters);
        return;
    }
    char cur_digit = digits.at(start_idx);
    string possible_letters = getLetters(cur_digit); 
    for(int i=0; i<possible_letters.length(); i++){
        letters.push_back(possible_letters[i]);
        dfs(results, letters, digits, start_idx+1, len);
        //letters.pop_back();
        letters.erase(letters.size()-1);
    }
}
    
vector<string> letterCombinations(string digits) {
    vector<string> results;
    string letters;
    dfs(results, letters, digits, 0, digits.length());
    return results;
}

int main(){
    string a("231");
    vector<string> combs = letterCombinations(a);
    printVector(combs);
    string b("9");
    vector<string> comb = letterCombinations(b);
    printVector(comb);
    return 0;
}
