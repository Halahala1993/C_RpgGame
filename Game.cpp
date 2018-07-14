//
// Created by ausro on 7/12/2018.
//

#include "Game.h"

Game::Game() {
    playing = true;
}

Game::~Game() {

}

// Intro To Game
void Game::GameInit() {
    std::string name;
    std::string playerClass;
    std::string checkClass;
    std::string playerReady;
    bool yes;
    bool ready;
    int checkStats;

    std::cout << "####################\n";
    std::cout << "# Welcome to TITLE #" << std::endl;
    std::cout << "####################\n";
    std::cout << "\nWhat is your name? ";
    std::getline(std::cin, name);
    do {
        std::cout << " \n======CLASSES======" << std::endl;

        do {
            std::cout << "1. Melee" << std::endl;
            std::cout << "2. Ranged" << std::endl;
            std::cout << "3. Magic\n" << std::endl;
            std::cout << "Enter class number to check stats: ";
            std::cin >> checkStats;

            switch (checkStats) {
                case 1:
                    meleeClass.PrintStats();
                    break;
                case 2:
                    rangedClass.PrintStats();
                    break;
                case 3:
                    magicClass .PrintStats();
                    break;
                default:
                    break;
            }
            std::cout << "Continue to selection? yes/no ";
            std::cin >> playerReady;

            if (playerReady == "Yes" || playerReady == "yes") {
                ready = true;
            }
            else
            {
                ready = false;
            }

        } while(!ready);


        std::cout << "Class: ";
        std::cin >> playerClass;

        // Game Initialized based off class selection
        if ( playerClass == "Magic" || playerClass == "magic") {
            magicClass.Initialize(name);
        }
        else if (playerClass == "Ranged" || playerClass == "ranged") {
            rangedClass.Initialize(name);
        }
        else if (playerClass == "Melee" || playerClass == "melee") {
            meleeClass.Initialize(name);
        }

        std::cout << "\nAre you sure you want to use " << playerClass << " class? yes/no" << std::endl;
        std::cin >> checkClass;

        if (checkClass == "Yes" || checkClass == "yes") {
            yes = true;
        }
        else {
            yes = false;
        }
    } while (!yes);
}

void Game::MainMenu() {
    std::cout << "\n======MAIN==MENU======"<< std::endl;
    std::cout << "|| 1. Skills        ||" << std::endl;
    std::cout << "|| 2. Level         ||" << std::endl;
    std::cout << "|| 3. Stats         ||" << std::endl;
    std::cout << "|| 4. Shop          ||" <<std::endl;
    std::cout << "|| 5. Travel        ||" << std::endl;
    std::cout << "|| 6. Inventory     ||" << std::endl;
    std::cout << "|| 7. Quit          ||" << std::endl;
    std::cout << "======================" << std::endl;
    std::cout << "choice: ";
    std::cin >> playerChoice;
    std::cout << std::endl;
}

// Main Menu selection
bool Game::isPlaying() {
    switch (playerChoice) {
        case 3:
            if (magicClass.IsSelected()) {
                magicClass.PrintStats();
            }
            else if (rangedClass.IsSelected()) {
                rangedClass.PrintStats();
            }
            else if (meleeClass.IsSelected()) {
                meleeClass.PrintStats();
            }
            break;
        case 7:
            playing = false;
            break;
        default:
            break;
    }
}




