def addLRL(self,inputLRL):
    LRL = float(inputLRL)

    if (LRL < float(self.URL)):
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
    try:
        URL = float(inputURL)
    except:
        return False, "URL must be a number"
    if (URL > float(self.LRL)):
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

def addmaxSenRate(self, inputSen):
    try:
        senRate = float(inputSen)
    except:
        return False, "Sensor Rate must be a number"
    if (senRate >= 50 and senRate <= 175):
        if (senRate % 5 == 0):
            self.senRate = senRate
            print ("Added Max Sensor Rate")
            return True, "Good"
        else:
            return False, "Max Sensor Rate must be increment of 5"
    else:
        return False, "Max Sensort Rate must be between 50-175"

def addActThres(self, inputAct):
    #V-Low, Low, Med-Low, Med, Med-High, High, V-High
    accepted = ["V-Low", "Low", "Med-Low", "Med", "Med-High", "High", "V-High"]
    if (inputAct in accepted):
        self.actThres = inputAct
        return True, "Good"
    else:
        return False, "Must be one of V-Low", "Low", "Med-Low", "Med", "Med-High", "High", "V-High"

def addReactTime(self, userInputTime):
    try:
        inputTime = float(userInputTime)
    except:
        return False, "Reaction Time must be a number"
    if (inputTime >= 10 and inputTime <= 50):
        if (inputTime % 10 == 0):
            self.reactTime = inputTime
            return True, "Good"
        else:
            return "False", "Must be increment of 10"
    else:
        return False, "Must be within bounds of 10s-50s"

def addRespFact(self, userInputFactor):
    try:
        inputFactor = float(userInputFactor)
    except:
        return False, "Response Factor must be a number"
    if (inputFactor >= 1 and inputFactor <= 16):
        if (inputFactor % 1 == 0):
            self.respFact = inputFactor
            return True, "Good"
        else:
            return False, "Response Factor must be increment of 1"
    else:
        return False, "Response Factor must be between 1 and 16"

def addRecTime(self, userInputTime):
    try:
        inputTime = float(userInputTime)
    except:
        return False, "Recovery Time must be a number"
    if (inputTime >= 2 and inputTime <= 16):
        if (inputTime % 1 == 0):
            self.recTime = inputTime
            return True, "Good"
        else:
            return False, "Recovery Time must be increment of 1"
    else:
        return False, "Recovery Time must be between 2 and 16"

def addSensitivity(self, inputSens):
    try:
        sens = float(inputSens)
    except:
        return False, "Sensitivity must be a number"
    if (sens == 0.25 or sens == 0.5 or sens == 0.75):
        return True, "Good"
    elif (sens >= 1 and sens <= 10):
        if (sens % 0.5 == 0):
            return True, "Good"
        else:
            return False, "Senitivity must be increment of 0.5"
    else:
        return False, "sensitivity must be 0.25, 0.5, 0.75 or between 1 and 10"

def addPVARP(self, inputPVARP):
    try:
        PVARP = float(inputPVARP)
    except:
        return False, "PVARP must be a number"
    if (PVARP >= 150 and PVARP <= 500):
        if (PVARP % 10 == 0):
            return True, "Good"
        else:
            return False, "PVARP must be increment of 10"
    else:
        return False, "PVARP must be between 150 and 500"

def addHysterisis(self, input):
    try:
        hysterisis = float(input)

        if (hysterisis >= 30 and hysterisis <= 50):
            if (hysterisis % 5 == 0):
                print("Added hysterisis")
                return True,"Good"
            else:
                print("hysterisis must be an increment of 5")
                return False,"hysterisis must be an increment of 5"
        elif (hysterisis >= 50 and hysterisis <= 90):
            if (hysterisis % 1 == 0):
                print("Added hysterisis")
                return True,"Good"
            else:
                print("hysterisis must be an increment of 1")
                return False,"hysterisis must be an increment of 1"
        elif (hysterisis >= 90 and hysterisis <= 175):
            if (hysterisis % 5 == 0):
                print("Added hysterisis")
                return True,"Good"
            else:
                print("hysterisis must be an increment of 5")
                return False,"hysterisis must be an increment of 5"
        else:
            print("hysterisis not within range of 30-175")
            return False, "hysterisis not within range of 30-175"
    except:
        if (input == "off"):
            return True, "Good"
        else:
            return False, "Hysterisis must be off or within range of 30-175"

def addSmoothing(self, input):
    acceptable = ["off", "3", "6", "9", "12", "15", "18", "21", "25"]

    if (input in acceptable):
        return True, "Good"
    else:
        return False, "Smoothing must be one of off, 3, 6, 9, 12, 15, 18, 21, 25"

##################################################################################################################################
############################ ATRIUM STUFF ########################################################################################
##################################################################################################################################

def addAA(self,inputAA):
    try:
        AA = float(inputAA)
        if (AA >= 0.5 and AA <= 3.2):
            if ((AA / 0.1) == int (AA / 0.1)):
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
            return False, "AA must be off, within range of 0.5-3.2 or 3.5-7.0"

    except:
        AA = inputAA
        if (str(AA).lower == "off"):
            self.AA = "off"
            print("Added AA")
            return True, "Good"

        else:
            print("AA must be off, within range of 0.5-3.2 or 3.5-7.0")
            return False, "AA must be off, within range of 0.5-3.2 or 3.5-7.0"

def addAPW(self,inputAPW):
    APW = float(inputAPW)
    if (APW == 0.05):
        self.APW = APW
        print("Added APW")
        return True, "Good"
    elif (APW >= 1 and APW <= 30):
        if ((APW / 1) == int (APW / 1)):
            self.APW = APW
            print("Added APW")
            return True, "Good"
        else:
            print("APW must be increment of 1")
            return False, "APW must be increment of 1"
    else:
        print("APW must be within range of 1-30")
        return False, "APW must be within range of 1-30"
def addARP(self,inputARP):
    ARP = int(inputARP)
    if (ARP >= 150 and ARP <= 500):
        if (ARP > 60000/float(self.LRL)):
            print ("ARP must be smaller than the LRL")
            return False, "ARP must be larger than the LRL"
        if (ARP < float(self.APW)):
            print ("ARP must be greater than the APW")
            return False, "ARP must be less than the APW"
        if (ARP % 10 == 0):
            self.ARP = ARP
            print("Added ARP")
            return True, "Good"
        else:
            return False, "ARP must be increment of 10"
    else:
        return False, "ARP must be within range of 150-500"

##############################################################################################################################
####################################################### VENTRICAL STUFF ######################################################
##############################################################################################################################

def addVA(self,inputVA):
    try:
        VA = float(inputVA)
        if (VA >= 0.5 and VA <= 3.2):
            if ((VA / 0.1) == int (VA / 0.1)):
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
    elif (VPW >= 1 and VPW <= 30):
        if (True):
            self.VPW = VPW
            print("Added VPW")
            return True, "Good"
        else:
            print("VPW must be increment of 1")
            return False, "VPW must be increment of 1"
    else:
        print("VPW must be within range of 1-30")
        return False, "VPW must be within range of 1-30"

def addVRP(self,inputVRP):
    VRP = int(inputVRP)
    if (VRP >= 150 and VRP <= 500):
        if (VRP > 60000/float(self.LRL)):
            print ("VRP must be smaller than the LRL")
            return False, "VRP must be larger than the LRL"
        if (VRP < float(self.VPW)):
            print ("VRP must be larger than the VPW")
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