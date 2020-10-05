# 아무 일꾼이나 키카드를 한 시간에 세번 이상 사용하면 alert를 띄운다.

# alert을 "보게된" 직원 이름을 증가하는 순서로 출력한다.

# 총 인원 N = 10**5

class Solution:
    def alertNames(self, keyName: List[str], keyTime: List[str]) -> List[str]:
        table = dict()

        for i in range(len(keyName)):
            if keyName[i] not in table:
                table[keyName[i]] = []
            table[keyName[i]].append(keyTime[i])

        ret = []
        for name, times in table.items():
            if len(times) <= 2:
                continue

            times.sort()
            for i in range(2, len(times)):
                hour1, min1 = map(int, times[i].split(":"))
                hour2, min2 = map(int, times[i-2].split(":"))

                if (hour1*100 - min1) - (hour2*100 - min2) <= 100:
                    ret.append(name)
                    break

        ret.sort()
        return ret
