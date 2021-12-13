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