#import desired libraries
from cmath import log
from copyreg import pickle
import tkinter
from tokenize import String
import customtkinter

from distutils.cmd import Command
from tkinter import *
from tkinter import messagebox
from PIL import ImageTk, Image

import users
import modes

#set appearances
customtkinter.set_appearance_mode("System")  # Modes: "System" (standard), "Dark", "Light"
customtkinter.set_default_color_theme("green")  # Themes: "blue" (standard), "green", "dark-blue"


##############################################################################################################
######################## MODE PAGES###########################################################################
##############################################################################################################

#VOO PAGE
def open_VOO(prev_page):
    #intialize VOO page
    global VOO_page
    VOO_page = Toplevel()
    VOO_page.title('VOO')
    VOO_page.geometry('')
    frame = customtkinter.CTkFrame(master=VOO_page)
    frame.pack(pady=30, padx=60, fill="both", expand=True)

    VOOData = modes.VOO(loginUser.getName())
    VOOData.loadVOO()

    #Create entries and labels for all programmable parameters and assign the entry text to variables
    VOO_url = VOOData.URL
    url_label = customtkinter.CTkLabel(master=frame,text="Upper Rate Limit")
    url_label.pack(pady=0, padx=10)
    url_entry = customtkinter.CTkEntry(master=frame, placeholder_text=VOO_url)
    url_entry.pack(pady=8, padx=10)

    VOO_lrl = VOOData.LRL
    lrl_label = customtkinter.CTkLabel(master=frame,text="Lower Rate Limit")
    lrl_label.pack(pady=0, padx=10)
    lrl_entry = customtkinter.CTkEntry(master=frame, textvariable=VOO_lrl)
    lrl_entry.pack(pady=8, padx=10)

    VOO_VA = VOOData.VA
    ventricular_amplitude_label = customtkinter.CTkLabel(master=frame,text="Ventricular Amplitude")
    ventricular_amplitude_label.pack(pady=0, padx=10)
    ventricular_amplitude_entry = customtkinter.CTkEntry(master=frame, placeholder_text=VOO_VA)
    ventricular_amplitude_entry.pack(pady=8, padx=10)

    VOO_VPW = VOOData.VPW
    ventricular_pulse_width_label = customtkinter.CTkLabel(master=frame,text="Ventricular Pulse Width")
    ventricular_pulse_width_label.pack(pady=0, padx=10)
    ventricular_pulse_width_entry = customtkinter.CTkEntry(master=frame, placeholder_text=VOO_VPW)
    ventricular_pulse_width_entry.pack(pady=8, padx=10)

    #we need to create functionality for all enter buttons, so they save the information we have entered
    save_button = customtkinter.CTkButton(master=frame, text = "Save", command = lambda : [VOOData.addLRL(lrl_entry.get()),VOOData.addURL(url_entry.get()),VOOData.addVA(ventricular_amplitude_entry.get()),VOOData.addVPW(ventricular_pulse_width_entry.get()),VOOData.addVOO()])
    save_button.pack(pady=10, padx=10)

    back_button = customtkinter.CTkButton(master=frame, text = "Back", command = lambda : [VOO_page.destroy(),open_home(VOO_page)])
    back_button.pack(pady=10, padx=10)

    heart_label = customtkinter.CTkLabel(master=frame, image = small_pixel_heart)
    heart_label.pack(pady=10, padx=10)

#AOO PAGE
def open_AOO(prev_page):
    #intialzie AOO page
    global AOO_page
    AOO_page = Toplevel()
    AOO_page.title('AOO')
    AOO_page.geometry('')
    frame = customtkinter.CTkFrame(master=AOO_page)
    frame.pack(pady=30, padx=60, fill="both", expand=True)

    AOOData = modes.AOO(loginUser.getName())
    AOOData.loadAOO()

    #Create entries and labels for all programmable parameters and assign the entry text to variables
    AOO_url = AOOData.URL
    url_label = customtkinter.CTkLabel(master=frame,text="Upper Rate Limit")
    url_label.pack(pady=0, padx=10)
    url_entry = customtkinter.CTkEntry(master=frame, placeholder_text=AOO_url)
    url_entry.pack(pady=8, padx=10)

    AOO_lrl = AOOData.LRL
    lrl_label = customtkinter.CTkLabel(master=frame,text="Lower Rate Limit")
    lrl_label.pack(pady=0, padx=10)
    lrl_entry = customtkinter.CTkEntry(master=frame, placeholder_text=AOO_lrl)
    lrl_entry.pack(pady=8, padx=10)

    AOO_AA = AOOData.AA
    atrial_amplitude_label = customtkinter.CTkLabel(master=frame,text="Atrial Amplitude")
    atrial_amplitude_label.pack(pady=0, padx=10)
    atrial_amplitude_entry = customtkinter.CTkEntry(master=frame, placeholder_text=AOO_AA)
    atrial_amplitude_entry.pack(pady=8, padx=14)

    AOO_APW = AOOData.APW
    atrial_pulse_width_label = customtkinter.CTkLabel(master=frame,text="Atrial Pulse Width")
    atrial_pulse_width_label.pack(pady=0, padx=10)
    atrial_pulse_width_entry = customtkinter.CTkEntry(master=frame, placeholder_text=AOO_APW)
    atrial_pulse_width_entry.pack(pady=8, padx=14)

    #functionality needs to be added here
    save_button = customtkinter.CTkButton(master=frame, text = "Save", command = lambda : [AOOData.addAA(atrial_amplitude_entry.get()),AOOData.addAPW(atrial_pulse_width_entry.get()),AOOData.addLRL(lrl_entry.get()),AOOData.addURL(url_entry.get()),AOOData.addAOO()])
    save_button.pack(pady=10, padx=10)

    back_button = customtkinter.CTkButton(master=frame, text = "Back", command = lambda : [AOO_page.destroy(),open_home(AOO_page)])
    back_button.pack(pady=10, padx=10)

    heart_label = customtkinter.CTkLabel(master=frame, image = small_pixel_heart)
    heart_label.pack(pady=10, padx=10)

#VVI PAGE
def open_VVI(prev_page):
    #intialize VVI page
    global VVI_page
    VVI_page = Toplevel()
    VVI_page.title('VVI')
    VVI_page.geometry('')
    frame = customtkinter.CTkFrame(master=VVI_page)
    frame.pack(pady=30, padx=60, fill="both", expand=True)

    VVIData = modes.VVI(loginUser.getName())
    VVIData.loadVVI()

    #Create entries for all programmable parameters and assign the entry text to variables
    VVI_url = VVIData.URL
    url_label = customtkinter.CTkLabel(master=frame,text="Upper Rate Limit")
    url_label.pack(pady=0, padx=10)
    url_entry = customtkinter.CTkEntry(master=frame, placeholder_text=VVI_url)
    url_entry.pack(pady=0, padx=10)

    VVI_lrl = VVIData.LRL
    lrl_label = customtkinter.CTkLabel(master=frame,text="Lower Rate Limit")
    lrl_label.pack(pady=0, padx=10)
    lrl_entry = customtkinter.CTkEntry(master=frame, placeholder_text=VVI_lrl)
    lrl_entry.pack(pady=0, padx=10)

    VVI_VA = VVIData.VA
    ventricular_amplitude_label = customtkinter.CTkLabel(master=frame,text="Ventricular Amplitude")
    ventricular_amplitude_label.pack(pady=0, padx=10)
    ventricular_amplitude_entry = customtkinter.CTkEntry(master=frame, placeholder_text=VVI_VA)
    ventricular_amplitude_entry.pack(pady=0, padx=10)

    VVI_VPW = VVIData.VPW
    ventricular_pulse_width_label = customtkinter.CTkLabel(master=frame,text="Ventricular Pulse Width")
    ventricular_pulse_width_label.pack(pady=0, padx=10)
    ventricular_pulse_width_entry = customtkinter.CTkEntry(master=frame, placeholder_text=VVI_VPW)
    ventricular_pulse_width_entry.pack(pady=0, padx=10)

    VVI_VRP = VVIData.VRP
    VRP_label = customtkinter.CTkLabel(master=frame,text="VRP")
    VRP_label.pack(pady=0, padx=10)
    VRP_entry = customtkinter.CTkEntry(master=frame, placeholder_text=VVI_VRP)
    VRP_entry.pack(pady=0, padx=10)

    VVI_VS = StringVar()
    ventricular_sensitivity_label = customtkinter.CTkLabel(master=frame,text="Ventricular Sensitivity")
    ventricular_sensitivity_label.pack(pady=0, padx=10)
    ventricular_sensitivity_entry = customtkinter.CTkEntry(master=frame, placeholder_text=VVI_VS)
    ventricular_sensitivity_entry.pack(pady=0, padx=10)

    VVI_H = StringVar()
    hysterisis_label = customtkinter.CTkLabel(master=frame,text="Hysterisis")
    hysterisis_label.pack(pady=0, padx=10)
    hysterisis_entry = customtkinter.CTkEntry(master=frame, placeholder_text=VVI_H)
    hysterisis_entry.pack(pady=0, padx=10)

    VVI_RS = StringVar()
    rate_smoothing_label = customtkinter.CTkLabel(master=frame,text="Rate Smoothing")
    rate_smoothing_label.pack(pady=0, padx=10)
    rate_smoothing_entry = customtkinter.CTkEntry(master=frame, placeholder_text=VVI_RS)
    rate_smoothing_entry.pack(pady=0, padx=10)

    #functionality needs to be added
    save_button = customtkinter.CTkButton(master=frame, text = "Save", command = lambda : [VVIData.addVA(ventricular_amplitude_entry.get()),VVIData.addVPW(ventricular_pulse_width_entry.get()),VVIData.addVRP(VRP_entry.get()),VVIData.addLRL(lrl_entry.get()),VVIData.addURL(url_entry.get()),VVIData.addVVI()])
    save_button.pack(pady=10, padx=10)

    #we need to open home page
    back_button = customtkinter.CTkButton(master=frame, text = "Back", command = lambda : [VVI_page.destroy(),open_home(VVI_page)])
    back_button.pack(pady=10, padx=10)

    heart_label = customtkinter.CTkLabel(master=frame, image = small_pixel_heart)
    heart_label.pack(pady=10, padx=10)

#AAI PAGE
def open_AAI(prev_page):
    #initializing AAI page
    global AAI_page
    AAI_page = Toplevel()
    AAI_page.title('AAI')
    AAI_page.geometry('')
    frame = customtkinter.CTkFrame(master=AAI_page)
    frame.pack(pady=30, padx=60, fill="both", expand=True)

    #Getting AAI DATA
    AAIData = modes.AAI(loginUser.getName())
    AAIData.loadAAI()

    #Create entries for all programmable parameters and assign the entry text to variables
    AAI_url = AAIData.URL
    url_label = customtkinter.CTkLabel(master=frame,text="Upper Rate Limit")
    url_label.pack(pady=0, padx=10)
    url_entry = customtkinter.CTkEntry(master=frame, placeholder_text=AAI_url)
    url_entry.pack(pady=0, padx=10)

    AAI_lrl = AAIData.LRL
    lrl_label = customtkinter.CTkLabel(master=frame, text = "Lower Rate Limit")
    lrl_label.pack(pady=0,padx=10)
    lrl_entry = customtkinter.CTkEntry(master=frame, placeholder_text=AAI_lrl)
    lrl_entry.pack(pady=0,padx=10)

    AAI_aa = AAIData.AA
    atrial_amplitude_label = customtkinter.CTkLabel(master=frame,text="Atrial Amplitude")
    atrial_amplitude_label.pack(pady=0, padx=10)
    atrial_amplitude_entry = customtkinter.CTkEntry(master=frame, placeholder_text=AAI_aa)
    atrial_amplitude_entry.pack(pady=0, padx=10)

    AAI_APW = AAIData.APW
    atrial_pulse_width_label = customtkinter.CTkLabel(master=frame,text="Atrial Pulse Width")
    atrial_pulse_width_label.pack(pady=0, padx=10)
    atrial_pulse_width_entry = customtkinter.CTkEntry(master=frame, placeholder_text=AAI_APW)
    atrial_pulse_width_entry.pack(pady=0, padx=10)

    AAI_ARP = AAIData.ARP
    atrial_refactory_period_label = customtkinter.CTkLabel(master=frame,text="Atrial Refactory Period")
    atrial_refactory_period_label.pack(pady=0, padx=10)
    atrial_refactory_period_entry = customtkinter.CTkEntry(master=frame, placeholder_text=AAI_ARP)
    atrial_refactory_period_entry.pack(pady=0, padx=10)

    AAI_AS = StringVar()
    atrial_sensitivity_label = customtkinter.CTkLabel(master=frame,text="Atrial Sensitivity")
    atrial_sensitivity_label.pack(pady=0, padx=10)
    atrial_sensitivity_entry = customtkinter.CTkEntry(master=frame, placeholder_text="HERE IS A PLACEHOLDER", textvariable=AAI_AS)
    atrial_sensitivity_entry.pack(pady=0, padx=10)

    AAI_H = StringVar()
    hysterisis_label = customtkinter.CTkLabel(master=frame,text="Hysterisis")
    hysterisis_label.pack(pady=0, padx=10)
    hysterisis_entry = customtkinter.CTkEntry(master=frame, placeholder_text="HERE IS A PLACEHOLDER", textvariable=AAI_H)
    hysterisis_entry.pack(pady=0, padx=10)

    AAI_RS = StringVar()
    rate_smoothing_label = customtkinter.CTkLabel(master=frame,text="Rate Smoothing")
    rate_smoothing_label.pack(pady=0, padx=10)
    rate_smoothing_entry = customtkinter.CTkEntry(master=frame, placeholder_text="HERE IS A PLACEHOLDER", textvariable = AAI_RS)
    rate_smoothing_entry.pack(pady=0, padx=10)

    #need to add functionality
    save_button = customtkinter.CTkButton(master=frame, text = "Save", command= lambda : [AAIData.addAA(atrial_amplitude_entry.get()),AAIData.addAPW(atrial_pulse_width_entry.get()),AAIData.addARP(atrial_refactory_period_entry.get()),AAIData.addLRL(lrl_entry.get()),AAIData.addURL(url_entry.get()),AAIData.addAAI()])
    save_button.pack(pady=10, padx=10)

    back_button = customtkinter.CTkButton(master=frame, text = "Back", command = lambda : [AAIData.addAAI(),AAI_page.destroy(),open_home(AAI_page)])
    back_button.pack(pady=10, padx=10)

    heart_label = customtkinter.CTkLabel(master=frame, image = small_pixel_heart)
    heart_label.pack(pady=10, padx=10)


#############################################################################################
######################### HOME PAGE #########################################################
#############################################################################################
def open_home(welcomePage):
    #need to hide root welcome window and destroy login window if its open
    #welcome.withdraw()
    #iniialize home page
    global home_page
    home_page = Toplevel()
    home_page.title('Home')
    home_page.geometry('')
    frame = customtkinter.CTkFrame(master=home_page)
    frame.pack(pady=30, padx=60, fill="both", expand=True)
    
    modes_label = customtkinter.CTkLabel(master=frame, text = "Modes")
    modes_label.pack(pady=12, padx=10)

    AOO_button = customtkinter.CTkButton(master=frame, text = "AOO", command = lambda : [home_page.destroy(),open_AOO(home_page)])
    AOO_button.pack(pady=12, padx=10)

    VOO_button = customtkinter.CTkButton(master=frame, text = "VOO", command = lambda : [home_page.destroy(),open_VOO(home_page)])
    VOO_button.pack(pady=12, padx=10)

    AAI_button = customtkinter.CTkButton(master=frame, text = "AAI", command = lambda : [home_page.destroy(),open_AAI(home_page)])
    AAI_button.pack(pady=12, padx=10)

    VVI_button = customtkinter.CTkButton(master=frame, text = "VVI", command = lambda : [home_page.destroy(),open_VVI(home_page)])
    VVI_button.pack(pady=12, padx=10)

    back_button = customtkinter.CTkButton(master=frame, text = "Logout", command = lambda : [home_page.destroy(),welcome.deiconify()])
    back_button.pack(pady=12, padx=8)

    quit_button = customtkinter.CTkButton(master=frame, text = "Quit", command = welcome.quit)
    quit_button.pack(pady=10, padx=8)

    heart_label = customtkinter.CTkLabel(master=frame, image = small_pixel_heart)
    heart_label.pack(pady=12, padx=10)
    

###################################################################
#################### REGISTER USERS PAGES #########################
###################################################################

#Check if you can register a user
def checkRegister(register_page, name, password):
    print("ENTER HERE\n")
    global loginUser
    loginUser = users.User(name,password)

    canReg, message = loginUser.addUser()

    if (canReg == True):
        print("registered\n")
        register_page.destroy()
        open_home(register_page)
    else:
        print(message)
        return

#Opens register page
def open_register(welcome):
    #intialize register page
    welcome.withdraw()
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

    register_button = customtkinter.CTkButton(master=frame, text = "Register", command = lambda : checkRegister(register_page, username_entry.get(), password_entry.get()))
    register_button.pack(pady=12, padx=10)

    back_button = customtkinter.CTkButton(master=frame, text = "Back", command = lambda : [welcome.deiconify(),register_page.destroy()])
    back_button.pack(pady=12, padx=10)

    heart_label = customtkinter.CTkLabel(master=frame, image = small_pixel_heart)
    heart_label.pack(pady=12, padx=10)


###############################################################################
####################### LOGIN PAGES ###########################################
###############################################################################

#Check if you can login
def checkLogin(username,password,welcome):
    global loginUser
    loginUser = users.User(username,password)

    canLog, message = loginUser.login()

    if (canLog == True):
        welcome.withdraw()
        print ("Good Login")
        open_home(welcome)
    else:
        print (message)
        return


##############################################################################
########################### WELCOME PAGE #####################################
##############################################################################

def welcomePage():
    #initalize welcome page
    global welcome
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

    login_button = customtkinter.CTkButton(master=frame, text = "Login", command = lambda : checkLogin(username_entry.get(), password_entry.get(), welcome))
    login_button.pack(pady=12, padx=10)

    register_button = customtkinter.CTkButton(master=frame, text = "Register as a new user", command = lambda : open_register(welcome))
    register_button.pack(pady=12, padx=10,)

    quit_button = customtkinter.CTkButton(master=frame, text = "Quit", command = welcome.quit)
    quit_button.pack(pady=10, padx=8)

    #picture details
    pic = Image.open(r"DCM\heart.png")
    heart = pic.resize((50,50), Image.ANTIALIAS)
    small_heart = pic.resize((20,20), Image.ANTIALIAS)
    small_pixel_heart = ImageTk.PhotoImage(small_heart)
    pixel_heart = ImageTk.PhotoImage(heart)
    heart_label = customtkinter.CTkLabel(master=frame, image = pixel_heart)
    heart_label.pack(pady=12, padx=10)

    welcome.mainloop()

global pic
global heart
global small_heart
global small_pixel_heart
global pixel_heart
global heart_label
welcomePage()
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
