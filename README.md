**English** | [العربية](README.ar.md)

# Rock Paper Scissors — C++ Console Game 🪨📄✂️

A console Rock-Paper-Scissors game where you play against the computer, built in C++ with a clean **Divide & Conquer** 

> Project 1 of **Algorithms & Problem-Solving Level 2** (Course 5 of Dr. Mohammed Abu-Hadhoud's programming roadmap).

## Features

- Play 1 to 10 rounds against the computer (with full input validation)
- Round-by-round results with colored output (green = you win, red = computer wins, yellow = draw)
- Sound alert when the computer wins a round (Linux)
- Final scoreboard: wins, losses, draws, and the overall winner
- Play again without restarting the program

## Sample Gameplay

```
How many rounds do you want [1 to 10]? 3

____________ Round[1] ____________
Your Choice [1]: Stone, [2]: Paper, [3]: Scissors ? 2
Player1 Choice : Paper
Computer Choice : Stone
Round Winner : [ Player1 ]

...

____________ [ Game Results ] ____________
Game Round : 3
Player1 won times : 2
Computer won times : 1
Draw times : 0
Final Winner : [ Player1 ]

Do you want to play again y/n ?
```

## Code Structure — Divide & Conquer

Every function is focused on a single responsibility:

| Function | Responsibility |
|---|---|
| `ReadNumberOfRound()` | Ask for number of rounds and validate it (1–10) |
| `UserChoice()` | Read and validate the player's choice |
| `RandomNumber(From, To)` | Generate a random number in a range |
| `ComputerChoice()` | Pick the computer's move |
| `PlayRound()` | Play one full round and update the scores |
| `GetChoiceName()` | Convert a choice enum to readable text |
| `PlayGameRounds()` | Run all rounds and show each round's result |
| `PrintFinalResults()` | Print the final scoreboard and overall winner |
| `StartGame()` | Full game loop with the play-again option |

The game state (scores and last choices) lives in one `struct` passed by reference — no global variables.

## Build & Run

```bash
g++ main.cpp -o rps
./rps
```

> **Note:** screen clearing and the sound alert use Linux commands (`clear`, `speaker-test`). On Windows, replace `system("clear")` with `system("cls")` and remove the sound line — or use the `#ifdef _WIN32` guard.

## What I Practiced

- Breaking a program into single-responsibility functions (Divide & Conquer)
- `enum` + `struct` to model game state cleanly
- Passing state by reference instead of using globals
- Input validation with `do...while` loops
- Implementing ANSI escape codes for colored output and sound feedback

## Author

**Ahmad Slik** — self-taught developer building in public.

- LinkedIn: [linkedin.com/in/ahmad-slik-99661840b](https://www.linkedin.com/in/ahmad-slik-99661840b)
- Portfolio: [ahmadslik.netlify.app](https://ahmadslik.netlify.app)
- GitHub: [github.com/AhmadSlik](https://github.com/AhmadSlik)
