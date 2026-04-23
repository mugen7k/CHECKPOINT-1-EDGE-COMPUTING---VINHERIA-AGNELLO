# CHECKPOINT-1-EDGE-COMPUTING---VINHERIA-AGNELLO


Sistema de Monitoramento de Luminosidade - Vinheria Agnello

Este projeto consiste em um sistema de monitoramento de luz ambiente desenvolvido para a Vinheria Agnello. Utilizando um microcontrolador Arduino e um sensor LDR, o sistema visa proteger os vinhos contra a exposição excessiva à luminosidade, que pode degradar a qualidade e o sabor do produto.

---

Funcionalidades

O sistema realiza a leitura contínua dos dados de luz do ambiente e indica o estado atual por meio de alertas visuais e sonoros, divididos em três categorias:

| **Adequado** | 🟢 LED Verde - A luminosidade está dentro dos padrões seguros para os vinhos.
| **Alerta** | 🟡 LED Amarelo - A luz está aumentando e requer atenção preventiva. 
| **Crítico** | 🔴 LED Vermelho - 🔊 Buzzer (3 segundos) | Risco aos produtos. O alarme sonoro é disparado para notificação imediata dos funcionários. |

---

Hardware Necessário

Para a montagem deste protótipo, foram utilizados os seguintes componentes eletrônicos:

* 1x Placa Arduino (Uno, Nano ou equivalente)
* 1x Sensor de Luminosidade (LDR)
* 1x LED Verde
* 1x LED Amarelo
* 1x LED Vermelho
* 1x Buzzer
* 1x Resistor de 10kΩ (para o divisor de tensão do LDR)
* 3x Resistores de 220Ω ou 330Ω (para proteção dos LEDs)
* 1x Protoboard
* Cabos Jumper

---

Soluções Técnicas e Lógica de Programação

O maior desafio durante a implementação deste projeto foi o desenvolvimento do código, especificamente a lógica de controle de tempo. 

Para que o buzzer fosse acionado por exatos 3 segundos durante o "Estado Crítico", evitou-se o uso da função padrão `delay()`. O uso dessa função travaria o processamento do Arduino, impedindo que o sistema continuasse lendo a luminosidade do ambiente durante o toque do alarme. 

**A Solução:** Implementamos uma rotina não-bloqueante utilizando a função `millis()`. Com isso, o Arduino consegue registrar o tempo de ativação do buzzer em segundo plano, permitindo que o sensor LDR continue lendo os dados do ambiente de forma contínua e ininterrupta.

---

Como Executar

1. Montagem do Circuito: Conecte o sensor LDR a uma porta analógica do Arduino (ex: `A0`). Conecte os LEDs e o buzzer aos pinos digitais configurados no código.
2. Software: Instale a [Arduino IDE](https://www.arduino.cc/en/software) em seu computador.
3. Upload: Abra o arquivo de código (`.ino`) deste repositório na IDE, conecte sua placa Arduino via USB e faça o upload do código.
4. Testes: Para validar o funcionamento, utilize a lanterna de um smartphone para variar a intensidade de luz sobre o sensor LDR e observe as mudanças de estado dos LEDs e o acionamento do buzzer. Você também pode acompanhar os valores brutos lidos pelo sensor abrindo o **Monitor Serial** na IDE.

---

Equipe Desenvolvedora

* Augusto Torin
* Fabricio Mendoza
* Felipe Peres
* Julia da Silva
* Thiago Silva

*Projeto desenvolvido como requisito de avaliação acadêmica.*
