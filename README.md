<h1 align="center">Máquina de refri com arduino</h1>
<h2 align="center">Projeto de máquina de refri utilizando arduino</h2>

<p align="center">
  <img loading="lazy" src="http://img.shields.io/static/v1?label=STATUS&message=EM%20DESENVOLVIMENTO&color=red&style=for-the-badge"/>
</p>

## ❓ Do que se trata o projeto?
- Projeto de uma máquina de refrigerante utilizando duas bombas d'água para arduino e o próprio arduino para controle das funções. O projeto foi feito como desafio para ser apresentado na Feivest da Universidade Tiradentes (UNIT) com o intuito de demonstrar a versatilidade do arduino, seus diversos usos e sensores.

## ⚙️ Materiais utilizados
- 1x Arduino UNO
- 2x Bomba d'água para arduino RS-385
- 2x Módulo relé
- 2x Push button
- 1x Fonte chaveada
- 1x Placa universal de cobre
- Protoboard para prototipagem
- Jumpers para prototipagem

## 💻 Funcionamento do Projeto
- Descrição do código
  1. Importando as bibliotecas
  ```cpp
    #include <LiquidCrystal_I2C.h>
    #include <Wire.h>
  ```
    - A biblioteca LiquidCrystal_I2C é necessária para utilizarmos o display LCD com o módulo I2C, ja o Wire serve para o arduino conversar com o módulo I2C do display
  2. Declarando as variáveis
    ```cpp
      const int buttonPin1 = 1; // botao para a primeira bomba
      const int buttonPin2 = 2; // botao para a segunda bomba
      const int rele1Pin = 6; // rele que ativa oa primeria bomba
      const int rele2Pin = 5; // rele que ativa a segunda bomba
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
    ```
    - Lembrando que as variáveis foram definidas com base nas portas utilizadas no arduino, caso você mude as portas no seu projeto, deve alterar elas aqui também
  3. Setup do projeto
    ```cpp
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
    ```
  4. Loop principal do código
     ```cpp
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
            ligaDesligaComTimer(rele1Pin);
          }

          if(button2State == LOW) // verifica se o botão 2 foi apertado
          {
            ligaDesligaComTimer(rele2Pin);
          }
        }
     ```
    5. Funções Auxiliares
       ```cpp
        // Função que liga e desliga as bombas com um timer
       
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
       ```
       ```cpp
        // liga e desliga as bombas, porem sem timer
       
        void ligaDesliga(int relePin)
        {
          digitalWrite(relePin, LOW); // liga o relé
          digitalWrite(relePin, HIGH); // desliga o relé
        }
       ```
       ```cpp
        // função que cria um contador de 2 segundos, enquanto enche uma barrinha usando o custom char criado anteriormente
       
        void contador()
        {
          for (int i = 0; i < 16; i++){
           lcd.setCursor(i, 1); // define o cursor para a linha 1 e a coluna i, que varia dependendo da posição do i no loop for
           lcd.write(1); // escreve o custom char
           delay(125); // aguarda 125 milissegundos
          }
        }
       ```
       - ⚠️ Aviso ⚠️
       - O código atual pode funcionar tanto com o timer quanto sem ele, basta trocar a função no void loop. Porém, ao trocar para o modo sem timer, o display não funcionará durante a execução das bombas
         
- Montagem do arduino
  - O protótipo do projeto foi feito no tinkercad. Porém, por falta dos materiais utilizados no projeto no tinkercad, foram feitas algumas alterações
    * [Link do Tinkercad](https://www.tinkercad.com/things/eKNAdw7JYok-maquinaderefriprojeto2/editel)
    * Diferenças:
      * pela falta de relés e bombas na plataforma, foram utilizados leds, então certos status como LOW e HIGH ou alguns outros pequenos detalhes foram modificados
  - Descrição da montagem oficial:
    - Lembrando que essa montagem oficial será feita na placa de prototipagem ainda, sem nada de solda
    ### Arduino
      - Primeiramente, conectaremos o arduino a protoboard, para energizar ela, colocamos um jumper entre a entrada 5v e o positivo na protoboard e outro entre o GND e o negativo na protoboard
    ### Bombas dágua
      - Para Conectar as bombas dágua aos relés e ao arduino, basta seguir o guia do seguinte site e seguir o padrão de pinagem utilizado no código -> [Link para montagem da bomba dágua](https://curtocircuito.com.br/blog/Categoria%20Arduino/como-usar-a-bomba-de-agua-diafragma)
      - Para ligar os relés, ligaremos o VCC no positivo da protoboard, o GND no negativo e o IN na porta selecionada do arduino
    ### Botões
      - Para evitar conexões indesejadas, conecte os botões no meio da placa, assim como mostrado no tinkercad.
      - Em um dos lados, conectaremos uma das perninhas do botão a um resistor de 10kΩ, que estará ligado no positivo da protoboard e a outra perninha conectaremos ao negativo
      - Do outro lado, conectaremos a perninha que está do lado oposto do resistor na porta do arduino
      - Em caso de duvidas de como ligar os botões, olhar o esquema do tinkercad
    ### Display LCD com I2C
      - recomendo o uso desse tipo de display para reduzir a quantidade de fios utilizados
      - Primeiramente, liga o pino GND do display no negativo da protoboard e o VCC no positivo
      - Após isso, Ligamos o SDA e o SCL em duas entradas analógicas do arduino, no meu caso, as escolhidas foram a A4 e A5
      - Em caso de duvidas, verificar o modelo do tinkercad
  - Video da montagem do projeto
    * 🚧 Em breve 🚧
    
