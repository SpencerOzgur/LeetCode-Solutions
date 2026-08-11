class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        wordMap = defaultdict(list)

        for s in strs:
            wordMap[tuple(sorted(s))].append(s)
        return [v for v in wordMap.values()]
