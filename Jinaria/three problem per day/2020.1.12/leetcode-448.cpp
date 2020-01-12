class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> num_nums(nums.size() + 1, 0);
        for(int a : nums){
            num_nums[a]++;
        }
        vector<int> ret;
        for(int i = 1; i < num_nums.size(); ++i){
            if(num_nums[i] == 0)
                ret.push_back(i);
        }
        return ret;
    }
};