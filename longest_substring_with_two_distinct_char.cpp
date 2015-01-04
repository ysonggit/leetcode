#include "utils.h"
#include <gtest/gtest.h>

using namespace std;
/*
  idea : maintain a sliding window
         use 3 indices to trace/represent the window
         
 */
int lengthOfLongestSubstringTwoDistinct(string s){
    int n = s.length();
    if(n==0) return 0;
    int i=0, j=0;
    int max_len = 1;
    for(int k=1; k<n; k++){
        if(s[k]!= s[i] && s[k]!= s[j]){
            j = k;
            //search back from k to j
            // find the character that is different from s[k], mark its index as i
            int  tmp=k-1;
            while((s[k]==s[tmp] || s[tmp]==s[tmp-1]) && tmp>0 ){
                tmp--;
            }
            i = tmp;
        }
        max_len = max(max_len, k-i+1);
    }
    return max_len;
}

TEST(TwoDistinct, One){
    string s("eceba");
    int res = 3;
    ASSERT_EQ(res, lengthOfLongestSubstringTwoDistinct(s));
}

TEST(TwoDistinct, Two){
    string s("abaccc");
    int res = 4;
    ASSERT_EQ(res, lengthOfLongestSubstringTwoDistinct(s));
}

TEST(TwoDistinct, Three){
    string s("abaacddefffggesabdakdhijklmnaabbbcdcdcdcdhiiilm");
    int res = 8;
    ASSERT_EQ(res, lengthOfLongestSubstringTwoDistinct(s));
}


TEST(TwoDistinct, Four){
    string s("aac");
    int res = 3;
    ASSERT_EQ(res, lengthOfLongestSubstringTwoDistinct(s));
}

int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


