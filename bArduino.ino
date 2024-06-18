#include <LiquidCrystal_I2C.h>
#include <Wire.h>

// declaração das variáveis
const int buttonPin1 = 1; // botao do primeiro refri
const int buttonPin2 = 2; // botao do segundo refri
const int rele1Pin = 6; // rele que ativa o primeiro motor
const int rele2Pin = 5; // rele que ativa o segundo motor
int button1State = 0; // variavel para definir o estado do botao 1
int button2State = 0; // variavel para definir o estado do botao 2
LiquidCrystal_I2C lcd(0x27,16,2); // cria a variavel do LCD

byte customChar[8] = { // define um caracter personalizado para o contador de tempo
	0b11111,
	0b11111,
	0b11111,
	0b11111,
	0b11111,
	0b11111,
	0b11111,
	0b11111
};


// definindo os pinos de saída e entrada
void setup()
{
 pinMode(rele1Pin, OUTPUT); // define o primeiro relé como saída
 pinMode(rele2Pin, OUTPUT); // define o segundo relé como saída 
 pinMode(buttonPin1, INPUT); // define o primeiro botao como entrada
 pinMode(buttonPin2, INPUT); // define o segundo botao como entrada
 digitalWrite(rele1Pin, HIGH); // inicia o primeiro relé como desligado
 digitalWrite(rele2Pin, HIGH); // inicia o segundo relé como desligado

 lcd.init(); // liga o display lcd
 lcd.createChar(1, customChar); // cria o caracter personalizado
 lcd.backlight(); // liga a backlight do lcd
 lcd.setCursor(4,0); // define o cursor para a coluna 4 e linha 0
 lcd.print("Ligando"); // escreve a mensagem onde o cursor está apontando
 lcd.setCursor(4,1); // define o cursor para a coluna 4 e linha 1
 lcd.print("Maquina"); // escreve a mensagem onde o cursor está apontando
 delay(3000); // aguarda 3000 milissegundos
 lcd.clear(); // limpa o lcd
 
}

// funcionamento do código
void loop()
{
  button1State = digitalRead(buttonPin1); // define o estado do botao 1 como ligado ou desligado
  button2State = digitalRead(buttonPin2); // define o estado do botao 2 como ligado ou desligado

  lcd.setCursor(3,0); // define o cursor para a coluna 3 e linha 0
  lcd.print("Escolha um"); // escreve a mensagem onde o cursor aponta
  lcd.setCursor(2,1); // define o cursor para a coluna 3 e linha 0
  lcd.print("Refrigerante"); // escreve a mensagem onde o cursor aponta

  if(button1State == LOW) // verifica se o botao 1 foi apertado
  {
    // ligaDesliga(rele1Pin);
    ligaDesligaComTimer(rele1Pin);
  }

  if(button2State == LOW) // verifica se o botão 2 foi apertado
  {
    // ligaDesliga(rele2Pin);
    ligaDesligaComTimer(rele2Pin);
  }
}

// funcao para ligar e desligar o relé
void ligaDesligaComTimer(int relePin)
{
    lcd.clear(); // limpa o display
    digitalWrite(relePin, LOW); // liga o relé
    lcd.print("Refri ligado"); // escreve essa mensagem no display
    contador(); // chama a função do contador
    lcd.clear(); // limpa o display
    lcd.print("finalizando!"); // escreve essa mensagem no display
    delay(1500); // aguarda 1500 milissegundos
    digitalWrite(relePin, HIGH); // desliga o relé
    lcd.clear(); // limpa o display
}

void ligaDesliga(int relePin)
{
    digitalWrite(relePin, LOW); // liga o relé
    digitalWrite(relePin, HIGH); // desliga o relé
}

void contador()
{
  // função que cria um contador de 2 segundos, enquanto enche uma barrinha usando o custom char criado anteriormente
  for (int i = 0; i < 16; i++){
   lcd.setCursor(i, 1); // define o cursor para a linha 1 e a coluna i, que varia dependendo da posição do i no loop for
   lcd.write(1); // escreve o custom char
   delay(125); // aguarda 125 milissegundos
  }
}
