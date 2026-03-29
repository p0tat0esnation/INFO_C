#! /bin/sh

# Compiler le projet
make clean all
# Lancer les tests d'évaluation
./out/bin/main_test
# Exemple d'exécution du programme principal
./out/bin/anagram data/words eraser 0


