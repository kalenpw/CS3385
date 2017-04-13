import os
import shutil

if not os.path.exists("hw"):
    os.makedirs("hw")
    print("created hw directory")

source='/home/kalenpw/Documents/School/2017Spring/CS3385/hw/'

files = os.listdir()

for f in files:
    if f.startswith("hw") and len(f) > 2:
        #Delete hw<number> foloders
        #shutil.rmtree(f)

        #move inside files to hw/ folder
        for eachFile in os.listdir(f):
            filePath = os.path.join(f, eachFile)
            shutil.move(filePath, source)

