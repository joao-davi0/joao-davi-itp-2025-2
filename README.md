# Introdução a Técnicas de Programação - Unidades 1 e 2
- **Aluno**: João Davi dos Santos Araújo
- **Matrícula**: 20250039243
- **Período**: 2025.2

## 📁 Estrutura do Projeto

- `projeto/`: Projeto principal da unidade
- `listas/`: Soluções das listas de exercícios
- `README.md`: Este arquivo

## 🚀 Projeto: Jogo de Campo Minado (versão texto)

**Descrição**: Jogo textual de Campo Minado em C no qual o jogador revela posições e marca possíveis posições perigosas em um tabuleiro 5x5 tentando evitar minas ocultas, aplicando lógica e estratégia para vencer.

**Repositório**: https://github.com/joao-davi0/joao-davi-itp-2025-2/

### Funcionalidades Implementadas:
- Geração aleatória de minas;
- Tabuleiro 5x5;
- Exibição e atualização do campo;
- Leitura e validação das jogadas;
- Verificação de vitória ou derrota;
- Uso de bandeiras para marcação de possíveis minas;
- Uso de strings para leitura do nome do jogador;
- Alocação dinâmica de matrizes com uso de ponteiros;
- Interface de linha de comando (CLI).

### Conceitos da U1 Aplicados:
- **Estruturas condicionais**: usadas para verificar se o jogador acertou uma mina, venceu o jogo ou informou uma posição inválida.
- **Estruturas de repetição**: aplicadas nos loops de geração do campo, posicionamento das minas e execução das jogadas até o fim da partida.
- **Vetores**: utilizados para representar o campo e as posições reveladas.
- **Funções**: quatro funções principais — uma para gerar o campo, uma para imprimir, uma para processar jogadas e a função `main()` que coordena o jogo.

### Conceitos da U2 Aplicados:
- **Strings**: usadas para ler e tratar o nome do jogador.
- **Repetições aninhadas**: aplicadas na inicialização do campo, no cálculo de minas vizinhas e na impressão da matriz.
- **Matrizes**: representaram o estado de jogo (campo, revelação de posições e bandeiras.
- **Ponteiros e alocação dinâmica**: usados para alocar dinamicamente as matrizes com malloc e liberar memória corretamente.

## 📚 Listas de Exercícios

### Semana 2 - Variáveis, Tipos e Operadores:
- ✅ Problema 1: Calculadora de IMC
- ✅ Problema 2: Conversão de temperatura
- ✅ Problema 3: Cálculo de juros compostos
- ✅ Problema 4: Operações aritméticas básicas

### Semana 3 - Condicionais:
- ✅ Problema 1: Classificação de IMC
- ✅ Problema 2: Calculadora de energia elétrica
- ✅ Problema 3: Sistema de notas
- ✅ Problema 4: Pedra, papel, tesoura
- ✅ Problema 5: Calculadora de desconto progressivo
- ✅ Problema 6: Diagnóstico médico simples
- ✅ Problema 7: Sistema de equações do 2º grau
- ✅ Problema 8: Validador de triângulos

### Semana 4A - Repetições:
- ✅ Problema 1: Dobrar folha
- ✅ Problema 2: Homem Aranha
- ✅ Problema 3: Números colegas
- ✅ Problema 4: Jogo de dardos

### Semana 5 - Funções (Parte 1):
- ✅ Problema 1: Horários das rondas
- ✅ Problema 2: Primos triplos

### Semana 6 - Vetores:
- ✅ Problema 1: MEC - Correção ENEM
- ✅ Problema 2: Álbum de figurinhas
- ✅ Problema 3: A construção da ponte
- ✅ Problema 4: Em busca do tesouro perdido

### Semana 7 - Strings:
- ✅ Problema 1: Campo minado 1D
- ✅ Problema 2: Detecção de placas
- ✅ Problema 3: OpenMeet

### Semana 8 - Repetições aninhadas
- ✅ Problema 1: Estou com sorte (ou não)
- ✅ Problema 2: Os dias mais chuvosos
- ✅ Problema 3: Esse sim é piloto

### Semana 9 - Matrizes
- ✅ Problema 1: Campo agrícola
- ✅ Problema 2: Sugestão de amigos
- ✅ Problema 3: Campeonato de empates
- ✅ Problema 4: Uma pechincha!

### Semana 10 - Ponteiros e alocação dinâmica
- ✅ Problema 1: Soma de vetores
- ✅ Problema 2: Ocorrências no vetor
- ✅ Problema 3: Sopa de letrinhas

## 🎯 Principais Aprendizados
O desenvolvimento do Campo Minado permitiu consolidar os conceitos iniciais da linguagem C. Foi possível compreender melhor o uso de matrizes, o funcionamento de loops e condicionais e a importância da organização modular. Após a U2, foi possível implementar alocação dinâmica com uso de ponteiros e usar strings para personalizar o jogo, além de reforçar os conhecimentos anteriores e ver a importância do uso correto da memória.

## 🔧 Ambiente de Desenvolvimento
- **SO**: Windows
- **Compilador**: GCC versão 15.2.0
- **Editor**: VS code
