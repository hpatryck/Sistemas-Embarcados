# Sistemas-Embarcados
Atividades práticas de Sistemas Embarcados usando C para Arduino.

- ATIVIDADE 1 -
  - Tarefa 1:
    a) Faça um código/montagem com um LED e um botão, onde o LED deve acender depois que o botão for acionado 15 vezes. Faça o teste repetidas vezes e cheque se o LED acendeu depois de          exatos 15 pressionamentos do botão.
    b) Implemente o código contador de bouncing e faça a leitura de quantas de um botão ao pressioná-lo. Depois, implemente o debouncing via software e refaça a leitura do botão.

  - Tarefa 2:
    Use a biblioteca servo.h para controlar um servo motor ( este controle em baixo nível é feito usando comandos de PWM, porém com a biblioteca isso é feito com funções simples já em 
    alto nível). Use a função map para indicar a posição do servo entre 0% e 100%.

  - Tarefa 3:
    Use a leitura de um potenciômetro para ajustar o ângulo do servo motor. O valor mínimo do pot deve corresponder ao ângulo mínimo do servo, e o valor máximo do pot deve corresponder       ao ângulo máximo do servo (esse ajuste pode ser feito com a função map).

- ATIVIDADE 2 -
  - Tarefa 1:
    Faça a leitura do sensor acelerômetro MPU-6050 utilizando a biblioteca de i2c <wire.h>. Mostre as leituras no display serial.

  - Tarefa 2:
    Conecte 3 LED’s em uma protoboard (vermelho, amarelo e verde). Usando a leitura do acelerometro em qualquer um dos 3 eixos, acenda o LED verde se a inclinação for pequena (você pode      decidir o valor limite para ser considerado “pequeno”), acenda o LED amarelo para uma inclinação média e acenda o LED vermelho para uma inclinação grande.

  - Tarefa 3:
    Use a leitura do acelerômetro (escolha um dos 3 eixos) para mudar a posição de um servo motor.

- ATIVIDADE 3 -
  https://www.robocore.net/tutoriais/usando-teclado-matricial-com-arduino
  - Tarefa 1:
    Volte no blog da robocore e implemente o projeto de controle de acesso localizado abaixo da primeira implementação do teclado.

  - Tarefa 2:
    Utilize 3 LED’s: um vermelho, um amarelo e um verde. As teclas 1, 2 ou 3 do teclado devem acender o verde, as teclas 4, 5 ou 6 devem acender o amarelo, as teclas 7, 8 ou 9 devem 
    acender o vermelho. A tecla 0 apaga tudo e a tecla * acende tudo.

- ATIVIDADE 4 -
  - Tarefa 1:
    Faça as seguintes operações e mostre o resultado no serial.print:
    a) Converta x = 10 de decimal para binário e faça um deslocamento de 2 bits para a direita.
    b) Converta x = 15 de decimal para binário e faça um deslocamento de 3 bits para a esquerda.
    c) Usando x = 30 e y = 7, calcule o resto da divisão de x por y.
    d) Defina um vetor x qualquer com 4 números inteiros e printe cada elemento do vetor individualmente acessando seus índices.

  - Tarefa 2:
    Usando a ideia de número binário, deslocamento de bits e vetores, use 4 LEDs e 1 botão, de forma que o primeiro LED comece aceso e quando o botão é pressionado, o LED atual apaga e o     próximo LED acende (use a operação de deslocamento de bits em uma variável e use ela para escrita no vetor de LEDs).

  - Tarefa 3:
    Use a mesma estrutura da Tarefa 2 (4 LED’s, 1 botão, acionamento por vetor) e faça o buzzer emitir um sinal sonoro baixo para o LED 1, médio para o LED 2, alto para o LED 3 e muito       alto para o LED 4.

- ATIVIDADE 5 -
  
  - Keypad (teclado matricial)
  - 3 LEDs
  - 1 botão
  - Servo motor
  
  - A tecla 1 do keypad deve acender/apagar o primeiro LED;
  - A tecla 2 faz o mesmo para o segundo LED;
  - A tecla 3 faz o mesmo para o terceiro LED;
  - O botão altera o brilho de todos os LEDs entre um brilho fraco e um brilho forte (LED’s apagados no momento não devem ser acesos);
  - A tecla 4 do keypad ajusta o servo para o ângulo 0°;
  - A tecla 5 do keypad ajusta o servo para o ângulo 90°;
  - A tecla 6 do keypad ajusta o servo para o ângulo 180°;
  - A tecla 7 apaga todos os LEDs;
  - A tecla 8 acende todos os LEDs (no valor de brilho correto);
  - Um serial print deve rodar em paralelo (uso do millis) a cada 1 segundo, mostrando o status de cada LED, o valor do brilho (forte ou fraco) e o ângulo do servo.
 
- ATIVIDADE 6 -

  - 3 LEDs
  - 2 botões
  - Servo motor
  - Acelerômetro
  - Sonar
  - Potenciômetro
 
  Um dos botões deve servir para alternar entre 3 modos de funcionamento, descritos abaixo. Cada LED indica um dos modos como estando ativo, ou seja, o botão deve fazer os LED’s ligarem    alternadamente (apenas LED1, apenas LED2 ou apenas LED3).
  
  - Modo 1: Use a leitura de um dos eixos do acelerômetro para controlar a posição do servo motor.
  - Modo 2: Use a leitura do sonar para controlar a posição do servo motor
  - Modo 3: Use a leitura do potenciômetro para controlar a posição do servo motor
  
  O segundo botão ativa uma interrupção que funciona como uma emergência. Caso seja apertado, todos os LED’s se ligam e o servo não deve ser controlado por nenhum dos dispositivos          acima. Após 3 segundos, o funcionamento retorna ao normal, o LED que estava ligado anteriormente se liga novamente e o servo volta a ser controlado como antes. Um serial print deve       rodar em paralelo (uso do millis) a cada 1 segundo, mostrando qual o modo ativo e o ângulo do servo. Caso a interrupção seja ativada, o serial print deve parar de mostrar as              informações e mostrar a mensagem “INTERRUPÇÃO” apenas uma vez. Após a emergência acabar, o serial print volta à sua operação normal.



