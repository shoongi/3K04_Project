import serial
import time


# ----------- USER DEFINED CONSTANTS ------------ #
SERIALPORT  = 'COM10'
BAUDRATE    = 115200
DATASIZE    = 8
TIMEOUT     = 1


#Initialize serial port with defined parameters
ser = serial.Serial(port        = SERIALPORT, 
                    baudrate    = BAUDRATE, 
                    bytesize    = DATASIZE, 
                    timeout     = TIMEOUT, 
                    stopbits    = serial.STOPBITS_ONE)

serialString = 0;

while(1):

    print("printing..")
    
    # Read data out of the buffer until a carriage return / new line is found
    serialString = ser.read(5)

    # Print the contents of the serial data
    print(serialString.hex())

    time.sleep(5)
