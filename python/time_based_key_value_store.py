class TimeMap:

    def __init__(self):
        self.timeMap = defaultdict(list)
        

    def set(self, key: str, value: str, timestamp: int) -> None:
        self.timeMap[key].append([timestamp, value])
        

    def get(self, key: str, timestamp: int) -> str:
        res = ''
        vals = self.timeMap.get(key, [])
        l, r = 0, len(vals) - 1

        while l <= r:
            mid = l + (r - l) // 2
            if vals[mid][0] == timestamp:
                res = vals[mid][1]
                break
            elif vals[mid][0] < timestamp:
                res = vals[mid][1]
                l = mid + 1
            else:
                r = mid -1
        return res
        


# Your TimeMap object will be instantiated and called as such:
# obj = TimeMap()
# obj.set(key,value,timestamp)
# param_2 = obj.get(key,timestamp)
