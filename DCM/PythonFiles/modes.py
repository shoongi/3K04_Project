import database
import parameters
import serial_comm
import time
import serial

NUM_BYTES = 34

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

        self.loadAOO()

        ser = serial_comm.initializeSerial()
        checkCondition = False

        while(not checkCondition):
            transmit = serial_comm.packTransmitData(int(self.LRL), int(self.URL), 0, 0, 2, 330, float(self.AA), float(self.APW), 2, 250, 1, 2)
            time.sleep(0.01)
            ser.write(transmit[0])

            time.sleep(0.05)
            data = ser.read(NUM_BYTES)
            
            receive = serial_comm.unpackReceiveData(data)
            time.sleep(0.01)

            checkCondition  = serial_comm.compareChecksum(transmit[1], receive)
        serial_comm.deinitializeSerial(ser)

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

        self.loadVOO()

        ser = serial_comm.initializeSerial()
        checkCondition = False

        while(not checkCondition):
            transmit = serial_comm.packTransmitData(int(self.LRL), int(self.URL), float(self.VA), float(self.VPW), 2, 330, 5, 2, 2, 250, 1, 4)
            time.sleep(0.01)
            ser.write(transmit[0])

            time.sleep(0.05)
            data = ser.read(NUM_BYTES)

            receive = serial_comm.unpackReceiveData(data)
            time.sleep(0.01)

            checkCondition  = serial_comm.compareChecksum(transmit[1], receive)
        serial_comm.deinitializeSerial(ser)
        

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
        self.sensitivity = 0.75
        self.PVARP = 250
        self.hysteresis = "off"
        self.smoothing = "off"
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
                self.sensitivity = userDict[self.name]["AAI"]["Sensitivity"]
                self.PVARP = userDict[self.name]["AAI"]["PVARP"]
                self.hysteresis = userDict[self.name]["AAI"]["Hysteresis"]
                self.smoothing = userDict[self.name]["AAI"]["Smoothing"]
            else:
                userDict[self.name]["AAI"] = {}
                userDict[self.name]["AAI"]["LRL"] = self.LRL
                userDict[self.name]["AAI"]["URL"] = self.URL
                userDict[self.name]["AAI"]["AA"] = self.AA
                userDict[self.name]["AAI"]["APW"] = self.APW
                userDict[self.name]["AAI"]["ARP"] = self.ARP
                userDict[self.name]["AAI"]["Sensitivity"] = self.sensitivity
                userDict[self.name]["AAI"]["PVARP"] = self.PVARP
                userDict[self.name]["AAI"]["Hysteresis"] = self.hysteresis 
                userDict[self.name]["AAI"]["Smoothing"] = self.smoothing 
        else:
            userDict[self.name] = {}
            userDict[self.name]["AAI"] = {}
            userDict[self.name]["AAI"]["LRL"] = self.LRL
            userDict[self.name]["AAI"]["URL"] = self.URL
            userDict[self.name]["AAI"]["AA"] = self.AA
            userDict[self.name]["AAI"]["APW"] = self.APW
            userDict[self.name]["AAI"]["ARP"] = self.ARP
            userDict[self.name]["AAI"]["Sensitivity"] = self.sensitivity
            userDict[self.name]["AAI"]["PVARP"] = self.PVARP
            userDict[self.name]["AAI"]["Hysteresis"] = self.hysteresis 
            userDict[self.name]["AAI"]["Smoothing"] = self.smoothing 
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
        acceptable, comment = parameters.addAA(self,inputAA)

        if (acceptable == True):
            self.URL = inputAA
            self.addAAI()
        else:
            print(comment)

    def addAPW(self,inputAPW):
        acceptable, comment = parameters.addAPW(self,inputAPW)

        if (acceptable == True):
            self.URL = inputAPW
            self.addAAI()
        else:
            print(comment)

    def addARP(self,inputARP):
        acceptable, comment = parameters.addARP(self,inputARP)

        if (acceptable == True):
            self.URL = inputARP
            self.addAAI()
        else:
            print(comment)

    def addSensitivity(self,inputSens):
        acceptable, comment = parameters.addSensitivity(self,inputSens)

        if (acceptable == True):
            self.sensitivity = inputSens
            self.addAAI()
        else:
            print(comment)

    def addPVARP(self, inputPVARP):
        acceptable, comment = parameters.addPVARP(self,inputPVARP)

        if (acceptable == True):
            self.PVARP = inputPVARP
            self.addAAI()
        else:
            print(comment)

    def addHysteresis(self, inputHysteresis):
        acceptable, comment = parameters.addHysterisis(self,inputHysteresis)

        if (acceptable == True):
            self.hysteresis = inputHysteresis
            self.addAAI()
        else:
            print(comment)

    def addSmoothing(self, inputSmoothing):
        acceptable, comment = parameters.addSmoothing(self,inputSmoothing)

        if (acceptable == True):
            self.smoothing = inputSmoothing
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
        self.AAIData[self.name]["AAI"]["Sensitivity"] = self.sensitivity
        self.AAIData[self.name]["AAI"]["PVARP"] = self.PVARP
        self.AAIData[self.name]["AAI"]["Hysteresis"] = self.hysteresis 
        self.AAIData[self.name]["AAI"]["Smoothing"] = self.smoothing 
        print("Saving")
        print(self.AAIData)
        self.userData.saveParam(self.AAIData)


        self.loadAAI()

        ser = serial_comm.initializeSerial()
        checkCondition = False

        while(not checkCondition):
            transmit = serial_comm.packTransmitData(int(self.LRL), int(self.URL), 0, 0, 2, 330, float(self.AA), float(self.APW), 2, int(self.ARP), 1, 3)
            time.sleep(0.01)
            ser.write(transmit[0])

            time.sleep(0.05)
            data = ser.read(NUM_BYTES)
            
            receive = serial_comm.unpackReceiveData(data)
            time.sleep(0.01)

            checkCondition  = serial_comm.compareChecksum(transmit[1], receive)
        serial_comm.deinitializeSerial(ser)


######################################################################################################################################
######################################################################################################################################
#####################################################################################################################################

class AOOR:
    def __init__(self,name):
        self.name = name
        self.userData = database.DataBase()
        self.LRL = 60
        self.URL = 175
        self.AA = 3.5
        self.APW = 0.4
        self.sensorRate = 120
        self.actThres = "Med"
        self.reactTime = 30
        self.respFact = 8
        self.recTime = 5
        self.AOORData = {}

    def loadAOOR(self):
        self.userData.loadParam()
        userDict = self.userData.userParamDict
        if (self.name in userDict):
            if ("AOOR" in userDict[self.name]):
                self.LRL = userDict[self.name]["AOOR"]["LRL"]
                self.URL = userDict[self.name]["AOOR"]["URL"]
                self.AA = userDict[self.name]["AOOR"]["AA"]
                self.APW = userDict[self.name]["AOOR"]["APW"]
                self.sensorRate = userDict[self.name]["AOOR"]["Sensor Rate"]
                self.actThres = userDict[self.name]["AOOR"]["Activity Threshold"]
                self.reactTime = userDict[self.name]["AOOR"]["Reaction Time"]
                self.respFact = userDict[self.name]["AOOR"]["Response Factor"]
                self.recTime = userDict[self.name]["AOOR"]["Recovery Time"]
            else:
                userDict[self.name]["AOOR"] = {}
                userDict[self.name]["AOOR"]["LRL"] = self.LRL
                userDict[self.name]["AOOR"]["URL"] = self.URL
                userDict[self.name]["AOOR"]["AA"] = self.AA
                userDict[self.name]["AOOR"]["APW"] = self.APW
                userDict[self.name]["AOOR"]["Sensor Rate"] = self.sensorRate 
                userDict[self.name]["AOOR"]["Activity Threshold"] = self.actThres
                userDict[self.name]["AOOR"]["Reaction Time"] = self.reactTime
                userDict[self.name]["AOOR"]["Response Factor"] = self.respFact 
                userDict[self.name]["AOOR"]["Recovery Time"] = self.recTime 
        else:
            userDict[self.name] = {}
            userDict[self.name]["AOOR"] = {}
            userDict[self.name]["AOOR"]["LRL"] = self.LRL
            userDict[self.name]["AOOR"]["URL"] = self.URL
            userDict[self.name]["AOOR"]["AA"] = self.AA
            userDict[self.name]["AOOR"]["APW"] = self.APW
            userDict[self.name]["AOOR"]["Sensor Rate"] = self.sensorRate 
            userDict[self.name]["AOOR"]["Activity Threshold"] = self.actThres
            userDict[self.name]["AOOR"]["Reaction Time"] = self.reactTime
            userDict[self.name]["AOOR"]["Response Factor"] = self.respFact 
            userDict[self.name]["AOOR"]["Recovery Time"] = self.recTime 
        self.AOORData = userDict

    def addLRL(self,inputLRL):
        acceptable, comment = parameters.addLRL(self,inputLRL)

        if (acceptable == True):
            self.LRL = inputLRL
            self.addAOOR()
        else: 
            print(comment)

    def addURL(self,inputURL):
        acceptable, comment = parameters.addURL(self,inputURL)

        if (acceptable == True):
            self.URL = inputURL
            self.addAOOR()
        else:
            print(comment)

    def addAA(self,inputAA):
        acceptable, comment = parameters.addAA(self,inputAA)

        if (acceptable == True):
            self.AA = inputAA
            self.addAOOR()
        else:
            print(comment)

    def addAPW(self,inputAPW):
        acceptable, comment = parameters.addAPW(self,inputAPW)

        if (acceptable == True):
            self.APW = inputAPW
            self.addAOOR()
        else:
            print(comment)
    
    def addSensRate(self, inputSens):
        acceptable, comment = parameters.addmaxSenRate(self,inputSens)

        if (acceptable == True):
            self.sensorRate = inputSens
            self.addAOOR()
        else:
            print(comment)

    def addActThres(self, inputActThres):
        acceptable, comment = parameters.addActThres(self,inputActThres)

        if (acceptable == True):
            self.actThres = inputActThres
            self.addAOOR()
        else:
            print(comment)

    def addReactTime(self, inputReactTime):
        acceptable, comment = parameters.addReactTime(self,inputReactTime)

        if (acceptable == True):
            self.reactTime = inputReactTime
            self.addAOOR()
        else:
            print(comment)
    
    def addRespFact(self, inputRespFact):
        acceptable, comment = parameters.addRespFact(self,inputRespFact)

        if (acceptable == True):
            self.respFact = inputRespFact
            self.addAOOR()
        else:
            print(comment)

    def addRecTime(self, inputRecTime):
        acceptable, comment = parameters.addRecTime(self,inputRecTime)

        if (acceptable == True):
            self.recTime = inputRecTime
            self.addAOOR()
        else:
            print(comment)

    def addAOOR(self):
        print("Added AOOR\n")
        self.AOORData[self.name]["AOOR"]["LRL"] = self.LRL
        self.AOORData[self.name]["AOOR"]["URL"] = self.URL
        self.AOORData[self.name]["AOOR"]["AA"] = self.AA
        self.AOORData[self.name]["AOOR"]["APW"] = self.APW
        self.AOORData[self.name]["AOOR"]["Sensor Rate"] = self.sensorRate 
        self.AOORData[self.name]["AOOR"]["Activity Threshold"] = self.actThres
        self.AOORData[self.name]["AOOR"]["Reaction Time"] = self.reactTime
        self.AOORData[self.name]["AOOR"]["Response Factor"] = self.respFact 
        self.AOORData[self.name]["AOOR"]["Recovery Time"] = self.recTime 
        print("Saving")
        print(self.AOORData)
        self.userData.saveParam(self.AOORData)


        self.loadAOOR()

        # ser = serial_comm.initializeSerial()
        # checkCondition = False

        # while(not checkCondition):
        #     transmit = serial_comm.packTransmitData(int(self.LRL), int(self.URL), 0, 0, 2, 330, float(self.AA), float(self.APW), 2, 120, 1, 3)
        #     time.sleep(0.01)
        #     ser.write(transmit[0])

        #     time.sleep(0.05)
        #     data = ser.read(34)
            
        #     receive = serial_comm.unpackReceiveData(data)
        #     time.sleep(0.01)

        #     checkCondition  = serial_comm.compareChecksum(transmit[1], receive)
        # serial_comm.deinitializeSerial(ser)


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
        self.sensitivity = 0.75
        self.PVARP = 250
        self.hysteresis = "off"
        self.smoothing = "off"
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
                self.sensitivity = userDict[self.name]["VVI"]["Sensitivity"]
                self.hysteresis = userDict[self.name]["VVI"]["Hysteresis"]
                self.smoothing = userDict[self.name]["VVI"]["Smoothing"]
            else:
                userDict[self.name]["VVI"] = {}
                userDict[self.name]["VVI"]["LRL"] = self.LRL
                userDict[self.name]["VVI"]["URL"] = self.URL
                userDict[self.name]["VVI"]["VA"] = self.VA
                userDict[self.name]["VVI"]["VPW"] = self.VPW
                userDict[self.name]["VVI"]["VRP"] = self.VRP
                userDict[self.name]["VVI"]["Sensitivity"] = self.sensitivity
                userDict[self.name]["VVI"]["Hysteresis"] = self.hysteresis 
                userDict[self.name]["VVI"]["Smoothing"] = self.smoothing 
        else:
            userDict[self.name] = {}
            userDict[self.name]["VVI"] = {}
            userDict[self.name]["VVI"]["LRL"] = self.LRL
            userDict[self.name]["VVI"]["URL"] = self.URL
            userDict[self.name]["VVI"]["VA"] = self.VA
            userDict[self.name]["VVI"]["VPW"] = self.VPW
            userDict[self.name]["VVI"]["VRP"] = self.VRP
            userDict[self.name]["VVI"]["Sensitivity"] = self.sensitivity
            userDict[self.name]["VVI"]["Hysteresis"] = self.hysteresis 
            userDict[self.name]["VVI"]["Smoothing"] = self.smoothing 
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
        acceptable, comment = parameters.addVPW(self,inputVPW)

        if (acceptable == True):
            self.VPW = inputVPW
            self.addVVI()
        else:
            print(comment)

    def addVRP(self,inputVRP):
        acceptable, comment = parameters.addVRP(self,inputVRP)

        if (acceptable == True):
            self.VRP = inputVRP
            self.addVVI()
        else:
            print(comment)

    def addSensitivity(self,inputSens):
        acceptable, comment = parameters.addSensitivity(self,inputSens)

        if (acceptable == True):
            self.sensitivity = inputSens
            self.addVVI()
        else:
            print(comment)

    def addHysteresis(self, inputHysteresis):
        acceptable, comment = parameters.addHysterisis(self,inputHysteresis)

        if (acceptable == True):
            self.hysteresis = inputHysteresis
            self.addVVI()
        else:
            print(comment)

    def addSmoothing(self, inputSmoothing):
        acceptable, comment = parameters.addSmoothing(self,inputSmoothing)

        if (acceptable == True):
            self.smoothing = inputSmoothing
            self.addVVI()
        else:
            print(comment)

    def addVVI(self):
        print("Added VVI\n")
        print(self.VRP)
        self.VVIData[self.name]["VVI"]["LRL"] = self.LRL
        self.VVIData[self.name]["VVI"]["URL"] = self.URL
        self.VVIData[self.name]["VVI"]["VA"] = self.VA
        self.VVIData[self.name]["VVI"]["VPW"] = self.VPW
        self.VVIData[self.name]["VVI"]["VRP"] = self.VRP
        self.VVIData[self.name]["VVI"]["Sensitivity"] = self.sensitivity
        self.VVIData[self.name]["VVI"]["Hysteresis"] = self.hysteresis 
        self.VVIData[self.name]["VVI"]["Smoothing"] = self.smoothing 
        print("Saving")
        print(self.VVIData)
        self.userData.saveParam(self.VVIData)

        self.loadVVI()

        ser = serial_comm.initializeSerial()
        checkCondition = False

        while(not checkCondition):
            transmit = serial_comm.packTransmitData(int(self.LRL), int(self.URL), float(self.VA), float(self.VPW), 2, int(self.VRP), 5, 2, 2, 250, 1, 5)
            time.sleep(0.01)
            ser.write(transmit[0])

            time.sleep(0.05)
            data = ser.read(NUM_BYTES)
            
            receive = serial_comm.unpackReceiveData(data)
            time.sleep(0.01)

            checkCondition  = serial_comm.compareChecksum(transmit[1], receive)
        serial_comm.deinitializeSerial(ser)
 

#####################################################################################################################################
#####################################################################################################################################
#####################################################################################################################################

class VOOR:
    def __init__(self,name):
        self.name = name
        self.userData = database.DataBase()
        self.LRL = 60
        self.URL = 175
        self.VA = 3.5
        self.VPW = 0.4
        self.sensorRate = 120
        self.actThres = "Med"
        self.reactTime = 30
        self.respFact = 8
        self.recTime = 5
        self.VOORData = {}

    def loadVOOR(self):
        self.userData.loadParam()
        userDict = self.userData.userParamDict
        if (self.name in userDict):
            if ("VOOR" in userDict[self.name]):
                self.LRL = userDict[self.name]["VOOR"]["LRL"]
                self.URL = userDict[self.name]["VOOR"]["URL"]
                self.VA = userDict[self.name]["VOOR"]["VA"]
                self.VPW = userDict[self.name]["VOOR"]["VPW"]
                self.sensorRate = userDict[self.name]["VOOR"]["Sensor Rate"]
                self.actThres = userDict[self.name]["VOOR"]["Activity Threshold"]
                self.reactTime = userDict[self.name]["VOOR"]["Reaction Time"]
                self.respFact = userDict[self.name]["VOOR"]["Response Factor"]
                self.recTime = userDict[self.name]["VOOR"]["Recovery Time"]
            else:
                userDict[self.name]["VOOR"] = {}
                userDict[self.name]["VOOR"]["LRL"] = self.LRL
                userDict[self.name]["VOOR"]["URL"] = self.URL
                userDict[self.name]["VOOR"]["VA"] = self.VA
                userDict[self.name]["VOOR"]["VPW"] = self.VPW
                userDict[self.name]["VOOR"]["Sensor Rate"] = self.sensorRate
                userDict[self.name]["VOOR"]["Activity Threshold"] = self.actThres
                userDict[self.name]["VOOR"]["Reaction Time"] = self.reactTime
                userDict[self.name]["VOOR"]["Response Factor"] = self.respFact 
                userDict[self.name]["VOOR"]["Recovery Time"] = self.recTime 
        else:
            userDict[self.name] = {}
            userDict[self.name]["VOOR"] = {}
            userDict[self.name]["VOOR"]["LRL"] = self.LRL
            userDict[self.name]["VOOR"]["URL"] = self.URL
            userDict[self.name]["VOOR"]["VA"] = self.VA
            userDict[self.name]["VOOR"]["VPW"] = self.VPW
            userDict[self.name]["VOOR"]["Sensor Rate"] = self.sensorRate
            userDict[self.name]["VOOR"]["Activity Threshold"] = self.actThres
            userDict[self.name]["VOOR"]["Reaction Time"] = self.reactTime
            userDict[self.name]["VOOR"]["Response Factor"] = self.respFact 
            userDict[self.name]["VOOR"]["Recovery Time"] = self.recTime 
        self.VOORData = userDict

    def addLRL(self,inputLRL):
        acceptable, comment = parameters.addLRL(self,inputLRL)

        if (acceptable == True):
            self.LRL = inputLRL
            self.addVOOR()
        else: 
            print(comment)

    def addURL(self,inputURL):
        acceptable, comment = parameters.addURL(self,inputURL)

        if (acceptable == True):
            self.URL = inputURL
            self.addVOOR()
        else:
            print(comment)

    def addVA(self,inputVA):
        acceptable, comment = parameters.addVA(self,inputVA)

        if (acceptable == True):
            self.VA = inputVA
            self.addVOOR()
        else:
            print(comment)

    def addVPW(self,inputVPW):
        acceptable, comment = parameters.addVPW(self,inputVPW)

        if (acceptable == True):
            self.VPW = inputVPW
            self.addVOOR()
        else:
            print(comment)
    
    def addSensRate(self, inputSens):
        acceptable, comment = parameters.addmaxSenRate(self,inputSens)

        if (acceptable == True):
            self.sensorRate = inputSens
            self.addVOOR()
        else:
            print(comment)

    def addActThres(self, inputActThres):
        acceptable, comment = parameters.addActThres(self,inputActThres)

        if (acceptable == True):
            self.actThres = inputActThres
            self.addVOOR()
        else:
            print(comment)

    def addReactTime(self, inputReactTime):
        acceptable, comment = parameters.addReactTime(self,inputReactTime)

        if (acceptable == True):
            self.reactTime = inputReactTime
            self.addVOOR()
        else:
            print(comment)
    
    def addRespFact(self, inputRespFact):
        acceptable, comment = parameters.addRespFact(self,inputRespFact)

        if (acceptable == True):
            self.respFact = inputRespFact
            self.addVOOR()
        else:
            print(comment)

    def addRecTime(self, inputRecTime):
        acceptable, comment = parameters.addRecTime(self,inputRecTime)

        if (acceptable == True):
            self.recTime = inputRecTime
            self.addVOOR()
        else:
            print(comment)

    def addVOOR(self):
        print("Added VOOR\n")
        self.VOORData[self.name]["VOOR"]["LRL"] = self.LRL
        self.VOORData[self.name]["VOOR"]["URL"] = self.URL
        self.VOORData[self.name]["VOOR"]["VA"] = self.VA
        self.VOORData[self.name]["VOOR"]["VPW"] = self.VPW
        self.VOORData[self.name]["VOOR"]["Sensor Rate"] = self.sensorRate
        self.VOORData[self.name]["VOOR"]["Activity Threshold"] = self.actThres
        self.VOORData[self.name]["VOOR"]["Reaction Time"] = self.reactTime
        self.VOORData[self.name]["VOOR"]["Response Factor"] = self.respFact 
        self.VOORData[self.name]["VOOR"]["Recovery Time"] = self.recTime 
        print("Saving")
        print(self.VOORData)
        self.userData.saveParam(self.VOORData)

        """
        self.loadVOOR()

        ser = serial_comm.initializeSerial()
        checkCondition = False

        while(not checkCondition):
            transmit = serial_comm.packTransmitData(int(self.LRL), int(self.URL), float(self.VA), float(self.VPW), 2, 250, 5, 2, 2, 250, 1, 5)
            time.sleep(0.01)
            ser.write(transmit[0])

            time.sleep(0.05)
            data = ser.read(34)
            
            receive = serial_comm.unpackReceiveData(data)
            time.sleep(0.01)

            checkCondition  = serial_comm.compareChecksum(transmit[1], receive)
        serial_comm.deinitializeSerial(ser)
        """
#######################################################################################################################################
#######################################################################################################################################
#######################################################################################################################################

class AAIR:
    def __init__(self,name):
        self.name = name
        self.userData = database.DataBase()
        self.LRL = 60
        self.URL = 175
        self.AA = 3.5
        self.APW = 0.4
        self.atrialSens = 2.5
        self.ARP = 250
        self.PVARP = 250
        self.hysteresis = "off"
        self.smoothing = "off"
        self.sensorRate = 120
        self.actThres = "Med"
        self.reactTime = 30
        self.respFact = 8
        self.recTime = 5
        self.AAIRData = {}

    def loadAAIR(self):
        self.userData.loadParam()
        userDict = self.userData.userParamDict
        if (self.name in userDict):
            if ("AAIR" in userDict[self.name]):
                self.LRL = userDict[self.name]["AAIR"]["LRL"]
                self.URL = userDict[self.name]["AAIR"]["URL"]
                self.AA = userDict[self.name]["AAIR"]["AA"]
                self.APW = userDict[self.name]["AAIR"]["APW"]
                self.ARP = userDict[self.name]["AAIR"]["ARP"]
                self.atrialSens = userDict[self.name]["AAIR"]["Sensitivity"]
                self.PVARP = userDict[self.name]["AAIR"]["PVARP"]
                self.hysteresis = userDict[self.name]["AAIR"]["Hysteresis"]
                self.smoothing = userDict[self.name]["AAIR"]["Smoothing"]
                self.sensorRate = userDict[self.name]["AAIR"]["Sensor Rate"]
                self.actThres = userDict[self.name]["AAIR"]["Activity Threshold"]
                self.reactTime = userDict[self.name]["AAIR"]["Reaction Time"]
                self.respFact = userDict[self.name]["AAIR"]["Response Factor"]
                self.recTime = userDict[self.name]["AAIR"]["Recovery Time"]
            else:
                userDict[self.name]["AAIR"] = {}
                userDict[self.name]["AAIR"]["LRL"] = self.LRL
                userDict[self.name]["AAIR"]["URL"] = self.URL
                userDict[self.name]["AAIR"]["AA"] = self.AA
                userDict[self.name]["AAIR"]["APW"] = self.APW
                userDict[self.name]["AAIR"]["ARP"] = self.ARP
                userDict[self.name]["AAIR"]["Sensitivity"] = self.atrialSens 
                userDict[self.name]["AAIR"]["PVARP"] = self.PVARP 
                userDict[self.name]["AAIR"]["Hysteresis"] = self.hysteresis 
                userDict[self.name]["AAIR"]["Smoothing"] = self.smoothing 
                userDict[self.name]["AAIR"]["Sensor Rate"] = self.sensorRate
                userDict[self.name]["AAIR"]["Activity Threshold"] = self.actThres
                userDict[self.name]["AAIR"]["Reaction Time"] = self.reactTime
                userDict[self.name]["AAIR"]["Response Factor"] = self.respFact 
                userDict[self.name]["AAIR"]["Recovery Time"] = self.recTime 
        else:
            userDict[self.name] = {}
            userDict[self.name]["AAIR"] = {}
            userDict[self.name]["AAIR"]["LRL"] = self.LRL
            userDict[self.name]["AAIR"]["URL"] = self.URL
            userDict[self.name]["AAIR"]["AA"] = self.AA
            userDict[self.name]["AAIR"]["APW"] = self.APW
            userDict[self.name]["AAIR"]["ARP"] = self.ARP
            userDict[self.name]["AAIR"]["Sensitivity"] = self.atrialSens 
            userDict[self.name]["AAIR"]["PVARP"] = self.PVARP 
            userDict[self.name]["AAIR"]["Hysteresis"] = self.hysteresis 
            userDict[self.name]["AAIR"]["Smoothing"] = self.smoothing 
            userDict[self.name]["AAIR"]["Sensor Rate"] = self.sensorRate
            userDict[self.name]["AAIR"]["Activity Threshold"] = self.actThres
            userDict[self.name]["AAIR"]["Reaction Time"] = self.reactTime
            userDict[self.name]["AAIR"]["Response Factor"] = self.respFact 
            userDict[self.name]["AAIR"]["Recovery Time"] = self.recTime 
        self.AAIRData = userDict

    def addLRL(self,inputLRL):
        acceptable, comment = parameters.addLRL(self,inputLRL)

        if (acceptable == True):
            self.LRL = inputLRL
            self.addAAIR()
        else: 
            print(comment)

    def addURL(self,inputURL):
        acceptable, comment = parameters.addURL(self,inputURL)

        if (acceptable == True):
            self.URL = inputURL
            self.addAAIR()
        else:
            print(comment)

    def addAA(self,inputAA):
        acceptable, comment = parameters.addAA(self,inputAA)

        if (acceptable == True):
            self.AA = inputAA
            self.addAAIR()
        else:
            print(comment)

    def addAPW(self,inputAPW):
        acceptable, comment = parameters.addAPW(self,inputAPW)

        if (acceptable == True):
            self.APW = inputAPW
            self.addAAIR()
        else:
            print(comment)

    def addARP(self,inputARP):
        acceptable, comment = parameters.addARP(self,inputARP)

        if (acceptable == True):
            self.ARP = inputARP
            self.addAAIR()
        else:
            print(comment)

    def addSensitivity(self,inputSens):
        acceptable, comment = parameters.addSensitivity(self,inputSens)

        if (acceptable == True):
            self.atrial = inputSens
            self.addAAIR()
        else:
            print(comment)

    def addPVARP(self, inputPVARP):
        acceptable, comment = parameters.addPVARP(self,inputPVARP)

        if (acceptable == True):
            self.PVARP = inputPVARP
            self.addAAIR()
        else:
            print(comment)

    def addHysteresis(self, inputHysteresis):
        acceptable, comment = parameters.addHysterisis(self,inputHysteresis)

        if (acceptable == True):
            self.hysteresis = inputHysteresis
            self.addAAIR()
        else:
            print(comment)

    def addSmoothing(self, inputSmoothing):
        acceptable, comment = parameters.addSmoothing(self,inputSmoothing)

        if (acceptable == True):
            self.smoothing = inputSmoothing
            self.addAAIR()
        else:
            print(comment)
    
    def addSensRate(self, inputSens):
        acceptable, comment = parameters.addmaxSenRate(self,inputSens)

        if (acceptable == True):
            self.sensorRate = inputSens
            self.addAAIR()
        else:
            print(comment)

    def addActThres(self, inputActThres):
        acceptable, comment = parameters.addActThres(self,inputActThres)

        if (acceptable == True):
            self.actThres = inputActThres
            self.addAAIR()
        else:
            print(comment)

    def addReactTime(self, inputReactTime):
        acceptable, comment = parameters.addReactTime(self,inputReactTime)

        if (acceptable == True):
            self.reactTime = inputReactTime
            self.addAAIR()
        else:
            print(comment)
    
    def addRespFact(self, inputRespFact):
        acceptable, comment = parameters.addRespFact(self,inputRespFact)

        if (acceptable == True):
            self.respFact = inputRespFact
            self.addAAIR()
        else:
            print(comment)

    def addRecTime(self, inputRecTime):
        acceptable, comment = parameters.addRecTime(self,inputRecTime)

        if (acceptable == True):
            self.recTime = inputRecTime
            self.addAAIR()
        else:
            print(comment)

    def addAAIR(self):
        print("Added AAIR\n")
        self.AAIRData[self.name]["AAIR"]["LRL"] = self.LRL
        self.AAIRData[self.name]["AAIR"]["URL"] = self.URL
        self.AAIRData[self.name]["AAIR"]["AA"] = self.AA
        self.AAIRData[self.name]["AAIR"]["APW"] = self.APW
        self.AAIRData[self.name]["AAIR"]["ARP"] = self.ARP
        self.AAIRData[self.name]["AAIR"]["Sensor Rate"] = self.sensorRate
        self.AAIRData[self.name]["AAIR"]["Sensitivity"] = self.atrialSens 
        self.AAIRData[self.name]["AAIR"]["PVARP"] = self.PVARP 
        self.AAIRData[self.name]["AAIR"]["Hysteresis"] = self.hysteresis 
        self.AAIRData[self.name]["AAIR"]["Smoothing"] = self.smoothing 
        self.AAIRData[self.name]["AAIR"]["Activity Threshold"] = self.actThres
        self.AAIRData[self.name]["AAIR"]["Reaction Time"] = self.reactTime
        self.AAIRData[self.name]["AAIR"]["Response Factor"] = self.respFact 
        self.AAIRData[self.name]["AAIR"]["Recovery Time"] = self.recTime 
        print("Saving")
        print(self.AAIRData)
        self.userData.saveParam(self.AAIRData)

        
        self.loadAAIR()

        # ser = serial_comm.initializeSerial()
        # checkCondition = False

        # while(not checkCondition):
        #     transmit = serial_comm.packTransmitData(int(self.LRL), int(self.URL), 0, 0, 2, 330, float(self.AA), float(self.APW), 2, int(self.ARP), 1, 3)
        #     time.sleep(0.01)
        #     ser.write(transmit[0])

        #     time.sleep(0.05)
        #     data = ser.read(34)
            
        #     receive = serial_comm.unpackReceiveData(data)
        #     time.sleep(0.01)

        #     checkCondition  = serial_comm.compareChecksum(transmit[1], receive)
        # serial_comm.deinitializeSerial(ser)
       

###############################################################################################################################        
###############################################################################################################################
###############################################################################################################################

class VVIR:
    def __init__(self,name):
        self.name = name
        self.userData = database.DataBase()
        self.LRL = 60
        self.URL = 175
        self.VA = 3.5
        self.VPW = 0.4
        self.ventricularSens = 2.5
        self.VRP = 250
        self.hysteresis = "off"
        self.smoothing = "off"
        self.sensorRate = 120
        self.actThres = "Med"
        self.reactTime = 30
        self.respFact = 8
        self.recTime = 5
        self.VVIRData = {}

    def loadVVIR(self):
        self.userData.loadParam()
        userDict = self.userData.userParamDict
        if (self.name in userDict):
            if ("VVIR" in userDict[self.name]):
                self.LRL = userDict[self.name]["VVIR"]["LRL"]
                self.URL = userDict[self.name]["VVIR"]["URL"]
                self.VA = userDict[self.name]["VVIR"]["VA"]
                self.VPW = userDict[self.name]["VVIR"]["VPW"]
                self.VRP = userDict[self.name]["VVIR"]["VRP"]
                self.ventricularSens = userDict[self.name]["VVIR"]["Sensitivity"]
                self.hysteresis = userDict[self.name]["VVIR"]["Hysteresis"]
                self.smoothing = userDict[self.name]["VVIR"]["Smoothing"]
                self.sensorRate = userDict[self.name]["VVIR"]["Sensor Rate"]
                self.actThres = userDict[self.name]["VVIR"]["Activity Threshold"]
                self.reactTime = userDict[self.name]["VVIR"]["Reaction Time"]
                self.respFact = userDict[self.name]["VVIR"]["Response Factor"]
                self.recTime = userDict[self.name]["VVIR"]["Recovery Time"]
            else:
                userDict[self.name]["VVIR"] = {}
                userDict[self.name]["VVIR"]["LRL"] = self.LRL
                userDict[self.name]["VVIR"]["URL"] = self.URL
                userDict[self.name]["VVIR"]["AA"] = self.VA
                userDict[self.name]["VVIR"]["APW"] = self.VPW
                userDict[self.name]["VVIR"]["ARP"] = self.VRP
                userDict[self.name]["VVIR"]["Sensitivity"] = self.ventricularSens 
                userDict[self.name]["VVIR"]["Hysteresis"] = self.hysteresis 
                userDict[self.name]["VVIR"]["Smoothing"] = self.smoothing 
                userDict[self.name]["VVIR"]["Sensor Rate"] = self.sensorRate
                userDict[self.name]["VVIR"]["Activity Threshold"] = self.actThres
                userDict[self.name]["VVIR"]["Reaction Time"] = self.reactTime
                userDict[self.name]["VVIR"]["Response Factor"] = self.respFact 
                userDict[self.name]["VVIR"]["Recovery Time"] = self.recTime 
        else:
            userDict[self.name] = {}
            userDict[self.name]["VVIR"] = {}
            userDict[self.name]["VVIR"]["LRL"] = self.LRL
            userDict[self.name]["VVIR"]["URL"] = self.URL
            userDict[self.name]["VVIR"]["AA"] = self.VA
            userDict[self.name]["VVIR"]["APW"] = self.VPW
            userDict[self.name]["VVIR"]["ARP"] = self.VRP
            userDict[self.name]["VVIR"]["Sensitivity"] = self.ventricularSens 
            userDict[self.name]["VVIR"]["Hysteresis"] = self.hysteresis 
            userDict[self.name]["VVIR"]["Smoothing"] = self.smoothing 
            userDict[self.name]["VVIR"]["Sensor Rate"] = self.sensorRate
            userDict[self.name]["VVIR"]["Activity Threshold"] = self.actThres
            userDict[self.name]["VVIR"]["Reaction Time"] = self.reactTime
            userDict[self.name]["VVIR"]["Response Factor"] = self.respFact 
            userDict[self.name]["VVIR"]["Recovery Time"] = self.recTime 
        self.VVIRData = userDict

    def addLRL(self,inputLRL):
        acceptable, comment = parameters.addLRL(self,inputLRL)

        if (acceptable == True):
            self.LRL = inputLRL
            self.addVVIR()
        else: 
            print(comment)

    def addURL(self,inputURL):
        acceptable, comment = parameters.addURL(self,inputURL)

        if (acceptable == True):
            self.URL = inputURL
            self.addVVIR()
        else:
            print(comment)

    def addVA(self,inputVA):
        acceptable, comment = parameters.addVA(self,inputVA)

        if (acceptable == True):
            self.URL = inputVA
            self.addVVIR()
        else:
            print(comment)

    def addVPW(self,inputVPW):
        acceptable, comment = parameters.addVPW(self,inputVPW)

        if (acceptable == True):
            self.VPW = inputVPW
            self.addVVIR()
        else:
            print(comment)

    def addVRP(self,inputVRP):
        acceptable, comment = parameters.addVRP(self,inputVRP)

        if (acceptable == True):
            self.URL = inputVRP
            self.addVVIR()
        else:
            print(comment)

    def addSensitivity(self,inputSens):
        acceptable, comment = parameters.addSensitivity(self,inputSens)

        if (acceptable == True):
            self.ventricularSens = inputSens
            self.addVVIR()
        else:
            print(comment)

    def addHysteresis(self, inputHysteresis):
        acceptable, comment = parameters.addHysterisis(self,inputHysteresis)

        if (acceptable == True):
            self.hysteresis = inputHysteresis
            self.addVVIR()
        else:
            print(comment)

    def addSmoothing(self, inputSmoothing):
        acceptable, comment = parameters.addSmoothing(self,inputSmoothing)

        if (acceptable == True):
            self.smoothing = inputSmoothing
            self.addVVIR()
        else:
            print(comment)
    
    def addSensRate(self, inputSens):
        acceptable, comment = parameters.addmaxSenRate(self,inputSens)

        if (acceptable == True):
            self.sensorRate = inputSens
            self.addVVIR()
        else:
            print(comment)

    def addActThres(self, inputActThres):
        acceptable, comment = parameters.addActThres(self,inputActThres)

        if (acceptable == True):
            self.actThres = inputActThres
            self.addVVIR()
        else:
            print(comment)

    def addReactTime(self, inputReactTime):
        acceptable, comment = parameters.addReactTime(self,inputReactTime)

        if (acceptable == True):
            self.reactTime = inputReactTime
            self.addVVIR()
        else:
            print(comment)
    
    def addRespFact(self, inputRespFact):
        acceptable, comment = parameters.addRespFact(self,inputRespFact)

        if (acceptable == True):
            self.respFact = inputRespFact
            self.addVVIR()
        else:
            print(comment)

    def addRecTime(self, inputRecTime):
        acceptable, comment = parameters.addRecTime(self,inputRecTime)

        if (acceptable == True):
            self.recTime = inputRecTime
            self.addVVIR()
        else:
            print(comment)

    def addVVIR(self):
        print("Added VVIR\n")
        self.VVIRData[self.name]["VVIR"]["LRL"] = self.LRL
        self.VVIRData[self.name]["VVIR"]["URL"] = self.URL
        self.VVIRData[self.name]["VVIR"]["VA"] = self.VA
        self.VVIRData[self.name]["VVIR"]["VPW"] = self.VPW
        self.VVIRData[self.name]["VVIR"]["ARP"] = self.VRP
        self.VVIRData[self.name]["VVIR"]["Sensor Rate"] = self.sensorRate
        self.VVIRData[self.name]["VVIR"]["Sensitivity"] = self.ventricularSens  
        self.VVIRData[self.name]["VVIR"]["Hysteresis"] = self.hysteresis 
        self.VVIRData[self.name]["VVIR"]["Smoothing"] = self.smoothing 
        self.VVIRData[self.name]["VVIR"]["Activity Threshold"] = self.actThres
        self.VVIRData[self.name]["VVIR"]["Reaction Time"] = self.reactTime
        self.VVIRData[self.name]["VVIR"]["Response Factor"] = self.respFact 
        self.VVIRData[self.name]["VVIR"]["Recovery Time"] = self.recTime 
        print("Saving")
        print(self.VVIRData)
        self.userData.saveParam(self.VVIRData)

        self.loadVVIR()

        # ser = serial_comm.initializeSerial()
        # checkCondition = False

        # while(not checkCondition):
        #     transmit = serial_comm.packTransmitData(int(self.LRL), int(self.URL), float(self.VA), float(self.VPW), 2, int(self.VRP), 5, 2, 2, 250, 1, 5)
        #     time.sleep(0.01)
        #     ser.write(transmit[0])

        #     time.sleep(0.05)
        #     data = ser.read(34)
            
        #     receive = serial_comm.unpackReceiveData(data)
        #     time.sleep(0.01)

        #     checkCondition  = serial_comm.compareChecksum(transmit[1], receive)
        # serial_comm.deinitializeSerial(ser)
