class Solution:
    def minWindow(self, s: str, t: str) -> str:
        if len(s) < len(t): return ''

        window, tCnt = defaultdict(int), defaultdict(int)
        for i in range(len(t)):
            tCnt[t[i]] += 1
        l = 0
        have, need = 0, len(t)
        res, resLen = [-1, -1], float('inf')

        for r in range(len(s)):
            window[s[r]] += 1
            have += 1 if window[s[r]] <= tCnt[s[r]] else 0
            while have == need:
                if r - l + 1 < resLen:
                    res = [l, r]
                    resLen = r - l + 1
                window[s[l]] -= 1
                if s[l] in tCnt and window[s[l]] < tCnt[s[l]]:
                    have -= 1
                l += 1
        l, r = res
        return s[l:r+1] if resLen != float('inf') else ''
