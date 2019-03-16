# -*- coding: utf-8 -*-
# @Time    : 3/16/2019 13:42
# @Author  : MARX·CBR
# @File    : 宝石与石头.py

class Solution:
    def numJewelsInStones(self, J: str, S: str) -> int:
        # print(J, S)
        st = list(J)
        sh=list(S)
        # print(st,sh)
        num=0
        for i in st:
            for j in sh:
                if i==j:
                    num+=1
        return num


def stringToString(input):
    return input[1:-1].decode('string_escape')


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
            J = str(line);
            line = next(lines)
            S = str(line);

            ret = Solution().numJewelsInStones(J, S)

            out = str(ret);
            print(out)
        except StopIteration:
            break


if __name__ == '__main__':
    main()