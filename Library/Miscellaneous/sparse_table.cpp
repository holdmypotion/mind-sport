// video https://youtu.be/0jWeUdxrGm4
// problem https://www.spoj.com/problems/RMQSQ/
// Used when the array is static and you can precompute values to answer queries in
// O(1) -> for min, max, gcd etc. [Reason: Overlapping subarrays aren't a problem]
// O(logN) -> for sum [Reason: Can't Overlap subarray so need to break the range into exact power of 2 which will take LogN in worst case]
//
//
//
// A Dense Table would be N*N that is the number of subarrays you can have, you'll pre compute the values. That will achieve answering each queries in O(1)
//  but the entire algorightm would be bounded by O(N*N)
//
//  A Sparse table instead of computing values for each subarray only computes it for subarrays of len in power of 2 -> Hence only O(logN) computation for each N
//  Once this computation is done, the way you answer query is you break the range down to 2 sub ranges of power of 2 (they will overlap if the range isn't a power of 2. But it doesn't matter for min, max, gcd etc.) 
//
#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 100'005;
const int LOG = 17;
int a[MAX_N];
int m[MAX_N][LOG]; // m[i][j] is minimum among a[i..i+2^j-1]
int bin_log[MAX_N];

int query(int L, int R) { // O(1)
  int length = R - L + 1;
  int k = bin_log[length];
  return min(m[L][k], m[R-(1<<k)+1][k]);
}

int main() {
  // 1) read input
  int n;
  cin >> n;
  bin_log[1] = 0;
  
  // Log2 simpliy is: How many times you have to divide a number by a 2 to get 1
  for(int i = 2; i <= n; i++) {
    bin_log[i] = bin_log[i/2]+1;
  }

  // Preprocessing for 2^0 -> len == 1, hence just the element itself
  for(int i = 0; i < n; i++) {
    cin >> a[i];
    m[i][0] = a[i];
  }
  // 2) preprocessing, O(N*log(N)) -> for 2^1 -- 2^16
  for(int k = 1; k < LOG; k++) { // Going over all the powers of 2 till the MAX_N is hit. Which will be 16 in this case.
    for(int i = 0; i + (1 << k) - 1 < n; i++) { // Going from 0 to 2^16 -1
      m[i][k] = min(m[i][k-1], m[i+(1<<(k-1))][k-1]);
      // m[i][k] would depend on previous power hence k-1
      // m[i][k-1] would be the range -> [i, i+2^(k-1)-1]
      // Hence the the range [i, i+2^k-1] would be min of [i, i+2^(k-1)-1] and [i+2^(k-1), i+2^(k-1)+2^(k-1)] ---- [xxxxxx][xxxxxx]
      // if j = i+2^(k-1)
      // [i, k] = [i, j-1] and [j, j+2^(k-1)-1]
    }
  }
  // 3) answer queries
  int q;
  cin >> q;
  for(int i = 0; i < q; i++) {
    int L, R;
    cin >> L >> R;
    cout << query(L, R) << "\n";
  }
}
