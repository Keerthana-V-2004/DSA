class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        int i=0, maxLen=0, zeros=0;
        for(int j=0; j<nums.size(); j++){
            if(nums[j] == 0) zeros++;

            while(zeros > k){
                if(nums[i] == 0) zeros--;
                i++;
            }
            maxLen = max(maxLen, j-i+1);
        }
        return maxLen;
    }
};