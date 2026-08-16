class Solution(object):
    def moveZeroes(self, nums):
       x=0
       i=0
       n=len(nums)
       z=0
       while i<n:
        if nums[i]==0 :
             z+=1
        i+=1
       i=0
       while x<len(nums):
        if nums[x]!=0:
             nums[i]=nums[x]
             i+=1 
             x+=1
        else :
            x+=1
       j=n-z
       while j<n:
            nums[j]=0
            j+=1
