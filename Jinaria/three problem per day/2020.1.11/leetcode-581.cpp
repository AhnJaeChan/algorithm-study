class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> sorted_nums = nums;
        sort(sorted_nums.begin(), sorted_nums.end());
        int start = 0, end = nums.size() - 1;
        while(start < nums.size() && sorted_nums[start] == nums[start])
            start++;
        while(end > start && sorted_nums[end] == nums[end])
            end--;
        int len = 0;
        if(end <= start)
            len = 0;
        else
            len = end - start + 1;
        return len;
        
    }
};