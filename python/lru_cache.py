class Node:

    def __init__(self, key, val):
        self.key, self.val = key, val
        self.next, self.prev = None, None

class LRUCache:

    def __init__(self, capacity: int):
        self.cap = capacity
        self.cache = {}
        self.left, self.right = Node(0, 0), Node(0, 0)
        self.left.next, self.right.prev = self.right, self.left

    def get(self, key: int) -> int:
        if key in self.cache:
            self.evict(self.cache[key])
            self.insert(self.cache[key])
            return self.cache[key].val
        return -1
        

    def put(self, key: int, value: int) -> None:
        if key in self.cache:
            self.evict(self.cache[key])
        self.cache[key] = Node(key=key, val=value)
        self.insert(self.cache[key])

        if len(self.cache) > self.cap:
            lru = self.left.next
            self.evict(lru)
            del self.cache[lru.key]

    def insert(self, node: Node):
        node.next, node.prev = self.right, self.right.prev
        node.prev.next, node.next.prev = node, node

    def evict(self, node: Node):
        node.prev.next, node.next.prev = node.next, node.prev
        node.next, node.prev = None, None

# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
