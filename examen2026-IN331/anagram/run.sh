#! /bin/sh

# compile the project
make clean all
# run the test project
./out/bin/main_test
# run the project
./out/bin/anagram data/words eraser 0


