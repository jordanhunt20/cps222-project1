/*
 * Copyright 2016 Jordan Hunt and Adam Vigneaux
 * $Smake: g++ -fpermissive -o %F %f
 */

#include <iostream>
#include <vector>

/**
 * Draw game board
 * @param totalRows     Number of rows on game board
 * @param totalCols     Number of columns on game board
 * @param numOrganisms  Number of organisms to start with
 * @param initOrganisms Starting positions of organisms
 */
void drawBoard(int totalRows, int totalCols, int numOrganisms,
    int initOrganisms[]) {

    for (int row = 0; row < totalRows; row++) {  // row loop
        for (int col = 0; col < totalCols; col++) {  // column loop
            if (row == 0 || row == totalRows - 1) {  // top and bottom
                if (col == 0 || col == totalCols - 1) {  // corners
                    std::cout << "+";
                } else {  // not corners
                    std::cout << "-";
                }
            } else {  // not top or bottom
                if (col == 0 || col == totalCols - 1) {  // sides
                    std::cout << "|";
                } else {
                    bool dead = true;
                    for (int j = 0; j < numOrganisms * 2; j += 2) {
                        if (initOrganisms[j] == row &&
                            initOrganisms[j + 1] == col) {  // Living organism
                            std::cout << "*";
                            dead = false;
                        }
                    }
                    if (dead) {
                        std::cout << " ";
                    }
                }
            }
        }
        std::cout << std::endl;
    }
}

/**
 * Run the game of life
 */
int main() {
    int numOrganisms, generations, currentGeneration;

    std::cout << "How many organisms initially? ";
    std::cin >> numOrganisms;

    std::cout << "Locations? ";
    int initOrganisms[numOrganisms];

    for (int i = 0; i < numOrganisms * 2; i++) {  // works
        std::cin >> initOrganisms[i];
    }
    while (std::cin.get() != '\n') {}  // Clear input buffer
    std::cout << "Generations? ";
    std::cin >> generations;

    while (std::cin.get() != '\n') {}  // Clear input buffer

    static const char ESC = 27;  // Clear screen
    std::cout << ESC << "[H" << ESC << "[J" << "Initial:" << std::endl;

    static const int activeRows = 18;
    static const int activeCols = 50;
    static const int totalRows = activeRows + 2;
    static const int totalCols = activeCols + 2;

    while (currentGeneration++ < generations) {
        std::cout << "Generation " << currentGeneration << std::endl;
        drawBoard(totalRows, totalCols, numOrganisms, initOrganisms);

        std::cout << ESC << "[23;1H" << ESC << "[K"
            << "Press RETURN to continue";
        while (std::cin.get() != '\n') {}  // Wait for user to press RETURN
    }

    // Representation of each cell
    enum Organism { NONE, GESTATING, LIVING, DYING };
    Organism _board[totalRows][totalCols];  // Create board

    return 0;
}
