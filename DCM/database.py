from msilib.schema import Class
import pickle 
import os

class DataBase:
    def __init__(self):
        self.userDict = {}
        self.fileName = "usersData.txt"

    def saveUsers(self,name,password):
        self.userDict[name] = password
        outFile = open(self.fileName,"wb")
        pickle.dump(self.userDict,outFile)
        outFile.close()

    def loadUsers(self):
        try:
            file = open(self.fileName,"rb")
        except:
            file = open(self.fileName,"w")
            file.close()
            file = open(self.fileName,"rb")
        try:
            loadDict = pickle.load(file)
            if loadDict == None:
                self.userDict = {}
            else:
                self.userDict = loadDict
        except:
            print("Couldn't load pickle file")
            self.userDict = {}
        print("Orginal user dictionary: ", self.userDict)
        file.close()

    def getUsers(self):
        return self.userDict

    def alreadyExist(self,name):
        if (name in self.userDict):
            return True
        else:
            return False
    
    def passMatch(self,name,password):
        if (password == self.userDict[name]):
            return True
        else:
            return False
