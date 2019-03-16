from math import sqrt


class Solution:
    def nearestPalindromic(self, n: str) -> str:
        # print(str)
        test_number = n
        s = str(test_number)
        ol=len(str(test_number))
        l = len(s)
        if l % 2 == 0:
            # 前半截
            hs = s[:int(l / 2):]
        else:
            hs = s[:int(l / 2) + 1:]
        k = hs
        k=int(k)
        t=k
        for i in range(k):
            if k<=int(t/10):
                break
            if k<2:
                break
            k-=1
        k=str(k)

        if int(n) <=10:
            return str(int(n) - 1)

        r=[]
        r.append(int(n))
        r.append(999999999999999)
        r.append(0)
        # print(r)
        while 1:

            ss = k[:len(k):] + k[::-1]
            if int(ss) not in r:
                if abs(int(ss)-r[0])<abs(r[1]-r[0]):
                    r[1]=int(ss)
                else:
                    r[2]+=1
                # if int(ss)<int(test_number)/10:
                #     ...
                # elif int(ss)>int(test_number)*10:
                #     ...
                # else:
                #     r.append(int(ss))
            ss = k + k[-2::-1]
            if int(ss)  not in r:
                if abs(int(ss)-r[0])<=abs(r[1]-r[0]):
                    if abs(int(ss)-r[0])==abs(r[1]-r[0]):
                        if int(ss)<r[1]:
                            r[1]=int(ss)
                        else:
                            ...
                    else:
                        r[1] = int(ss)
                else:
                    r[2]+=1
                # r.append(int(ss))
                # if int(ss) < int(test_number) / 10:
                #     ...
                # elif int(ss)>int(test_number)*10:
                #     ...
                # else:
                #     r.append(int(ss))

            k = int(k) + 1
            k = str(k)
            if r[2] > int(sqrt(int(n))+1000):
                # print(r)
                return str(r[1])
                # print(r)
                # print(r[0])
                # if int(n) not in r:
                    # r.append(int(n))
                # r.sort(reverse=False)
                # print(r)
                # o=0
                # for g in r:
                #     if g==int(n):
                #         if abs(int(n)-r[o-1])>abs(int(n)-r[o+1]):
                #             return str(r[o+1])
                #         else:
                #             return str(r[o - 1])
                #     o+=1
                # return str(r[0])



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
            N = int(line)
            ret = Solution().nearestPalindromic(N)
            out = str(ret)
            print(out)
        except StopIteration:
            break


if __name__ == '__main__':
    main()

    # t=
    # # while k>(k-2):
    # #     if k<=1:
    # #         break
    # #     k-=1
    # k = str(k)
    # r = []
    # if int(n) < 10:
    #     return str(int(n) - 1)
    # r.append(int(n))
    # bs = []
    # if int(test_number) > 1111111:
    #     print('超大')
    #     # k是减掉后是数字
    #     middle = int(hs)
    #     middle = int(middle - 10)
    #     middle = str(middle)
    #     while 1:
    #         ss = middle + middle[::-1]
    #         bs.append(int(ss))
    #         ss = middle + middle[-2::-1]
    #         bs.append(int(ss))
    #         middle = int(middle)
    #         middle += 1
    #         middle = str(middle)
    #         if len(bs) > 1000:
    #             # print(r)
    #             # print(r[0])
    #             if int(n) not in bs:
    #                 bs.append(int(n))
    #             bs.sort()
    #             print(bs)
    #             o = 0
    #             for g in bs:
    #                 if g == int(n):
    #                     if abs(int(n) - bs[o - 1]) > abs(int(n) - bs[o + 1]):
    #                         return str(bs[o + 1])
    #                     else:
    #                         return str(bs[o - 1])
    #                 o += 1
