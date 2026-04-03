class Solution {
public:
    int myAtoi(string s) {
        vector<char> v;
        int n = s.size();
        int i = 0;
        while (i < n) {
            if (s[i] == ' ' ) {
                if (v.size() == 0) {
                    i++;
                    continue;
                }
                else{
                    break;
                }
            }
            if (s[i] == '-' || s[i] == '+') {
                if (v.size() == 0) {
                    v.push_back(s[i]);
                } else {
                    break;
                }
            }
            if (isdigit(s[i])) {
                v.push_back(s[i]);
            }
            if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || s[i] == '.') {
                break;
            }
            i++;
        }
        i = 0;
        long long num = 0;
        int sign = 1;
        int start = 0;

        if (v.empty())
            return 0;

        if (v[0] == '-') {
            sign = -1;
            start = 1;
        } else if (v[0] == '+') {
            start = 1;
        }

        for (int i = start; i < v.size(); i++) {
            num = num * 10 + (v[i] - '0');

            if (num * sign > INT_MAX)
                return INT_MAX;
            if (num * sign < INT_MIN)
                return INT_MIN;
        }

        num *= sign;
        return num;
    }
};