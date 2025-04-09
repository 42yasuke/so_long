# 🎮 so_long

**so_long** est un projet de l'école 42 consistant à créer un petit jeu en 2D avec une vue de dessus à l’aide de la mini-libX (la bibliothèque graphique utilisée à 42). L’objectif : collecter tous les objets, atteindre la sortie et éviter les ennemis éventuels !

## 🎯 Objectif

Développer un jeu simple où un joueur se déplace dans une carte en ramassant des collectibles (`C`), en évitant les murs (`1`), et en atteignant la sortie (`E`) une fois tous les objets récupérés.

## 🧱 Fonctionnalités Principales

- 🧍 Déplacement du joueur avec les touches `W`, `A`, `S`, `D`
- 🧱 Gestion de la carte en `.ber` avec parsing et vérifications
- 🪙 Collecte des objets
- 🚪 Ouverture de la porte uniquement après avoir tout collecté
- ❌ Fermeture correcte du jeu avec `ESC`
- 🐛 Gestion des erreurs de map : murs fermés, forme rectangulaire, composants manquants, etc.
- 🎨 Affichage graphique avec MiniLibX

## ▶️ Lancement du jeu

```bash
make
./so_long maps/map.ber
```
Utilise les touches W, A, S, D pour te déplacer, et ESC pour quitter le jeu.
