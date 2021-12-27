English:

# Pacman, version 1.0
### Made by: Jan Fojtík

Simple game made in the SDL2 library.
The game is completely made in C.

## Compilation and launching of the game

The game requires the SDL2, SDL2_image, SDL2_ttf and SDL2_mixer library.

```sh
cd Pacman
make
./pacman
```

## Map:
- if you want to change the map edit the file map1.txt
- resolution of the map is 34x21 chars

## Loading of the map

### Map marking:
- P - spawnpoint of Pacman
- W - wall sign
- C - cherry sign (special buff lasting 15 seconds allowing you to eat ghosts)
- '-' point sign

### Ghosts
- 1 - Blinky spawnpoint
- 2 - Inky spawnpoint
- 3 - Pinky spawnpoint
- 4 - Clyde spawnpoint

# Game operations
### Pacman movement:
- Pacman is controlled with the arrow keys
- pressing an arrow key changes the direction of Pacman
- Pacman can't walk through walls or doors and into the center cell, where the ghost spawnpoints are located (see original map)

### Score:
- points are worth 10 points
- cherries are worth 200 points and it also provides a buff to eat ghosts lasting 15 seconds
- catching a ghost is worth 500 points

### Catching Pacman:
- the player has 3 lives in the beginning
- if the ghosts catch Pacman, then the player takes 1 life and the positions of Pacman and the ghosts are reset

### Game Over:
- if the player runs out of lives the game ends and the Game Over screen appears
- if the player collects all the points on the map the game ends and the Winning screen appears
- pressing the R key restarts the game
- pressing the Q key quits the game

### Developer options:
- pressing the G key forces Game Over
- pressing the H key forces the Win


Czech:

# Pacman, version 1.0
### Made by: Jan Fojtík

Jednoduchá hra udělaná v knihovně SDL2.
Hra je kompletně udělaná v jazyce C

## Kompilace a spuštění hry

Hra vyžaduje knihovnu SDL2, SDL2_image, SDL2_ttf a SDL2_mixer.

Pokud chcete spustit hru na operačním systému Windows, musíte si knihovny SDL2 doinstalovat, na Linuxu/Macu jsou knihovny propojeny automaticky


```sh
cd Pacman
make
./pacman
```

## Mapa:
- pro změnu mapy upravte soubor map1.txt
- rozměry mapy jsou 34x21 charakterů

## Načítání mapy

### Značení mapy:
- P - spawnpoint Pacmana
- W - značka zdi
- C - značka třešně (speciální buff trvající 15 vteřin umožňující sníst duchy)
- '-' Značka bodu
### Duchové:
- 1 - spawnpoint ducha Blinky
- 2 - spawnpoint ducha Inky
- 3 - spawnpoint ducha Pinky
- 4 - spawnpoint ducha Clyde

# Průběh hry
### Pohyb Pacmana po mapě:
- Pacman se ovládá pomocí šipek
- stisknutí šipky změní směr Pacmana
- Pacman nemůže procházet zdmi ani dveřmi a do středové buňky, kde se nachází spawnpointy duchů (viz. originální mapa)

### Score:
- sebrání bodu je za 10 bodů
- sebrání třešně je za 200 bodů a zároveň poskytuje buff umožňující sníst duchy trvající 15 vteřin
- chycení ducha je za 500 bodů

### Chycení Pacmana:
- hráč má ze začátku 3 životy
- pokud duchové chytí Pacmana, když není powered tak se hráči ubere 1 život a pozice Pacmana a duchů se vyresetují

### Konec Hry:
- pokud hráči dojdou životy hra končí a ukáže se Game Over screen
- pokud hráč posbírá všechny body na mapě hra končí a ukáže se Winning screen
- klávesou R se hra restartuje
- klávesou Q se hra ukončí

### Vývojářské možnosti:
- klávesou G vynutíte prohru
- klávesou H vynutíte výhru
