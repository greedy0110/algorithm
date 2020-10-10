# 작은 값들에 대한 최대힙을 설계한다.
# 큰 값들에 대한 최소힙을 설계한다.

# max-heap-size = min-heap-size or min-heap-size + 1

import queue
import heapq

# python의 PriorityQueue는 Min Heap이다. max_heap은 뒤집어서 저장하자.

C = int(input())
for _ in range(C):
    N, a, b = map(int, input().split())

    max_heap = []
    min_heap = []

    sum = 0
    inp = 1983

    heapq.heappush(max_heap, -inp)
    sum += -max_heap[0]
    for i in range(N-1):
        inp = (inp*a+b) % 20090711
        assert(len(max_heap) + len(min_heap) == i+1)

        # 힙 크기 제약
        if len(min_heap) == len(max_heap):
            heapq.heappush(max_heap, -inp)
        else:
            heapq.heappush(min_heap, inp)

        assert(max_heap and min_heap)
        size_diff = len(max_heap) - len(min_heap)
        assert(size_diff == 0 or size_diff == 1)

        # 원소 크기 제약
        max_heap0 = -max_heap[0]
        min_heap0 = min_heap[0]
        if min_heap0 < max_heap0:
            heapq.heappop(max_heap)
            heapq.heappop(min_heap)

            heapq.heappush(max_heap, -min_heap0)
            heapq.heappush(min_heap, max_heap0)

        assert(-max_heap[0] <= min_heap[0])

        sum += -max_heap[0]
        sum %= 20090711

    print(sum)
