import serial
import time
import struct


# ----------- USER DEFINED CONSTANTS ------------ #
SERIALPORT  = 'COM10'
BAUDRATE    = 115200
DATASIZE    = 8
TIMEOUT     = 1


def initializeSerial():
#   Initialize serial port with defined parameters
    ser = serial.Serial(port = SERIALPORT, baudrate = BAUDRATE, bytesize = DATASIZE, timeout = TIMEOUT, parity = 'N',stopbits = serial.STOPBITS_ONE)
    return ser

def deinitializeSerial(ser):
    ser.close()
'''
note:   The packing function will pack the required parameters into a 33 bit integer
        according to their required space as outlined below.


Parameter		Data Type	Bytes

LRL			    uint8_t		1
URL			    uint8_t		1
VAMP			single		4
VPW			    single		4
VSensitivty		single		4
VRP			    uint16_t	2
AAMP			single		4
APW			    single		4
ASensitivty		single		4
ARP			    uint16_t	2
PVARP			uint16_t	2
MODE			uint8_t 	1

MODES:
    AOO     (2)
    AAI     (3)
    VOO     (4)
    VVI     (5)

'''
def packTransmitData(lrl, url, vamp, vpw, vsensitivity, vrp, aamp, apw, asensitivity, arp, pvarp, mode):
    
    checksum = lrl + url + vamp + vpw + vsensitivity + vrp + aamp + apw + asensitivity + arp + pvarp + mode

    lrl_s           =       struct.pack('B', lrl)
    url_s           =       struct.pack('B', url)
    vamp_s          =       struct.pack('f', vamp)
    vpw_s           =       struct.pack('f', vpw)
    vsensitivity_s  =       struct.pack('f', vsensitivity)
    vrp_s           =       struct.pack('H', vrp)
    aamp_s          =       struct.pack('f', aamp)
    apw_s           =       struct.pack('f', apw)
    asensitivity_s  =       struct.pack('f', asensitivity)
    arp_s           =       struct.pack('H', arp)
    pvarp_s         =       struct.pack('H', pvarp)
    mode_s          =       struct.pack('B', mode)

    transmitPacket  = b'\x10' + lrl_s + url_s + vamp_s + vpw_s + vsensitivity_s + vrp_s + aamp_s + apw_s + asensitivity_s + arp_s + pvarp_s + mode_s

    return transmitPacket, checksum

def unpackReceiveData(data):

    lrl_s           =       data[0]
    url_s           =       data[1]
    vamp_s          =       struct.unpack('f', data[2:6])[0]
    vpw_s           =       struct.unpack('f', data[6:10])[0]
    vsensitivity_s  =       struct.unpack('f', data[10:14])[0]
    vrp_s           =       struct.unpack('H', data[14:16])[0]
    aamp_s          =       struct.unpack('f', data[16:20])[0]
    apw_s           =       struct.unpack('f', data[20:24])[0]
    asensitivity_s  =       struct.unpack('f', data[24:28])[0]
    arp_s           =       struct.unpack('H', data[28:30])[0]
    pvarp_s         =       struct.unpack('H', data[30:32])[0]
    mode_s          =       data[32]


    receivePacket   = lrl_s + url_s + vamp_s + vpw_s + vsensitivity_s + vrp_s + aamp_s + apw_s + asensitivity_s + arp_s + pvarp_s + mode_s

    return receivePacket

def compareChecksum(transmit, receive):
    
    return int(transmit) == int(receive)
    


def main():

    ser = initializeSerial()

    lrl = 20
    url = 145
    vamp = 5
    vpw = 1
    vsensitivity = 2
    vrp = 330
    aamp = 5
    apw = 2
    asensitivity = 2
    arp = 250
    pvarp = 1
    mode = 4
    
    count = 0 
    data = ser.read(4000)
    atr = [None] * 1000

    for i in range(0,4000,4):
        atr[count] = struct.unpack('f', data[i:i+4])[0]

        count = count+1
    for i in range(0, 1000):
        print(atr[i])


    # while(1):

    deinitializeSerial(ser)
    #     ser.write(transmit)

    #     print("printing..")

    
        
    #     # Read data out of the buffer until a carriage return / new line is found
    #     # if(ser.in_waiting):
    #     #     serialString = ser.read(5)
    #     #     tester1 = struct.unpack('f', serialString[0:4])
    #     #     tester2 = struct.unpack('B', serialString[4:5])
    #     #     # Print the contents of the serial data
    #     #     print(tester1)
    #     #     print(tester2)

    #     time.sleep(5)


if __name__ == "__main__":
   main()
