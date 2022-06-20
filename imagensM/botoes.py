import Muser as u
imagem = 'nada'
contador = 0 #contador para o histograma

def callbackC():
    global imagem
    global contador
    contador = 0
    imagem = u.carregar()
    
def callbackP():
    global imagem
    global contador
    contador = 1
    u.preto(imagem)
    
def callbackCN():
    global imagem
    global contador
    contador = 2
    u.cinza(imagem)

def callbackH():
    global imagem
    global contador
    u.histograma(contador,imagem)

def callbackI():
    global imagem
    global contador
    contador = 3
    u.inverter(imagem)

def callbackLSD():
    global imagem
    global contador
    contador = 4
    u.lsd(imagem)
    
def callbackOG():
    global imagem
    global contador
    contador = 5
    u.original(imagem)
