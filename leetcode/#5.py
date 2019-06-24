class Solution(object):
    def longestPalindrome(self, s: str) -> str:
        result = ""
        for i in range(len(s)):
            try:
                if i == 0:
                    result = s[i]
                    if s[i] == s[i + 1]:
                        result = s[i] + s[i + 1]
                elif i > 0:
                    # 单数长度的结果：
                    for l in range(1, i+1):
                        if s[i - l] == s[i + l]:
                            if len(result) <= len(s[i - l:i + l+1]):
                                result = s[i - l:i + l+1]
                        else:
                            break

                    # 双数长度的结果：
                    for l in range(1, i + 1):
                        if s[i] == s[i + 1]:
                            if len(result) <= 2:
                                result = s[i:i + 2]
                            if s[i - l] == s[i + l+1]:
                                if len(result) < len(s[i - l:i + l+2]):
                                    result = s[i - l:i + l+2]
                            else:
                                break
                        else:
                            break
            except IndexError:
                break
        return result


def stringToString(input):
    import json

    return json.loads(input)


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
            s = stringToString(line)

            ret = Solution().longestPalindrome(s)

            out = ret
            print(out)
        except StopIteration:
            break


if __name__ == '__main__':
    main()
