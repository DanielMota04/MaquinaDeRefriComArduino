const int buttonPin1 = 1; // botao do primeiro refri
const int buttonPin2 = 2; // botao do segundo refri
const int rele1Pin = 7; // rele que ativa o primeiro motor
const int rele2Pin = 8; // rele que ativa o segundo motor
int button1State = 0; 
int button2State = 0;


void setup()
{
 pinMode(rele1Pin, OUTPUT); // define o primeiro relé como saída
 pinMode(rele2Pin, OUTPUT); // define o segundo relé como saída 
 pinMode(buttonPin1, INPUT); // define o primeiro botao como entrada
 pinMode(buttonPin2, INPUT); // define o segundo botao como entrada
}

void loop()
{
  button1State = digitalRead(buttonPin1); // define o estado do botao 1 como ligado ou desligado
  button2State = digitalRead(buttonPin2); // define o estado do botao 2 como ligado ou desligado

  if(button1State == HIGH) // verifica se o botao 1 foi apertado
  {
    ligaDesliga(rele1Pin);
  }

  if(button2State == HIGH) // verifica se o botão 2 foi apertado
  {
    ligaDesliga(rele2Pin);
  }
}

void ligaDesliga(int relePin)
{
    digitalWrite(relePin, HIGH); // liga o 1 relé
    delay(3000); // conta 3 segundos
    digitalWrite(relePin, LOW); // desliga o 1 relé
}
