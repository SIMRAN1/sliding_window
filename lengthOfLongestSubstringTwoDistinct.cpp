class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int i=0,j=0,n=s.size(),k=2, ans=0;
        if(s.size()<2) {
            return s.size();
        }
        unordered_map<char,int> mp;
        while(j<n) {
           mp[s[j]]++;
           if(mp.size()<k) {
              j++;
           } else if(mp.size()==k) {
                 ans = max(ans, j-i+1);
                 j++;
           } else if(mp.size()>k) {
               while(mp.size()>k) {
                    mp[s[i]]--;
                    if(mp[s[i]]==0) {
                        mp.erase(s[i]);
                    }
                    i++;
               }
               j++;
           }
        }

        if(ans==0 && j>0) {
            return j;
        }

        return ans;
    }
};
