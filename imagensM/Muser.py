from skimage import io,util
from skimage.color import rgb2gray
from matplotlib import pyplot as plt
from skimage.filters import threshold_otsu,threshold_multiotsu
import tkinter as tk
from tkinter import simpledialog
import numpy as np


def carregar():
    return simpledialog.askstring("Input", 'nome')

def preto(x):
    imagem = io.imread(x)

    cinza = rgb2gray(imagem)

    thresh =  threshold_otsu(cinza)

    binary = cinza > thresh

    io.imshow(binary, cmap = plt.cm.gray)

    plt.axis('off')

    plt.show()

def cinza(x):
    imagem = io.imread(x)

    cinza = rgb2gray(imagem)

    io.imshow(cinza)

    plt.axis('off')

    plt.show()

def histograma(c,x):
    imagem = io.imread(x)
    cinza = rgb2gray(imagem)
    thresh1 =  threshold_otsu(cinza)
    inverted_img = util.invert(imagem)
    thresholds = threshold_multiotsu(cinza)

    
    
    if(c == 1):
        ax = plt.hist(cinza.ravel(), bins = 256)
        ax = plt.axvline(thresh1, color='r')
        
        plt.show()

    elif(c == 2):
        ax = plt.hist(cinza.ravel(), bins = 256)

        plt.show()

    elif(c == 3):
        ax = plt.hist(inverted_img.ravel(), bins = 256)

        plt.show()
        
    elif(c == 4):
        ax = plt.hist(cinza.ravel(), bins = 255)
        for thresh in thresholds:
            ax = plt.axvline(thresh, color='r')
        
        plt.show()
        
    elif(c == 5):
        ax = plt.hist(imagem.ravel(), bins = 256)

        plt.show()

    else:
        ax = plt.hist(imagem.ravel(), bins = 256)
        plt.show()

def inverter(x):
    imagem = io.imread(x)
    inverted_img = util.invert(imagem)
    io.imshow(inverted_img)
    plt.axis('off')
    plt.show()

def lsd(x):
    imagem = io.imread(x)
    cinza = rgb2gray(imagem)
    thresholds = threshold_multiotsu(cinza)
    regions = np.digitize(cinza, bins=thresholds)
    plt.axis('off')
    io.imshow(regions, cmap='jet')

    plt.show()
    
def original(x):
    imagem = io.imread(x)

    io.imshow(imagem)

    plt.axis('off')

    plt.show()


    
