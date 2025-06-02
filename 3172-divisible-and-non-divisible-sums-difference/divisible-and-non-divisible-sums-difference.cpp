class Solution {
public:
    int differenceOfSums(int n, int m) {
        long long totalSum = 1LL * n * (n + 1) / 2;

        int countDiv = n / m;
        long long divisibleSum = 1LL * m * countDiv * (countDiv + 1) / 2;

        return totalSum - 2 * divisibleSum;
    }
};