class Solution:
    def rearrangeArray(self, nums: List[int]) -> List[int]:
        posarr = []
        negarr = []
        
        for num in nums :
            if num < 0 :
                negarr.append(num)
            else :
                posarr.append(num)
                
        ans = []
        
        ind = 0
        
        while ind < len(posarr) and ind < len(negarr) :
            ans.append(posarr[ind])
            ans.append(negarr[ind])
            ind += 1
        
        while ind < len(posarr):
            ns.append(posarr[ind])
            ind += 1
            
        while ind < len(negarr):
            ns.append(negarr[ind])
            ind += 1
            
        return ans