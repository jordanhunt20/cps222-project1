/*
 *
 * $Smake: g++ -o %F %f
 */

#include <iostream>
#include <vector>

/**
 * Run the game of life
 */
int main() {
    int numOrganisms, generations;

    std::cout << "How many organisms initially? ";
    std::cin >> numOrganisms;

    std::cout << "Locations? ";
	int initOrganisms[numOrganisms];
	for (int i=0; i < numOrganisms; i++) {
		std::cin >> initOrganisms[i];
	}

    while (std::cin.get() != '\n'); // Clear input buffer

    std::cout << "Generations? ";
    std::cin >> generations;

    while (std::cin.get() != '\n'); // Clear input buffer

    return 0;
}
