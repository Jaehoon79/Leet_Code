class Solution:
    def simplifyPath(self, path: str) -> str:
        length = len(path)
        if path[length - 1] == '/':
            path = path[1:length -1]
        else:
            path = path[1:length]
        
        mlist = path.split('/')
        spath = list()
        sdepth = 0

        for val in mlist:
            if val != '..' and val != '.' and val != '':
                spath.append(val)
                sdepth += 1
            else:
                if val == '..' and sdepth > 0:
                    sdepth -= 1
                    spath.pop()  
        
        return '/' + '/'.join(spath[:len(spath)])

def main():
    path_1 = "/home/"
    path_2 = "/../"
    path_3 = "/home//foo/"
    path_4 = "/a/./b/../../c/"
    path_5 = "/a/../../b/../c//.//"
    path_6 = "/a//b////c/d//././/.."
    
    leet = Solution()
    
    print(f"1.Answer of 1st_Q: {leet.simplifyPath(path_1)}")
    print(f"2.Answer of 2nd_Q: {leet.simplifyPath(path_2)}")
    print(f"3.Answer of 3rd_Q: {leet.simplifyPath(path_3)}")
    print(f"4.Answer of 4th_Q: {leet.simplifyPath(path_4)}")
    print(f"5.Answer of 5th_Q: {leet.simplifyPath(path_5)}")
    print(f"5.Answer of 6th_Q: {leet.simplifyPath(path_6)}")
    
if __name__ == "__main__":
    main()