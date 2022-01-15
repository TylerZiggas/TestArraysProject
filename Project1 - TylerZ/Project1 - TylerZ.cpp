#include <iostream>
#include <ctime>
using namespace std;

//Part 1//
void intialize_array(int[], int);
int* shuffle_array(const int[], int);
void print_array(const int[], int);


//Part 2//
int* createOddArray(const int[], int, int&);
int* createEvenArray(const int[], int, int&);


//Part 3//
void array_war(int*, int, int*, int);
void sort_array(int*, int);


//Part 4//
int main()
{
	int SIZE, oddSize = 0, evenSize = 0;

	cout << "Input the size of the array from 1 to 52: ";
	cin >> SIZE;
	while (SIZE < 1 || 52 < SIZE) // Checking if user input is valid
	{
		cout << "Please input a valid number between 1 and 52: ";
		cin.clear();
		cin.ignore(10000, '\n');
		cin >> SIZE;
	}
	int* initialArray = new int[SIZE];

	intialize_array(initialArray, SIZE); // Creating the first array based on user input
	int* shuffleArray = shuffle_array(initialArray, SIZE); // Shuffling the first array
	int* oddArray = createOddArray(shuffleArray, SIZE, oddSize); // Using shuffled array to make array of the odd numbers
	int* evenArray = createEvenArray(shuffleArray, SIZE, evenSize); // Using shuffled array to make array of the even numbers
	array_war(oddArray, oddSize, evenArray, evenSize);
	
	delete[] initialArray;
	delete[] shuffleArray;
	delete[] oddArray;
	delete[] evenArray;
	return 0;
}


//Part 1 Functions//
void intialize_array(int initialArray[], int SIZE)
{
	for (int i = 0; i < SIZE; i++) // Creating the array to make the position the number
	{
		initialArray[i] = i;
	}
	cout << "The original array is [ ";
	print_array(initialArray, SIZE); // Printing first array
	cout << "]" << endl;
}


int* shuffle_array(const int initialArray[], int SIZE)
{
	int* shuffleArray = new int[SIZE];
	for (int i = 0; i < SIZE; i++) // Storing the initial array into the new one
	{
		shuffleArray[i] = initialArray[i];
	}
	srand(time(NULL));
	for (int i = SIZE - 1; i > 0; i--) // Shuffling the new array
	{
		int j = rand() % (i + 1);
		int temp = shuffleArray[i];
		shuffleArray[i] = shuffleArray[j];
		shuffleArray[j] = temp;

	}

	cout << "The shuffled array is [ ";
	print_array(shuffleArray, SIZE); // Printing second array
	cout << "]" << endl;
	return shuffleArray;
}


void print_array(const int theArray[], int SIZE)
{
	for (int i = 0; i < SIZE; i++) // Printing each number in the array
	{
		cout << theArray[i] << " ";
	}
}


//Part 2 Functions//
int* createOddArray(const int theArray[], int SIZE, int& oddSize)
{
	int newArrCounter = 0;

	for (int i = 0; i < SIZE; i++)  // Creates the size of the odd array
	{
		if (theArray[i] % 2 == 1)
		{
			oddSize += 1;
		}
	}
	int* oddArray = new int[oddSize];

	for (int i = 0; i < SIZE; i++) // If the number in the shuffled array is odd, put it into the next spot
	{
		if (theArray[i] % 2 == 1)
		{
			oddArray[newArrCounter] = theArray[i];
			newArrCounter++;
		}
	}

	cout << "The odd array is [ ";
	print_array(oddArray, oddSize); // Printing odd array
	cout << "]" << endl;

	return oddArray;
}


int* createEvenArray(const int theArray[], int SIZE, int& evenSize)
{
	int newArrCounter = 0;

	for (int i = 0; i < SIZE; i++) // Creates the size of the even array
	{
		if (theArray[i] % 2 == 0)
		{
			evenSize += 1;
		}
	}
	int* evenArray = new int[evenSize];

	for (int i = 0; i < SIZE; i++) // If the number in the shuffled array is even, put it into the next spot
	{
		if (theArray[i] % 2 == 0)
		{
			evenArray[newArrCounter] = theArray[i];
			newArrCounter++;
		}
	}

	cout << "The even array is [ ";
	print_array(evenArray, evenSize); // Printing even array
	cout << "]" << endl;

	return evenArray;
}


//Part 3 Functions//
void array_war(int* oddArray, int oddSize, int* evenArray, int evenSize)
{
	int warSize = 0;
	if (oddSize >= evenSize) // If odd is the larger sized array (or if they are even)
	{
		warSize = oddSize;
	}
	else // If even is the larger sized array
	{
		warSize = evenSize;
	}

	int* arrayWinners = new int[warSize];
	for (int i = 0; i < warSize; i++) 
	{
		if (oddArray[i] > evenArray[i]) // If odd wins in this scenario
		{
			arrayWinners[i] = oddArray[i];
		}
		else // If even wins in this scenario
		{
			arrayWinners[i] = evenArray[i];
		}
	}

	cout << "The war winners are [ ";
	print_array(arrayWinners, warSize); // Printing the array winners
	cout << "]" << endl;
	sort_array(arrayWinners, warSize); // Sending the array winners to sort them in order

	delete[] arrayWinners;
}


void sort_array(int* arrayWinners, int warSize)
{
	int minIndex, minValue;

	for (int i = 0; i < warSize - 1; i++) // Sorting the array starting from spot 1
	{
		minIndex = i;
		minValue = arrayWinners[i];
		for (int index = i + 1; index < warSize; index++) // Checking if that value is the lowest value
		{
			if (arrayWinners[index] < minValue) // Seeing which value is the lowest and next lowest, so on
			{
				minValue = arrayWinners[index];
				minIndex = index;
			}
		}
		int temp = arrayWinners[minIndex]; // Swapping them so it is lowest to highest
		arrayWinners[minIndex] = arrayWinners[i];
		arrayWinners[i] = temp;
	}

	cout << "The sorted war winners are [ ";
	print_array(arrayWinners, warSize); // Printing the sorted winners
	cout << "]" << endl;

}