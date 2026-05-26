class Solution {
public:
    const int MOD = 1e9 + 7;
    // Helper function to calculate (base^exp) % MOD efficiently
    long long power(long long base, long long exp) {
        long long res = 1;
        base = base % MOD;
        while (exp > 0) {
            if (exp % 2 == 1) {
                res = (res * base) % MOD;
            }
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    }
    int countGoodNumbers(long long n) {
        int even = 5;
        int prime = 4;
        long long EvenPositions, OddPositions = 0;
        if (n % 2 == 0) {
            EvenPositions = n / 2;
            OddPositions = n / 2;
        } else {
            EvenPositions = n / 2 + 1;
            OddPositions = n / 2;
        }
        int total = (power(5, EvenPositions) * power(4, OddPositions)) % MOD;
        if (n == 0)
            return 1;
        return total;
    }
};