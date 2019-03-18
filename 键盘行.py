# -*- coding: utf-8 -*-
# @Time    : 3/18/2019 20:56
# @Author  : MARX·CBR
# @File    : 键盘行.py

# 给定一个单词列表，只返回可以使用在键盘同一行的字母打印出来的单词。键盘如下图所示。
import json
class Solution:
    def findWords(self, words: list) -> list:
        l1=['q','w','e','r','t','y','u','i','o','p']
        l2=['a','s','d','f','g','h','j','k','l']
        l3=['z','x','c','v','b','n','m']
        p=[]

        for key in words:
            flag=1
            for cc in key:
                cc = cc.lower()
                if cc not in l1:
                    flag=0
                    break
            if flag==1:
                p.append(key)
            flag = 1
            for cc in key:
                cc = cc.lower()
                if cc not in l2:
                    flag = 0
                    break
            if flag==1:
                p.append(key)
            flag = 1
            for cc in key:
                cc = cc.lower()
                if cc not in l3:
                    flag = 0
                    break
            if flag==1:
                p.append(key)

        # print(p)

        return  p


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

            ret = Solution().findWords(A)

            out = integerListToString(ret);
            print(out)
        except StopIteration:
            break


if __name__ == '__main__':
    main()