#include <gtest/gtest.h>
#include "utils.h"
using namespace std;

class Solution : public ReadAPI{
public:
    // call the default constructor of the base class
     // read4 reads input into a buffer
    char * buffer = new char [4];
    // how many bytes read from buffer
    int bytes_from_buffer = 0;
    // offset from starting pos of buffer to the pos that should be read
    int offset = 0;
    // read reads buffer into buf
    // buf should be allocated properly
    int read(char *buf, int n) {
        bool eof = false;
        int bytes_in_buf = 0;
        while(!eof && bytes_in_buf <n){
            if(bytes_from_buffer == 0){
                bytes_from_buffer = read4(buffer);
                eof = (bytes_from_buffer < 4);
            }
            int bytes_read = min(bytes_from_buffer, n- bytes_in_buf);
            memcpy(buf+bytes_in_buf, buffer+offset, bytes_read);
            offset = (offset + bytes_read) % 4;
            bytes_from_buffer -= bytes_read;
            bytes_in_buf += bytes_read;
        }
        return bytes_in_buf;
    }

    void testRead(int bytes_to_read, const char * desired_output){
        const int n = bytes_to_read;
        cout<<"Input:  "<<input<<endl;
        char * buf = new char [n];
        read(buf, n);
        cout<<"Output: "<<buf<<endl;
        ASSERT_STREQ(desired_output, buf);
    }

    void testRead(vector<int> bytes){
        //int N = *max_element(bytes.begin(), bytes.end());
        cout<<"Input:  "<<input<<endl;
        for(int i : bytes){
            char * buf = new char [i];
            cout<<"read(buf, "<<i<<") : \n";
            read(buf, i);
            cout<<"Output: "<<buf<<endl;
        }
    }
};

TEST(test_case, I){
    const char * str = "ab";
    Solution s;
    s.setInput(str);
    int n = 2;
    const char * desired_output = "ab";
    s.testRead(n, desired_output);
}

TEST(test_case, II){
    const char * str = "ab";
    Solution s;
    s.setInput(str);
    vector<int> bytes{1,2};
    s.testRead(bytes);
}

TEST(test_case, III){
    const char * str = "abcdefghij";
    Solution s;
    s.setInput(str);
    vector<int> bytes{1,2,3,4, 5};
    s.testRead(bytes);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

