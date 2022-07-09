op = ['+', '-', '*', '/']
class Solution:
    def eval(self,t2,t1,o):
        if o==op[0]:
            return t1+t2;
        if o==op[1]:
            return t1-t2;
        if o==op[2]:
            return t1*t2;
        
        return int(t1/t2)
    
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []
        
        for t in tokens:
            if t in op:
                v=self.eval(stack.pop(),stack.pop(),t)
                stack.append(v)
            else:
                stack.append(int(t))
        return stack.pop()