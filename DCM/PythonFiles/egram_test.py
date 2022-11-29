import matplotlib.pyplot as plt
import matplotlib.animation as animation
import serial
import serial_comm
import struct


def egram_plot():
    ser = serial_comm.initializeSerial()

    # Parameters
    x_len = 5000         # Number of points to display
    y_range = [0, 1]    # Range of possible Y values to display

    # Create figure for plotting
    fig = plt.figure()

    ax = fig.add_subplot(1, 1, 1)



    # Add labels
    plt.title('ATR Voltage over Time')
    plt.xlabel('Samples')
    plt.ylabel('Temperature (deg C)')
    print("first")

    #plt.show()
    a = 0
    b = 1000

    while(True):
        x = list(range(a,b))
        count = 0 
        data = []
        data = ser.read(4000)
        atr = [None] * 1000

        for i in range(0,4000,4):
            atr[count] = struct.unpack('f', data[i:i+4])[0]
            count = count+1

        plt.plot(x, atr, color='r')
        a = a+1000
        b = b+1000
        plt.pause(0.05)

    
egram_plot()
