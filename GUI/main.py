#autor: Fernando Machado


from tkinter import *
import botoes
import mouseUsr




master = Tk()
w = Canvas(master, width=1580, height=730)
w.bind("<Button-1>", mouseUsr.getorigin)
w.pack()


buttonP = Button(master, text = "ponto", command = botoes.callbackP, anchor = CENTER)
buttonP.configure(width = 10, activebackground = "#33B5E5", relief = RAISED)
buttonP_window = w.create_window(0, 5, anchor=NW, window=buttonP)

buttonL = Button(master, text = "reta", command = botoes.callbackL, anchor = CENTER)
buttonL.configure(width = 10, activebackground = "#33B5E5", relief = RAISED)
buttonL_window = w.create_window(400, 5, anchor=NW, window=buttonL)

buttonC = Button(master, text = "circulo", command = botoes.callbackC, anchor = CENTER)
buttonC.configure(width = 10, activebackground = "#33B5E5", relief = RAISED)
buttonC_window = w.create_window(800, 5, anchor=NW, window=buttonC)

buttonT = Button(master, text = "Triangulo", command = botoes.callbackT, anchor = CENTER)
buttonT.configure(width = 10, activebackground = "#33B5E5", relief = RAISED)
buttonT_window = w.create_window(1100, 5, anchor=NW, window=buttonT)

buttonRC = Button(master, text = "Retas e circulos", command = botoes.callbackRC, anchor = CENTER)
buttonRC.configure(width = 12, activebackground = "#33B5E5", relief = RAISED)
buttonRC_window = w.create_window(1000, 5, anchor=NW, window=buttonRC)

buttonCor = Button(master, text = "Cor", command = botoes.callbackCor, anchor = CENTER)
buttonCor.configure(width = 10, activebackground = "#33B5E5", relief = RAISED)
buttonCor_window = w.create_window(700, 5, anchor=NW, window=buttonCor)

buttonEsp = Button(master, text = "espessura", command = botoes.callbackEsp, anchor = CENTER)
buttonEsp.configure(width = 10, activebackground = "#33B5E5", relief = RAISED)
buttonEsp_window = w.create_window(600, 5, anchor=NW, window=buttonEsp)

buttonLimp = Button(master, text = "limpar", command = botoes.callbackLimp, anchor = CENTER)
buttonLimp.configure(width = 10, activebackground = "#33B5E5", relief = RAISED)
buttonLimp_window = w.create_window(500, 5, anchor=NW, window=buttonLimp)

buttonRest = Button(master, text = "Restaurar", command = botoes.callbackRestaurador, anchor = CENTER)
buttonRest.configure(width = 10, activebackground = "#33B5E5", relief = RAISED)
buttonRest_window = w.create_window(300, 5, anchor=NW, window=buttonRest)

buttonMapa = Button(master, text = "mapear", command = botoes.callbackMapa, anchor = CENTER)
buttonMapa.configure(width = 10, activebackground = "#33B5E5", relief = RAISED)
buttonMapa_window = w.create_window(200, 5, anchor=NW, window=buttonMapa)

buttonSave = Button(master, text = "Salvar", command = botoes.callbackSave, anchor = CENTER)
buttonSave.configure(width = 10, activebackground = "#33B5E5", relief = RAISED)
buttonSave_window = w.create_window(100, 5, anchor=NW, window=buttonSave)

buttonLoad = Button(master, text = "Carregar", command = botoes.callbackLoad, anchor = CENTER)
buttonLoad.configure(width = 10, activebackground = "#33B5E5", relief = RAISED)
buttonLoad_window = w.create_window(900, 5, anchor=NW, window=buttonLoad)

mainloop()
