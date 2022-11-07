from msilib.schema import Class
import database
import modes

class User:
    def __init__(self,name,password):
        self.name = name
        self.password = password
        self.userData = database.DataBase() #Loads the database

    #Gets the username
    def getName(self):
        return self.name

    #Gets the password
    def getPassword(self):
        return self.password
    
    #Function to add a user to the database
    def addUser(self):
        self.userData.loadUsers() #Loads users

        if (self.name != "" and self.password != ""): #Checks if username or password is blank
            if (len(self.userData.userDict) < 10): #CHecks if number of users is less than 10
                if (self.userData.alreadyExist(self.name)): #The user already exists
                    print("User already exists")
                    return (False, "User already exists")
                else: #User doesn't exist, can create a new user
                    print("Saving User \n")
                    self.userData.saveUsers(self.name,self.password)
                    return (True, "Good")
            else: #There are already 10 users, can't create
                print("10 users already")
                return (False, "10 users already")
        else:
            if (self.name == "" and self.password != ""):
                return (False, "Enter a non empty username")
            elif (self.password == "" and self.name != ""):
                return (False, "Enter a non empty password")
            else:
                return (False, "Enter a non empty username and password")
    
    #Gets users
    def getUsers(self):
        return self.userData.userDict

    #Function to login 
    def login(self):
        canLogin = False
        self.userData.loadUsers()

        if (self.userData.alreadyExist(self.name)): #Checks if the user exists
            if (self.userData.passMatch(self.name,self.password)): #Checks if the the password matches, calls the password function in database.py
                print ("Logged In")
                return (True, "Good")
            else: #Password is incorrect
                print ("Password Wrong")
                return (False, "Password Wrong")
        else:
            print ("User doesn't exist")
            return (False, "User doesn't exist")
