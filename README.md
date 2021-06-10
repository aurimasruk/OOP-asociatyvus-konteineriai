# Asociatyvus konteineriai #

Papildoma OOP užduotis. 
std::string konteinerio, o taip pat ir asociatyvių konteinerių naudojimas.


## Programos veikimo principas ##
Paleidus programą, programa ieško `text.txt` failo savo direktorijoje.

Aptikus tekstinį failą, programa suranda pasikartojančius žodžius tekste ir juos išveda į naują tekstinį failą `output.txt`. Taip pat prie kiekvieno žodžio yra nurodoma, kiek kartų ir kuriose eilutėse yra pasikartojantis žodis.
Tekstiniame faile aptikti URL adresai taip pat yra išvedami į `output.txt` failą.

### Gaunamas rezultatas ###

```
------------------- URL ADRESAI: ------------------------
wikipedia.org/wiki/Vilnius
lt.wikipedia.org/wiki/Vilnius
https://lt.wikipedia.org/wiki/Vilnius

---------------------------------------------------

ZODIS ----------- PASIKARTOJA - EILUTES ---------
.
..
kur               2             13 19 
kuri              4             33 51 75 100 
kurio             2             97 107 
kurioje           2             97 103 
kurios            5             5 25 35 93 100 
labai             2             11 35 
laikotarpio       2             35 67 
legenda           2             17 35 
liepa             2             21 23 
liepos            2             35 81 
lietuva           3             39 43 49 
lietuvoje         8             3 29 35 51 79 100 109 111 
lietuvos          15            1 17 19 29 33 35 41 43 45 55 65 69 97 100 107
..
.
```

### Programos diegimas ir paleidimas ###

* Atsisiųskite vieną programos versijų iš [Releases](https://github.com/aurimasruk/OOP-asociatyvus-konteineriai/releases) aplanko ir ją išarchyvuokite.
* Komandinėje eilutėje įveskite `g++ -o main main.cpp` ir `./main`.
