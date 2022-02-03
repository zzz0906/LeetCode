class Solution:
    def findDuplicate(self, paths: List[str]) -> List[List[str]]:
        dic = {}
        for path in paths:
            dire =  path.split(' ')[0]
            files = path.split(' ')[1:]
            for file in files:
                content = file[file.find('(') + 1:file.find(')',file.find('(') + 1)]
                name = file[:file.find('(')]
                if (content in dic):
                    dic[content].append(dire + '/' + name)
                else:
                    dic[content] = []
                    dic[content].append(dire + '/' + name)
        res = []
        for key in dic:
            tmp = []
            if (len(dic[key]) < 2):
                continue
            for file in dic[key]:
                tmp.append(file)
            res.append(tmp)
        return res