🃏 Super Trunfo em C – Níveis de Desenvolvimento
🔰 Nível Novato

Neste primeiro nível, o objetivo é aprender a estruturar os dados.
O jogador cadastra duas cartas manualmente (com atributos como população, área, PIB e pontos turísticos) e o programa apenas exibe essas informações organizadas.
➡️ Não há lógica de comparação nem cálculos adicionais.

🧭 Nível Aventureiro

Aqui, o sistema passa a calcular novos atributos automaticamente:

Densidade populacional = População ÷ Área

PIB per capita = PIB ÷ População

O usuário continua cadastrando duas cartas, mas agora o programa exibe também os valores calculados junto com os dados básicos.
➡️ Foco em enriquecer as informações exibidas.

🏆 Nível Mestre

No nível mestre, o jogo ganha a lógica de comparação.
O programa compara as duas cartas em todos os atributos e determina o vencedor:

Para densidade populacional, vence o menor valor.

Para os demais atributos (população, área, PIB, PIB per capita, pontos turísticos), vence o maior valor.
Além disso, é implementado o Super Poder: soma de todos os atributos (com densidade invertida, ou seja, 1 ÷ densidade).
➡️ O jogador descobre qual carta é mais forte de forma completa.

🧙‍♂️ Nível Mestre Avançado (Comparações Interativas)

Nesta fase, o programa adiciona interatividade:

O jogador escolhe quais atributos comparar por meio de menus com switch.

As comparações usam if-else (inclusive aninhados).

Se o jogador escolher dois atributos, o sistema compara ambos, soma os valores e determina a carta vencedora da rodada.
➡️ Aqui o código integra menus dinâmicos, lógica condicional, cálculo e interatividade.
