import serial
import time


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
                        stopbits    = serial.STOPBITS_ONE)
    return ser

'''
note:   The packing function will pack the required parameters into a 40 bit integer
        according to their required space as outlined below.

Parameter		        Data Type	Bytes

LRL			            uint8_t		1
URL			            uint8_t		1
Max Sensor Rate		    uint8_t		1
VAMP			        single		4
VPW			            single		4
VSensitivty		        single		4
VRP			            uint16_t	2
AAMP			        single		4
APW			            single		4
ASensitivty		        single		4
ARP			            uint16_t	2
PVARP			        uint16_t	2
Activity Threshold	    uint8_t		1
Reaction Time		    uint8_t		1
Response Factor		    uint8_t		1
Recovery Time		    single		4

'''
def packTransmitData(lrl, url, max_rate, vamp, vpw, vsensitivity, vrp, aamp, apw, 
                     asensitivity, arp, pvarp, act_threshold, react_time, resp_factor, recover_time):
    

    

def main():

    ser = initializeSerial()
    serialString = 0;

    while(1):

        print("printing..")
    
        # Read data out of the buffer until a carriage return / new line is found
        serialString = ser.read(5)

        # Print the contents of the serial data
        print(serialString.hex())

        time.sleep(5)
