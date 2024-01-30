class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack_num = [];
        for exp in tokens :
            if exp.isdigit():
                stack_num.append(int(exp))
            elif exp[0] == '-' and exp[1:].isdigit():
                stack_num.append(int(exp))
            else:
                a = stack_num.pop()
                b = stack_num.pop()
                if exp == "+":
                    ans = a + b
                elif exp == '-':
                    ans = b - a
                elif exp == '*':
                    ans = a * b
                elif exp == '/':
                    if (a > 0 and b > 0) or (a < 0 and b < 0) :
                        ans = math.floor(b / a)
                    else :
                        ans = math.ceil(b / a)
                stack_num.append(ans);
        
        return stack_num.pop();
        
        