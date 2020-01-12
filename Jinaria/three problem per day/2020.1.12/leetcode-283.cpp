class Solution {
public:
    void swap(int &a, int &b){
        int t = a;
        a = b;
        b = t;
    }
    void moveZeroes(vector<int>& nums) {
        for(int lastNonZeroFoundAt = 0, cur = 0; cur < nums.size(); ++cur){
            if(nums[cur])
                swap(nums[lastNonZeroFoundAt++], nums[cur]);
        }
    }
};