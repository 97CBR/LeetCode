# -*- coding: utf-8 -*-
# @Time    : 3/19/2019 17:28
# @Author  : MARX·CBR
# @File    : 各位相加.py

class Solution:
    def __init__(self):
        self.sn=[]

    def addDigits(self, num: int) -> int:
        if num < 10:
            return num
        # print(num)
        self.sn = list(str(num))
        self.sn = [int(g) for g in self.sn]
        while sum(self.sn) > 9:
            nn = 0
            for k in self.sn:
                nn = nn + int(k)
            self.sn = list(str(nn))
            self.sn = [int(g) for g in self.sn]
            # print(sn)
        else:
            return (sum(self.sn))
        if len(self.sn) < 2:
            return int(self.sn[0])
        elif len(self.sn) == 2:
            return (int(self.sn[0]) + int(self.sn[1]))


def main():
    import sys
    import io
    def readlines():
        for line in io.TextIOWrapper(sys.stdin.buffer, encoding='utf-8'):
            yield line.strip('\n')

    lines = readlines()
    while True:
        try:
            line = next(lines)
            num = int(line);

            ret = Solution().addDigits(num)

            out = str(ret);
            print(out)
        except StopIteration:
            break


if __name__ == '__main__':
    main()
#
# 执行用时 : 80 ms, 在Add Digits的Python3提交中击败了49.25% 的用户
# 内存消耗 : 13.3 MB, 在Add Digits的Python3提交中击败了0.54% 的用户