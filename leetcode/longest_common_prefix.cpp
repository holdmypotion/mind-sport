class Solution {
private:
    string lcpDivideAndConquer(vector<string>& strs, int l, int r) {
        if (l < r) {
            int mid = (l+r)/2;
            string leftLCP = lcpDivideAndConquer(strs, l, mid);
            string rightLCP = lcpDivideAndConquer(strs, mid+1, r);
            return lcp(leftLCP, rightLCP);
        } else {
            return strs[l];
        }
    }

    string lcp(string left, string right) {
        int minLen = min(left.length(), right.length());

        for (int i = 0; i < minLen; i++) {
            if (left[i] != right[i]) {
                return left.substr(0, i);
            }
        }
        return left.substr(0, minLen);
    }

public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        //// Via Prefix Check

        // string prefix = strs[0];
        // for (int i = 1; i < strs.size(); i++) {
        //     while (strs[i].find(prefix) != 0) {
        //         prefix = prefix.substr(0, prefix.length() - 1);
        //         if (prefix.empty()) return "";
        //     }
        // }
        // return prefix;



        //// Via one char at a time check

        // for (int i = 0; i < strs[0].size(); i++) {
        //     char ch = strs[0][i];
        //     for (int j = 1; j < strs.size(); j++) {
        //         if (ch != strs[j][i] || i == strs[j].size()) {
        //             // if min str length is reached or if char isn't same. You'll got the loggentest Prefix.
        //             return strs[0].substr(0, i);
        //         }
        //     }
        // }
        // return strs[0];

        // Via Divide and Conquere
        return lcpDivideAndConquer(strs, 0, strs.size() - 1);

    }
};
