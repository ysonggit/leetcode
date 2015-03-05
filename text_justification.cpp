#include <gtest/gtest.h>
#include "utils.h"

using namespace std;

/*
  idea: 
  read given words one by one, while check if these words' total length is greater than L 
  if exceeds L, then combine these words to form one line 
  (need variables to record the starting position and total length)
  so on and so forth
  until the last line, just append spaces 
    
  question: how to insert spaces to let them distributed as evenly as possible?
    
  for example, given three words: This is an. how to insert spaces evenly to make it "This    is    an"?
  char_count = 8, spaces_count = L-char_count=8, words_count = 3, so 2 places to insert spaces
  hence each places we put spaces_count/2 = 4
    
  example of text
  char_count = 13, words_count = 3, 2 places to insert spaces, 
  spaces_count = L-13=5  put each space 5/2=2 spaces 
  still remains 5%2= 1 spaces, for these 5%2 spaces, insert to each place until remaining space # is 0

  corner case:
  1) the last line, between every two words, only one space. after the last word, fill spaces until total length reaches L
  2) only one word in a line:
     if L > word.length left alignment by append spaces
     if L == word.length, no spaces needed
*/
string justifyCurrentLine(vector<string>& words, int first, int last, int &L, bool is_last_line){
    string justified_line;
    int places = last-first; // = words_count -1
    if(is_last_line){
        for(int i=first; i<last; i++){
            justified_line += words[i];
            if(places>=1) justified_line.append(1, ' ');
        }
        justified_line += words[last];
        int spaces_needed = L - justified_line.length();
        if(spaces_needed>0) justified_line.append(spaces_needed, ' ');
        return justified_line;
    }
  
    int char_count = 0;
    for(int i=first; i<=last; i++){
        char_count += words[i].length();
    }
    int spaces_to_insert = L - char_count;
    if(places<1){
        // only one word in a line
        // but this is not the last line
        justified_line += words[first];
        justified_line.append(spaces_to_insert, ' ');
    }else{
        int min_spaces = spaces_to_insert/places;
        int remaining_spaces = spaces_to_insert % places;
        for(int i=first; i<last; i++){
            justified_line += words[i];
            justified_line.append(min_spaces, ' ');
            if(remaining_spaces > 0){
                justified_line.append(1, ' ');
                remaining_spaces--;
            }
        }
        justified_line += words[last];
    }
    return justified_line;
}

vector<string> fullJustify(vector<string> &words, int L) {
    if(L<=0 || words.empty()) return vector<string>{""};
    vector<string> results;
    int begin =0, len=0;
    int n = words.size();
    for(int i=0; i<n; ++i){
        if(len+words[i].length()+(i-begin)>L){ 
            // only select from word[begin] to word[i-1]
            results.push_back(justifyCurrentLine(words, begin, i-1, L, false));
            begin = i;
            len=0;
        }
        // word[i] should be placed in next line
        len+= words[i].length();
    }
    // for the last line, if lenght is < L, just append spaces
    results.push_back(justifyCurrentLine(words, begin, n-1, L, true));
    return results;
}

TEST(test_case, I){
    vector<string> words{"a","b","c","d","e"};
    int L=1;
    vector<string> results = fullJustify(words, L);
    printVector(results);
}

TEST(test_case, II){
    vector<string> words{"Listen","to","many,","speak","to","a","few."};
    int L=6;
    vector<string> results = fullJustify(words, L);
    printVector(results);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}