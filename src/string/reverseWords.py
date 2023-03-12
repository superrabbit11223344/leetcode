class Solution(object):
    # 翻转字符串
    def reverse(self, s, i, j):
        while (i < j):
            s[i], s[j] = s[j], s[i]
            i += 1
            j -= 1
        return None

    # 去除多余空格
    def removeExtraSpaces(self, s):
        slow = 0
        fast = 0
        while (len(s) > 0 and fast < len(s) and s[fast] == ' '):
            fast += 1

        while (fast < len(s)):
            if (fast - 1 > 0 and s[fast - 1] == s[fast] and s[fast] == ' '):
                fast += 1
            else:
                s[slow] = s[fast]
                slow += 1
                fast += 1

        if (slow - 1 > 0 and s[slow - 1] == ' '):
            return s[:slow - 1]
        else:
            return s[0:slow]

    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        s = list(s)
        s = self.removeExtraSpaces(s)
        self.reverse(s, 0, len(s) - 1)

        start = 0
        for i in range(len(s) + 1):
            if ((i == len(s)) or s[i] == ' '):
                self.reverse(s, start, i - 1)
                start = i + 1
        return ''.join(s)

solution = Solution()
result = solution.reverseWords("  hello world  ")
print(result)