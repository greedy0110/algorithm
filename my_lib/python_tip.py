# 빠른 입력을 위한 코드 스니팻
import sys


def input(): return sys.stdin.readline().strip()


# 문자열 뒤집기 코드 스니펫
some = "abcd"

some[::-1]

# stdin 에서 eof을 처리하는 코드 스니펫

for line in sys.stdin:
    # do something
    pass

# float 반올림, 정해진 자리 까지 출력하는 코드 스니펫
# 관련 링크: https://pyformat.info/
print("{:.3f}%".format(10.213123))  # 10.213

# 2차원 배열 원하는 사이즈로 초기화 코드 스니펫
cached = [[-1] * 101 for _ in range(10)]
# cached = [[-1] * 101] * 10
# 이 코드는 -1 이 똑같은 레퍼런스를 참조해서 이상해진다.

# 재귀 호출 깊이 제한 해제하는 코드 스니펫
sys.setrecursionlimit(20_000)
