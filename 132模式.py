# -*- coding: utf-8 -*-
# @Time    : 3/15/2019 21:01
# @Author  : MARX·CBR
# @File    : 132模式.py
# 给定一个整数序列：a1, a2, ..., an，一个132模式的子序列 ai, aj, ak 被定义为：当 i < j < k 时，ai < ak < aj。设计一个算法，当给定有 n 个数字的序列时，验证这个序列中是否含有132模式的子序列。
#
# 注意：n 的值小于15000。

#TODO 思路不够清晰，后面整理好再做
import json
class Solution:
    def __init__(self):
        self.num=[0]
        self.mydic={}

    def find132pattern(self, nums: [int]) -> bool:
        for index,con in enumerate(nums):
            self.mydic[str(index)]=con
        self.mydic=self.mysort()
        print(self.mydic)
        hh=[]
        for k,v in self.mydic:
            print(k,v)


    def mysort(self):
        # 按key排序
        dic = self.mydic
        dict = sorted(dic.items(), key=lambda d: int(d[1]))
        print(dict)
        return dict



def stringToIntegerList(input):
    return json.loads(input)


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
            nums = stringToIntegerList(line);

            ret = Solution().find132pattern(nums)

            out = (ret);
            print(out)
        except StopIteration:
            break


if __name__ == '__main__':
    main()