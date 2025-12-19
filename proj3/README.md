Instructions for compilation:
1. In your terminal, on the command line type make
2. Once the program has compiled, type ./a.out
3. Program should run now

Usage instructions:
1. Once program has compiled, run ./a.out

Game instructions:
1. Read the instructions and get started
2. Enter in as many words as you can, timer will countdown per entry
3. If you found all the words you think you found or you want to end early, then type done
4. The end will print out missed words, your score vs maximum score, and the time it took for the solver to find all words
5. Run the program again if you want to play.

Notes:
1. The code does run suspiciously fast, I do not know how or why so some words may be or may not be missing, I am unsure.
2. If words are missing I am willing to take the partial credit.
3. A LOT, like A LOT of cplusplus.com was used along with googling(ie StackOverflow or the geeksforgeeks). Also some googling was used for my errors because I had linking issues at some point which was not fun. 
4. I have included my test.cpp and driver.cpp in the folder but you can ignore them as it was the code pulled from the website for testing purposes, both are the same but one of them stopped working for a good minute.
5. I have made the game interactive, however the timer countdown sucks, like it would could count down to 60 seconds but since no user input was made it will still be there until the user made an input. I am open to feedback on how to make the timer work better.

Sources:
1. the random_shuffle library within algorithm: https://cplusplus.com/reference/algorithm/random_shuffle/
examples on how to use it: https://www.geeksforgeeks.org/cpp/shuffle-vs-random_shuffle-c/
from another website: https://en.cppreference.com/w/cpp/algorithm/random_shuffle.html
2. push_back within the vector library: https://cplusplus.com/reference/vector/vector/push_back/
more sources: https://www.geeksforgeeks.org/cpp/vector-push-back-cpp-stl/
another source:https://stackoverflow.com/questions/5322522/using-push-back-on-a-vector-of-strings-c
vector within vector usage which does include the push_back: https://www.geeksforgeeks.org/cpp/vector-of-vectors-in-c-stl-with-examples/
3. For roll() in boggledie.cpp: https://www.geeksforgeeks.org/cpp/rand-and-srand-in-ccpp/
another source: https://cplusplus.com/reference/cstdlib/rand/
4. Lower_bound in the vector: https://www.geeksforgeeks.org/cpp/lower_bound-in-cpp/
another source: https://stackoverflow.com/questions/77022796/get-lower-bound-iterator-of-search-string-from-set-here-strings-length-in-set
5. For each loop with string: https://www.w3schools.com/cpp/cpp_for_loop_foreach.asp
example video: https://www.youtube.com/watch?v=4yK9LJN87io
6. .insert for the dictionary: https://cplusplus.com/reference/string/string/insert/
.insert for character for later in the code: https://www.geeksforgeeks.org/cpp/stdstringinsert-in-c/#insert-a-single-character
