class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> Hash;
        int left = 0, right = 0;
        int n = s.size();
        int count = 0, Max_length = 0;
        while(left < n){
            while(left <= right && Hash[s[right]] == 0 && right < n){
                Hash[s[right]]++;
                count++;
                right++;
            }
            if(Hash[s[right]] != 0){
                Hash[s[left]]--; 
            }
            left++;
            Max_length = max(Max_length, count);
            count = right - left;
        }
        // for(auto it = Hash.begin(); it != Hash.end(); it++){
        //     cout<<(*it).first<<" "<<(*it).second<<endl;
        // }
        return Max_length;
    }
};