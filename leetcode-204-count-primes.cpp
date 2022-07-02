// accepted
// https://leetcode.com/problems/count-primes
// time: O(N * log(log(N)))
// space: O(N)
class Solution {
public:
    int countPrimes(int n) {
        if(n <= 1) return 0;
        
        vector<bool> isPrime(n, true);
        isPrime[0] = false;
        isPrime[1] = false;
        int count = 0;

        for(int i = 2; i*i < n; ++i) {
            if(!isPrime[i]) continue;

            for(int j = i*i; j < n; j += i) {
                isPrime[j] = false;
            }
        }

        for(int i = 2; i < n; ++i) {
            if(isPrime[i]) count++;
        }

        return count;
    }
};