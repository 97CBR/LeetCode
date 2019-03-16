# -*- coding: utf-8 -*-
# @Time    : 3/10/2019 21:06
# @Author  : MARX·CBR
# @File    : 回文素数.py

import sys
from array import array
from math import log


class Solution:
    def __init__(self):
        self.number=0
        self.ss=[]

    def backToText(self,primeNumbers):
        primeNumbers_string=str(primeNumbers)
        a = reversed(list(primeNumbers_string))
        if list(a) == list(primeNumbers_string):
            # print("回文素数")
            return True

    def get_primeNumber(self,primeNumbers):
        for i in range(2, int(primeNumbers/2+1)):
            if primeNumbers % i == 0:
                break
        else:
            return True

    def FindPrime(N):
        MAXNUM = int((log(N, 10) * 2.5 + 0.5) * N)
        i = 2
        a = array.array('i')
        p = array.array('i')
        for x in range(MAXNUM):
            a.append(1)
        while (i < len(a) - 1 and len(p) < N):
            if a[i] == 1:
                p.append(i)
            for j in range(len(p)):
                if i * p[j] >= MAXNUM: break
                a[i * p[j]] = 0
                if i % p[j] == 0: break
            i += 1
        return (p)

    def primePalindrome(self, N: int) -> int:
        test_number = N
        while 1:
            if self.backToText(test_number):
                if self.get_primeNumber(test_number):
                    print(test_number)
                    return True
            test_number+=1
        return N


if __name__ == "__main__":
    for line in sys.stdin:
        line = line.strip()
        number=int(line)
        ob = Solution()
        ob.primePalindrome(number)


# 求出大于或等于
# N
# 的最小回文素数。
#
# 回顾一下，如果一个数大于
# 1，且其因数只有
# 1
# 和它自身，那么这个数是素数。
#
# 例如，2，3，5，7，11
# 以及
# 13
# 是素数。
#
# 回顾一下，如果一个数从左往右读与从右往左读是一样的，那么这个数是回文数。
#
# 例如，12321
# 是回文数。
#
#
#
# 示例
# 1：
#
# 输入：6
# 输出：7