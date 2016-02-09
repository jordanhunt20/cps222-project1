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
    std::vector<int> liveOrganisms) {

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
                        if (liveOrganisms[j] == row &&
                            liveOrganisms[j + 1] == col) {  // Living organism
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
	
	// Representation of each cell
    enum Organism { NONE, GESTATING, LIVING, DYING };
    Organism _board[totalRows][totalCols];  // Create board
	
    //store initArray in a vector
    std::vector<int> livingOrganisms;
    for (int n = 0; n < numOrganisms * 2; n++) {
	livingOrganisms.push_back(initOrganisms[n]);
    }

    // Draw initial Board
    drawBoard(totalRows, totalCols, numOrganisms, livingOrganisms); // Draw initial board with initial organisms
	
    // populate _board with initial organisms
    for (int row = 0; row < totalRows; row++) { 
        for (int col = 0; col < totalCols; col++) {
	    bool dead = true;
            for (int j = 0; j < numOrganisms * 2; j += 2) {
	        
                if (initOrganisms[j] == row && initOrganisms[j + 1] == col) {  // Living organism
		    _board[row][col] = LIVING;
                    dead = false;
                }
	    }
	    if (dead) {
	        _board[row][col] = NONE;
                
	    }
        }
    }
    int neighborOffsetsX[8] = {-1, 0, 1, 1, 1, 0, -1, -1}; //offsets in X direction starting top left going clockwise
    int neighborOffsetsY[8] = {1, 1, 1, 0, -1, -1, -1, 0}; //offsets in Y direction starting top left going clockwise
    currentGeneration = 0; //necessary because sometimes it will be arbitrary if not initialized to 0
    while (currentGeneration++ < generations) {
	std::cout << ESC << "[23;1H" << ESC << "[K"
            << "Press RETURN to continue";
	while (std::cin.get() != '\n') {}  // Wait for user to press RETURN
	// Put new values into _board based on old values;
	// Temporary values of gestating/dying
	for (int row = 1; row < activeRows; row++) { //row
            for (int col = 1; col < activeCols; col++) { //col
		int numNeighbors = 0;
		for (int m = 0; m < 8; m++) {
		    Organism neighbor = _board[row + neighborOffsetsY[m]][col + neighborOffsetsX[m]];
		    if (neighbor == LIVING || neighbor == DYING) //include dying since they are not yet dead cells
		        numNeighbors++;
		}
		if(_board[row][col] == NONE) { //empty cell
		    if (numNeighbors == 3)
			_board[row][col] = GESTATING;
		}
		if(_board[row][col] == LIVING) { //living cell
	            if (numNeighbors < 2 || numNeighbors > 3)
			_board[row][col] = DYING;
		}
	    }
	}

	// Put permanent values of dying/living into board
	for (int row = 1; row < activeRows; row++) { //row
            for (int col = 1; col < activeCols; col++) { //col
		if(_board[row][col] == GESTATING) { //empty cell
		    _board[row][col] = LIVING;
		}
		if(_board[row][col] == DYING) { //living cell
		    _board[row][col] = NONE;
		}
	    }
	}

	//Empty living organisms vector
	livingOrganisms.clear();
	// Fill living organisms vector with new organism locations
	for (int row = 1; row < activeRows; row++) { //row
            for (int col = 1; col < activeCols; col++) { //col
		if(_board[row][col] == LIVING) {
	            livingOrganisms.push_back(row);
		    livingOrganisms.push_back(col);
		}
	    }
	}
	numOrganisms = livingOrganisms.size() / 2;
        std::cout << "Generation " << currentGeneration << std::endl;
	std::cout << ESC << "[H" << ESC << "[J" << "Initial:" << std::endl;
        drawBoard(totalRows, totalCols, numOrganisms, livingOrganisms);
    }

    
	
    return 0;
}
