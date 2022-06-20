from pynput import mouse
import formaGeometrica
import booleanos
import botoes
import SaveAndLoad as SL
import tkinter as tk
from tkinter import simpledialog
import mapa

cor = '#000000'
espessura = 5
def getorigin(eventorigin):
    global x,y,w,x0,y0,x1,y1,x2,y2,Xc,Yc,xT1,xT2,xT3,yT1,yT2,yT3,nivel,cor,espessura
    w = eventorigin.widget
    x = eventorigin.x
    y = eventorigin.y
    if booleanos.Inicio== True: #para que não apareca a seleção de cor apos o primeiro click na tela
        booleanos.Inicio = True #para que não apareca a seleção de cor apos o primeiro click na tela
    elif booleanos.LimparB == True:
        formaGeometrica.limpador(w)
        if booleanos.mapaB == True:
            mapa.mapeador("limpador",-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,2,cor,-1)
    elif booleanos.CorB == False:
        cor = simpledialog.askstring("Input", 'cor',parent=w)
    elif booleanos.EspB == False:
        espessura = int(simpledialog.askstring("Input", 'espessura',parent=w))
    elif booleanos.pontoB == True:
        formaGeometrica.ponto(x,y,w,espessura,cor)
        if booleanos.mapaB == True:
            booleanos.mapeadorON = True
            mapa.mapeador("ponto",x,-1,-1,-1,-1,y,-1,-1,-1,-1,2,cor,-1)
            booleanos.mapeadorON = False
    elif booleanos.linhaB == True:
        if booleanos.pontoUM == False:
            formaGeometrica.ponto(x,y,w,espessura,cor)
            x1 = x
            y1 = y
            booleanos.pontoUM = True
        else:
            formaGeometrica.ponto(x,y,w,espessura,cor)
            x2 = x
            y2 = y
            if x2>x1:
                x0 = x1
                y0 = y1
                x1 = x2
                y1 = y2
                
                formaGeometrica.linha(x0,x1,y0,y1,w,espessura,cor)
                if booleanos.mapaB == True:
                    booleanos.mapeadorON = True
                    mapa.mapeador("linha",-1,x0,x1,-1,-1,-1,y0,y1,-1,-1,2,cor,-1)
                    booleanos.mapeadorON = False
                booleanos.pontoUM = False
            else:
                x0 = x2
                y0 = y2
                formaGeometrica.linha(x0,x1,y0,y1,w,espessura,cor)
                if booleanos.mapaB == True:
                    booleanos.mapeadorON = True
                    mapa.mapeador("linha",-1,x0,x1,-1,-1,-1,y0,y1,-1,-1,2,cor,-1)
                    booleanos.mapeadorON = False
                booleanos.pontoUM = False

    elif booleanos.circuloB == True:
        if booleanos.pontoC == False:
            Xc = x
            Yc = y
            booleanos.pontoC = True
        else:
            x1 = x
            y1 = y
            formaGeometrica.circulo(Xc,Yc,x,y,w,espessura,cor)
            if booleanos.mapaB == True:
                booleanos.mapeadorON = True
                mapa.mapeador("circulo",x,-1,-1,-1,Xc,y,-1,-1,-1,Yc,2,cor,-1)
                booleanos.mapeadorON = False
            booleanos.pontoC = False

    elif booleanos.TrianguloB == True:
        if booleanos.pontoUM == False:
            formaGeometrica.ponto(x,y,w,espessura,cor)
            xT1 = x
            yT1 = y
            booleanos.pontoUM = True
        elif booleanos.pontoC == False:
            formaGeometrica.ponto(x,y,w,espessura,cor)
            xT2 = x
            yT2 = y
            booleanos.pontoC = True
        else:
            xT3 = x
            yT3 = y
            nivel = int(simpledialog.askstring("Input", "nivel",parent=w))
            formaGeometrica.TrianguloS(xT1,xT2,xT3,yT1,yT2,yT3,w,nivel,espessura,cor,True)
            if booleanos.mapaB == True:
                booleanos.mapeadorON = True
                mapa.mapeador("Triangulo",-1,xT1,xT2,xT3,-1,-1,yT1,yT2,yT3,-1,2,cor,nivel)
                booleanos.mapeadorON = False
            booleanos.pontoUM = False
            booleanos.pontoC = False
    elif booleanos.RestauradorB == True:
        quantidadeR = int(simpledialog.askstring("Input", "quantidade",parent=w))
        formaGeometrica.restaurador(w,quantidadeR)
    
    elif booleanos.RCB == True:
        formaGeometrica.RetasCirculos(w)

    elif booleanos.mapaB == True:
        mapa.criar()
        
    elif booleanos.SaveB == True:
        SL.save()
        booleanos.SaveB = False
        
    elif booleanos.LoadB == True:
        nome = simpledialog.askstring("Input", 'nome',parent=w)
        SL.load(nome,w)
        booleanos.LoadB = False
        

