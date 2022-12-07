from typing import List


def uncommonFromSentences(s1: str, s2: str) -> List[str]:

    common = []
    x = s1.split()
    y = s2.split()

    xDict = {}
    yDict = {}

    for i in x:
        if (i in xDict):
            xDict[i] += 1
        else:
            xDict[i] = 1

    for j in y:
        if (j in yDict):
            yDict[j] += 1
        else:
            yDict[j] = 1

    for i in xDict : 
        if xDict.get(i) == 1 and yDict.get(i) == None : common.append(i)

    for j in yDict :
        if yDict.get(j) == 1 and xDict.get(j) == None : common.append(j)
    
    return common


prompt = ["this apple is sweet", "this apple is sour"]
print(uncommonFromSentences(prompt[0], prompt[1]))