// declaração das variáveis
const int buttonPin1 = 1; // botao do primeiro refri
const int buttonPin2 = 2; // botao do segundo refri
const int rele1Pin = 7; // rele que ativa o primeiro motor
const int rele2Pin = 8; // rele que ativa o segundo motor
int button1State = 0; 
int button2State = 0;

// definindo os pinos de saída e entrada
void setup()
{
 pinMode(rele1Pin, OUTPUT); // define o primeiro relé como saída
 pinMode(rele2Pin, OUTPUT); // define o segundo relé como saída 
 pinMode(buttonPin1, INPUT); // define o primeiro botao como entrada
 pinMode(buttonPin2, INPUT); // define o segundo botao como entrada
 digitalWrite(rele1Pin, HIGH); // inicia o primeiro relé como desligado
 digitalWrite(rele2Pin, HIGH); // inicia o segundo relé como desligado

 
}

// funcionamento do código
void loop()
{
  button1State = digitalRead(buttonPin1); // define o estado do botao 1 como ligado ou desligado
  button2State = digitalRead(buttonPin2); // define o estado do botao 2 como ligado ou desligado

  if(button1State == LOW) // verifica se o botao 1 foi apertado
  {
    ligaDesliga(rele1Pin);
    // ligaDesligaComTimer(rele1pin);
  }

  if(button2State == LOW) // verifica se o botão 2 foi apertado
  {
    ligaDesliga(rele2Pin);
    // ligaDesligaComTimer(rele2pin);
  }
}

// funcao para ligar e desligar o relé
void ligaDesligaComTimer(int relePin)
{
    // Desvantagem: funciona apenas uma bomba por vez
    digitalWrite(relePin, LOW); // liga o relé
    delay(3000); // conta 3 segundos
    digitalWrite(relePin, HIGH); // desliga o relé
}

void ligaDesliga(int relePin)
{
    // Pode rodar as duas bombas simultaneamente
    digitalWrite(relePin, LOW); // liga o relé
    digitalWrite(relePin, HIGH); // desliga o relé
}
