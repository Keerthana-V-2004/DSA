class Solution {
public:
    int secondHighest(string s) {
        int largest=-1, secLargest = -1;
        for(char c : s){
            if(isdigit(c)){
                int num = c-'0';
                if(num > largest){
                    secLargest = largest;
                    largest = num;
                } else if(num > secLargest && num < largest){
                    secLargest = num;
                }
            }
        }
        return secLargest;
    }
};