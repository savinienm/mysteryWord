// mysteryWord.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include "mixUpWord.h"
using namespace std;

int main()
{
    string reco;
    srand(time(0));

    do {
        // Première étape : saisie du mot par le joueur 1

        string mysteryWord, randomWord, guessWord;

        cout << "Please, enter a word to start a game: ";
        cin >> mysteryWord;

        // Deuxième étape : mélange des lettres du mot
        do {
            randomWord = mixUpWord(mysteryWord);
        } while (randomWord == mysteryWord);

        // Troisième étape : tentative de saisie du mot par le joueur 2

        cout << "What is the mystery word " << randomWord << ": ";
        cin >> guessWord;

        while (guessWord != mysteryWord) {

            cout << "Oh no, it's not the right word, please try again " << randomWord << ": ";
            cin >> guessWord;

        }

        cout << "Welldone, you guess the mystery word " << mysteryWord << "! Do you want to play again? (yes/no) ";
        cin >> reco;

    while (reco != "no" && reco != "yes") {
        cout << "The question is simple: YES OR NO? (yes/no) ";
        cin >> reco;
    }

    } while (reco == "yes");

        return 0;
}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
