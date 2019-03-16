# -*- coding: utf-8 -*-
# @Time    : 3/16/2019 14:00
# @Author  : MARX·CBR
# @File    : 转换成小写字母.py

class Solution:
    def __init__(self):
        self.mydict = {}
        for g in range(0, 26):
            self.mydict[chr(ord('A') + g)] = chr(ord('a') + g)

    def toLowerCase(self, str: str) -> str:
        s = list(str)

        r=""
        for k in s:
            try:
                y=self.mydict[k]
                r+=y
            except:
                r +=k
        self.mydict.clear()
        return (r)



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
            strs = str(line);

            ret = Solution().toLowerCase(strs)

            out = (ret);
            print(out)
        except StopIteration:
            break


if __name__ == '__main__':
    main()