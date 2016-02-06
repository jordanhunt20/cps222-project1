/*
 *
 * $Smake: g++ -o %F %f
 */

using namespace std;
#include <iostream>
#include <string>

/* Main program
 * Program that displays the game of life in the command prompt
 */

main()
{
    string inputLocations, inputLocationsClean, input;
    int numOrganisms, generations, **initOrganisms, i, j, k, m, n;
    initOrganisms = new int*[2];
    inputLocations = ' ';

    cout << "How many organisms initially? ";
    std::cin >> numOrganisms;
    std::cout << "Number of Organisms: " << numOrganisms << endl;

    std::cout << "Locations? ";

    //get rid of whitespace code guided by code found at http://stackoverflow.com/questions/8394930/c-remove-whitespace 
    std::getline( std::cin, input );
    std::cout << input;
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


