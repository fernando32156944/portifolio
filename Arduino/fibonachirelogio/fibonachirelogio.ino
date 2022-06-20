int LedMonocromatico = 1;
int LedRgbVermelho1 = 2; 
int LedRgbVerde1 = 3;
int LedRgbAzul1 = 4;
int LedRgbVermelho2 = 5;
int LedRgbVerde2 = 6;
int LedRgbAzul2= 7;
int LedRgbVermelho3 = 8;
int LedRgbVerde3 = 9;
int LedRgbAzul3 = 10;
int LedRgbVermelho5 = 11;
int LedRgbVerde5 = 12;
int LedRgbAzul5 = 13;

void setup() 
{
  pinMode(LedMonocromatico,OUTPUT); //led monocromatico
  pinMode(LedRgbVermelho1,OUTPUT); //Led rgb vermelho 1 
  pinMode(LedRgbVerde1,OUTPUT); //Led rgb verde 1 
  pinMode(LedRgbAzul1,OUTPUT); //Led rgb azul 1 
  pinMode(LedRgbVermelho2,OUTPUT); //Led rgb vermelho 2
  pinMode(LedRgbVerde2,OUTPUT); //Led rgb verde 2
  pinMode(LedRgbAzul2,OUTPUT); //Led rgb azul 2
  pinMode(LedRgbVermelho3,OUTPUT); //Led rgb vermelho 3
  pinMode(LedRgbVerde3,OUTPUT); //Led rgb verde 3
  pinMode(LedRgbAzul3,OUTPUT); //Led rgb azul 3
  pinMode(LedRgbVermelho5,OUTPUT); //Led rgb vermelho 5
  pinMode(LedRgbVerde5,OUTPUT); //Led rgb verde 5
  pinMode(LedRgbAzul5,OUTPUT); //Led rgb azul 5
}
void loop()
{
  delay(5000);// de 0-5
  digitalWrite(LedRgbVerde1, HIGH);
  delay(5000);// de 5-10
  digitalWrite(LedRgbVerde1, LOW);
  digitalWrite(LedRgbVerde2, HIGH);
  delay(5000); // de 10 - 15
  digitalWrite(LedRgbVerde2, LOW);
  digitalWrite(LedRgbVerde3, HIGH);
  delay(5000); // de 15-20
  digitalWrite(LedRgbVerde1, HIGH);
  delay(5000); // de 20-25
  digitalWrite(LedRgbVerde1, LOW);
  digitalWrite(LedRgbVerde3, LOW);
  digitalWrite(LedRgbVerde5, HIGH);
  delay(5000); // de 25-30
  digitalWrite(LedRgbVerde1, HIGH);
  delay(5000); // de 30-35
  digitalWrite(LedRgbVerde1,LOW);
  digitalWrite(LedRgbVerde2,HIGH);
  delay(5000);// de 35-40
  digitalWrite(LedRgbVerde2,LOW);
  digitalWrite(LedRgbVerde3,HIGH);
  delay(5000);// de 40-45
  digitalWrite(LedRgbVerde1,HIGH);
  delay(5000);// de 45-50
  digitalWrite(LedRgbVerde1,LOW);
  digitalWrite(LedRgbVerde2,HIGH);
  delay(5000);// de 50-55
  digitalWrite(LedRgbVerde1,HIGH);
  delay(5000);// de 55-60
  digitalWrite(LedRgbVerde1,LOW);
  digitalWrite(LedRgbVerde2,LOW);
  digitalWrite(LedRgbVerde3,LOW);
  digitalWrite(LedRgbVerde5,LOW);
  digitalWrite(LedMonocromatico, HIGH);
  delay(5000);// 1 hora
  digitalWrite(LedRgbVerde1, HIGH);
  delay(5000);// de 5-10
  digitalWrite(LedRgbVerde1, LOW);
  digitalWrite(LedRgbVerde2, HIGH);
  delay(5000); // de 10 - 15
  digitalWrite(LedRgbVerde2, LOW);
  digitalWrite(LedRgbVerde3, HIGH);
  delay(5000); // de 15-20
  digitalWrite(LedRgbVerde1, HIGH);
  delay(5000); // de 20-25
  digitalWrite(LedRgbVerde1, LOW);
  digitalWrite(LedRgbVerde3, LOW);
  digitalWrite(LedRgbVerde5, HIGH);
  delay(5000); // de 25-30
  digitalWrite(LedRgbVerde1, HIGH);
  delay(5000); // de 30-35
  digitalWrite(LedRgbVerde1,LOW);
  digitalWrite(LedRgbVerde2,HIGH);
  delay(5000);// de 35-40
  digitalWrite(LedRgbVerde2,LOW);
  digitalWrite(LedRgbVerde3,HIGH);
  delay(5000);// de 40-45
  digitalWrite(LedRgbVerde1,HIGH);
  delay(5000);// de 45-50
  digitalWrite(LedRgbVerde1,LOW);
  digitalWrite(LedRgbVerde2,HIGH);
  delay(5000);// de 50-55
  digitalWrite(LedRgbVerde1,HIGH);
  delay(5000);// de 55-60
  digitalWrite(LedRgbVerde1,LOW);
  digitalWrite(LedRgbVerde2,LOW);
  digitalWrite(LedRgbVerde3,LOW);
  digitalWrite(LedRgbVerde5,LOW);
  digitalWrite(LedMonocromatico, LOW);
  digitalWrite(LedRgbVermelho2,HIGH);
  delay(5000); // 2 horas
  digitalWrite(LedRgbVerde1, HIGH);
  delay(5000);// de 5-10
  digitalWrite(LedRgbVerde1, LOW);
  digitalWrite(LedRgbVermelho2, LOW);
  digitalWrite(LedRgbAzul2, HIGH);
  delay(5000); // de 10 - 15
  digitalWrite(LedRgbAzul2, LOW);
  digitalWrite(LedRgbVermelho2, HIGH);
  digitalWrite(LedRgbVerde3, HIGH);
  delay(5000); // de 15-20
  digitalWrite(LedRgbVerde1, HIGH);
  delay(5000); // de 20-25
  digitalWrite(LedRgbVerde1, LOW);
  digitalWrite(LedRgbVerde3, LOW);
  digitalWrite(LedRgbVerde5, HIGH);
  delay(5000); // de 25-30
  digitalWrite(LedRgbVerde1, HIGH);
  delay(5000); // de 30-35
  digitalWrite(LedRgbVerde1,LOW);
  digitalWrite(LedRgbVermelho2, LOW);
  digitalWrite(LedRgbAzul2,HIGH);
  delay(5000);// de 35-40
  digitalWrite(LedRgbAzul2,LOW);
  digitalWrite(LedRgbVermelho2, HIGH);
  digitalWrite(LedRgbVerde3,HIGH);
  delay(5000);// de 40-45
  digitalWrite(LedRgbVerde1,HIGH);
  delay(5000);// de 45-50
  digitalWrite(LedRgbVerde1,LOW);
  digitalWrite(LedRgbVermelho2,LOW);
  digitalWrite(LedRgbAzul2, HIGH);
  delay(5000);// de 50-55
  digitalWrite(LedRgbVerde1,HIGH);
  delay(5000);// de 55-60
  digitalWrite(LedRgbVerde1,LOW);
  digitalWrite(LedRgbAzul2,LOW);
  digitalWrite(LedRgbVerde3,LOW);
  digitalWrite(LedRgbVerde5,LOW);
  digitalWrite(LedRgbVermelho3, HIGH);
  delay(5000); // 3 horas
  digitalWrite(LedRgbVerde1, HIGH);
  delay(5000);// de 5-10
  digitalWrite(LedRgbVerde1, LOW);
  digitalWrite(LedRgbVerde2, HIGH);
  delay(5000); // de 10 - 15
  digitalWrite(LedRgbVerde2, LOW);
  digitalWrite(LedRgbVermelho3, LOW);
  digitalWrite(LedRgbAzul3, HIGH);
  delay(5000); // de 15-20
  digitalWrite(LedRgbVerde1, HIGH);
  delay(5000); // de 20-25
  digitalWrite(LedRgbVerde1, LOW);
  digitalWrite(LedRgbAzul3, LOW);
  digitalWrite(LedRgbVermelho3, HIGH);
  digitalWrite(LedRgbVerde5, HIGH);
  delay(5000); // de 25-30
  digitalWrite(LedRgbVerde1, HIGH);
  delay(5000); // de 30-35
  digitalWrite(LedRgbVerde1,LOW);
  digitalWrite(LedRgbVerde2, HIGH);
  delay(5000);// de 35-40
  digitalWrite(LedRgbVerde2,LOW);
  digitalWrite(LedRgbVermelho3,LOW);
  digitalWrite(LedRgbAzul3, HIGH);
  delay(5000);// de 40-45
  digitalWrite(LedRgbVerde1,HIGH);
  delay(5000);// de 45-50
  digitalWrite(LedRgbVerde1,LOW);
  digitalWrite(LedRgbVerde2,HIGH);
  delay(5000);// de 50-55
  digitalWrite(LedRgbVerde1,HIGH);
  delay(5000);// de 55-60
  digitalWrite(LedRgbVerde1,LOW);
  digitalWrite(LedRgbVerde2,LOW);
  digitalWrite(LedRgbAzul3, LOW);
  digitalWrite(LedRgbVerde5,LOW);
  digitalWrite(LedRgbVermelho3, HIGH);
  digitalWrite(LedMonocromatico, HIGH);
  delay(5000);//4 horas
  digitalWrite(LedRgbVerde1, HIGH);
  delay(5000);// de 5-10
  digitalWrite(LedRgbVerde1, LOW);
  digitalWrite(LedRgbVerde2, HIGH);
  delay(5000); // de 10 - 15
  digitalWrite(LedRgbVerde2, LOW);
  digitalWrite(LedRgbVermelho3, LOW);
  digitalWrite(LedRgbAzul3, HIGH);
  delay(5000); // de 15-20
  digitalWrite(LedRgbVerde1, HIGH);
  delay(5000); // de 20-25
  digitalWrite(LedRgbVerde1, LOW);
  digitalWrite(LedRgbAzul3, LOW);
  digitalWrite(LedRgbVermelho3, HIGH);
  digitalWrite(LedRgbVerde5, HIGH);
  delay(5000); // de 25-30
  digitalWrite(LedRgbVerde1, HIGH);
  delay(5000); // de 30-35
  digitalWrite(LedRgbVerde1,LOW);
  digitalWrite(LedRgbVerde2, HIGH);
  delay(5000);// de 35-40
  digitalWrite(LedRgbVerde2,LOW);
  digitalWrite(LedRgbVermelho3,LOW);
  digitalWrite(LedRgbAzul3, HIGH);
  delay(5000);// de 40-45
  digitalWrite(LedRgbVerde1,HIGH);
  delay(5000);// de 45-50
  digitalWrite(LedRgbVerde1,LOW);
  digitalWrite(LedRgbVerde2,HIGH);
  delay(5000);// de 50-55
  digitalWrite(LedRgbVerde1,HIGH);
  delay(5000);// de 55-60
  digitalWrite(LedRgbVerde1,LOW);
  digitalWrite(LedRgbVerde2,LOW);
  digitalWrite(LedRgbAzul3, LOW);
  digitalWrite(LedRgbVerde5,LOW);
  digitalWrite(LedMonocromatico,LOW);
  digitalWrite(LedRgbVermelho5, HIGH);
  delay(5000);//5 horas
  digitalWrite(LedRgbVerde1, HIGH);
  delay(5000);// de 5-10
  digitalWrite(LedRgbVerde1, LOW);
  digitalWrite(LedRgbVerde2, HIGH);
  delay(5000); // de 10 - 15
  digitalWrite(LedRgbVerde2, LOW);
  digitalWrite(LedRgbVerde3, HIGH);
  delay(5000); // de 15-20
  digitalWrite(LedRgbVerde1, HIGH);
  delay(5000); // de 20-25
  digitalWrite(LedRgbVerde1, LOW);
  digitalWrite(LedRgbVerde3, LOW);
  digitalWrite(LedRgbVermelho5,LOW);
  digitalWrite(LedRgbAzul5, HIGH);
  delay(5000); // de 25-30
  digitalWrite(LedRgbVerde1, HIGH);
  delay(5000); // de 30-35
  digitalWrite(LedRgbVerde1,LOW);
  digitalWrite(LedRgbVerde2, HIGH);
  delay(5000);// de 35-40
  digitalWrite(LedRgbVerde2,LOW);
  digitalWrite(LedRgbVerde3,HIGH);
  delay(5000);// de 40-45
  digitalWrite(LedRgbVerde1,HIGH);
  delay(5000);// de 45-50
  digitalWrite(LedRgbVerde1,LOW);
  digitalWrite(LedRgbVerde2,HIGH);
  delay(5000);// de 50-55
  digitalWrite(LedRgbVerde1,HIGH);
  delay(5000);// de 55-60
  digitalWrite(LedRgbVerde1,LOW);
  digitalWrite(LedRgbVerde2,LOW);
  digitalWrite(LedRgbVerde3, LOW);
  digitalWrite(LedRgbAzul5,LOW);
  digitalWrite(LedRgbVermelho5, HIGH);
  digitalWrite(LedMonocromatico,HIGH);
  delay(5000);//6 horas
  digitalWrite(LedRgbVerde1, HIGH);
  delay(5000);// de 5-10
  digitalWrite(LedRgbVerde1, LOW);
  digitalWrite(LedRgbVerde2, HIGH);
  delay(5000); // de 10 - 15
  digitalWrite(LedRgbVerde2, LOW);
  digitalWrite(LedRgbVerde3, HIGH);
  delay(5000); // de 15-20
  digitalWrite(LedRgbVerde1, HIGH);
  delay(5000); // de 20-25
  digitalWrite(LedRgbVerde1, LOW);
  digitalWrite(LedRgbVerde3, LOW);
  digitalWrite(LedRgbVermelho5,LOW);
  digitalWrite(LedRgbAzul5, HIGH);
  delay(5000); // de 25-30
  digitalWrite(LedRgbVerde1, HIGH);
  delay(5000); // de 30-35
  digitalWrite(LedRgbVerde1,LOW);
  digitalWrite(LedRgbVerde2, HIGH);
  delay(5000);// de 35-40
  digitalWrite(LedRgbVerde2,LOW);
  digitalWrite(LedRgbVerde3,HIGH);
  delay(5000);// de 40-45
  digitalWrite(LedRgbVerde1,HIGH);
  delay(5000);// de 45-50
  digitalWrite(LedRgbVerde1,LOW);
  digitalWrite(LedRgbVerde2,HIGH);
  delay(5000);// de 50-55
  digitalWrite(LedRgbVerde1,HIGH);
  delay(5000);// de 55-60
  digitalWrite(LedRgbVerde1,LOW);
  digitalWrite(LedRgbVerde2,LOW);
  digitalWrite(LedRgbVerde3, LOW);
  digitalWrite(LedRgbAzul5,LOW);
  digitalWrite(LedMonocromatico,LOW);
  digitalWrite(LedRgbVermelho5, HIGH);
  digitalWrite(LedRgbVermelho2, HIGH);
  delay(5000); // 7 horas
  digitalWrite(LedRgbVerde1, HIGH);
  delay(5000);// de 5-10
  digitalWrite(LedRgbVerde1, LOW);
  digitalWrite(LedRgbVermelho2, LOW);
  digitalWrite(LedRgbAzul2, HIGH);
  delay(5000); // de 10 - 15
  digitalWrite(LedRgbAzul2, LOW);
  digitalWrite(LedRgbVermelho2, HIGH);
  digitalWrite(LedRgbVerde3, HIGH);
  delay(5000); // de 15-20
  digitalWrite(LedRgbVerde1, HIGH);
  delay(5000); // de 20-25
  digitalWrite(LedRgbVerde1, LOW);
  digitalWrite(LedRgbVerde3, LOW);
  digitalWrite(LedRgbVermelho5,LOW);
  digitalWrite(LedRgbAzul5, HIGH);
  delay(5000); // de 25-30
  digitalWrite(LedRgbVerde1, HIGH);
  delay(5000); // de 30-35
  digitalWrite(LedRgbVerde1,LOW);
  digitalWrite(LedRgbVermelho2, LOW);
  digitalWrite(LedRgbAzul2, HIGH);
  delay(5000);// de 35-40
  digitalWrite(LedRgbAzul2,LOW);
  digitalWrite(LedRgbVermelho2, HIGH);
  digitalWrite(LedRgbVerde3,HIGH);
  delay(5000);// de 40-45
  digitalWrite(LedRgbVerde1,HIGH);
  delay(5000);// de 45-50
  digitalWrite(LedRgbVerde1,LOW);
  digitalWrite(LedRgbVermelho2, LOW);
  digitalWrite(LedRgbAzul2,HIGH);
  delay(5000);// de 50-55
  digitalWrite(LedRgbVerde1,HIGH);
  delay(5000);// de 55-60
  digitalWrite(LedRgbVerde1,LOW);
  digitalWrite(LedRgbAzul2,LOW);
  digitalWrite(LedRgbVerde3, LOW);
  digitalWrite(LedRgbAzul5,LOW);
  digitalWrite(LedRgbVermelho5, HIGH);
  digitalWrite(LedRgbVermelho3, HIGH);
  delay(5000); // 8 horas
  digitalWrite(LedRgbVerde1, HIGH);
  delay(5000);// de 5-10
  digitalWrite(LedRgbVerde1, LOW);
  digitalWrite(LedRgbVerde2, HIGH);
  delay(5000); // de 10 - 15
  digitalWrite(LedRgbVerde2, LOW);
  digitalWrite(LedRgbVermelho3,LOW);
  digitalWrite(LedRgbAzul3, HIGH);
  delay(5000); // de 15-20
  digitalWrite(LedRgbVerde1, HIGH);
  delay(5000); // de 20-25
  digitalWrite(LedRgbVerde1, LOW);
  digitalWrite(LedRgbAzul3, LOW);
  digitalWrite(LedRgbVermelho3, HIGH);
  digitalWrite(LedRgbVermelho5,LOW);
  digitalWrite(LedRgbAzul5, HIGH);
  delay(5000); // de 25-30
  digitalWrite(LedRgbVerde1, HIGH);
  delay(5000); // de 30-35
  digitalWrite(LedRgbVerde1,LOW);
  digitalWrite(LedRgbVerde2, HIGH);
  delay(5000);// de 35-40
  digitalWrite(LedRgbVerde2,LOW);
  digitalWrite(LedRgbVermelho3,LOW);
  digitalWrite(LedRgbAzul3,HIGH);
  delay(5000);// de 40-45
  digitalWrite(LedRgbVerde1,HIGH);
  delay(5000);// de 45-50
  digitalWrite(LedRgbVerde1,LOW);
  digitalWrite(LedRgbVerde2, HIGH);
  delay(5000);// de 50-55
  digitalWrite(LedRgbVerde1,HIGH);
  delay(5000);// de 55-60
  digitalWrite(LedRgbVerde1,LOW);
  digitalWrite(LedRgbVerde2,LOW);
  digitalWrite(LedRgbAzul3, LOW);
  digitalWrite(LedRgbAzul5,LOW);
  digitalWrite(LedMonocromatico,HIGH);
  digitalWrite(LedRgbVermelho5, HIGH);
  digitalWrite(LedRgbVermelho3, HIGH);
  delay(5000);// 9 horas
  digitalWrite(LedRgbVerde1, HIGH);
  delay(5000);// de 5-10
  digitalWrite(LedRgbVerde1, LOW);
  digitalWrite(LedRgbVerde2, HIGH);
  delay(5000); // de 10 - 15
  digitalWrite(LedRgbVerde2, LOW);
  digitalWrite(LedRgbVermelho3,LOW);
  digitalWrite(LedRgbAzul3, HIGH);
  delay(5000); // de 15-20
  digitalWrite(LedRgbVerde1, HIGH);
  delay(5000); // de 20-25
  digitalWrite(LedRgbVerde1, LOW);
  digitalWrite(LedRgbAzul3, LOW);
  digitalWrite(LedRgbVermelho3, HIGH);
  digitalWrite(LedRgbVermelho5,LOW);
  digitalWrite(LedRgbAzul5, HIGH);
  delay(5000); // de 25-30
  digitalWrite(LedRgbVerde1, HIGH);
  delay(5000); // de 30-35
  digitalWrite(LedRgbVerde1,LOW);
  digitalWrite(LedRgbVerde2, HIGH);
  delay(5000);// de 35-40
  digitalWrite(LedRgbVerde2,LOW);
  digitalWrite(LedRgbVermelho3,LOW);
  digitalWrite(LedRgbAzul3,HIGH);
  delay(5000);// de 40-45
  digitalWrite(LedRgbVerde1,HIGH);
  delay(5000);// de 45-50
  digitalWrite(LedRgbVerde1,LOW);
  digitalWrite(LedRgbVerde2, HIGH);
  delay(5000);// de 50-55
  digitalWrite(LedRgbVerde1,HIGH);
  delay(5000);// de 55-60
  digitalWrite(LedRgbVerde1,LOW);
  digitalWrite(LedRgbVerde2,LOW);
  digitalWrite(LedRgbAzul3, LOW);
  digitalWrite(LedRgbAzul5,LOW);
  digitalWrite(LedMonocromatico,LOW);
  digitalWrite(LedRgbVermelho5, HIGH);
  digitalWrite(LedRgbVermelho3, HIGH);
  digitalWrite(LedRgbVermelho2, HIGH);
  delay(5000); // 10 horas
  digitalWrite(LedRgbVerde1, HIGH);
  delay(5000);// de 5-10
  digitalWrite(LedRgbVerde1, LOW);
  digitalWrite(LedRgbVermelho2, LOW);
  digitalWrite(LedRgbAzul2, HIGH);
  delay(5000); // de 10 - 15
  digitalWrite(LedRgbAzul2, LOW);
  digitalWrite(LedRgbVermelho3,LOW);
  digitalWrite(LedRgbAzul3, HIGH);
  digitalWrite(LedRgbVermelho2, HIGH);
  delay(5000); // de 15-20
  digitalWrite(LedRgbVerde1, HIGH);
  delay(5000); // de 20-25
  digitalWrite(LedRgbVerde1, LOW);
  digitalWrite(LedRgbAzul3, LOW);
  digitalWrite(LedRgbVermelho3, HIGH);
  digitalWrite(LedRgbVermelho5,LOW);
  digitalWrite(LedRgbAzul5, HIGH);
  delay(5000); // de 25-30
  digitalWrite(LedRgbVerde1, HIGH);
  delay(5000); // de 30-35
  digitalWrite(LedRgbVerde1,LOW);
  digitalWrite(LedRgbVermelho2, LOW);
  digitalWrite(LedRgbAzul2, HIGH);
  delay(5000);// de 35-40
  digitalWrite(LedRgbAzul2,LOW);
  digitalWrite(LedRgbVermelho3,LOW);
  digitalWrite(LedRgbAzul3,HIGH);
  digitalWrite(LedRgbVermelho2, HIGH);
  delay(5000);// de 40-45
  digitalWrite(LedRgbVerde1,HIGH);
  delay(5000);// de 45-50
  digitalWrite(LedRgbVerde1,LOW);
  digitalWrite(LedRgbVermelho2, LOW);
  digitalWrite(LedRgbAzul2, HIGH);
  delay(5000);// de 50-55
  digitalWrite(LedRgbVerde1,HIGH);
  delay(5000);// de 55-60
  digitalWrite(LedRgbVerde1,LOW);
  digitalWrite(LedRgbAzul2,LOW);
  digitalWrite(LedRgbAzul3, LOW);
  digitalWrite(LedRgbAzul5,LOW);
  digitalWrite(LedRgbVermelho5, HIGH);
  digitalWrite(LedRgbVermelho3, HIGH);
  digitalWrite(LedRgbVermelho2, HIGH); 
  digitalWrite(LedMonocromatico,HIGH);
  delay(5000);// 11 horas
    digitalWrite(LedRgbVerde1, HIGH);
  delay(5000);// de 5-10
  digitalWrite(LedRgbVerde1, LOW);
  digitalWrite(LedRgbVermelho2, LOW);
  digitalWrite(LedRgbAzul2, HIGH);
  delay(5000); // de 10 - 15
  digitalWrite(LedRgbAzul2, LOW);
  digitalWrite(LedRgbVermelho3,LOW);
  digitalWrite(LedRgbAzul3, HIGH);
  digitalWrite(LedRgbVermelho2, HIGH);
  delay(5000); // de 15-20
  digitalWrite(LedRgbVerde1, HIGH);
  delay(5000); // de 20-25
  digitalWrite(LedRgbVerde1, LOW);
  digitalWrite(LedRgbAzul3, LOW);
  digitalWrite(LedRgbVermelho3, HIGH);
  digitalWrite(LedRgbVermelho5,LOW);
  digitalWrite(LedRgbAzul5, HIGH);
  delay(5000); // de 25-30
  digitalWrite(LedRgbVerde1, HIGH);
  delay(5000); // de 30-35
  digitalWrite(LedRgbVerde1,LOW);
  digitalWrite(LedRgbVermelho2, LOW);
  digitalWrite(LedRgbAzul2, HIGH);
  delay(5000);// de 35-40
  digitalWrite(LedRgbAzul2,LOW);
  digitalWrite(LedRgbVermelho3,LOW);
  digitalWrite(LedRgbAzul3,HIGH);
  digitalWrite(LedRgbVermelho2, HIGH);
  delay(5000);// de 40-45
  digitalWrite(LedRgbVerde1,HIGH);
  delay(5000);// de 45-50
  digitalWrite(LedRgbVerde1,LOW);
  digitalWrite(LedRgbVermelho2, LOW);
  digitalWrite(LedRgbAzul2, HIGH);
  delay(5000);// de 50-55
  digitalWrite(LedRgbVerde1,HIGH);
  delay(5000);// de 55-60
  digitalWrite(LedRgbVerde1,LOW);
  digitalWrite(LedRgbAzul2,LOW);
  digitalWrite(LedRgbAzul3, LOW);
  digitalWrite(LedRgbAzul5,LOW); 
  digitalWrite(LedMonocromatico,LOW);
}
