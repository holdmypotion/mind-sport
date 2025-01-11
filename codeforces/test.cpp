// Converted from python code that was facing TLE on 27th test case
#include <bits/stdc++.h>
using namespace std;
 
// Constants
const int MOD = 998244353;
const long long INF = 1e18;
const long long NINF = -1e18;
 
// Function to calculate value
long long val(vector<long long>& a, int i, int n) {
    if (i < 0 || i >= n) {
        return 0;
    }
    
    long long x = a[i];
    long long y = (i == n-1) ? 0 : a[i+1];
    return max(x-y, 0LL);
}
 
// Function to swap elements
void swap(vector<long long>& a, int x, int y) {
    long long temp = a[x];
    a[x] = a[y];
    a[y] = temp;
}
 
void potion() {
    int n, q;
    cin >> n >> q;
    
    vector<long long> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    long long ans = 0;
    for(int i = 0; i < n; i++) {
        ans += val(a, i, n);
    }
    
    cout << ans << "\n";
    
    for(int query = 0; query < q; query++) {
        int x, y;
        cin >> x >> y;
        x--; y--;  // Convert to 0-based indexing
        
        if(x < y) {
            ans -= val(a, x, n);
            ans -= val(a, x-1, n);
            ans -= val(a, y, n);
            if(x != y-1) {
                ans -= val(a, y-1, n);
            }
            
            swap(a, x, y);
            
            ans += val(a, x-1, n);
            ans += val(a, x, n);
            ans += val(a, y, n);
            if(x != y-1) {
                ans += val(a, y-1, n);
            }
        }
        
        cout << ans << "\n";
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--) {
        potion();
    }
    
    return 0;
}
