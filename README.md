# 🚢 Batalha Naval Simples em C

Este é um mini-projeto de Batalha Naval (Battleship) desenvolvido em linguagem C pura. É um jogo "Jogador vs. Computador" super simples, baseado em texto, que roda no terminal.

## 🌟 Funcionalidades

* **Tabuleiro 5x5:** Um grid simples para facilitar o jogo.
* **Posicionamento Aleatório:** O computador esconde **3 navios** (de 1 posição cada) em locais aleatórios a cada novo jogo.
* **Interface de Terminal:** O jogador "atira" inserindo coordenadas de linha e coluna.
* **Feedback Imediato:** O jogo informa `*** FOGO! ***` (acerto) ou `--- ÁGUA! ---` (erro).
* **Validação de Entradas:** O jogo verifica se o jogador:
    * Digitou coordenadas dentro do tabuleiro (0 a 4).
    * Digitou um local onde já não tenha atirado.
    * Digitou uma entrada válida (números).
* **Condição de Vitória:** O jogo termina quando todos os 3 navios são afundados, e exibe o número total de tentativas.

## ⚙️ Como Compilar e Executar

### Pré-requisitos

* Um compilador C instalado (como `gcc` no Linux/macOS ou `MinGW`/`TDM-GCC` no Windows).

### Compilação

1.  Salve o código-fonte em um arquivo chamado `batalha.c`.
2.  Abra seu terminal (ou Prompt de Comando) e navegue até a pasta onde salvou o arquivo.
3.  Digite o comando de compilação:

    **No Linux/macOS:**
    ```bash
    gcc batalha.c -o batalha
    ```

    **No Windows:**
    ```bash
    gcc batalha.c -o batalha.exe
    ```

### Execução (Como Jogar)

1.  Após compilar, execute o arquivo gerado:

    **No Linux/macOS:**
    ```bash
    ./batalha
    ```

    **No Windows:**
    ```bash
    .\batalha.exe
    ```

2.  Siga as instruções na tela. Digite suas coordenadas no formato `linha coluna` (ex: `2 4`) e pressione Enter.
3.  Afunde todos os navios!
