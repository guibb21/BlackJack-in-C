# LittleBlackJack

A command-line Blackjack game written in C. (made in about 3 hours)

## How it works

The player chooses a bet multiplier (1–10) which scales the number of available cards in the deck. Each card type starts with `4 × bet` copies, simulating multiple decks. The game then deals two cards to both the player and the dealer, hiding the dealer's last card until the player stands.

The player can hit or stand. After standing, the dealer draws until reaching 17 or above, following standard Blackjack rules. Aces are handled dynamically — counted as 11 and reduced to 1 if the hand would bust.

## Concepts used

- Sentinel values to track hand size within fixed-size arrays
- Input validation using `fgets` + `sscanf` to avoid buffer overflow
- Dynamic Ace handling (11 → 1 on bust)
- Deck depletion tracking per card type
- `rand()` seeded with `time()` for randomness

## Compile and run

```
gcc LittleBlackJack.c -o blackjack
./blackjack
```

## Environment

Developed on Linux. The `eject` command at game over opens the CD tray — harmless on machines without one.
