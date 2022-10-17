from msilib.schema import Class
import database

class User:
    def __init__(self,name,password):
        self.name = name
        self.password = password
        self.userData = database.DataBase()

    def getName(self):
        return self.name

    def getPassword(self):
        return self.password
    
    def addUser(self):
        self.userData.loadUsers()

        if (len(self.userData.userDict) < 10):
            if (self.userData.alreadyExist(self.name)):
                print("User already exists")
            else:
                self.userData.saveUsers(self.name,self.password)
        else:
            print("10 users already")
    
    def getUsers(self):
        return self.userData.userDict

    def login(self):
        canLogin = False
        self.userData.loadUsers()

        if (self.userData.alreadyExist(self.name)):
            if (self.userData.passMatch(self.name,self.password)):
                print ("Logged In")
                return True
            else:
                print ("Password Wrong")
                return False
        else:
            print ("User doesn't exist")
            return False