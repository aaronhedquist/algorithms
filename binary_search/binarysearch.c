#import <stdio.h>
#import <stdlib.h>
#include <string.h>
#include <math.h>

typedef enum { false, true } bool;

/*

Basic binary search algorithm

Let min = 0 and max = n-1.
Compute guess as the average of max and min, rounded down (so that it is an integer).
If array[guess] equals target, then stop. You found it! Return guess.
If the guess was too low, that is, array[guess] < target, then set min = guess + 1.
Otherwise, the guess was too high. Set max = guess - 1.
Go back to step 2.

*/

#define COUNT_OF_ARRAY(x) 	(sizeof(x) / sizeof((x)[0]))

// Method prototypes
void setup();
void beginBinarySearch();
void printArray(int array[], size_t length);
int * copyIntArray(int const * arrayToCopy, size_t length);
void printStatus(int array[], size_t length);

// Array to search through
int primes[25] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

// Stores the target value
int randomPrime;

// Index to store the lower range of the active search area of the array
int minGuess = 0;

// Index to store the upper range of the active search area of the array
int maxGuess = COUNT_OF_ARRAY(primes) - 1;

int main() {
	
	setup();
	beginBinarySearch();

	return 0;
}

/* Intialize our variables and make our random guess */
void setup() {

	int randomIndex = arc4random_uniform(COUNT_OF_ARRAY(primes));
	randomPrime = primes[randomIndex];

	printf("Random Prime: %d\n", randomPrime);
	printStatus(primes, COUNT_OF_ARRAY(primes));
	
}

/* Performs the search */
void beginBinarySearch() {

	// Will flip this value once the target value is found
	bool found = false;

	// Added an iterator just in case of endless loops while developing
	int i = 0;

	// loop until we find the correct value
	while (!found && i < 25) {

		// find average value, rounding down to nearest int
		int middleIndex = floor((maxGuess - minGuess) / 2) + minGuess;
		int valueToCheck = primes[middleIndex];
		printf("middleIndex %d valueToCheck %d\n", middleIndex, valueToCheck);

		if (valueToCheck == randomPrime) {
			found = true;
			printf("found it! it's %d at index %d\n", valueToCheck, middleIndex);
			break;
		} else if (valueToCheck < randomPrime) {
			minGuess = middleIndex+1;
			printStatus(primes, 25);
		} else if (valueToCheck > randomPrime) {
			maxGuess = middleIndex-1;
			printStatus(primes, 25);
		}

		i++;

	}

}

/* Prints each value of an array */
void printArray(int array[], size_t length) {

	for (int i = 0; i < length; i++) {

		if (i == length -1) {
			printf("%d\n", (array[i]));
		} else {
			printf("%d, ", (array[i]));
		}
		
	}

}

/* Special formatting for printing the results of this search */
void printStatus(int array[], size_t length) {

	for (int i = 0; i < length; i++) {

		if (i == minGuess && i == maxGuess) {

			// When we find the final value
			printf("[min]-> %d <-[max], ", array[i]);

		} else if (i == minGuess && i != maxGuess) {

			// show where the min value is
			printf("[min]-> %d, ", array[i]);

		} else if (i == maxGuess && i != minGuess) {

			// show where the max value is
			printf("%d <-[max]", array[i]);

		} else {

			// print the value at this index
			printf("%d, ", array[i]);

		}

		// last value, add CR
		if (i == length -1) {
			printf("\n");
		}
		
	}

}

/* Copies an array */
int * copyIntArray(int const * arrayToCopy, size_t length) {

	int * copy = malloc(length * sizeof(int));
	memcpy(copy, arrayToCopy, length * sizeof(int));

	return copy;

}
