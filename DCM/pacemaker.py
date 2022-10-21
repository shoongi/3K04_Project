#import desired libraries
import tkinter
from tokenize import String
import customtkinter

from distutils.cmd import Command
from tkinter import *
from tkinter import messagebox
from PIL import ImageTk, Image

#set appearances
customtkinter.set_appearance_mode("System")  # Modes: "System" (standard), "Dark", "Light"
customtkinter.set_default_color_theme("green")  # Themes: "blue" (standard), "green", "dark-blue"


def open_VOO():
    #intialize VOO page
    global VOO_page
    VOO_page = Toplevel()
    VOO_page.title('VOO')
    VOO_page.geometry('')
    frame = customtkinter.CTkFrame(master=VOO_page)
    frame.pack(pady=30, padx=60, fill="both", expand=True)

    #Create entries and labels for all programmable parameters and assign the entry text to variables
    VOO_url = StringVar()
    url_label = customtkinter.CTkLabel(master=frame,text="Upper Rate Limit")
    url_label.pack(pady=0, padx=10)
    url_entry = customtkinter.CTkEntry(master=frame, placeholder_text=VOO_url.get, textvariable=VOO_url)
    url_entry.pack(pady=8, padx=10)

    VOO_lrl = StringVar()
    lrl_label = customtkinter.CTkLabel(master=frame,text="Lower Rate Limit")
    lrl_label.pack(pady=0, padx=10)
    lrl_entry = customtkinter.CTkEntry(master=frame, textvariable=VOO_lrl.get, placeholder_text="Lower Rate Limit")
    lrl_entry.pack(pady=8, padx=10)

    VOO_VA = StringVar()
    ventricular_amplitude_label = customtkinter.CTkLabel(master=frame,text="Ventricular Amplitude")
    ventricular_amplitude_label.pack(pady=0, padx=10)
    ventricular_amplitude_entry = customtkinter.CTkEntry(master=frame, placeholder_text=VOO_VA.get, textvariable=VOO_VA)
    ventricular_amplitude_entry.pack(pady=8, padx=10)

    VOO_VPW = StringVar()
    ventricular_pulse_width_label = customtkinter.CTkLabel(master=frame,text="Ventricular Pulse Width")
    ventricular_pulse_width_label.pack(pady=0, padx=10)
    ventricular_pulse_width_entry = customtkinter.CTkEntry(master=frame, placeholder_text=VOO_VPW.get, textvariable = VOO_VPW)
    ventricular_pulse_width_entry.pack(pady=8, padx=10)

    #we need to create functionality for all enter buttons, so they save the information we have entered
    save_button = customtkinter.CTkButton(master=frame, text = "Save")
    save_button.pack(pady=10, padx=10)

    back_button = customtkinter.CTkButton(master=frame, text = "Back", command = VOO_page.withdraw)
    back_button.pack(pady=10, padx=10)

    heart_label = customtkinter.CTkLabel(master=frame, image = small_pixel_heart)
    heart_label.pack(pady=10, padx=10)

def open_AOO():
    #intialzie AOO page
    global AOO_page
    AOO_page = Toplevel()
    AOO_page.title('AOO')
    AOO_page.geometry('')
    frame = customtkinter.CTkFrame(master=AOO_page)
    frame.pack(pady=30, padx=60, fill="both", expand=True)

    #Create entries and labels for all programmable parameters and assign the entry text to variables
    AOO_url = StringVar()
    url_label = customtkinter.CTkLabel(master=frame,text="Upper Rate Limit")
    url_label.pack(pady=0, padx=10)
    url_entry = customtkinter.CTkEntry(master=frame, placeholder_text=AOO_url, textvariable=AOO_url)
    url_entry.pack(pady=8, padx=10)

    AOO_lrl = StringVar()
    lrl_label = customtkinter.CTkLabel(master=frame,text="Lower Rate Limit")
    lrl_label.pack(pady=0, padx=10)
    lrl_entry = customtkinter.CTkEntry(master=frame, placeholder_text=AOO_lrl, textvariable=AOO_lrl)
    lrl_entry.pack(pady=8, padx=10)

    AOO_AA = StringVar()
    atrial_amplitude_label = customtkinter.CTkLabel(master=frame,text="Atrial Amplitude")
    atrial_amplitude_label.pack(pady=0, padx=10)
    atrial_amplitude_entry = customtkinter.CTkEntry(master=frame, placeholder_text=AOO_AA, textvariable=AOO_AA)
    atrial_amplitude_entry.pack(pady=8, padx=14)

    AOO_APW = StringVar()
    atrial_pulse_width_label = customtkinter.CTkLabel(master=frame,text="Atrial Pulse Width")
    atrial_pulse_width_label.pack(pady=0, padx=10)
    atrial_pulse_width_entry = customtkinter.CTkEntry(master=frame, placeholder_text=AOO_APW, textvariable = AOO_APW)
    atrial_pulse_width_entry.pack(pady=8, padx=14)

    #functionality needs to be added here
    save_button = customtkinter.CTkButton(master=frame, text = "Save")
    save_button.pack(pady=10, padx=10)

    back_button = customtkinter.CTkButton(master=frame, text = "Back", command = AOO_page.withdraw)
    back_button.pack(pady=10, padx=10)

    heart_label = customtkinter.CTkLabel(master=frame, image = small_pixel_heart)
    heart_label.pack(pady=10, padx=10)

def open_VVI():
    #intialize VVI page
    global VVI_page
    VVI_page = Toplevel()
    VVI_page.title('VVI')
    VVI_page.geometry('')
    frame = customtkinter.CTkFrame(master=VVI_page)
    frame.pack(pady=30, padx=60, fill="both", expand=True)

    #Create entries for all programmable parameters and assign the entry text to variables
    VVI_url = StringVar()
    url_label = customtkinter.CTkLabel(master=frame,text="Upper Rate Limit")
    url_label.pack(pady=0, padx=10)
    url_entry = customtkinter.CTkEntry(master=frame, placeholder_text=VVI_url, textvariable=VVI_url)
    url_entry.pack(pady=8, padx=10)

    VVI_lrl = StringVar()
    lrl_label = customtkinter.CTkLabel(master=frame,text="Lower Rate Limit")
    lrl_label.pack(pady=0, padx=10)
    lrl_entry = customtkinter.CTkEntry(master=frame, placeholder_text=VVI_lrl, textvariable=VVI_lrl)
    lrl_entry.pack(pady=8, padx=10)

    VVI_VA = StringVar()
    ventricular_amplitude_label = customtkinter.CTkLabel(master=frame,text="Ventricular Amplitude")
    ventricular_amplitude_label.pack(pady=0, padx=10)
    ventricular_amplitude_entry = customtkinter.CTkEntry(master=frame, placeholder_text=VVI_VA, textvariable=VVI_VA)
    ventricular_amplitude_entry.pack(pady=8, padx=10)

    VVI_VPW = StringVar()
    ventricular_pulse_width_label = customtkinter.CTkLabel(master=frame,text="Ventricular Pulse Width")
    ventricular_pulse_width_label.pack(pady=0, padx=10)
    ventricular_pulse_width_entry = customtkinter.CTkEntry(master=frame, placeholder_text=VVI_VPW, textvariable = VVI_VPW)
    ventricular_pulse_width_entry.pack(pady=8, padx=10)

    VVI_VS = StringVar()
    ventricular_sensitivity_label = customtkinter.CTkLabel(master=frame,text="Ventricular Sensitivity")
    ventricular_sensitivity_label.pack(pady=0, padx=10)
    ventricular_sensitivity_entry = customtkinter.CTkEntry(master=frame, placeholder_text=VVI_VS, textvariable=VVI_VS)
    ventricular_sensitivity_entry.pack(pady=8, padx=10)

    VVI_VRP = StringVar()
    VRP_label = customtkinter.CTkLabel(master=frame,text="VRP")
    VRP_label.pack(pady=0, padx=10)
    VRP_entry = customtkinter.CTkEntry(master=frame, placeholder_text=VVI_VRP, textvariable = VVI_VRP)
    VRP_entry.pack(pady=8, padx=10)

    VVI_H = StringVar()
    hysterisis_label = customtkinter.CTkLabel(master=frame,text="Hysterisis")
    hysterisis_label.pack(pady=0, padx=10)
    hysterisis_entry = customtkinter.CTkEntry(master=frame, placeholder_text=VVI_H, textvariable=VVI_H)
    hysterisis_entry.pack(pady=8, padx=10)

    VVI_RS = StringVar()
    rate_smoothing_label = customtkinter.CTkLabel(master=frame,text="Rate Smoothing")
    rate_smoothing_label.pack(pady=0, padx=10)
    rate_smoothing_entry = customtkinter.CTkEntry(master=frame, placeholder_text=VVI_RS, textvariable=VVI_RS)
    rate_smoothing_entry.pack(pady=8, padx=10)

    #functionality needs to be added
    save_button = customtkinter.CTkButton(master=frame, text = "Save")
    save_button.pack(pady=10, padx=10)

    #we need to open home page
    back_button = customtkinter.CTkButton(master=frame, text = "Back", command = VVI_page.destroy)
    back_button.pack(pady=10, padx=10)

    heart_label = customtkinter.CTkLabel(master=frame, image = small_pixel_heart)
    heart_label.pack(pady=10, padx=10)


def open_AAI():
    #initializing AAI page
    global AAI_page
    AAI_page = Toplevel()
    AAI_page.title('AAI')
    AAI_page.geometry('')
    frame = customtkinter.CTkFrame(master=AAI_page)
    frame.pack(pady=30, padx=60, fill="both", expand=True)
    
    #Create entries for all programmable parameters and assign the entry text to variables
    AAI_url = StringVar()
    url_label = customtkinter.CTkLabel(master=frame,text="Upper Rate Limit")
    url_label.pack(pady=0, padx=10)
    url_entry = customtkinter.CTkEntry(master=frame, placeholder_text=AAI_url, textvariable=AAI_url)
    url_entry.pack(pady=8, padx=10)

    AAI_lrl = StringVar()
    lrl_label = customtkinter.CTkLabel(master=frame,text="Lower Rate Limit")
    lrl_label.pack(pady=0, padx=10)
    lrl_entry = customtkinter.CTkEntry(master=frame, placeholder_text=AAI_lrl, textvariable=AAI_lrl)
    lrl_entry.pack(pady=8, padx=10)

    AAI_AA = StringVar()
    atrial_amplitude_label = customtkinter.CTkLabel(master=frame,text="Atrial Amplitude")
    atrial_amplitude_label.pack(pady=0, padx=10)
    atrial_amplitude_entry = customtkinter.CTkEntry(master=frame, placeholder_text=AAI_AA, textvariable=AAI_AA)
    atrial_amplitude_entry.pack(pady=8, padx=10)

    AAI_APW = StringVar()
    atrial_pulse_width_label = customtkinter.CTkLabel(master=frame,text="Atrial Pulse Width")
    atrial_pulse_width_label.pack(pady=0, padx=10)
    atrial_pulse_width_entry = customtkinter.CTkEntry(master=frame, placeholder_text=AAI_APW, textvariable= AAI_APW)
    atrial_pulse_width_entry.pack(pady=8, padx=10)

    AAI_AS = StringVar()
    atrial_sensitivity_label = customtkinter.CTkLabel(master=frame,text="Atrial Sensitivity")
    atrial_sensitivity_label.pack(pady=0, padx=10)
    atrial_sensitivity_entry = customtkinter.CTkEntry(master=frame, placeholder_text=AAI_AS, textvariable=AAI_AS)
    atrial_sensitivity_entry.pack(pady=8, padx=10)

    AAI_H = StringVar()
    hysterisis_label = customtkinter.CTkLabel(master=frame,text="Hysterisis")
    hysterisis_label.pack(pady=0, padx=10)
    hysterisis_entry = customtkinter.CTkEntry(master=frame, placeholder_text=AAI_H, textvariable=AAI_H)
    hysterisis_entry.pack(pady=8, padx=10)

    AAI_RS = StringVar()
    rate_smoothing_label = customtkinter.CTkLabel(master=frame,text="Rate Smoothing")
    rate_smoothing_label.pack(pady=0, padx=10)
    rate_smoothing_entry = customtkinter.CTkEntry(master=frame, placeholder_text=AAI_RS, textvariable = AAI_RS)
    rate_smoothing_entry.pack(pady=8, padx=10)

    #need to add functionality
    save_button = customtkinter.CTkButton(master=frame, text = "Save")
    save_button.pack(pady=10, padx=10)

    back_button = customtkinter.CTkButton(master=frame, text = "Back", command = AAI_page.withdraw)
    back_button.pack(pady=10, padx=10)

    heart_label = customtkinter.CTkLabel(master=frame, image = small_pixel_heart)
    heart_label.pack(pady=10, padx=10)


def open_home():
    #need to hide root welcome window and destroy login window if its open
    welcome.withdraw()
    #iniialize home page
    global home_page
    home_page = Toplevel()
    home_page.title('Home')
    home_page.geometry('')
    frame = customtkinter.CTkFrame(master=home_page)
    frame.pack(pady=30, padx=60, fill="both", expand=True)
    
    modes_label = customtkinter.CTkLabel(master=frame, text = "Modes")
    modes_label.pack(pady=12, padx=10)

    AOO_button = customtkinter.CTkButton(master=frame, text = "AOO", command = open_AOO)
    AOO_button.pack(pady=12, padx=10)

    VOO_button = customtkinter.CTkButton(master=frame, text = "VOO", command = open_VOO)
    VOO_button.pack(pady=12, padx=10)

    AAI_button = customtkinter.CTkButton(master=frame, text = "AAI", command = open_AAI)
    AAI_button.pack(pady=12, padx=10)

    VVI_button = customtkinter.CTkButton(master=frame, text = "VVI", command = open_VVI)
    VVI_button.pack(pady=12, padx=10)

    quit_button = customtkinter.CTkButton(master=frame, text = "Quit", command = welcome.quit)
    quit_button.pack(pady=10, padx=8)

    heart_label = customtkinter.CTkLabel(master=frame, image = small_pixel_heart)
    heart_label.pack(pady=12, padx=10)
    

def open_register():
    #intialize register page
    global register_page
    register_page = Toplevel()
    register_page.title('Register')
    register_page.geometry('')
    frame = customtkinter.CTkFrame(master=register_page)
    frame.pack(pady=30, padx=60, fill="both", expand=True)

    #store registered name and password in variables
    register_username = StringVar()
    username_label = customtkinter.CTkLabel(master=frame,text="Username")
    username_label.pack(pady=0, padx=10)
    username_entry = customtkinter.CTkEntry(master=frame, placeholder_text="Create a username..", textvariable = register_username)
    username_entry.pack(pady=12, padx=10)

    register_password = StringVar()
    password_label = customtkinter.CTkLabel(master=frame,text="Password")
    password_label.pack(pady=0, padx=10)
    password_entry = customtkinter.CTkEntry(master=frame, placeholder_text="Create a password", show = "*", textvariable = register_password)
    password_entry.pack(pady=12, padx=10)

    register_button = customtkinter.CTkButton(master=frame, text = "Register", command = open_home)
    register_button.pack(pady=12, padx=10)

    back_button = customtkinter.CTkButton(master=frame, text = "Back", command = register_page.destroy)
    back_button.pack(pady=12, padx=10)

    heart_label = customtkinter.CTkLabel(master=frame, image = small_pixel_heart)
    heart_label.pack(pady=12, padx=10)

#initalize welcome page
welcome = customtkinter.CTk()
welcome.geometry("500x580")
welcome.title("Pacemaker")
frame = customtkinter.CTkFrame(master=welcome)
frame.pack(pady=30, padx=60, fill="both", expand=True)

welcome_label = customtkinter.CTkLabel(master=frame, text = "Welcome to the Pacemaker Enviornment!")
welcome_label.pack(pady=12, padx=10)

login_label = customtkinter.CTkLabel(master=frame, text = "Please login or register as a new user below..")
login_label.pack(pady=12, padx=10)

username_entry = customtkinter.CTkEntry(master=frame, placeholder_text="Username")
username_entry.pack(pady=12, padx=10)

password_entry = customtkinter.CTkEntry(master=frame, placeholder_text="Password", show = "*")
password_entry.pack(pady=12, padx=10)

login_button = customtkinter.CTkButton(master=frame, text = "Login", command = open_home)
login_button.pack(pady=12, padx=10)

register_button = customtkinter.CTkButton(master=frame, text = "Register as a new user", command = open_register)
register_button.pack(pady=12, padx=10,)

quit_button = customtkinter.CTkButton(master=frame, text = "Quit", command = welcome.quit)
quit_button.pack(pady=10, padx=8)

#picture details
pic = Image.open("heart.png")
heart = pic.resize((50,50), Image.ANTIALIAS)
small_heart = pic.resize((20,20), Image.ANTIALIAS)
small_pixel_heart = ImageTk.PhotoImage(small_heart)
pixel_heart = ImageTk.PhotoImage(heart)
heart_label = customtkinter.CTkLabel(master=frame, image = pixel_heart)
heart_label.pack(pady=12, padx=10)

welcome.mainloop()



#You can create a tkinter variable like StringVar and set it as the textvariable of your Entry widget. 
#Then you can access the content by calling the get method on the variable.

# import tkinter as tk

# root = tk.Tk()
# var = tk.StringVar()
# user_name = tk.Entry(root,textvariable=var)
# user_name.pack()
# #var.trace("w",lambda *args: print (var.get()))
# var.trace("w", lambda *args: pg.typewrite(var.get(), interval=0.2)

# root.mainloop()
