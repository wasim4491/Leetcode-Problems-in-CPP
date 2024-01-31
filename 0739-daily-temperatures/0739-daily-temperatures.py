class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        stack = []
        n = len(temperatures)
        ans = [0] * n
        index = -1
        for temp in temperatures:
            index += 1
            if len(stack) == 0 or stack[-1][0] >= temp:
                stack.append((temp, index))
            else :
                while(len(stack) != 0 and stack[-1][0] < temp):
                    ans[stack[-1][1]] = index - stack[-1][-1]
                    stack.pop()
                stack.append((temp, index))
        return ans