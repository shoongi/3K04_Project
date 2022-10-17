from tkinter import *

window = Tk()
window.title("Pacemaker DCM")

window.configure(width=window.winfo_screenwidth(),height=window.winfo_screenheight())

winWidth = window.winfo_reqwidth()
winwHeight = window.winfo_reqheight()
posRight = int(window.winfo_screenwidth() / 2 - winWidth / 2)
posDown = int(window.winfo_screenheight() / 2 - winwHeight / 2)
window.geometry("+{}+{}".format(posRight, posDown))

window.mainloop()

