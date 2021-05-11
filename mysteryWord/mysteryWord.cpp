// mysteryWord.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <vector>
#include "mixUpWord.h"
using namespace std;

int main()
{
    string reco;
    srand(time(0));

    do {
        // Première étape : on va chercher dans un fichier un mot au hasard

        string const wordsList("C:/Users/user/source/repos/mysteryWord/mysteryWord/wordsList.txt");

        ifstream wordsListFlow(wordsList.c_str());

        string mysteryWord, randomWord, guessWord;

        if (wordsListFlow) {

            string line;
            int lineCount(0);
            vector<string> mysteryWordsList;
            int mysteryPosition(0);

            while (getline(wordsListFlow, line)){
                lineCount++;
                mysteryWordsList.push_back(line);
            }
                wordsListFlow.close();
                mysteryPosition = rand() % mysteryWordsList.size();
                mysteryWord = mysteryWordsList[mysteryPosition];
        }
        else {
            cout << "ERROR: Impossible to open the file " << wordsList << "." << endl;
        }


        // Deuxième étape : mélange les lettres du mot
        do {
            randomWord = mixUpWord(mysteryWord);
        } while (randomWord == mysteryWord);

        // Troisième étape : saisie d'un mot par l'opérateur

        cout << "What is the mystery word (be carefull, you only have 3 tries) " << randomWord << ": ";
        cin >> guessWord;

        int attempt(3);

        while (guessWord != mysteryWord && attempt > 0) {

            attempt--;
            cout << "Oh no, it's not the right word, please try again (you still have " << attempt << " attempts) " << randomWord << ": ";
            cin >> guessWord;

        }

        if (guessWord == mysteryWord) {
            cout << "Welldone, you guess the mystery word " << mysteryWord << "! Do you want to play again? (yes/no) ";
            cin >> reco;
        } else if (attempt == 0){
            cout << "Oh no... You did not find the mystery word " << mysteryWord << "! Do you want to play again? (yes/no) ";
            cin >> reco;
        }

    while (reco != "no" && reco != "yes") {
        cout << "The question is simple: YES OR NO? (yes/no) ";
        cin >> reco;
    }

    } while (reco == "yes");

        return 0;
}
