//SLIDING WINDOW MAXIMUM - LEETCODE 239
//nums = [1,3,-1,-3,5,3,6,7] k=3 , k is frame size ,in that frame return the maximum element from the frame and return the array of all max elem
//Actually MAX OF ALL SUBARRAY OF SIZE K
//1st frame = 1,3,-1 => 3 , 2nd frame => 3,-1,-1 => 3, 3rd frame => -1,-3,5 => 5 so on
//BRUTE O(n*k) : two for loop i to n and j=i to i+k 
//OPTIMAL - DEQUE
//1.curr window elem only should present in the queue
//2.currElem >= dq.front() elem => dq.pop() we pop that elem from the queue
//bcz it's no longer used if that elem is already smaller than the currElem then nxt window slide also not gonna have that elem as a larger elem so we pop it from the queue
//possible or viable answers are stored in the queue

#include<iostream>
#include<deque>
#include<vector>
using namespace std;

class Slide {

public:
   vector<int> maxSlideWin(vector<int> &nums, int k) { //O(n) SC-O(n)
    deque<int> dq;
    vector<int> res;

    //1st win
    for(int i=0 ;i < k ; i++) {  //O(k)
      while(dq.size() > 0 && nums[dq.back()] <= nums[i] ) {
        dq.pop_back();
      }
      dq.push_back(i);
    }

    for(int i=k ;i < nums.size() ;i++) { //O(n-k)
      res.push_back(nums[dq.front()]);

      //remove elem not part of window
      while(dq.size() > 0 && dq.front() <= i-k ) {
        dq.pop_front();
      }

      //remove the smaller val
      while(dq.size() > 0 && nums[dq.back()] <= nums[i] ) {
        dq.pop_back();
      }
      dq.push_back(i);
    }

    res.push_back(nums[dq.front()]);

    return res;
   }
  
   

};

int main() {
  return 0;
}