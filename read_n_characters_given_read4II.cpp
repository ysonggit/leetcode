#include <gtest/gtest.h>
#include "utils.h"
#include <stdio.h>
using namespace std;

/*
  example input "abcdef"
  call read(buf, 1) read(buf, 5)
  then in buf, should have "a" and "bcdef" sequentially
  read(buf, 1) ==> bytes_from_buffer = 0
                   offset = 1
                   buffer : |a|_|_|_|
                   buf : |a|
   read(buf, 5) ==> bytes_from_buffer = 4
                    bytes_read = 4
                    buffer  |b|c|d|e|
                    buf     |b|c|d|e|_|
                    offset = 1 
                    bytes_from_buffer = 0
                    bytes_in_buf = 4
                    (==next round==)
                    bytes_from_buffer = 1
                    buf     |b|c|d|e|f|
                    bytes_read = 1
                    offset = 2
                    bytes_from_buffer = 0
                    bytes_in_buf = 5
 */
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
        char * buf = new char [n];
        cout<<"read(buf, "<<n<<") ";
        read(buf, n);
        cout<<"Output: "<<buf<<endl;
        delete [] buf;
        buf = NULL;
        //ASSERT_STREQ(desired_output, buf);
    }

    void testRead(vector<int> bytes){
        cout<<"Input:  "<<input<<endl;
        int start = 0;
        for(int i : bytes){
            char * desired_output = new char [i];
            //strncpy(desired_output, input+start, i);
            testRead(i, desired_output);
            delete [] desired_output;
            desired_output = NULL;
            start += i;
        }
    }
};

TEST(test_case, I){
    const char * str = "abcdef";
    Solution s;
    s.setInput(str);
    vector<int> bytes{1,5};
    s.testRead(bytes);
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

