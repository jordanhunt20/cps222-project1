/*
 *
 * $Smake: g++ -o %F %f
 */

#include <iostream>
#include <vector>

/* Main program
 * Program that displays the game of life in the command prompt
 */

int main() {
    std::string inputLocations, inputLocationsClean;
    int numOrganisms, generations, **initOrganisms, i, j, k, m, n;

    std::cout << "How many organisms initially? ";
    std::cin >> numOrganisms;
    std::cout << "Number of Organisms: " << numOrganisms << std::endl;

    std::cout << "Locations? ";
	int initOrganisms[4];
	for (int i=0; i < 4; i++) {
		std::cin >> initOrganisms[i];
	}

	/*
    k = 0;
    j = 0;
    for ( i = 0; i < input.length(); i++ ) {
		std::cout << "in";
        if(input[i] != ' ') {
            if ( k < 1 )
                k++;
            else {
                j++;
                k--;
            }
            initOrganisms[j][k] = input[i];
            std::cout << "Organism Locations: " << initOrganisms[j][k];
        }
    }
    std::cout << endl;
    std::cout << "done" << endl;

    //cout << "Generations? ";
    //cin >> generations;
*/
}


