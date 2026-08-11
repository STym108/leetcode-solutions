class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        st={}

        for i  in range(0,len(nums)):
            if target-nums[i] in st:
                return [st[target-nums[i]],i]
            st[nums[i]]=i
        return {-1,-1}