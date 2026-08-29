class Solution {
    public double findMaxAverage(int[] nums, int k) {
        int l=0 , sum=0;
        double avg = 0.0 , maxAvg=Integer.MIN_VALUE;
        for(int r=0; r<nums.length; r++){ 
            if(l < r && r - l + 1 > k){
                sum -=nums[l];
                l++;
            }
            sum += nums[r];
            if(r - l + 1 == k)
               maxAvg = Math.max(maxAvg , (double)sum / k);

        }
        return maxAvg;
    }
}