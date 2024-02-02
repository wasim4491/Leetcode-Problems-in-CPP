class Solution:
    def sequentialDigits(self, low: int, high: int) -> List[int]:
        ans = []
        for i in range(1,10):
            total = i
            for j in range(i+1,10):
                total = total*10 + j
                if(total>=low and total<=high):
                    ans.append(total)
        ans.sort()
        return ans
        