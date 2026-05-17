# CHECKPOINT-EDGE-COMPUTING-VINHERIA-AGNELLO


Sistema de Monitoramento de Luminosidade, Temperatura e Umidade - Vinheria Agnello

Este projeto consiste em um sistema de monitoramento de luz ambiente desenvolvido para a Vinheria Agnello. Utilizando um microcontrolador Arduino e um sensor LDR, o sistema visa proteger os vinhos contra a exposição excessiva à luminosidade, que pode degradar a qualidade e o sabor do produto.
Na segunda etapa do projeto, o sistema foi expandido com a adição do sensor DHT11 e de um display LCD, permitindo também o monitoramento da temperatura e da umidade do ambiente em tempo real.

Tinkercad 1: https://www.tinkercad.com/things/cj0rKRjhNSL-brilliant-duup/editel?returnTo=%2Fthings%2Fcj0rKRjhNSL-brilliant-duup&sharecode=uIT6OYqQ6MeOwGfKARA3Tb-BJ5CffZTDMgfNKaBSkIs

Video apresentação 1: https://youtu.be/GsBgG1j2-8A?si=IkrNyRm6ifwsCfDr

Wokwi 2: https://wokwi.com/projects/464028857753056257

Video apresentação 2: https://youtu.be/32C6PoGZkLk

---

Funcionalidades

O sistema realiza a leitura contínua dos dados de luz, temperatura e umidade do ambiente e indica o estado atual por meio de alertas visuais, sonoros e mensagens exibidas no display LCD.

| **Adequado** | 🟢 LED Verde - A luminosidade está dentro dos padrões seguros para os vinhos.

| **Alerta** | 🟡 LED Amarelo - A luz está aumentando e requer atenção preventiva. 

| **Crítico** | 🔴 LED Vermelho - 🔊 Buzzer (3 segundos) | Risco aos produtos. O alarme sonoro é disparado para notificação imediata dos funcionários.

Além dos LEDs e do buzzer, o display LCD irá apresentar mensagens como:

- SISTEMA OK
- ALERTA TEMP
- ALTA UMIDADE
- ALERTA LUZ

---

Monitoramento de Temperatura

O sensor DHT11 foi implementado para realizar a leitura da temperatura do ambiente.
- Acima de 24°C → “Temperatura Alta”
- Acima de 20°C → LCD exibe “Temperatura média”
- Abaixo de 20°C → LCD exibe “Temperatura Ok”

Quando a temperatura sai da faixa ideal:
🟡 LED Amarelo é acionado
🔊 Buzzer permanece ligado continuamente

---

Monitoramento de Umidade

O sistema também monitora a umidade do ambiente utilizando o sensor DHT11.
- Entre 50% e 70% → Umidade ideal
- Acima de 70% → LCD exibe “Umidade Alta”
- Abaixo de 50% → LCD exibe “Umidade Baixa”

Quando a umidade sai da faixa ideal:
🔴 LED Vermelho é acionado
🔊 Buzzer permanece ligado continuamente

---

Display LCD

Foi adicionado um display LCD para facilitar a visualização dos dados do ambiente em tempo real.

O LCD exibe:
- Temperatura;
- Umidade;
- Estado da luminosidade;
- Mensagens de alerta;
- Condições do ambiente.

---

Hardware Necessário

Para a montagem deste protótipo, foram utilizados os seguintes componentes eletrônicos:

- 1x Placa Arduino (Uno, Nano ou equivalente)
- 1x Sensor de Luminosidade (LDR)
- 1x Sensor DHT11
- 1x Display LCD 16x2
- 1x LED Verde
- 1x LED Amarelo
- 1x LED Vermelho
- 1x Buzzer
- 1x Protoboard
- Cabos Jumper

---

Soluções Técnicas e Lógica de Programação

O maior desafio durante a implementação deste projeto foi o desenvolvimento do código, especificamente a lógica de controle de tempo e o monitoramento simultâneo dos sensores. 

Para que o buzzer fosse acionado corretamente sem interromper o funcionamento do sistema, evitou-se o uso da função padrão delay(). O uso dessa função travaria o processamento do Arduino, impedindo que o sistema continuasse lendo os sensores durante o acionamento do alarme.

**A Solução**: Implementamos uma rotina não-bloqueante utilizando a função millis(). Com isso, o Arduino consegue registrar o tempo de ativação do buzzer em segundo plano, monitorar a temperatura e a umidade através do sensor DHT11, atualizar o display LCD continuamente e permitir que o sensor LDR continue realizando a leitura dos dados do ambiente de forma contínua e ininterrupta.
Além disso, foi utilizada a biblioteca do sensor DHT11 para facilitar a leitura dos valores de temperatura e umidade, tornando o sistema mais organizado e eficiente.

---

Como Executar

1. Montagem do Circuito: Conecte o sensor LDR a uma porta analógica do Arduino (ex: A0). Conecte o sensor DHT11 a um pino digital configurado no código. Em seguida, conecte os LEDs, o buzzer e o display LCD aos respectivos pinos definidos no projeto.
2. Software: Instale a [Arduino IDE](https://www.arduino.cc/en/software) em seu computador. Também será necessário instalar as bibliotecas do sensor DHT11 e do display LCD pela própria IDE.
3. Upload: Abra o arquivo de código (`.ino`) deste repositório na IDE, conecte sua placa Arduino via USB e faça o upload do código.
4. Testes: Para validar o funcionamento, utilize a lanterna de um smartphone para variar a intensidade de luz sobre o sensor LDR e altere os valores do sensor DHT11 no simulador. Observe as mudanças de estado dos LEDs, o acionamento do buzzer e as informações exibidas no display LCD. Você também pode acompanhar os valores lidos pelos sensores abrindo o Monitor Serial na IDE.

---

Melhorias Implementadas no CP2

- Implementação do sensor DHT11;
- Monitoramento de temperatura;
- Monitoramento de umidade;
- Integração com display LCD;
- Exibição de mensagens em tempo real;
- Alertas para condições críticas de temperatura e umidade.

---

Equipe Desenvolvedora

* Augusto Torin
* Fabricio Mendoza
* Felipe Peres
* Julia da Silva
* Thiago Silva

*Projeto desenvolvido como requisito de avaliação acadêmica.*
