# -*- coding: utf-8 -*-
# @Time    : 3/14/2019 20:04
# @Author  : MARX·CBR
# @File    : 索引处的解码字符串.py

# 输入：S = "leet2code3", K = 10
# 输出："o"
# 解释：
# 解码后的字符串为 "leetleetcodeleetleetcodeleetleetcode"。
# 字符串中的第 10 个字母是 "o"。

class Solution:
    def __init__(self):
        self.content=""
    def decodeAtIndex(self, S: str, K: int) -> str:
        if K==1:
            return S[0]
        # print( S, K)
        for k in S:
            num=0
            try:
                num=int(k)
                num-=1
                now=self.content
                for gg in range(num):
                    self.content=self.content+now
            except:
                self.content += k
                # ...
        # print(self.content)
        return self.content[K-1]


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
            S = str(line);
            line = next(lines)
            K = int(line);

            ret = Solution().decodeAtIndex(S, K)

            out = (ret);
            print(out)
        except StopIteration:
            break


if __name__ == '__main__':
    main()