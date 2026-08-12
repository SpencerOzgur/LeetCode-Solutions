class Solution:
    def isPalindrome(self, s: str) -> bool:
        alnum = []

        for c in s:
            if c.isalnum():
                alnum.append(c.lower())

        l, r = 0, len(alnum) - 1
        while l < r:
            if alnum[l] != alnum[r]:
                return False
            l += 1
            r -= 1
        return True
