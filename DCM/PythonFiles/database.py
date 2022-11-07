from msilib.schema import Class
import pickle 
import os

class DataBase:
    def __init__(self):
        self.userDict = {}
        self.userParamDict = {}
        self.fileName = r"usersData.txt" #Username and password file
        self.parameterFile = r"parameterData.txt" #User parameter file

    #Function to save users into database
    def saveUsers(self,name,password): 
        self.userDict[name] = password #Adds user to dictionary
        outFile = open(self.fileName,"wb")
        pickle.dump(self.userDict,outFile) #Dumps dictionary into file
        outFile.close()

    #Save parameters of a user function
    def saveParam(self,dict): 
        self.userParamDict = dict
        outParamFile = open(self.parameterFile,"wb")
        pickle.dump(self.userParamDict,outParamFile)
        outParamFile.close()

    #Function to load the users from the database
    def loadUsers(self):
        try: #Open's file if it exists
            print("Opening File \n")
            file = open(self.fileName,"rb")
        except: #Creates the file if it doesn't exist
            print("Creating new file \n")
            file = open(self.fileName,"w")
            file.close()
        try: #Loads the dictioary 
            loadDict = pickle.load(file)
            if loadDict == None: #If the file is empty
                self.userDict = {} #Creates an empty dictionary
            else:
                self.userDict = loadDict
        except: #File couldn't be opened
            print("Couldn't load pickle file")
            self.userDict = {}
        print("Orginal user dictionary: ", self.userDict)
        file.close()

    #Function to load parameters
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

    #Gets users
    def getUsers(self):
        return self.userDict

    #Checks if a user exists in the database
    def alreadyExist(self,name):
        if (name in self.userDict):
            return True
        else:
            return False
    
    #Checks if the inputed password is correct
    def passMatch(self,name,password):
        if (password == self.userDict[name]):
            return True
        else:
            return False
