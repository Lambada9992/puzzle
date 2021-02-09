Puzzle (Terminal version) 

O grze

Puzzle jest to układanka polegająca na ustawieniu pól w odpowiedniej kombinacji. Jedno pole jest puste(pole oznaczone cyfrą - 0) umożliwiając wykonywanie ruchów w układance.

O projekcie 

W grze dostępne są dwa tryby gry 8 Puzzle[3x3] oraz 15 Puzzle[4x4]. W przypadku obu trybów gry dostępna jest opcja podpowiedź, która wskazuje następny ruch/ruchy prowadzące do rozwiązania łamigłówki w najkrótszy możliwy sposób(najmniejsza ilość ruchów). Do wyznaczania sposobu rozwiązania łamigłówki wykorzystywany jest algorytm A*(A Star). O ile w przypadku gry 8 Puzzle algorytm ten spisuje się wyśmienicie w celu wyznaczania najszybszego rozwiązania, to w przypadku trybu 15 puzzle przy odpowiednim ustawieniu planszy(duża ilość ruchów minimalnego rozwiązania) czas wykonywania algorytmu jest nie satysfakcjonujący. Wynika to z faktu ilości możliwych kombinacji ustawień pól w grze która wynosi:  n!/2 gdzie: n - ilość pól gry. W przypadku trybu 8 Puzzle n = 9, a ilość kombinacji wynosi 181 440. W przypadku trybu 15 Puzzle n = 16, a ilość kombinacji wynosi 10 461 394 944 000. Jak widać liczba możliwych kombinacji w drugim przypadku jest większa aż o 8 rzędów wielkości. Z tego właśnie powodu ilość sprawdzanych stanów gry gwałtownie rośnie co powoduje wydłużenie czasu poszukiwania najszybszego rozwiązania(nie satysfakcjonujący czas) oraz zapotrzebowania na pamięć operacyjną.

Instrukcja

Wybieranie trybu gry

Po uruchomieniu aplikacji użytkownik jest proszony o "podaj rozmiar GRY :" w celu wybrania trybu 8 Puzzle[3x3] należy wpisać 3, a w przypadku 15 Puzzle[4x4] należy wpisać 4. Następnie wybór należy zatwierdzić enterem.

Inicjalizacja tablicy startowej

Po wybraniu trybu gry program wyświetli informację "wprowadz tablice 0-puste pole :" należy wprowadzić początkową tablice wierszami. Przykładowe tablice wejściowe:
8 Puzzle: "1 2 3 4 5 6 7 8 0"
15 Puzzle: "1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 0" 

Rozgrywka oraz menu

Po inicjalizacji stanu początkowego program wyświetla planszę(gdzie 0 jest polem pustym) oraz menu. Aby wybrać daną opcje z menu należy wpisać literkę którą opcja jest poprzedzona, a następnie zatwierdzić ją enterem.

ENG

About game

Puzzle is a sliding puzzle game in which player has to place tiles in the in the correct combination. One tile is empty what create oportunity to make moves.

About project

The are two modes in game: 8 Puzzle[3x3] and 15 Puzzle[4x4]. In both case there is avible option to show hint, which make next move. Thoes moves lead to solving of the puzzle with the minimum number of moves possible. The hint work on A*(A Star) alghoritm. In 8 Puzzle mode alghoritm work pretty good on the other hand in 16 puzzle the time of calculations in most cases takes too long. It's due of the ammount of the possible combintation of tiles placed. This ammount is equal n!/2 where: n - number of tiles. In 8 Puzzle mode n = 9 and the amount of combinations is 181 440, where in the 16 Puzzle mode n = 16 and the ammount of combinations is 10 461 394 944 000. As it is clearly see in the second case order of magnitude is 8 times biger. Because of these reason prediction of next move take so long. It also makes bigger usage of operating system memory.

Manual

Chose of game mode

After starting the app there will be displayed message "podaj rozmiar GRY :". You will have to enter number of tilles in the row or column(they are equal). If you want to play 8 Puzzle, you have to type 3 or if you want to play 15 Puzzle you have to type 4. Then you have to confirm it by pressing enter. If you enter invalid input app will ask again the same question.

Initialization of starting board

After chosing game mode the app will  display message "wprowadz tablice 0-puste pole :" you will have to enter in rows the initial board where 0 is the empty tile. Examples:
8 Puzzle: "1 2 3 4 5 6 7 8 0",
16 Puzzle: "1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 0"
Those examples initialize board which is already solved.

Gamplay and menu

After initializating starting board the main board of the game and menu will be displayed. To chose option of the menu you have to type an character which is before an intresting option then you have to confirm it by pressing enter. 

Translation of options in menu: 

"w - Ruch do gory" -- move empty tile up
"s - Ruch do dolu" -- move empty tile down
"a - Ruch w lewo" -- move empty tile left
"d - Ruch w prawo" -- move empty tile right
"p - Podpowiedz" -- hint option(make one move)
"r - Randomize" -- randomize the board
"y - Zapisz rozwiazanie do pliku o podanej nazwie" -- save the sollution of courrent state into a file
"u - Wczytaj ponowinie gre" -- chose game mode and intit the starting board again
"k - Zakoncz gre" -- quit app




