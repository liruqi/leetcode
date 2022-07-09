import collections

class LRUCache(collections.OrderedDict):

    def __init__(self, capacity: int):
        self.maxsize = capacity
        
    def get(self, key: int) -> int:
        if key in self: 
            value = super().__getitem__(key)
            self.move_to_end(key)
            return value
        return -1
    
    def put(self, key: int, value: int) -> None:
        super().__setitem__(key, value)
        if len(self) > self.maxsize:
            oldest = next(iter(self))
            del self[oldest]
        self.move_to_end(key)

# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)