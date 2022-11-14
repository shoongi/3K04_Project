import database
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
        LRL = int(inputLRL)
        print(LRL)
        if (LRL < self.URL):
            if (LRL >= 30 and LRL <= 50):
                if (LRL % 5 == 0):
                    self.LRL = LRL
                    print("Added LRL")
                    return True,"Good"
                else:
                    print("LRL must be an increment of 5")
                    return False,"LRL must be an increment of 5"
            elif (LRL >= 50 and LRL <= 90):
                if (LRL % 1 == 0):
                    self.LRL = LRL
                    print("Added LRL")
                    return True,"Good"
                else:
                    print("LRL must be an increment of 1")
                    return False,"LRL must be an increment of 1"
            elif (LRL >= 90 and LRL <= 175):
                if (LRL % 5 == 0):
                    self.LRL = LRL
                    print("Added LRL")
                    return True,"Good"
                else:
                    print("LRL must be an increment of 5")
                    return False,"LRL must be an increment of 5"
            else:
                print("LRL not within range of 30-175")
                return False, "LRL not within range of 30-175"
        else:
            print("LRL is greater than the URL")
            return False, "LRL is greater than the URL"

    def addURL(self,inputURL):
        URL = int(inputURL)
        if (URL > self.LRL):
            if (URL >= 50 and URL <= 175):
                if (URL % 5 == 0):
                    self.URL = URL
                    print("Added URL")
                    return True, "Good"
                else:
                    return False, "URL must be increment of 5"
            else:
                return False, "URL not within range of 50-175"
        else:
            return False, "URL is smaller than the LRL"

    def addAA(self,inputAA):
        try:
            AA = float(inputAA)
            if (AA >= 0.5 and AA <= 3.2):
                if (AA % 0.1 == 0):
                    self.AA = AA
                    print("Added AA")
                    return True, "Good"
                else:
                    print("AA must be increment of 0.1")
                    return False, "AA must be increment of 0.1"

            elif (float(AA) >= 3.5 and float(AA) <= 7):
                if (float(AA) % 0.5 == 0):
                    self.AA = AA
                    print("Added AA")
                    return True, "Good"
                else:
                    print("AA must be increment of 0.5")
                    return False, "AA must be increment of 0.5"

            else:
                print ("AA must be off, within range of 0.5-3.2 or 3.5-7.0")

        except:
            AA = inputAA
            if (str(AA).lower == "off"):
                self.AA = "off"
                print("Added AA")

            else:
                print("AA must be off, within range of 0.5-3.2 or 3.5-7.0")
                return False, "AA must be off, within range of 0.5-3.2 or 3.5-7.0"

    def addAPW(self,inputAPW):
        APW = float(inputAPW)
        if (APW == 0.05):
            self.APW = APW
            print("Added APW")
            return True, "Good"
        elif (APW >= 0.1 and APW <= 1.9):
            if (True):
                self.APW = APW
                print("Added APW")
                return True, "Good"
            else:
                print("APW must be increment of 0.1")
                return False, "APW must be increment of 0.1"
        else:
            print("APW must be within range of 0.05 or 0.1-1.9")
            return False, "APW must be within range of 0.05 or 0.1-1.9"
    
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
        LRL = int(inputLRL)
        print(LRL)
        if (LRL < self.URL):
            if (LRL >= 30 and LRL <= 50):
                if (LRL % 5 == 0):
                    self.LRL = LRL
                    print("Added LRL")
                    return True,"Good"
                else:
                    print("LRL must be an increment of 5")
                    return False,"LRL must be an increment of 5"
            elif (LRL >= 50 and LRL <= 90):
                if (LRL % 1 == 0):
                    self.LRL = LRL
                    print("Added LRL")
                    return True,"Good"
                else:
                    print("LRL must be an increment of 1")
                    return False,"LRL must be an increment of 1"
            elif (LRL >= 90 and LRL <= 175):
                if (LRL % 5 == 0):
                    self.LRL = LRL
                    print("Added LRL")
                    return True,"Good"
                else:
                    print("LRL must be an increment of 5")
                    return False,"LRL must be an increment of 5"
            else:
                print("LRL not within range of 30-175")
                return False, "LRL not within range of 30-175"
        else:
            print("LRL is greater than the URL")
            return False, "LRL is greater than the URL"

    def addURL(self,inputURL):
        URL = int(inputURL)
        if (URL > self.LRL):
            if (URL >= 50 and URL <= 175):
                if (URL % 5 == 0):
                    self.URL = URL
                    print("Added URL")
                    return True, "Good"
                else:
                    print("URL must be increment of 5")
                    return False, "URL must be increment of 5"
            else:
                print("URL not within range of 50-175")
                return False, "URL not within range of 50-175"
        else:
            print("URL is smaller than the LRL")
            return False, "URL is smaller than the LRL"

    def addVA(self,inputVA):
        try:
            VA = float(inputVA)
            if (VA >= 0.5 and VA <= 3.2):
                if (VA % 0.1 == 0):
                    self.VA = VA
                    print("Added VA")
                    return True, "Good"
                else:
                    print("VA must be increment of 0.1")
                    return False, "VA must be increment of 0.1"

            elif (float(VA) >= 3.5 and float(VA) <= 7):
                if (float(VA) % 0.5 == 0):
                    self.VA = VA
                    print("Added AA")
                    return True, "Good"
                else:
                    print("AA must be increment of 0.5")
                    return False, "AA must be increment of 0.5"

            else:
                print ("AA must be off, within range of 0.5-3.2 or 3.5-7.0")

        except:
            VA = inputVA
            if (str(VA).lower == "off"):
                self.VA = "off"
                print("Added VA")

            else:
                print("VA must be off, within range of 0.5-3.2 or 3.5-7.0")
                return False, "AA must be off, within range of 0.5-3.2 or 3.5-7.0"

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
        LRL = int(inputLRL)
        print(LRL)
        if (LRL < self.URL):
            if (LRL >= 30 and LRL <= 50):
                if (LRL % 5 == 0):
                    self.LRL = LRL
                    print("Added LRL")
                    return True,"Good"
                else:
                    print("LRL must be an increment of 5")
                    return False,"LRL must be an increment of 5"
            elif (LRL >= 50 and LRL <= 90):
                if (LRL % 1 == 0):
                    self.LRL = LRL
                    print("Added LRL")
                    return True,"Good"
                else:
                    print("LRL must be an increment of 1")
                    return False,"LRL must be an increment of 1"
            elif (LRL >= 90 and LRL <= 175):
                if (LRL % 5 == 0):
                    self.LRL = LRL
                    print("Added LRL")
                    return True,"Good"
                else:
                    print("LRL must be an increment of 5")
                    return False,"LRL must be an increment of 5"
            else:
                print("LRL not within range of 30-175")
                return False, "LRL not within range of 30-175"
        else:
            print("LRL is greater than the URL")
            return False, "LRL is greater than the URL"

    def addURL(self,inputURL):
        URL = int(inputURL)
        if (URL > self.LRL):
            if (URL >= 50 and URL <= 175):
                if (URL % 5 == 0):
                    self.URL = URL
                    print("Added URL")
                    return True, "Good"
                else:
                    return False, "URL must be increment of 5"
            else:
                return False, "URL not within range of 50-175"
        else:
            return False, "URL is smaller than the LRL"

    def addAA(self,inputAA):
        try:
            AA = float(inputAA)
            if (AA >= 0.5 and AA <= 3.2):
                if (AA % 0.1 == 0):
                    self.AA = AA
                    print("Added AA")
                    return True, "Good"
                else:
                    print("AA must be increment of 0.1")
                    return False, "AA must be increment of 0.1"

            elif (float(AA) >= 3.5 and float(AA) <= 7):
                if (float(AA) % 0.5 == 0):
                    self.AA = AA
                    print("Added AA")
                    return True, "Good"
                else:
                    print("AA must be increment of 0.5")
                    return False, "AA must be increment of 0.5"

            else:
                print ("AA must be off, within range of 0.5-3.2 or 3.5-7.0")

        except:
            AA = inputAA
            if (str(AA).lower == "off"):
                self.AA = "off"
                print("Added AA")

            else:
                print("AA must be off, within range of 0.5-3.2 or 3.5-7.0")
                return False, "AA must be off, within range of 0.5-3.2 or 3.5-7.0"

    def addAPW(self,inputAPW):
        APW = float(inputAPW)
        if (APW == 0.05):
            self.APW = APW
            print("Added APW")
            return True, "Good"
        elif (APW >= 0.1 and APW <= 1.9):
            if (True):
                self.APW = APW
                print("Added APW")
                return True, "Good"
            else:
                print("APW must be increment of 0.1")
                return False, "APW must be increment of 0.1"
        else:
            print("APW must be within range of 0.05 or 0.1-1.9")
            return False, "APW must be within range of 0.05 or 0.1-1.9"

    def addARP(self,inputARP):
        ARP = int(inputARP)
        if (ARP >= 150 or ARP <= 500):
            if (ARP < self.LRL):
                print ("ARP must be larger than the LRL")
                return False, "ARP must be larger than the LRL"
            if (ARP > self.APW):
                print ("ARP must be less than the APW")
                return False, "ARP must be less than the APW"
            if (ARP % 10 == 0):
                self.ARP = ARP
                print("Added ARP")
                return True, "Good"
            else:
                return False, "ARP must be increment of 10"
        else:
            return False, "ARP must be within range of 150-500"

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

    def addLRL(self,inputLRL):
        LRL = int(inputLRL)
        print(LRL)
        if (LRL < self.URL):
            if (LRL >= 30 and LRL <= 50):
                if (LRL % 5 == 0):
                    self.LRL = LRL
                    print("Added LRL")
                    return True,"Good"
                else:
                    print("LRL must be an increment of 5")
                    return False,"LRL must be an increment of 5"
            elif (LRL >= 50 and LRL <= 90):
                if (LRL % 1 == 0):
                    self.LRL = LRL
                    print("Added LRL")
                    return True,"Good"
                else:
                    print("LRL must be an increment of 1")
                    return False,"LRL must be an increment of 1"
            elif (LRL >= 90 and LRL <= 175):
                if (LRL % 5 == 0):
                    self.LRL = LRL
                    print("Added LRL")
                    return True,"Good"
                else:
                    print("LRL must be an increment of 5")
                    return False,"LRL must be an increment of 5"
            else:
                print("LRL not within range of 30-175")
                return False, "LRL not within range of 30-175"
        else:
            print("LRL is greater than the URL")
            return False, "LRL is greater than the URL"

    def addURL(self,inputURL):
        URL = int(inputURL)
        if (URL > self.LRL):
            if (URL >= 50 and URL <= 175):
                if (URL % 5 == 0):
                    self.URL = URL
                    print("Added URL")
                    return True, "Good"
                else:
                    print("URL must be increment of 5")
                    return False, "URL must be increment of 5"
            else:
                print("URL not within range of 50-175")
                return False, "URL not within range of 50-175"
        else:
            print("URL is smaller than the LRL")
            return False, "URL is smaller than the LRL"

    def addVA(self,inputVA):
        try:
            VA = float(inputVA)
            if (VA >= 0.5 and VA <= 3.2):
                if (VA % 0.1 == 0):
                    self.VA = VA
                    print("Added VA")
                    return True, "Good"
                else:
                    print("VA must be increment of 0.1")
                    return False, "VA must be increment of 0.1"

            elif (float(VA) >= 3.5 and float(VA) <= 7):
                if (float(VA) % 0.5 == 0):
                    self.VA = VA
                    print("Added AA")
                    return True, "Good"
                else:
                    print("AA must be increment of 0.5")
                    return False, "AA must be increment of 0.5"

            else:
                print ("AA must be off, within range of 0.5-3.2 or 3.5-7.0")

        except:
            VA = inputVA
            if (str(VA).lower == "off"):
                self.VA = "off"
                print("Added VA")

            else:
                print("VA must be off, within range of 0.5-3.2 or 3.5-7.0")
                return False, "AA must be off, within range of 0.5-3.2 or 3.5-7.0"

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