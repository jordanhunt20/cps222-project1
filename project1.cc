/* Estimate the value of pi using the Taylor series for atan(x) at x = 1
 *
 * The user is asked to specify the number of digits of precision desired
 *
 * This version provides a sequential baseline for calculating speedup when using
 * various parallel versions
 *
 * $Smake: g++ -o %F %f
 */

using namespace std;
#include <iostream>

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
    cin >> numOrganisms;
    cout << "Number of Organisms: " << numOrganisms << endl;

    cout << "Locations? ";

    //get rid of whitespace code guided by code found at http://stackoverflow.com/questions/8394930/c-remove-whitespace 
    cin.get( input );
    cout << input;
    k = 0;
    j = 0;
    for ( i = 0; i < input.length(); i++ ) {
		cout << "in";
        if(input[i] != ' ') {
            if ( k < 1 )
                k++;
            else {
                j++;
                k--;
            }
            initOrganisms[j][k] = input[i];
            cout << "Organism Locations: " << initOrganisms[j][k];
        }
    }
    cout << endl;
    cout << "done" << endl;

    //cout << "Generations? ";
    //cin >> generations;
}


