class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int i=0,j=0,n=s.size(), ans=0;
        if(k==0) {
            return 0;
        }
        if(s.size()<k) {
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
