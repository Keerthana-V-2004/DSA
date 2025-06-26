//LEETCODE:basic approch 
// STOCK BUY AND SELL:- O(n)
//PRICES=[7,1,5,3,6,4] ,RETURN MAX PROFIT
//BUY:min  sell:max
#include<iostream>
#include<vector>
using namespace std;

int maxProfit(vector<int> prices){
  int maxprof = 0, bestBuy = prices[0];

  for(int i=1; i<prices.size();i++){
    if(prices[i] > bestBuy){
      maxprof = max(maxprof, (prices[i]-bestBuy));
    }
    bestBuy = min(bestBuy,prices[i]);
  }
  return maxprof;

}

int main(){
  vector<int> prices = {7,1,5,3,6,4};
  
  cout << maxProfit(prices) << endl;
  return 0;
}