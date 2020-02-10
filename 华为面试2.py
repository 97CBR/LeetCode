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
        data.sort()
        kk = ''.join(data)
        # print(kk)
        # self.outbox=[]
        e=''
        for ff in range(0, len(data)-1):
            if int(ord(data[ff])) - int(ord(data[ff+1])) == -1:
                e+=data[ff]
                # print(data[ff])
                if ff == len(data) - 2:
                    e+=data[ff+1]
                    self.outbox.append(e)
            else:
                e+=data[ff]
                self.outbox.append(e)
                e=''
                if ff == len(data) - 2:
                    e+=data[ff+1]
                    self.outbox.append(e)
                # print('new', data[ff+1])
        self.outbox.sort()
        if len(self.outbox)>0:
            key=self.outbox[0]
            ls=""
            for i in key:
                ls = ls + i + chr(ord(i) - (ord('A') - ord('a')))
            print(ls)
            self.outbox.pop(0)
            ls=""
            for mm in self.outbox:
                for i in mm:
                    ls = ls + i + chr(ord(i) - (ord('A') - ord('a')))
                self.mystr+=ls
            self.outbox.clear()

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
        ls=""
        oo=[]
        for key in self.outbox:
            for i in key:
                ls= ls+i + chr(ord(i) - (ord('A') - ord('a')))
            oo.append(ls)
            ls=""
        oo.sort(key=lambda x:len(x),reverse=True)
        # print(oo)
        if len(oo) >0:
            for ee in range(0,len(oo)-1):
                if oo[ee][0]!=oo[ee+1][0]:
                    print(oo[ee])
                else:
                    if len(oo[ee])<len( oo[ee+1]):
                        print(oo[ee+1])
                        oo[ee+1]=oo[ee]
                    else:
                        print(oo[ee])
                        # oo.pop(ee+1)
            print(oo[-1])
        else:
            print('Not Found')
# SwSE$3454356DD$$#E#eswsxxsssAAWDxxdderfvcRFER65645hbg^^%%^UnbnvccTRChnyvcxcvVCFR
import sys

if __name__ == "__main__":
    for line in sys.stdin:
        line = line.strip()
        content = str(line)
        # print(content)
        marxcbr().findAll(content)
