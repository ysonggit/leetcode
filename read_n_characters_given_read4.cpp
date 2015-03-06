#include <gtest/gtest.h>
#include "utils.h"
using namespace std;

class Solution : public ReadAPI{
public:
    // call the default constructor of the base class
    // read4 reads input into a buffer
    // read reads buffer into buf
    int read(char *buf, int n) {
        bool eof = false;
        int read_bytes = 0;
        char * buffer = new char[4];
        while(!eof && read_bytes<n){
            int chars_read = read4(buffer);
            if(chars_read < 4) eof = true;
            int bytes = min(chars_read, n-read_bytes);
            memcpy(buf+read_bytes, buffer, bytes);
            read_bytes += bytes;
        }
        delete [] buffer;
        buffer = NULL;
        return read_bytes;
    }

    void testRead(int bytes_to_read, const char * desired_output){
        const int n = bytes_to_read;
        cout<<"Input:  "<<input<<endl;
        char * buf = new char [n];
        // cout<<"Test Read(): "<<  read(buf, n) <<" bytes read: \n";
        read(buf, n);
        cout<<"Output: "<<buf<<endl;
        ASSERT_STREQ(desired_output, buf);
        delete [] buf;
        buf = NULL;
    }
};

TEST(test_case, I){
    const char * str = "abcdefghijklmn";
    Solution s;
    s.setInput(str);
    int n = 10;
    const char * desired_output = "abcdefghij";
    s.testRead(n, desired_output);
}

TEST(test_case, II){
    const char * str = "ab";
    Solution s;
    s.setInput(str);
    int n = 4;
    const char * desired_output = "ab";
    s.testRead(n, desired_output);
}

TEST(test_case, III){
    const char * str = "abcdefghijklmnopqrstuvwxyz";
    Solution s;
    s.setInput(str);
    int n = 30;
    const char * desired_output = "abcdefghijklmnopqrstuvwxyz";
    s.testRead(n, desired_output);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

