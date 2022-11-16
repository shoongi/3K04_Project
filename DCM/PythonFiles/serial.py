import serial


# ----------- USER DEFINED CONSTANTS ------------ #
SERIALPORT = "COM10"
BAUDRATE = 115200
DATASIZE = 8
TIMEOUT = 1


#Initialize serial port with defined parameters
ser = serial.Serial(port = SERIALPORT, 
                    baudrate = BAUDRATE, 
                    bytesize = DATASIZE, 
                    timeout = TIMEOUT, 
                    stopbits = serial.Serial.STOPBITS_ONE)