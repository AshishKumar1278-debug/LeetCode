class Solution {
public:
    void backtrack(int start, int k, vector<int>& comb, int n,
                   vector<vector<int>>& res) {
        if (comb.size() == k) {
            res.push_back(comb);
            return;
        }

        for (int i = start; i <= n; i++) {
            comb.push_back(i);
            backtrack(i + 1, k, comb, n, res);
            comb.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> comb;
        backtrack(1, k, comb, n, res);
        return res;
    }
};