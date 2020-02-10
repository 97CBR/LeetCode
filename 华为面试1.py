# -*- coding: utf-8 -*-
# @Time    : 3/20/2019 18:53
# @Author  : MARX·CBR
# @File    : 华为面试1.py

import sys
if __name__ == "__main__":
    for line in sys.stdin:
        line = line.strip()
        content=str(line)
        # print(content)
        try:
            first=content.split('=')[0]
        except:
            first=content
        l=content.split('+')
        # print(l)
        num=0
        for k in l:
            if '-' not in k:
                num+=int(k)
            else:
                down=k.split('-')
                num += int(down[0])
                for h in down[1::]:
                    num-=int(h)
        print(num)

