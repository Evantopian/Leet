from typing import List
from collections import Counter

def twoSum(nums: List[int], target: int) -> List[int]:
    x = {}
    for i, num in enumerate(nums):
        print(i, num)
        if target - num in x:
            print ("Passes: ", target - num)
            return [x[target-num], i]
        
        x[num] = i
        print(x)

# hash table function




y = [2,5,5,11]
print(twoSum(y, 16))