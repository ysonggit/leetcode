#include "utils.h"
#include <gtest/gtest.h>

using namespace std;
/*
  idea : Binary Search
  (= k^th order statistic, k = (m+n)/2+1 )
  m+n is odd , k = (m+n)/2+1, find the k-th smallest element 
  m+n is even return average of the k-th and k+1 th smallest elements (k=(m+n)/2)

  terminating conditions:
  if A or B is empty, return A[k-1] or B[k-1]
  if k=1 return min(A[0], B[0])
  if A[k/2-1] == B[k/2-1] return any one of them
*/
// assume A has shorter length
double findKth(int A[], int m, int B[], int n, int k){
    if(m>n) return findKth(B, n, A, m, k);
    if(m==0) return B[k-1];
    if(k==1) return min(A[0], B[0]);
    // find mid index of A and B
    int midA = min(k/2, m);
    int midB = k - midA;
    if(A[midA-1] > B[midB-1]){
        // drop first half of B (0...midB-1)
        int size_rest_B = n - midB;
        // find the (k-midB)~th smallest element from rest elements
        return findKth(A, m, B+midB, size_rest_B, k-midB);
    }
    if(A[midA-1] < B[midB-1]){
        // drop first half of A
        int size_rest_A = m - midA;
        return findKth(A+midA, size_rest_A, B, n, k-midA);
    }
    return A[midA-1];
}

double findMedianSortedArrays(int A[], int m, int B[], int n) {
    int total = m+n;
    int k = total/2;
    if(total&1){ //odd
        return findKth(A, m, B, n, k+1);
    }
    return (findKth(A, m, B, n, k) + findKth(A, m, B, n, k+1))/2.0;
}

TEST(Median, I){
    int A[] = {1,2,3,4,5,6};
    int B[] = {2,3,3,4};
    double res = 3;
    ASSERT_EQ(res, findMedianSortedArrays(A, 6, B, 4));
}

TEST(Median, II){
    int A[] = {1};
    int B[] = {2};
    double res = 1.5;
    ASSERT_EQ(res, findMedianSortedArrays(A, 1, B, 1));
}

TEST(Median, III){
    int A[] = {};
    int B[] = {2};
    double res = 2;
    ASSERT_EQ(res, findMedianSortedArrays(A, 0, B, 1));
}

TEST(Median, IV){
    int A[] = {1,3};
    int B[] = {2};
    double res = 2;
    ASSERT_EQ(res, findMedianSortedArrays(A, 2, B, 1));
}


int main(int argc, char *argv[]){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
