
from tkinter import *
import botoes
import Muser




master = Tk()
w = Canvas(master, width=840, height=30)
w.pack()


buttonC = Button(master, text = "Carregar imagem", command = botoes.callbackC, anchor = CENTER)
buttonC.configure(width = 15, activebackground = "#33B5E5", relief = RAISED)
buttonC_window = w.create_window(0, 5, anchor=NW, window=buttonC)


buttonP = Button(master, text = "preto e branco", command = botoes.callbackP, anchor = CENTER)
buttonP.configure(width = 15, activebackground = "#33B5E5", relief = RAISED)
buttonP_window = w.create_window(600, 5, anchor=NW, window=buttonP)


buttonCN = Button(master, text = "Cinza", command = botoes.callbackCN, anchor = CENTER)
buttonCN.configure(width = 15, activebackground = "#33B5E5", relief = RAISED)
buttonCN_window = w.create_window(360, 5, anchor=NW, window=buttonCN)

buttonH = Button(master, text = "Histograma", command = botoes.callbackH, anchor = CENTER)
buttonH.configure(width = 15, activebackground = "#33B5E5", relief = RAISED)
buttonH_window = w.create_window(240, 5, anchor=NW, window=buttonH)

buttonI = Button(master, text = "Filtro inversor", command = botoes.callbackI, anchor = CENTER)
buttonI.configure(width = 15, activebackground = "#33B5E5", relief = RAISED)
buttonI_window = w.create_window(480, 5, anchor=NW, window=buttonI)

buttonLSD = Button(master, text = "Filtro jet", command = botoes.callbackLSD, anchor = CENTER)
buttonLSD.configure(width = 15, activebackground = "#33B5E5", relief = RAISED)
buttonLSD_window = w.create_window(720, 5, anchor=NW, window=buttonLSD)

buttonOG = Button(master, text = "Original", command = botoes.callbackOG, anchor = CENTER)
buttonOG.configure(width = 15, activebackground = "#33B5E5", relief = RAISED)
buttonOG_window = w.create_window(120, 5, anchor=NW, window=buttonOG)

mainloop()
