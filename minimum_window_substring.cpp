#include "utils.h"
#include <gtest/gtest.h>

using namespace std;

/*
  idea :
  1 two pointers maintain a sliding window
  2 use a count to control, if count = T.length, move left pointer
  example S="acbbaca", T="aba"
  build a dictionary for T, call it need_find[256]
  so that need_find['a']=2 need_find['b']=1
  maintains a dictionary for S, call it has_found[256]

  initially left = 0, right=0
  move right, until has_found['a']=2, has_found['b']=2
  update count iff has_found[x] < need_find[x]
  a window is found as "acbba", update min_len = 5

  keep on moving right till reach the end, so has_found['a']=3
  move left to decrease has_found['a'] to 2
  then another window can be obtained "baca" with min_len=4

  corner case: if S does not contain such a window for T, return ?
*/
string minWindow(string S, string T){
    int s = S.length(), t = T.length();
    if (s<t) return string("");
    vector<int> has_found(256, 0);
    vector<int> need_find(256,0);
    for(char c : T){ need_find[(int)c]++; }
    int count = 0;
    int min_len = s+1;
    int start_idx_with_min_len = -1;
    for(int left =0, right = 0; right < s; right++){
        // update count and has_found
        char cur = S[right];
        if(need_find[cur] == 0 ) continue;
        if(has_found[cur]<need_find[cur]) count++;
        has_found[cur]++;
        // trace count to determine when the window is found
        while(count == t){
            // move left
            // 1 S[left] is not in need_find, then just pass by
            if(need_find[S[left]] == 0){
                left++;
            }
            // 2 S[left] is in need_find , decrease has_found[S[left]] by 1
            else if(has_found[S[left]] > need_find[S[left]]) {
                has_found[S[left]] --;
                left++;
            }else{
                // update start_idx_with_min_len
                if(min_len > right - left+1 ){
                    min_len = right-left+1;
                    start_idx_with_min_len = left;
                }
                break;
            }
        }
    }
    // corner case
    if(min_len>s) return string("");
    return S.substr(start_idx_with_min_len, min_len);
}

TEST(MinWindow, I){
    string S("acbbaca");
    string T("aba");
    const char * r = "baca";
    const char * m = minWindow(S, T).c_str();
    ASSERT_STREQ(r, m);
}

TEST(MinWindow, II){
    string S("FADABEDCODEBANC");
    string T("ABC");
    const char * r = "BANC";
    const char * m = minWindow(S, T).c_str();
    ASSERT_STREQ(r, m);
}

TEST(MinWindow, III){
    string S("cabwefgewcwaefgcf");
    string T("cae");
    const char * r = "cwae";
    const char * m = minWindow(S, T).c_str();
    ASSERT_STREQ(r, m);
}

int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


