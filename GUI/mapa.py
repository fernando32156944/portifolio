from tkinter import *
import formaGeometrica
import booleanos
numero = 1
def criar():
    if booleanos.criarM == True:
        booleanos.criarM = False
        global w,numero
        numeroS = str(numero)
        titulo = "mapa"+numeroS
        master = Tk()
        master.title(titulo)
        numero = numero + 1
        w = Canvas(master, width=270, height=124)
        w.pack()
        mainloop()
        
def mapeador(nome,x,x0,x1,x2,Xc,y,y0,y1,y2,Yc,espessura,cor,quantidade):
    global w
    if nome == "ponto":
        print("x: ",x)
        print("y: ",y)
        print(x/1580)
        print((x/1580)*270)
        print(y/730)
        print((y/730)*124)
        formaGeometrica.ponto(int((x/1580)*270),int((y/730)*124),w,espessura,cor)
    elif nome == "Triangulo":
        formaGeometrica.TrianguloS(int((x0/1580)*270),int((x1/1580)*270),int((x2/1580)*270),int((y0/730)*124),int((y1/730)*124),int((y2/730)*124),w,quantidade,espessura,cor,False)
    elif nome == "linha":
        formaGeometrica.linha(int((x0/1580)*270),int((x1/1580)*270),int((y0/730)*124),int((y1/730)*124),w,espessura,cor)
    elif nome == "circulo":
        formaGeometrica.circulo(int((Xc/1580)*270),int((Yc/730)*124),int((x/1580)*270),int((y/730)*124),w,espessura,cor)
    elif nome == "limpador":
        formaGeometrica.limpador(w)
    else:
        return 0

    w.update()


    
    
