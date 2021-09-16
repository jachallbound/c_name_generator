# Name Generation with C
C program to generate random 'names': strings of letters with light logic on choosing between vowel or consonant.

Tested only on Linux. 

## Build

```
gcc namer.c -o namer
```

## Information

This is one of the first programs I ever wrote (c. 2017) and its methods for generating random letters are inefficient and strange.
However, its produced names are still interesting to me and the logic for choosing letters is overly complex and
under commented to the point of being indecipherable (and interesting).

Its motivation was to experiment with random generation in C.
Its goal/use was to generate names for video game player characters, specifically rogue-likes where you constantly make new characters.

Any failure condition will exit the program and print !["Rot in shreds."](https://deathhammer.bandcamp.com/track/rot-in-shreds)
(Because I really liked that song at the time.)
