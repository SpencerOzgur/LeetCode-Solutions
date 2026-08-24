class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        res = 0
        window = defaultdict(int)
        l = 0

        for r in range(len(s)):
            window[s[r]] += 1
            while max(window.values()) + k < r - l + 1:
                window[s[l]] -= 1
                l += 1
            res = max(res, r - l + 1)
        return res


