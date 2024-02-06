# Tic-Tac-Toe
Simple Tic-Tac-Toe simulation in NxN square with 2 bots, each with its own strategy.

**First bot** strategy is simply putting his sign if sqare is free from left-top corner going from left to right and from top to bottom.  
**Second bot** strategy is putting his sign in a random free place.

**Game rules** are basicly classic tic-tac-toe rules but with larger board. Bot need to place *max(N, 5)* signs in a row or diagonally to win the game.

## Installation
Download game files from github and compile *symulacja.c* file in terminal.

```bash
gcc -Wextra -Werror -o symulacja symulacja.c plansza.c gracz_ze_strategia.c gracz_losowy.c
```

Run *symulacja* with additional argument about board size N 
*(base size of a board is 4x4 square if you don't give any argument)*

```bash
./symulacja N
```

You can go to the next move by just clicking *Enter* on your keyboard.
