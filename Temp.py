# -*- coding: utf-8 -*-
# @Time    : 3/20/2019 19:13
# @Author  : MARX·CBR
# @File    : 华为面试2.py

class marxcbr:
    def __init__(self):
        self.mystr = ""
        self.allchar = [chr(ord('A') + gg) for gg in range(0, 26)]
        self.outbox=[]

    def make_string(self, data: list):
        data.sort(reverse=False)
        kk = ''.join(data)
        e=''
        for ff in range(0, len(kk)-1):
            if int(ord(kk[ff])) - int(ord(kk[ff+1])) == -1:
                e+=kk[ff]
                # print(data[ff])
                if ff == len(data) - 2:
                    e+=kk[ff+1]
                    self.outbox.append(e)
            else:
                e+=kk[ff]
                self.outbox.append(e)
                e=''
                if ff == len(kk) - 2:
                    e+=kk[ff+1]
                    self.outbox.append(e)
                # print('new', data[ff+1])
        self.outbox.sort(key=lambda x:len(x),reverse=True)
        if len(self.outbox)>0:
            key=self.outbox[0]
            ls=""
            for i in key:
                ls = ls + i + chr(ord(i) - (ord('A') - ord('a')))
            print(ls)
            self.outbox.pop(0)
            for mm in self.outbox:
                ls = ""
                for i in mm:
                    ls = ls + i + chr(ord(i) - (ord('A') - ord('a')))
                self.mystr+=ls
            self.outbox.clear()
        else:
            ...

    def findAll(self, instr):
        self.mystr = instr
        # print(self.allchar)
        gogo = []
        for gg in self.allchar:
            if gg in self.mystr:
                s = chr(ord(gg) - (ord('A') - ord('a')))
                if s in self.mystr:
                    gogo.append(gg)
                    self.mystr = self.mystr.replace(gg, '', 1)
                    self.mystr = self.mystr.replace(s, '', 1)
        # print(gogo)
        self.make_string(gogo)
        if len(gogo)==0:
            print('Not Found')
            return 0
        while len(gogo)>0:
            gogo=[]
            for gg in self.allchar:
                if gg in self.mystr:
                    s = chr(ord(gg) - (ord('A') - ord('a')))
                    if s in self.mystr:
                        gogo.append(gg)
                        self.mystr = self.mystr.replace(gg, '', 1)
                        self.mystr = self.mystr.replace(s, '', 1)
            # print(self.mystr)
            # print(gogo)
            self.make_string(gogo)

import sys

if __name__ == "__main__":
    for line in sys.stdin:
        line = line.strip()
        content = str(line)
        marxcbr().findAll(content)
