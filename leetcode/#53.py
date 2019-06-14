# number's "List" Type => []
from typing import List


class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        if max(nums) < 0:
            return max(nums)

        local_max, global_max = 0, 0
        for num in nums:
            local_max = max(0, local_max+num)
            global_max = max(global_max, local_max)

        return global_max


def stringToIntegerList(_input):
    import json
    return json.loads(_input)


def main():
    import sys
    import io
    def readlines():
        for _line in io.TextIOWrapper(sys.stdin.buffer, encoding='utf-8'):
            yield _line.strip('\n')

    lines = readlines()
    while True:
        try:
            line = next(lines)
            nums = stringToIntegerList(line)

            ret = Solution().maxSubArray(nums)

            out = str(ret)
            print(out)
        except StopIteration:
            break


if __name__ == '__main__':
    main()
