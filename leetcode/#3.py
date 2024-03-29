class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        left, right = 0, 0
        chars = set()
        res = 0
        # s = 'pwwkew'
        while left < len(s) and right < len(s):
            if s[right] in chars:
                if s[left] in chars:
                    chars.remove(s[left])
                left += 1
            else:
                chars.add(s[right])
                right += 1
                res = max(res, len(chars))
        return res