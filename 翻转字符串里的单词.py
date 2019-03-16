# -*- coding: utf-8 -*-
# @Time    : 3/15/2019 20:05
# @Author  : MARX·CBR
# @File    : 翻转字符串里的单词.py
from copy import deepcopy
class Solution:
    def __init__(self):
        self.content=[]

    def reverseWords(self, s: str) -> str:
        mystring=s
        self.content=mystring.split(' ')
        # print(self.content)
        kk=[]
        for gg in self.content:
            if len(gg)>0:
                kk.append(gg)
        # # self.content('')
        # print(kk)
        kk.reverse()
        # print(kk)
        s=' '.join(kk)
        return s
        # print(self.content)

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
            s = str(line);

            ret = Solution().reverseWords(s)

            out = (ret);
            print(out)
        except StopIteration:
            break


if __name__ == '__main__':
    main()