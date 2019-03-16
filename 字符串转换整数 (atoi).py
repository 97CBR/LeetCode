# -*- coding: utf-8 -*-
# @Time    : 3/14/2019 17:25
# @Author  : MARX·CBR
# @File    : 字符串转换整数 (atoi).py

class Solution:
    def __init__(self):
        self.num=''

    def transform(self):
        num=0
        for i in self.num:
            if i!=' ':
                self.num=self.num[num::]
                break
            num+=1
        # print(len(self.num))
        em=0
        for gg in self.num:
            if gg==' ':
                em+=1
        if em==len(self.num):
            return 0

        k=[ str(o) for o in range(0,10)]
        flag=0
        symbol=''
        if self.num[0] in ['-','+']:
            flag=1
            symbol=self.num[0]
            self.num=self.num[1::]
            if int(self.num[0]) not in range(0,10):
                return 0
        num = 0
        for j in self.num:
            if j not in k:
                # num+=1
                self.num=self.num[:num:]
                break
            num+=1
        # print(self.num)
        if flag:
            if self.num == '':
                self.num=symbol+self.num
                return self.num
            else:
                return self.num
        else:
            if self.num=='':
                return 0
            else:
                return self.num


    def myAtoi(self, str: str) -> int:
        mystr=str
        self.num=str
        # print(str)
        if len(mystr)>0:
            first=mystr[0]
        else:
            return 0
        try:
            if first in [' ','-','+']:
                # print('正负')
                result=self.transform()
            elif int(first) in range(0,10):
                # print('数字开头')
                result =self.transform()
            else:
                return 0
        except:
            return 0
        if int(result)>2**31-1:
            return 2**31-1
        elif int(result)<-2**31:
            return -2 ** 31
        else:
            return int(result)

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
            n = str(line);

            ret = Solution().myAtoi(n)

            out = str(ret);
            print(out)
        except StopIteration:
            break


if __name__ == '__main__':
    main()