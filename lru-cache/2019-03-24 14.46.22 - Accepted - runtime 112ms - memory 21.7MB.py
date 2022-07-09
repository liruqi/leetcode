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
        if key not in self: 
            if len(self) >= self.maxsize:
                oldest = next(iter(self))
                del self[oldest]
        else:
            self.move_to_end(key)
        super().__setitem__(key, value)

# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)