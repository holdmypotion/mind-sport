#
# @lc app=leetcode id=295 lang=python3
#
# [295] Find Median from Data Stream
#

# @lc code=start
class MedianFinder:
    ## Sorting
    # def __init__(self):
    #     self.data = []

    # def addNum(self, num: int) -> None:
    #     self.data.append(num)

    # def findMedian(self) -> float:
    #     self.data.sort()
    #     n = len(self.data)
    #     return (self.data[n // 2] if (n & 1) else 
    #             (self.data[n // 2] + self.data[n // 2 - 1]) / 2)

    ## Heap Sol
    def __init__(self):
        # Break the list into 2 approx equal parts where left is a max heap and right part is a min heap
        self.left, self.right = [], []
        # left is a max heap
        # right is a min heap
        

    def addNum(self, num: int) -> None:
        heapq.heappush(self.left, -1 * num)

        # If we added in the wrong heap
        if self.left and self.right and (
            -1 * self.left[0] > self.right[0]
        ):
            val = -1 * heapq.heappop(self.left)
            heapq.heappush(self.right, val)
            

        # if after addition left pile became more skewed
        if len(self.left) > len(self.right) + 1:
            val = -1 * heapq.heappop(self.left)
            heapq.heappush(self.right, val)
        

        # if after addition right pile became more skewed
        if len(self.right) > len(self.left) + 1:
            val = heapq.heappop(self.right)
            heapq.heappush(self.left, -1 * val)


    def findMedian(self) -> float:
        if len(self.left) > len(self.right):
            return -1 * self.left[0]
        elif len(self.right) > len(self.left):
            return self.right[0]
        else:
            return (-1 * self.left[0] + self.right[0]) / 2


# Your MedianFinder object will be instantiated and called as such:
# obj = MedianFinder()
# obj.addNum(num)
# param_2 = obj.findMedian()
# @lc code=end

