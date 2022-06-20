import math
import pilha
import fila
import booleanos
import xml.etree.ElementTree as ET

global armazenador
global contador
armazenador = pilha.iniciar()
contador = 0

def RetasCirculos(w):
    w.create_line(515,500,885,500,width=1,fill = 'red')
    w.create_line(515,500,700,600,width=1,fill = 'red')
    w.create_line(885,500,700,600,width=1,fill = 'red')
    w.create_line(700,600,700,200,width=1,fill = 'red')
    w.create_line(515,300,885,300,width=1,fill = 'red')
    w.create_line(515,300,700,200,width=1,fill = 'red')
    w.create_line(885,300,700,200,width=1,fill = 'red')
    w.create_line(515,500,515,300,width=1,fill = 'red')
    w.create_line(885,500,885,300,width=1,fill = 'red')
    w.create_line(515,300,700,600,width=1,fill = 'red')
    w.create_line(885,300,700,600,width=1,fill = 'red')
    w.create_line(515,500,700,200,width=1,fill = 'red')
    w.create_line(885,500,700,200,width=1,fill = 'red')
    w.create_line(515,500,885,300,width=1,fill = 'red')
    w.create_line(885,500,515,300,width=1,fill = 'red')
    w.create_line(575,400,825,400,width=1,fill = 'red')
    w.create_line(640,300,760,500,width=1,fill = 'red')
    w.create_line(760,300,640,500,width=1,fill = 'red')
    circulo(700,400,575,400,w,2,'green')
    circulo(575,400,700,400,w,2,'green')
    circulo(825,400,700,400,w,2,'green')
    circulo(640,300,515,300,w,2,'green')
    circulo(760,300,885,300,w,2,'green')
    circulo(640,500,515,500,w,2,'green')
    circulo(760,500,885,500,w,2,'green')
def getMidX(x0,x1):
    x = (x0+x1)/2
    return x 
    
def getMidY(y0,y1):
    y = (y0+y1)/2
    return y
    
def TrianguloS(x0,x1,x2,y0,y1,y2,w,quantidade,esp,cor,booleano): 
    w.create_line(x0,y0,x1,y1,width=esp,fill= cor)
    w.create_line(x1,y1,x2,y2,width=esp,fill= cor)
    w.create_line(x2,y2,x0,y0,width=esp,fill= cor)
    #armazenar triangulo
    if booleano == True:
        trinaguloArmazenado = fila.iniciar()
        fila.push(trinaguloArmazenado,"triangulo")
        fila.push(trinaguloArmazenado,x0)
        fila.push(trinaguloArmazenado,x1)
        fila.push(trinaguloArmazenado,x2)
        fila.push(trinaguloArmazenado,y0)
        fila.push(trinaguloArmazenado,y1)
        fila.push(trinaguloArmazenado,y2)
        fila.push(trinaguloArmazenado,quantidade)
        fila.push(trinaguloArmazenado,esp)
        fila.push(trinaguloArmazenado,cor)
        armazenar(trinaguloArmazenado)
    if quantidade>0:
        TrianguloS(x0,getMidX(x0,x1),getMidX(x0,x2),y0,getMidY(y0,y1),getMidY(y0,y2),w,quantidade-1,esp,cor,False)
        TrianguloS(x1,getMidX(x1,x0),getMidX(x1,x2),y1,getMidY(y1,y0),getMidY(y1,y2),w,quantidade-1,esp,cor,False)
        TrianguloS(x2,getMidX(x2,x0),getMidX(x2,x1),y2,getMidY(y2,y0),getMidY(y2,y1),w,quantidade-1,esp,cor,False)
    
    

def linha(x0,x1,y0,y1,w,esp,cor):
    #armazenar reta
    if booleanos.mapeadorON == False:
        linhaArmazenado = fila.iniciar()
        fila.push(linhaArmazenado,"linha")
        fila.push(linhaArmazenado,x0)
        fila.push(linhaArmazenado,x1)
        fila.push(linhaArmazenado,y0)
        fila.push(linhaArmazenado,y1)
        fila.push(linhaArmazenado,esp)
        fila.push(linhaArmazenado,cor)
        armazenar(linhaArmazenado)
    if(x1-x0) == 0:
        m = 0
    else:
        m = (y1-y0)/(x1-x0) *-1
    if m == 0:
        for b in range(y0,y1+1):
            ponto(x0,b,w,esp,cor)
    #vertical
    elif abs(m) >= 1:
        if m <= -1:
            for c in range(y0,y1+1):
                reta = ((m*(x1)+y1-c)/-m)*-1
                novoX = int(reta)
                ponto(novoX,c,w,esp,cor)
        else:
            for d in range(y1,y0+1):
                reta = ((m*(x1)+y1-d)/-m)*-1
                novoX = int(reta)
                ponto(novoX,d,w,esp,cor)
    else:
        for a in range(x0,x1+1):
            reta = m*(x1-a)+y1
            novoY = int(reta)
            ponto(a,novoY,w,esp,cor)
    booleanos.retaR = False
    
def ponto(x,y,w,esp,cor):
    #armazenar ponto      
    if booleanos.pontoB == True or booleanos.RestauradorB == True:
        if booleanos.retaR == False and booleanos.circuloR == False:
            if booleanos.mapeadorON == False:
                pontoArmazenado = fila.iniciar()
                fila.push(pontoArmazenado,"ponto")
                fila.push(pontoArmazenado,x)
                fila.push(pontoArmazenado,y)
                fila.push(pontoArmazenado,esp)
                fila.push(pontoArmazenado,cor)
                armazenar(pontoArmazenado)
    z = y
    for x in range(x,x+esp):
        w.create_line(x,y,x+1,y,fill= cor)
        y = z
        for y in range(y,y+esp):
            w.create_line(x,y,x,y+1,fill = cor)
   

def circulo(Xc,Yc,x,y,w,esp,cor):
    for ang in range(0,361):
        R2 = (x-Xc)**2 + (y-Yc)**2
        R = math.sqrt(R2)
        pi = math.pi
        sen = math.sin((ang*pi)/180)* R
        cos = math.cos((ang*pi)/180)* R

        senInt = int(sen)
        cosInt = int(cos)

        
        ponto(Xc+cosInt,Yc+senInt,w,esp,cor)

    #armazenar circulo
    if booleanos.mapeadorON == False:
        circuloArmazenado = fila.iniciar()
        fila.push(circuloArmazenado,"circulo")
        fila.push(circuloArmazenado,Xc)
        fila.push(circuloArmazenado,Yc)
        fila.push(circuloArmazenado,x)
        fila.push(circuloArmazenado,y)
        fila.push(circuloArmazenado,esp)
        fila.push(circuloArmazenado,cor)
        armazenar(circuloArmazenado)
    booleanos.circuloR = False

def limpador(w):
    w.create_rectangle(0, 0, 1580, 730,fill = 'gray93')
    limparA = fila.iniciar()
    fila.push(limparA,"limpar")
    armazenar(limparA)



def armazenar(item): #pilha de Aswang
    global contador 
    if booleanos.RestauradorB == True:
        fila.push(armazenador,item)
    else:
        if contador == 0:
            pilha.push(armazenador,item)
        else:
            pilha.push(armazenador,item)
            while contador>0:
                armazenador.insert(1,armazenador[len(armazenador)- 1])
                pilha.popUltimo(armazenador)
                contador = contador -1


def restaurador(w,quantidade): #restaura usando os elementos como parametros
    global contador
    while quantidade>0:
        if armazenador[0][0] !="limpar":
            if armazenador[0][0] == "circulo":
                booleanos.circuloR = True
                circulo(armazenador[0][1],armazenador[0][2],armazenador[0][3],armazenador[0][4],w,armazenador[0][5],armazenador[0][6])
                pilha.pop(armazenador)
                quantidade = quantidade -1
            elif armazenador[0][0] == "ponto":
                ponto(armazenador[0][1],armazenador[0][2],w,armazenador[0][3],armazenador[0][4])
                pilha.pop(armazenador)
                quantidade = quantidade -1 
            elif armazenador[0][0] == "linha":
                booleanos.retaR = True
                linha(armazenador[0][1],armazenador[0][2],armazenador[0][3],armazenador[0][4],w,armazenador[0][5],armazenador[0][6])
                pilha.pop(armazenador)
                quantidade = quantidade -1 
            elif armazenador[0][0] == "triangulo":
                TrianguloS(armazenador[0][1],armazenador[0][2],armazenador[0][3],armazenador[0][4],armazenador[0][5],armazenador[0][6],w,armazenador[0][7],armazenador[0][8],armazenador[0][9],True)
                pilha.pop(armazenador)
                quantidade = quantidade -1
            contador = contador + 1
        else:
            pilha.pop(armazenador)



