class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> freq;
        int i=0, maxFreq=0, res=0;

        for(int j=0; j<s.size(); j++){
            freq[s[j]]++;
            maxFreq = max(maxFreq,freq[s[j]]);

            while((j - i + 1) - maxFreq > k){
                freq[s[i]]--;
                i++;
            }
            res = max(res,j - i + 1);
        }
        return res;
    }
};