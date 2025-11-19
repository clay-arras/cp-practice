// https://leetcode.com/problems/count-number-of-balanced-permutations

class Solution {
public:

struct Int256 {
    uint64_t parts[4];  // Represents the 256-bit integer as four 64-bit parts

    // Constructor initializes with zero by default
    Int256(uint64_t low = 0) {
        parts[0] = low;
        parts[1] = parts[2] = parts[3] = 0;
    }

    // Add operator
    Int256 operator+(const Int256& other) const {
        Int256 result;
        uint64_t carry = 0;
        for (int i = 0; i < 4; i++) {
            uint64_t temp = parts[i] + other.parts[i] + carry;
            result.parts[i] = temp;
            carry = (temp < parts[i]) ? 1 : 0;
        }
        return result;
    }

    // Subtract operator
    Int256 operator-(const Int256& other) const {
        Int256 result;
        uint64_t borrow = 0;
        for (int i = 0; i < 4; i++) {
            uint64_t temp = parts[i] - other.parts[i] - borrow;
            result.parts[i] = temp;
            borrow = (parts[i] < other.parts[i] + borrow) ? 1 : 0;
        }
        return result;
    }

    // Multiply operator
    Int256 operator*(const Int256& other) const {
        Int256 result;
        std::vector<uint64_t> temp(8, 0);

        // Perform multiplication part by part
        for (int i = 0; i < 4; i++) {
            uint64_t carry = 0;
            for (int j = 0; j < 4; j++) {
                __uint128_t mul = (__uint128_t)parts[i] * other.parts[j] + temp[i + j] + carry;
                temp[i + j] = (uint64_t)mul;
                carry = (uint64_t)(mul >> 64);
            }
            temp[i + 4] = carry;
        }

        // Copy the result back into the Int256 structure
        for (int i = 0; i < 4; i++) {
            result.parts[i] = temp[i];
        }

        return result;
    }
    bool operator>=(const Int256& other) const {
        for (int i = 3; i >= 0; --i) {
            if (parts[i] > other.parts[i]) return true;
            if (parts[i] < other.parts[i]) return false;
        }
        return true;
    }

    Int256 operator<<(int shift) const {
        Int256 result;
        int fullShifts = shift / 64;
        int bitShift = shift % 64;
        for (int i = 3; i >= fullShifts; --i) {
            result.parts[i] = parts[i - fullShifts] << bitShift;
            if (i - fullShifts - 1 >= 0 && bitShift != 0) {
                result.parts[i] |= parts[i - fullShifts - 1] >> (64 - bitShift);
            }
        }
        return result;
    }


    // Division operator (assuming simple division by a small 64-bit integer)
    Int256 operator/(const Int256& divisor) const {
        Int256 quotient, remainder;
        for (int i = 255; i >= 0; --i) {
            remainder = remainder << 1;  // Left shift remainder
            remainder.parts[0] |= (parts[i / 64] >> (i % 64)) & 1;  // Add the bit

            if (remainder >= divisor) {
                remainder = remainder - divisor;
                quotient.parts[i / 64] |= (1ULL << (i % 64));
            }
        }

        return quotient;
    }


    // Convert to long long (may overflow if the value doesn't fit)
    long long convertToLongLong() const {
        if (parts[1] || parts[2] || parts[3]) {
            throw std::overflow_error("Int256 value is too large to fit in a long long");
        }
        return static_cast<long long>(parts[0]);
    }
    long long mod(long long divisor) const {
        if (divisor == 0) {
            throw std::overflow_error("Modulo by zero");
        }

        __int128_t remainder = 0;  // To handle intermediate values larger than long long
        for (int i = 3; i >= 0; --i) {
            remainder = (remainder << 64) + parts[i];
            remainder %= divisor;
        }
        return static_cast<long long>(remainder);
    }


    // Print for debugging purposes
    void print() const {
        std::cout << "Int256(";
        for (int i = 3; i >= 0; i--) {
            std::cout << parts[i];
            if (i > 0) std::cout << ", ";
        }
        std::cout << ")" << std::endl;
    }

};





    int target;
    vector<int> rest;
    long long ans = 0;
    long long MOD = 1e9+7;
    Int256 f[41];
    
    Int256 mod_init(int n) {
        f[0] = 1;
        for(int i=1;i<=n;i = i+1) {
            f[i] = (Int256(i) * f[i-1]);
        }
        return f[n];
    }

    void subsets(vector<int> arr, int sum, int index) {
        
        if (sum > target) return;
        if ((int)arr.size() > (int)rest.size()/2) return;
        
        if (sum == target && (int)arr.size() == (int)rest.size()/2) {
            
            unordered_map<int, int> m;
            for (int i : arr)
                m[i]++;
            
            Int256 add = f[((int)rest.size()/2)];
            for (auto [k, v] : m) {
                add = add / f[(v)];
            }

            unordered_map<int, int> m2;
            for (int i : rest) {
                if (m[i] == 0) 
                    m2[i]++; 
                else  m[i]--;
            }
            Int256 add2 = f[(int)(ceil((int)rest.size()*1.0/2))];
            for (auto [k, v] : m2) {
                add2 = add2 / f[(v)];
            }
            ans = (ans + ((add2*add).mod(MOD))) % MOD;
            return;
        }

        int last = -1;
        for (int i=index; i<(int)rest.size(); i++) {
            if (rest[i] == last) continue;
            arr.push_back(rest[i]);
            sum += rest[i];
            subsets(arr, sum, i+1);
            last = rest[i];
            arr.pop_back();
            sum -= rest[i];
        }
    }

    int countBalancedPermutations(string num) {
        mod_init(40);
        // __int256 i  = 0;

        for (char c : num) {
            target += c - '0';
            rest.push_back(c - '0');
        }
        sort(rest.begin(), rest.end());
        if (target % 2) return 0;
        target /= 2;

        subsets({}, 0, 0);
        return ans;
    }
};