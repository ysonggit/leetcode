#include "utils.h"
using namespace std;
bool containsNearbyDuplicate(vector<int>& nums, int k) {
  unordered_map<int, int>  records; // nums[index] -> index of its last occurence;
  for (int i = 0; i < nums.size(); i++) {
    if (records.find(nums[i]) != records.end() && i - records[nums[i]] <= k) {
      return true;
    }
    records[nums[i]] = i;
  }
  return false;
}
