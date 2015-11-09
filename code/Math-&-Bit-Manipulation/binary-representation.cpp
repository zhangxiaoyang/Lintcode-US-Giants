描述
给定一个十进制小数，转换成二进制。


思路
分别对小数部分和整数部分转换，对于小数部分，依次乘以2取整数部分，再把小数部分依次乘以2取整数部分...，不断重复，直到小数部分为0，最后把取出的整数部分拼成二进制；对于整数部分，依次除以2，再对商除以2，依次不断重复，直到商为0，最后把余数倒叙排序即可。需要注意的是，c++的double和float无法进行精确计算啊！所以，使用python的decimal库完成。


代码
import decimal

class Solution:
    #@param n: Given a decimal number that is passed in as a string
    #@return: A string
    def binaryRepresentation(self, n):
        # write you code here
        num = decimal.Decimal(n)
        left = int(num)
        right = num - left
        result = ''
        while left:
            result = chr(left % 2 + ord('0')) + result
            left /= 2
        
        if result == '':
            result = '0'
        if right:
            result += '.'
        
        count = 0
        limit = 32
        while right:
            if count >= limit:
                return 'ERROR'
                
            result += chr(int(right * 2) + ord('0'))
            right = right * 2 - int(right * 2)
            count += 1
        
        return result

