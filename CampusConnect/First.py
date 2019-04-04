import random
from _io import open
fp1=open("Myfile.txt","r")
fp2=open("MyfileScrambled.txt","w")
l=list()
for line in fp1.readlines():
    l=line.split()
    for word in l:
        if(len(word)<=3):
            fp2=open("MyfileScrambled.txt","a")
            fp2.write(word+' ')
            fp2.close()
        elif(word[len(word)-1]==',' or word[len(word)-1]=='!' or word[len(word)-1]=='.'):
            fp2=open("MyfileScrambled.txt","a")
            sword=word[0]
            words=(random.sample(word[1:(len(word)-2)],(len(word)-3)))
            sword+=''.join(str(i) for i in words)
            sword+=word[len(word)-2]
            sword+=word[len(word)-1]
            fp2.write(sword+' ')
            fp2.close()
        else:
            fp2=open("MyfileScrambled.txt","a")
            sword=word[0]
            words=(random.sample(word[1:len(word)-1],(len(word)-2)))
            sword+=''.join(str(i) for i in words)
            sword+=word[len(word)-1]
            fp2.write(sword+' ')
            fp2.close()
    fp2=open("MyfileScrambled.txt","a")
    fp2.write('\n')
    fp2.close()
fp1.close()
fp2.close()
fp2=open("MyfileScrambled.txt","r")
print(fp2.read())