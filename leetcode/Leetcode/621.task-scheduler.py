#
# @lc app=leetcode id=621 lang=python3
#
# [621] Task Scheduler
#

# @lc code=start
class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        ## Greedy
        count = [0] * 26
        for task in tasks:
            count[ord(task) - ord('A')] += 1
        
        count.sort()
        maxf = count[25]
        idle = (maxf - 1) * n

        for i in range(24, -1, -1):
            idle -= min(maxf - 1, count[i])
        return max(0, idle) + len(tasks)

        ## Math
        count = [0] * 26
        for task in tasks:
            count[ord(task) - ord('A')] += 1
        
        maxf = max(count)
        maxCount = 0
        for i in count:
            maxCount += 1 if i == maxf else 0

        time = (maxf - 1) * (n + 1) + maxCount
        return max(len(tasks), time)
        ## Heap
        freq_map = Counter(tasks)

        max_heap = [-freq for freq in freq_map.values()]
        heapq.heapify(max_heap)

        time = 0
        q = deque()
        while max_heap or q:
            time += 1
            if max_heap:
                cnt = heapq.heappop(max_heap) + 1
                if cnt:
                    q.append((cnt, time+n))
            else:
                time = q[0][1] # fast forward to when we can pop from the queue
            
            if q and q[0][1] == time:
                heapq.heappush(max_heap, q.popleft()[0])

        return time

        
# @lc code=end

