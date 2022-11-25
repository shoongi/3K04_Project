import database
import parameters
class AOO:
    def __init__(self,name):
        self.name = name
        self.userData = database.DataBase()
        self.LRL = 60
        self.URL = 120
        self.AA = 3.5
        self.APW = 0.4
        self.AOOData = {}

    def loadAOO(self): #Loads AOO data
        self.userData.loadParam()
        userDict = self.userData.userParamDict
        if (self.name in userDict): #If the user has existing data
            if ("AOO" in userDict[self.name]): #If the user has existing AOO data, set class data to file data
                self.LRL = userDict[self.name]["AOO"]["LRL"]
                self.URL = userDict[self.name]["AOO"]["URL"]
                self.AA = userDict[self.name]["AOO"]["AA"]
                self.APW = userDict[self.name]["AOO"]["APW"]
            else: #User doesn't have existing AOO data, set dictionary data to class data
                userDict[self.name]["AOO"] = {}
                userDict[self.name]["AOO"]["LRL"] = self.LRL
                userDict[self.name]["AOO"]["URL"] = self.URL
                userDict[self.name]["AOO"]["AA"] = self.AA
                userDict[self.name]["AOO"]["APW"] = self.APW
        else: #User doesn't exist, set dictionary data to class data
            userDict[self.name] = {}
            userDict[self.name]["AOO"] = {}
            userDict[self.name]["AOO"]["LRL"] = self.LRL
            userDict[self.name]["AOO"]["URL"] = self.URL
            userDict[self.name]["AOO"]["AA"] = self.AA
            userDict[self.name]["AOO"]["APW"] = self.APW
        self.AOOData = userDict

    def addLRL(self,inputLRL):
        acceptable, comment = parameters.addLRL(self,inputLRL)

        if (acceptable == True):
            self.LRL = inputLRL
            self.addAOO()
        else: 
            print(comment)

    def addURL(self,inputURL):
        acceptable, comment = parameters.addURL(self,inputURL)

        if (acceptable == True):
            self.URL = inputURL
            self.addAOO()
        else:
            print(comment)

    def addAA(self,inputAA):
        acceptable, comment = parameters.addAA(self,inputAA)

        if (acceptable == True):
            self.AA = inputAA
            self.addAOO()
        else:
            print(comment)

    def addAPW(self,inputAPW):
        acceptable, comment = parameters.addAPW(self,inputAPW)

        if (acceptable == True):
            self.APW = inputAPW
            self.addAOO()
        else:
            print(comment)
    
    def addAOO(self):
        print("Added AOO\n")
        print(self.APW)
        self.AOOData[self.name]["AOO"]["LRL"] = self.LRL
        self.AOOData[self.name]["AOO"]["URL"] = self.URL
        self.AOOData[self.name]["AOO"]["AA"] = self.AA
        self.AOOData[self.name]["AOO"]["APW"] = self.APW
        print("Saving")
        print(self.AOOData)
        self.userData.saveParam(self.AOOData)

####################################################################################################################################
####################################################################################################################################
####################################################################################################################################

class VOO:
    def __init__(self,name):
        self.name = name
        self.userData = database.DataBase()
        self.LRL = 60
        self.URL = 120
        self.VA = 3.5
        self.VPW = 0.4
        self.VOOData = {}

    def loadVOO(self):
        self.userData.loadParam()
        userDict = self.userData.userParamDict
        if (self.name in userDict):
            if ("VOO" in userDict[self.name]):
                self.LRL = userDict[self.name]["VOO"]["LRL"]
                self.URL = userDict[self.name]["VOO"]["URL"]
                self.VA = userDict[self.name]["VOO"]["VA"]
                self.VPW = userDict[self.name]["VOO"]["VPW"]
            else:
                userDict[self.name]["VOO"] = {}
                userDict[self.name]["VOO"]["LRL"] = self.LRL
                userDict[self.name]["VOO"]["URL"] = self.URL
                userDict[self.name]["VOO"]["VA"] = self.VA
                userDict[self.name]["VOO"]["VPW"] = self.VPW
        else:
            userDict[self.name] = {}
            userDict[self.name]["VOO"] = {}
            userDict[self.name]["VOO"]["LRL"] = self.LRL
            userDict[self.name]["VOO"]["URL"] = self.URL
            userDict[self.name]["VOO"]["VA"] = self.VA
            userDict[self.name]["VOO"]["VPW"] = self.VPW
        self.VOOData = userDict

    def addLRL(self,inputLRL):
        acceptable, comment = parameters.addLRL(self,inputLRL)

        if (acceptable == True):
            self.LRL = inputLRL
            self.addVOO()
        else: 
            print(comment)
    
    def addURL(self,inputURL):
        acceptable, comment = parameters.addURL(self,inputURL)

        if (acceptable == True):
            self.URL = inputURL
            self.addVOO()
        else:
            print(comment)

    def addVA(self,inputVA):
        acceptable, comment = parameters.addVA(self,inputVA)

        if (acceptable == True):
            self.VA = inputVA
            self.addVOO()
        else:
            print(comment)

    def addVPW(self,inputVPW):
        acceptable, comment = parameters.addVPW(self,inputVPW)

        if (acceptable == True):
            self.VPW = inputVPW
            self.addVOO()
        else:
            print(comment)

    def addVOO(self):
        print("Added VOO\n")
        print(self.VPW)
        self.VOOData[self.name]["VOO"]["LRL"] = self.LRL
        self.VOOData[self.name]["VOO"]["URL"] = self.URL
        self.VOOData[self.name]["VOO"]["VA"] = self.VA
        self.VOOData[self.name]["VOO"]["VPW"] = self.VPW
        print("Saving")
        print(self.VOOData)
        self.userData.saveParam(self.VOOData)

####################################################################################################################################
####################################################################################################################################
####################################################################################################################################

class AAI:
    def __init__(self,name):
        self.name = name
        self.userData = database.DataBase()
        self.LRL = 60
        self.URL = 120
        self.AA = 3.5
        self.ARP = 250
        self.APW = 0.4
        self.AAIData = {}

    def loadAAI(self):
        self.userData.loadParam()
        userDict = self.userData.userParamDict
        if (self.name in userDict):
            if ("AAI" in userDict[self.name]):
                self.LRL = userDict[self.name]["AAI"]["LRL"]
                self.URL = userDict[self.name]["AAI"]["URL"]
                self.AA = userDict[self.name]["AAI"]["AA"]
                self.APW = userDict[self.name]["AAI"]["APW"]
                self.ARP = userDict[self.name]["AAI"]["ARP"]
            else:
                userDict[self.name]["AAI"] = {}
                userDict[self.name]["AAI"]["LRL"] = self.LRL
                userDict[self.name]["AAI"]["URL"] = self.URL
                userDict[self.name]["AAI"]["AA"] = self.AA
                userDict[self.name]["AAI"]["APW"] = self.APW
                userDict[self.name]["AAI"]["ARP"] = self.ARP
        else:
            userDict[self.name] = {}
            userDict[self.name]["AAI"] = {}
            userDict[self.name]["AAI"]["LRL"] = self.LRL
            userDict[self.name]["AAI"]["URL"] = self.URL
            userDict[self.name]["AAI"]["AA"] = self.AA
            userDict[self.name]["AAI"]["APW"] = self.APW
            userDict[self.name]["AAI"]["ARP"] = self.ARP
        self.AAIData = userDict

    def addLRL(self,inputLRL):
        acceptable, comment = parameters.addLRL(self,inputLRL)

        if (acceptable == True):
            self.LRL = inputLRL
            self.addAAI()
        else: 
            print(comment)

    def addURL(self,inputURL):
        acceptable, comment = parameters.addURL(self,inputURL)

        if (acceptable == True):
            self.URL = inputURL
            self.addAAI()
        else:
            print(comment)

    def addAA(self,inputAA):
        acceptable, comment = parameters.addURL(self,inputAA)

        if (acceptable == True):
            self.URL = inputAA
            self.addAAI()
        else:
            print(comment)

    def addAPW(self,inputAPW):
        acceptable, comment = parameters.addURL(self,inputAPW)

        if (acceptable == True):
            self.URL = inputAPW
            self.addAAI()
        else:
            print(comment)

    def addARP(self,inputARP):
        acceptable, comment = parameters.addURL(self,inputARP)

        if (acceptable == True):
            self.URL = inputARP
            self.addAAI()
        else:
            print(comment)

    def addAAI(self):
        print("Added AAI\n")
        print(self.ARP)
        self.AAIData[self.name]["AAI"]["LRL"] = self.LRL
        self.AAIData[self.name]["AAI"]["URL"] = self.URL
        self.AAIData[self.name]["AAI"]["AA"] = self.AA
        self.AAIData[self.name]["AAI"]["APW"] = self.APW
        self.AAIData[self.name]["AAI"]["ARP"] = self.ARP
        print("Saving")
        print(self.AAIData)
        self.userData.saveParam(self.AAIData)

####################################################################################################################################
####################################################################################################################################
####################################################################################################################################

class VVI:
    def __init__(self,name):
        self.name = name
        self.userData = database.DataBase()
        self.LRL = 60
        self.URL = 175
        self.VA = 3.5
        self.VPW = 0.4
        self.VRP = 320
        self.VVIData = {}

    def loadVVI(self):
        self.userData.loadParam()
        userDict = self.userData.userParamDict
        if (self.name in userDict):
            if ("VVI" in userDict[self.name]):
                self.LRL = userDict[self.name]["VVI"]["LRL"]
                self.URL = userDict[self.name]["VVI"]["URL"]
                self.VA = userDict[self.name]["VVI"]["VA"]
                self.VPW = userDict[self.name]["VVI"]["VPW"]
                self.VRP = userDict[self.name]["VVI"]["VRP"]
            else:
                userDict[self.name]["VVI"] = {}
                userDict[self.name]["VVI"]["LRL"] = self.LRL
                userDict[self.name]["VVI"]["URL"] = self.URL
                userDict[self.name]["VVI"]["VA"] = self.VA
                userDict[self.name]["VVI"]["VPW"] = self.VPW
                userDict[self.name]["VVI"]["VRP"] = self.VRP
        else:
            userDict[self.name] = {}
            userDict[self.name]["VVI"] = {}
            userDict[self.name]["VVI"]["LRL"] = self.LRL
            userDict[self.name]["VVI"]["URL"] = self.URL
            userDict[self.name]["VVI"]["VA"] = self.VA
            userDict[self.name]["VVI"]["VPW"] = self.VPW
            userDict[self.name]["VVI"]["VRP"] = self.VRP
        self.VVIData = userDict

    def addURL(self,inputURL):
        acceptable, comment = parameters.addURL(self,inputURL)

        if (acceptable == True):
            self.URL = inputURL
            self.addVVI()
        else:
            print(comment)

    def addLRL(self,inputLRL):
        acceptable, comment = parameters.addLRL(self,inputLRL)

        if (acceptable == True):
            self.LRL = inputLRL
            self.addVVI()
        else: 
            print(comment)

    def addVA(self,inputVA):
        acceptable, comment = parameters.addVA(self,inputVA)

        if (acceptable == True):
            self.VA = inputVA
            self.addVVI()
        else:
            print(comment)

    def addVPW(self,inputVPW):
        VPW = float(inputVPW)
        if (VPW == 0.05):
            self.VPW = VPW
            print("Added VPW")
            return True, "Good"
        elif (VPW >= 0.1 and VPW <= 1.9):
            if (True):
                self.VPW = VPW
                print("Added VPW")
                return True, "Good"
            else:
                print("VPW must be increment of 0.1")
                return False, "VPW must be increment of 0.1"
        else:
            print("VPW must be within range of 0.05 or 0.1-1.9")
            return False, "VPW must be within range of 0.05 or 0.1-1.9"

    def addVRP(self,inputVRP):
        VRP = int(inputVRP)
        if (VRP >= 150 or VRP <= 500):
            if (VRP < self.LRL):
                print ("VRP must be larger than the LRL")
                return False, "VRP must be larger than the LRL"
            if (VRP > self.VPW):
                print ("VRP must be less than the VPW")
                return False, "VRP must be less than the VPW"
            if (VRP % 10 == 0):
                self.VRP = VRP
                print("Added VRP")
                return True, "Good"
            else:
                print("VRP must be increment of 10")
                return False, "VRP must be increment of 10"
        else:
            print("VRP must be within range of 150-500")
            return False, "VRP must be within range of 150-500"

    def addVVI(self):
        print("Added VVI\n")
        print(self.VRP)
        self.VVIData[self.name]["VVI"]["LRL"] = self.LRL
        self.VVIData[self.name]["VVI"]["URL"] = self.URL
        self.VVIData[self.name]["VVI"]["VA"] = self.VA
        self.VVIData[self.name]["VVI"]["VPW"] = self.VPW
        self.VVIData[self.name]["VVI"]["VRP"] = self.VRP
        print("Saving")
        print(self.VVIData)
        self.userData.saveParam(self.VVIData)
