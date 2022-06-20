int aqu = A4; //porta do sensor de nivel da água
int umi = A0; // portado sensor de umidade
int umi2 = A1; // porta do sensor de umidade 2
const int vibra = 12;// porta do sensor SW-420
int led = 7;//porta do LED 
int led2 = 8;// porta do LED 2
int buzzer = 5;// porta do buzzer
const int bot1 = 1;// pota do botão 1
const int bot2 = 2;// porta do botão 2

void pisca() // função do alarme 
{
  tone(buzzer,10);// liga o buzzer 
  digitalWrite(led, HIGH); //liga LED
  delay(100);// delay 
  digitalWrite(led, LOW);// desliga o LED
  delay(100);// delay
}  

int inf = 0; // valor da varivel inf 
int botEst1 = 0;  // estado do botão 1
int botEst2 = 0; // estado do botão 2
void setup() 
{
  pinMode(vibra, INPUT); //input do sensor SW-420
  pinMode(led, OUTPUT); // output do led
  pinMode(led2, OUTPUT); // output do led 2
  pinMode(buzzer, OUTPUT); // output do buzzer
  pinMode(bot1, INPUT); // input do botão 1
  pinMode(bot2, INPUT);// input do botão 2
}

void loop() {
  botEst1 = digitalRead(bot1); // estado do botão 1
  botEst2 = digitalRead(bot2); // estado do botão 2
  int umiVa = analogRead(umi); // valor do sensor de umidade 
  int umiVa2 = analogRead(umi2); // valor llido do sensor de umidade 2
  int aquVa = analogRead(aqu);// valor lido no sensor de nive da água 

  if(aquVa>100) // se o valor lido pelo sensor de nivel da água for maior que 100 
  {
    while (inf<1) // loop infinito devido ao fato de que o LED deve piscar constatemente mesmo que o sensor cai junto com a barragem 
    {
      pisca();// chama a fução pisca
    }
  }

  if (umiVa < 400 or umiVa2 < 400)// se o valor lido pelo sensor de umidade ou pelo sensor de umidade 2 for menor que 400
  {
    while(inf<1) // loop infinito devido ao fato de que o LED deve piscar constatemente mesmo que o sensor cai junto com a barragem 
    {
      pisca();// chama a fução pisca
    }
  }

  if (botEst1 == 1) // se o botão 1 for precionado 
  {
    while(inf<1)// loop infinito devido ao fato de que o LED deve piscar constatemente mesmo que o botão não esteja sendo precionado 
    {
      pisca();// chama a fução pisca
    }
   }
   
  if(digitalRead(vibra) == HIGH) // se for detectaddo vibração 
  {
    digitalWrite(led2,HIGH); // liga o LED 2
  }
  
  if (botEst2 == 1)// se o botão 2 for precionado 
  {
   digitalWrite(led2, LOW);// desliga o LED 
  }
}
