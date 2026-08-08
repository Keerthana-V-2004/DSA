class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l=0, res=INT_MAX, sumOfCurrWind=0;
        for(int r=0; r<nums.size(); r++){
            sumOfCurrWind += nums[r];

            while(sumOfCurrWind >= target){
                res = min(res, r-l+1);
                sumOfCurrWind -= nums[l];
                l++;
            }
            
        }
        return res == INT_MAX? 0 : res;
    }
};