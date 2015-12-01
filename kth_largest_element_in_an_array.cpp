class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        if (n==0 || k > n || k< 1) return 0;
        make_heap(nums.begin(), nums.end()); // default is max_heap
        for(int i=0; i<k-1; i++){
            pop_heap(nums.begin(), nums.end());
            nums.pop_back();
        }
        return nums.front();
    }
};
