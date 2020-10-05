# 아무렇게나 한다.

class Solution:
    def restoreMatrix(self, rowSum: List[int], colSum: List[int]) -> List[List[int]]:
        if len(rowSum) == 1:
            # colSum 대로 col을 만든다.
            return [[x] for x in colSum]
        if len(colSum) == 1:
            return rowSum
