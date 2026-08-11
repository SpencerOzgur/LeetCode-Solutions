class Codec:
    def encode(self, strs: List[str]) -> str:
        """Encodes a list of strings to a single string.
        """

        res = ''
        for s in strs:
            res += str(len(s)) + '#' + s
        print(res)
        return res

        

    def decode(self, s: str) -> List[str]:
        """Decodes a single string to a list of strings.
        """
        i = 0
        res = []

        while i < len(s):
            j = i
            while j < len(s) and s[j] != '#':
                j += 1
            lenWord = int(s[i:j])
            res.append(s[j + 1 : j  + lenWord + 1])
            i = j + lenWord + 1
        return res


# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.decode(codec.encode(strs))
