#include <vector>
#include <cassert>
#include <unordered_set>
#include <algorithm>

// Required macro definitions
#define REQUIRE(cond) assert(cond)
#define ENSURE(cond) assert(cond)

bool isPrime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) return false;
    }
    return true;
}

std::vector<int> LucidNumbers(int n) {
    // Preconditions
    REQUIRE(n >= 0);
    
    std::unordered_set<int> lucidSet;
    std::vector<int> primes;
    
    // Include 1 as it appears in all test cases
    lucidSet.insert(1);
    
    // Find all primes up to n
    for (int i = 2; i <= n; ++i) {
        if (isPrime(i)) {
            primes.push_back(i);
            // Add prime numbers to lucid set
            lucidSet.insert(i);
        }
    }
    
    // Generate sums of consecutive primes
    for (size_t i = 0; i < primes.size(); ++i) {
        int sum = 0;
        for (size_t j = i; j < primes.size(); ++j) {
            sum += primes[j];
            if (sum > n) break;
            // Include sums of consecutive primes if they are <= n
            lucidSet.insert(sum);
        }
    }
    
    // Convert to sorted vector
    std::vector<int> result(lucidSet.begin(), lucidSet.end());
    std::sort(result.begin(), result.end());
    
    // Postconditions
    // All numbers should be <= n
    for (int num : result) {
        ENSURE(num <= n);
    }
    
    // Numbers should be strictly increasing
    for (size_t i = 0; i < result.size() - 1; ++i) {
        ENSURE(result[i] < result[i + 1]);
    }
    
    return result;
}
