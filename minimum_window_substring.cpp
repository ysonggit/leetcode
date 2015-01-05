#include "utils.h"
#include <gtest/gtest.h>

using namespace std;

/*
  idea: move a sliding window represented as two pointers
        presteps: establish a dict (hashmap) of characters in T,
                  key is the char, and value is the shown times in S
                  initially , values are all 0s
  1. first move back pointer, count the frequency of each T'char shown in S
  2. if any one char in the dict showns 0 times, return ""
  3. move front pointer while deducing the count in the dict, until the dict[S[front]] is equal to destdict[]
     record the current substring
  4. return step 1 until to the tail of S
  Question : how about T contains duplicated characters?
  answer: use two dicts : dest dict and actual dict 
 */

string minWindow(string S, string T){
    int n = S.length(), m = T.length();
    if (n < m) return string("");
    // create dest dict of T
    vector<int> dest_dict(128, 0);
    vector<int> actual_dict(dest_dict);
    for(char t: T){
        int idx = (int)(unsigned char)t;
        dest_dict[idx]++;
    }
    int front = 0, count =0;
    int min_len = n+1, min_start = front;
    for(int back=0; back<n; back++){
        // move back pointer i
        int b_idx = (int)(unsigned char)S[back];
        if(dest_dict[b_idx] != 0){
            actual_dict[b_idx]++;
            if(actual_dict[b_idx]<= dest_dict[b_idx]) count++;
            while(count == m){
                // current window contains all chars in T
                // now move front pointer
                int f_idx = (int)(unsigned char)S[front];
                if(dest_dict[f_idx]==0){
                    front++;
                }
                else if (actual_dict[f_idx]>dest_dict[f_idx]){
                    actual_dict[f_idx]--;
                    front++;
                }else{
                    // tricky: use min_len = min(min_len, back-front+1);
                    //             min_start = front;
                    //    is wrong because min_start is not correctly updated
                    if(min_len > back-front+1){
                        min_start = front;
                        min_len = back-front+1;
                    }
                    break;
                }

            }
        }
    }
    if(min_len > n) return string("");
    return S.substr(min_start, min_len);
}

TEST(MinWindow, One){
    string S("FADABEDCODEBANC");
    string T("ABC");
    string res("BANC");
    const char * r = res.c_str();
    const char * m = minWindow(S, T).c_str();
    ASSERT_STREQ(r, m);
}

TEST(MinWindow, Two){
    string S("cabwefgewcwaefgcf");
    string T("cae");
    string res("cwae");
    const char * r = res.c_str();
    const char * m = minWindow(S, T).c_str();
    ASSERT_STREQ(r, m);
}

int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


