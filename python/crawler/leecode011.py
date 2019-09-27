def maxArea0(height):
	maxA = 0
	for i in range(len(height)):
		for j in range(i,len(height)):
			cul = (j-i)*min(height[i],height[j])
			if(cul>maxA):
				maxA = cul
	return maxA


class Solution:
    def maxArea(self, height: List[int]) -> int:
        left ,right =0, len(height) - 1
        maxArea = 0
        while left < right:
            b = right - left
            if height[left] < height[right]:
                h = height[left]
                left += 1
            else:
                h = height[right]
                right -= 1
            area = b*h
            if maxArea < area:
                maxArea = area
        return maxArea

print(maxArea([8,6,2,5,4,8,3,7]))