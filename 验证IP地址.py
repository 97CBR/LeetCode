# -*- coding: utf-8 -*-
# @Time    : 3/15/2019 18:58
# @Author  : MARX·CBR
# @File    : 验证IP地址.py

class Solution:

    def __init__(self):
        self.content=[]
    def my_judege(self):
        flag=1
        if len(self.content)==4:
            for j in self.content:
                try:
                    if int(self.content[0]) == 0:
                        return 0
                    good=[ str(y) for y in range(0,10)]
                    if int(j) in range(0,256):
                        for u in j:
                            if u not in good:
                                flag = 0
                                break
                        num=0
                        for k in j:
                            if k !='0':
                                # print(num)
                                if num==0:
                                    ...
                                else:
                                    flag = 0
                                    break
                            else:
                                num += 1

                    else:
                        flag=0
                        break
                except:
                    flag = 0
                    break

        elif len(self.content)==8:
            uc=[ chr(ord('A')+g) for g in range(0,6)]
            for g in range(0,10):
                uc.append(str(g))
            # print(uc)
            for i in self.content:
                if  len(i)>4:
                    flag = 0
                    break
                elif len(i)==0 :
                    flag = 0
                    break
                else:
                    for  l in i:
                        if l.upper() not in uc:
                            flag = 0
                            break
                    ...
        else:
            flag=0
        return flag

    def validIPAddress(self, IP: str) -> str:
        myip= IP
        temp=myip.split('.')
        if  len(temp)==4:
        # if len(myip)<=15:
            self.content=myip.split('.')
            # print(self.content)
            if self.my_judege():
                # print('IPV4')
                return 'IPv4'
            else:
                return 'Neither'
        else:
            self.content=myip.split(':')
            # print(self.content)
            if self.my_judege():
                # print('IPV6')
                return 'IPv6'
            else:
                return 'Neither'

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
            IP = str(line);

            ret = Solution().validIPAddress(IP)

            out = (ret);
            print(out)
        except StopIteration:
            break


if __name__ == '__main__':
    main()