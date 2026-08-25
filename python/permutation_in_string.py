class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        s1Cnt = defaultdict(int)
        s2Cnt = defaultdict(int)

        for i in range(len(s1)):
            s1Cnt[s1[i]] += 1
        l = 0

        for r in range(len(s2)):
            if s1Cnt == s2Cnt:
                return True
            s2Cnt[s2[r]] += 1
            if r >= len(s1):
                if s2Cnt[s2[l]] == 1:
                    del s2Cnt[s2[l]]
                else:
                    s2Cnt[s2[l]] -= 1
                l += 1
        return s1Cnt == s2Cnt

