class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        prefix = [0] * n
        suffix = [0] * n

        prefix[0] = nums[0]
        suffix[-1] = nums[-1]

        for i,j in zip(range(1, n), range(n-2, -1, -1)):
            prefix[i] = prefix[i-1] * nums[i]
            suffix[j] = suffix[j+1] * nums[j]

        res = [1] * n
     
        for i in range(n):
            if i-1 >= 0:
                res[i] *= prefix[i-1]
            if i+1 < n:
                res[i] *= suffix[i+1]
      
        return res
        