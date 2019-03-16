# -*- coding: utf-8 -*-
# @Time    : 3/12/2019 22:23
# @Author  : MARX·CBR
# @File    : 超级回文数.py
from math import sqrt


class Solution:
    def __init__(self):
        self.result=[]

    def backToText(self,primeNumbers):
        primeNumbers_string = str(primeNumbers)
        if primeNumbers_string[-1]!=primeNumbers_string[1]:
            return  False
        a = reversed(list(primeNumbers_string))
        if list(a) == list(primeNumbers_string):
            # print("回文素数")
            return True

    def superpalindromesInRange(self, L: str, R: str) -> int:
        for i in range(int(L),int(R)+1):
            if self.backToText(str(i)):
                # self.result.append(i)
                sqrt_res=sqrt(i)
                st=str(sqrt_res)
                if st[-2::]=='.0':
                    print("整除")
                    if self.backToText(st[:-2:]):
                        self.result.append(i)
                    # sqrt_twice=str(sqrt(sqrt(i)))
                    # if sqrt_twice[-2::]=='.0':
                    #     if self.backToText(st[:-2:]):
                    #         self.result.append(i)

        # print(self.result)
        # print(len(self.result))
        return len(self.result)

def stringToString(input):
    return input[1:-1].decode('string_escape')
# 92904622
# 232747148

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
            L = line
            line = next(lines)
            R = line
            ret = Solution().superpalindromesInRange(L,R)
            out = str(ret)
            print(out)
        except StopIteration:
            break


if __name__ == '__main__':
    main()