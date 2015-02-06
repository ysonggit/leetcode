#include "utils.h"
#include <bitset>
#include <unordered_set>

using namespace std;
/*
  idea: 
  for each char s[i] in s, i =0 ... n-1
      for each s.substr(i,10)
      save in hashmap and value is the times it appears

     Memory Limit Exceeded 

vector<string> findRepeatedDnaSequences(string s){
    vector<string> repeats;
    int n = s.length();
    if(s.empty() || s.length()<20) return repeats;
    unordered_map<string,int> dna;
    for(int i=0; i<n-10; i++){
        string ten_letters = s.substr(i, 10);
        if(dna.find(ten_letters) == dna.end()){
            dna.insert(make_pair(ten_letters, 1));
        } else{
            dna[ten_letters]++;
        }
    }
    for(auto iter= dna.begin(); iter != dna.end(); ++iter){
        if(iter->second>1) repeats.push_back(iter->first);
    }
    
    return repeats;
    }*/
// input is a 10-letter string
// output is an integer
int encodeDnaMolecule(string s){
    string encode;
    for(int i=0; i<s.length(); i++){
        switch(s[i]){
            case 'A':
                encode +=string("00");
                break;
            case 'C':
                encode += string("01");
                break;
            case 'G':
                encode += string("10");
                break;
            default:
                encode += string("11");
        }
    }
    bitset<32> bs(encode);
    return bs.to_ulong();
}

string decodeDnaMolecule(int n){
    bitset<32> bs(n);
    string decode=bs.to_string();
    string dna;
    for(int i=12; i<decode.size(); i+=2){
        string twobits = decode.substr(i,2);
        if(twobits == string("00")) dna += string("A");
        if(twobits == string("01")) dna += string("C");
        if(twobits == string("10")) dna += string("G");
        if(twobits == string("11")) dna += string("T");
    }
    return dna;
}

vector<string> findRepeatedDnaSequences(string s){
    vector<string> repeats;
    int n = s.length();
    if(s.empty() || s.length()<20) return repeats;
    unordered_map<int,int> encoded_numbers;
    for(int i=0; i<n-9; i++){
        int num = encodeDnaMolecule(s.substr(i,10));
        if(encoded_numbers.find(num)==encoded_numbers.end()){
            encoded_numbers.insert(make_pair(num, 1));
        }else{
            encoded_numbers[num]++;
        }
    }
    for(auto it=encoded_numbers.begin(); it != encoded_numbers.end(); it++){
        if(it->second>1){
            string dna = decodeDnaMolecule(it->first);
            repeats.push_back(dna);
        }
    }
    return repeats;
}

int main(int argc, char *argv[]){
    string s("AAAAACCCCCAAAAACCCCCAAAAAGGGTTT");
    vector<string> res = findRepeatedDnaSequences(s);
    printVector(res);
    return 0;
}



