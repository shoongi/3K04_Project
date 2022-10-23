from msilib.schema import Class
import pickle 
import os

class DataBase:
    def __init__(self):
        self.userDict = {}
        self.userParamDict = {}
        self.fileName = r"usersData.txt"
        self.parameterFile = r"parameterData.txt"

    def saveUsers(self,name,password):
        self.userDict[name] = password
        outFile = open(self.fileName,"wb")
        pickle.dump(self.userDict,outFile)
        outFile.close()

    def saveParam(self,dict):
        self.userParamDict = dict
        outParamFile = open(self.parameterFile,"wb")
        pickle.dump(self.userParamDict,outParamFile)
        outParamFile.close()

    def loadUsers(self):
        try:
            print("Opening File \n")
            file = open(self.fileName,"rb")
        except:
            print("Creating new file \n")
            file = open(self.fileName,"w")
            file.close()
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

    def loadParam(self):
        try:
            print("Opening File \n")
            file = open(self.parameterFile,"rb")
        except:
            print("Creating new file \n")
            file = open(self.parameterFile,"w")
            file.close()
        try:
            loadDict = pickle.load(file)
            if loadDict == None:
                self.userParamDict = {}
            else:
                self.userParamDict = loadDict
        except:
            print("Couldn't load pickle file")
            self.userParamDict = {}
        print("Orginal parameter dictionary: ", self.userParamDict)
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
