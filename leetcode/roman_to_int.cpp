class Solution {
public:
  int romanToInt(string s) {
    int n = s.length();
    int res = 0;
    for (int i = 0; i < n; i++) {
      if (i < n-1) {
        if (s[i] == 'I') {
          if(s[i+1] == 'V') res += 4, i++;
          else if(s[i+1] == 'X') res += 9, i++;
          else res += 1;
        } else if (s[i] == 'X') {
          if(s[i+1] == 'L') res += 40, i++;
          else if(s[i+1] == 'C') res += 90, i++;
          else res += 10;
        } else if (s[i] == 'C') {
          if(s[i+1] == 'D') res += 400, i++;
          else if(s[i+1] == 'M') res += 900, i++;
          else res += 100;
        }
        else if (s[i] == 'V') res += 5;
        else if (s[i] == 'L') res += 50;
        else if (s[i] == 'D') res += 500;
        else if (s[i] == 'M') res += 1000;
      } else {
        if (s[i] == 'I') res += 1;
        else if (s[i] == 'V') res += 5;
        else if (s[i] == 'X') res += 10;
        else if (s[i] == 'L') res += 50;
        else if (s[i] == 'C') res += 100;
        else if (s[i] == 'D') res += 500;
        else if (s[i] == 'M') res += 1000;
      }
    }

    return res;
  }
};


// Better Sol

class Solution {
public:
    int romanToInt(string s) {
        map<char, int> mp;
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;

        int ans = 0, prev = INT_MAX; 
        for (auto& ch: s) {
            int curr = mp[ch];
            if (curr > prev) ans += curr - 2*prev;
            else ans += curr;
            prev = curr;
        }

        return ans;
    }
};
