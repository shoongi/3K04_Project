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
    ser = serial.Serial(port        = SERIALPORT, 
                        baudrate    = BAUDRATE, 
                        bytesize    = DATASIZE, 
                        timeout     = TIMEOUT, 
                        parity      = 'N',
                        stopbits    = serial.STOPBITS_ONE)
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
'''
def packTransmitData(lrl, url, vamp, vpw, vsensitivity, vrp, aamp, apw, asensitivity, arp, pvarp, mode):
    
    lrl_s           =       struct.pack('B', lrl)
    url_s           =       struct.pack('B', url)
    vamp_s          =       struct.pack('f', vamp)
    vpw_s           =       struct.pack('f', vpw)
    vsensitivity_s  =       struct.pack('f', vsensitivity)
    vrp_s           =       struct.pack('h', vrp)
    aamp_s          =       struct.pack('f', aamp)
    apw_s           =       struct.pack('f', apw)
    asensitivity_s  =       struct.pack('f', asensitivity)
    arp_s           =       struct.pack('h', arp)
    pvarp_s         =       struct.pack('h', pvarp)
    mode_s          =       struct.pack('B', mode)

    transmitPacket  = lrl_s + url_s + vamp_s + vpw_s + vsensitivity_s + vrp_s + aamp_s + apw_s + asensitivity_s + arp_s + pvarp_s + mode_s

    return transmitPacket
    

def main():

    ser = initializeSerial()

    # integer = struct.pack('B', 45)
    transmit = packTransmitData(110, 90, 2, 2, 2, 100, 5, 2, 2, 250, 1, 1)
    time.sleep(0.01)
    ser.write(transmit)
    # while(1):

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
