class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        map<int, vector<int>> locations;
        for (int i = 0; i < n; i++) {
            locations[nums[i]].push_back(i);
        }

        int mindistance = -1;
        for (auto it = locations.begin(); it != locations.end(); it++) {
            vector<int> v = (*it).second;
            if (v.size() >= 3) {
                for (int i = 0; i <= (int)v.size() - 3; i++) {
                    int size = (v[i + 1] - v[i]) +
                                          (v[i + 2] - v[i + 1]) +
                                          (v[i + 2] - v[i]);
                    if (mindistance == -1 || size < mindistance) {
                        mindistance = size;
                    }
                }
            }
            
        }
        return mindistance;
    }
};