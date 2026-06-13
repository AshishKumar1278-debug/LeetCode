class Solution {
public:
    void backtrack(int index, string& Inserter, vector<string>& result, int n) {
        int freq1 = count(Inserter.begin(), Inserter.end(), '(');
        int freq2 = count(Inserter.begin(), Inserter.end(), ')');
        if (index == 2*n) {
            if (Inserter.size() == 2*n)
                result.push_back(Inserter);
            return;
        }
        if (freq1 < n) {
            Inserter.push_back('(');
            backtrack(index + 1, Inserter, result, n);
            Inserter.pop_back();
        }
        if (freq2 < freq1) {
            Inserter.push_back(')');
            backtrack(index + 1, Inserter, result, n);
            Inserter.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string Inserter;
        int index = 0;
        backtrack(index, Inserter, result, n);
        return result;
    }
};