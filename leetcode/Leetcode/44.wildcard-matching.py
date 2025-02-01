#
# @lc app=leetcode id=44 lang=python3
#
# [44] Wildcard Matching
#

# @lc code=start
class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        """
        1. ? -> any one char
        2. * -> _, or any seq of chars

        s = "asdfasfadfsdfsa"
        s = "as____dfsa"
        p = "as*dfsa"

        if the length of the array after * is less than 

        1. Case: ss*sdfa*ss -> len() -> 4 in the middle
            -> len() -> 4 should match the string s fully somewhere
        2. 


        match = (s[i] == p[j] or p[j] == '?')
        if p[j] == '*':
            Either p[j+1] == s[i]
                in that case dfs(i, j+1)
            or:
                in that case dfs(i+1, j)
        # we'll have to check for both cases as either could give true
        else:
            dfs(i+1, j+1) if s[i] == p[j]

        ""aa"\n"*""
        ""adceb"\n"*a*b""
        ""zacabz"\n"*a?b*""
        ""acdcb"\n"a*c?b""
        ""ho"\n"ho**""
        ""\n"**""
        """
        cache = {}

        def dfs(i, j) -> bool:
            if (i, j) not in cache: 
                while j+1 < len(p) and p[j] == p[j+1]=='*': j+=1

                if (i >= len(s) and j >= len(p)) or (i >= len(s) and j == len(p)-1 and p[j] == '*'): return True
                if (i >= len(s) and j < len(p)) or j >= len(p): return False

                if p[j] == '*':
                    match = (j+1 < len(p) and (s[i] == p[j+1] or p[j+1] == '?'))
                    ans = (match and dfs(i, j+1)) or dfs(i+1, j)
                else:
                    match = (s[i] == p[j] or p[j] == '?')
                    ans = match and dfs(i+1, j+1)

                cache[(i,j)] = ans

            return cache[(i, j)]
        return dfs(0, 0)
        
# @lc code=end

