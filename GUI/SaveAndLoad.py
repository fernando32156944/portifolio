import xml.etree.ElementTree as ET
import math
import formaGeometrica
def save():
    FiguraX = ET.Element('Figura')
    L = len(formaGeometrica.armazenador)
    x = 0
    for j in range(len(formaGeometrica.armazenador)):
        if formaGeometrica.armazenador[j][0] == "limpar":
            L = j
    while x < L:
        if formaGeometrica.armazenador[x][0] == "linha":
            
            reta = ET.SubElement(FiguraX,'Reta')
            
            ponto1 = ET.SubElement(reta,'Ponto')
            
            x1 = ET.SubElement(ponto1,'x')
            
            x1porcentagem = formaGeometrica.armazenador[x][1]/1580
            
            x1.text = str(x1porcentagem)
            
            y1 = ET.SubElement(ponto1,'y')

            y1porcentagem = formaGeometrica.armazenador[x][3]/730
            
            y1.text = str(y1porcentagem)
            
            ponto2 = ET.SubElement(reta,'Ponto')
            
            x2 = ET.SubElement(ponto2,'x')

            x2porcentagem = formaGeometrica.armazenador[x][2]/1580
            
            x2.text = str(x2porcentagem)
            
            y2 = ET.SubElement(ponto2,'y')

            y2porcentagem = formaGeometrica.armazenador[x][4]/730
            
            y2.text = str(y2porcentagem)

            cores = ET.SubElement(reta,'Cor')
            
            cor = formaGeometrica.armazenador[x][6]
            
            corSemH = cor.lstrip('#')
            
            RGB = tuple(int(corSemH[i:i+2], 16) for i in (0, 2, 4))
            
            r = ET.SubElement(cores,'R')
            
            r.text = str(RGB[0])
            
            g = ET.SubElement(cores,'G')
            
            g.text = str(RGB[1])
            
            b = ET.SubElement(cores,'B')

            b.text = str(RGB[2])
            
        if formaGeometrica.armazenador[x][0] == "circulo":
            
            circulo = ET.SubElement(FiguraX,'Circulo')

            ponto1C = ET.SubElement(circulo,'Ponto')
            
            x1C = ET.SubElement(ponto1C,'x')
            
            x1Cporcentagem = formaGeometrica.armazenador[x][1]/1580
            
            x1C.text = str(x1Cporcentagem)
            
            y1C = ET.SubElement(ponto1C,'y')

            y1Cporcentagem = formaGeometrica.armazenador[x][2]/730
            
            y1C.text = str(y1Cporcentagem)

            raio = ET.SubElement(circulo,'Raio')

            R2 = (formaGeometrica.armazenador[x][3] - formaGeometrica.armazenador[x][1])**2 + (formaGeometrica.armazenador[x][4] - formaGeometrica.armazenador[x][2])**2

            R = math.sqrt(R2)

            Rfinal = R/1580

            raio.text = str(Rfinal)

            coresC = ET.SubElement(circulo,'Cor')
            
            corC = formaGeometrica.armazenador[x][6]
            
            corSemHC = corC.lstrip('#')
            
            RGBC = tuple(int(corSemHC[i:i+2], 16) for i in (0, 2, 4))
            
            rC = ET.SubElement(coresC,'R')
            
            rC.text = str(RGBC[0])
            
            gC = ET.SubElement(coresC,'G')
            
            gC.text = str(RGBC[1])
            
            bC = ET.SubElement(coresC,'B')

            bC.text = str(RGBC[2])
            
        x = x + 1
        
    tree = ET.ElementTree(FiguraX)
    tree.write('Save.xml')

    
def load(nome,w):
    tree = ET.parse(nome)
    root = tree.getroot()
    for p in range(len(root)):
        if root[p].tag == 'Circulo':
            RGB = list( )
            interio = int(root[p][2][0].text)
            interio2 = int(root[p][2][1].text)
            interio3 = int(root[p][2][2].text)
            RGB.append(interio)
            RGB.append(interio2)
            RGB.append(interio3)
            RGB = tuple(RGB)
            NovaCor = '#%02x%02x%02x' % RGB
            XC = float((root[p][0][0].text))*1580
            NovoXC = int(XC)
            YC = float((root[p][0][1].text))*730
            NovoYC = int(YC)
            raios = float(root[p][1].text)*1580
            x = raios+XC
            Novox = int(x)
            formaGeometrica.circulo(NovoXC,NovoYC,Novox,YC,w,5,NovaCor)
        if root[p].tag == 'Reta':
            RGB = list( )
            interio = int(root[p][2][0].text)
            interio2 = int(root[p][2][1].text)
            interio3 = int(root[p][2][2].text)
            RGB.append(interio)
            RGB.append(interio2)
            RGB.append(interio3)
            RGB = tuple(RGB)
            NovaCor = '#%02x%02x%02x' % RGB
            x1 = float((root[p][0][0].text))*1580
            NovoX1 = int(x1)
            y1 =float((root[p][0][1].text))*730
            NovoY1 = int(y1)
            x2 = float((root[p][1][0].text))*1580
            NovoX2 = int(x2)
            y2 = float((root[p][1][1].text))*730
            NovoY2 = int(y2)
            formaGeometrica.linha(NovoX1,NovoX2,NovoY1,NovoY2,w,5,NovaCor)
            


