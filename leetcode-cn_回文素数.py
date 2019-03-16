# -*- coding: utf-8 -*-
# @Time    : 3/10/2019 22:57
# @Author  : MARX·CBR
# @File    : leetcode-cn_回文素数.py
import array
from math import sqrt, log
class Solution:
    def __init__(self):
        self.ss=[]
        self.check = []
        self.count = 0
    def backToText(self, primeNumbers):
        primeNumbers_string = str(primeNumbers)
        a = reversed(list(primeNumbers_string))
        if list(a) == list(primeNumbers_string):
            # print("回文素数")
            return True
    def get_primeNumber(self, primeNumbers):
        for i in range(2, int(sqrt(primeNumbers))+2):
            if primeNumbers % i == 0:
                break
        else:
            return True
    def get_10_prime(self,test_number):
        if test_number == 1 or test_number == 2:
            return 2
        while 1:
            if self.backToText(test_number):
                if self.get_primeNumber(test_number):
                    # print(test_number)
                    return test_number
            test_number += 1
        return N



    def primePalindrome(self, N: int) -> int:
        test_number = N
        if test_number<11:
            return self.get_10_prime(test_number)
        elif test_number< 100000 :
            if test_number%2==0:
                test_number+=1
            while 1:
                if test_number%10%2 in [0,2,5]:
                    continue
                if self.backToText(test_number):
                    if self.get_primeNumber(test_number):
                        # print(test_number)
                        return test_number
                test_number += 2
            return N
        else:
            s = str(test_number)
            l = len(s)
            if l % 2 == 0:
                # 前半截
                s = s[:int(l / 2):]
            else:
                s = s[:int(l / 2) + 1:]
            k = s
            r=[]
            while 1:
                ss=k[:len(k):] + k[::-1]
                if int(ss) > test_number:
                    if self.get_primeNumber(int(ss)):
                        r.append(int(ss))
                        # print(ss)
                        # return int(ss)
                ss=k + k[-2::-1]
                if int(ss) > test_number:
                    if self.get_primeNumber(int(ss)):
                        r.append(int(ss))
                        # print(ss)
                        # return int(ss)
                # print()
                k = int(k) + 1
                k = str(k)
                if len(r)>5:
                    r.sort()
                    print(r)
                    # print(r)
                    # print(r[0])
                    return r[0]

            # print(l)
            # if l % 2 == 0:
            #     # 前半截
            #     p = s[:int(l / 2):]
            #     i = int(p)
            #     while 1:
            #         p = str(i)
            #         ss = p + p[::-1]
            #         if int(ss)>test_number:
            #             if self.get_primeNumber(int(ss)):
            #                 # print(ss)
            #                 return int(ss)
            #         # print(ss)
            #         i += 1
            # else:
            #     p = s[:int(l / 2) + 1:]
            #     i = int(p)
            #     while 1:
            #         p = str(i)
            #         ss = p + p[-2::-1]
            #         if int(ss)>test_number:
            #             if self.get_primeNumber(int(ss)):
            #                 # print(ss)
            #                 return int(ss)
            #         # print(ss)
            #         i += 1

            # self.ss= self.get_10x10_prime(test_number)
            # self.ss= self.sieve_of_eratosthenes(test_number)
            # for o in self.ss:
            #     if o>test_number:
            #         if self.backToText(test_number):
            #             return o


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
            N = int(line)
            ret = Solution().primePalindrome(N)
            out = str(ret)
            print(out)
        except StopIteration:
            break


if __name__ == '__main__':
    main()