# -*- coding: utf-8 -*-
# @Time    : 3/16/2019 14:12
# @Author  : MARX·CBR
# @File    : 有序数组的平方.py
import json
class Solution:
    def __init__(self):
        self.result=[]

    def sortedSquares(self, A: list) -> list:

        for k in A:
            self.result.append(k*k)
        self.result.sort()
        return (self.result)
       # return A

def stringToIntegerList(input):
    return json.loads(input)


def integerListToString(nums, len_of_list=None):
    if not len_of_list:
        len_of_list = len(nums)
    return json.dumps(nums[:len_of_list])


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
            A = stringToIntegerList(line);

            ret = Solution().sortedSquares(A)

            out = integerListToString(ret);
            print(out)
        except StopIteration:
            break


if __name__ == '__main__':
    main()