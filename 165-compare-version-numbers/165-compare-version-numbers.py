class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        li = version1.split('.')
        li2 = version2.split('.')
        
        if(len(li) > len(li2)):
            diff = len(li) - len(li2)
            for i in range (diff):
                li2.append('0')
                
        elif(len(li2) > len(li)):
            diff = len(li2) - len(li)
            for i in range (diff):
                li.append('0')
                
        for i in range (len(li)):
            if int(li[i]) > int(li2[i]):
                return 1
            elif int(li[i]) < int(li2[i]):
                return -1
        return 0
        