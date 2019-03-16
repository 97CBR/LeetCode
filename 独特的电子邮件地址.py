# -*- coding: utf-8 -*-
# @Time    : 3/16/2019 15:40
# @Author  : MARX·CBR
# @File    : 独特的电子邮件地址.py
import json
class Solution:
    def __init__(self):
        self.content=[]

    def numUniqueEmails(self, emails: list) -> int:
        # print(emails)
        for i in emails:
            # print(i)
            fr,to=i.split("@")
            try:
                ad=fr.split("+")[0].replace('.','')
            except:
                ad=fr.replace('.','')
            # print(ad)
            send=ad+'@'+to
            if send not in self.content:
                self.content.append(send)
            # # print(fr,to)
            # if to[0] not in self.content:
            #     self.content.append(i)
        # print(self.content)
        o=len(self.content)
        self.content.clear()
        return o


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

            ret = Solution().numUniqueEmails(A)

            out = integerListToString(ret);
            print(out)
        except StopIteration:
            break


if __name__ == '__main__':
    main()