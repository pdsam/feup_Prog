/*
PROGRAM 01
Test whether the user knows the basic math tables.
JAS
2013-02-12
*/
#include <iostream>
#include <ctime>
using namespace std;
int main(void)
{
	// variable declarations and initialization
	int operand1, operand2, result, answer;
	char operators[4] = { '+','-','*','/' }; 
	char operation; // why not 'operator' ...?
	int maxOperandValue;
	int numOperations;
	int numCorrectAnswers = 0;
	
	srand((unsigned int)time(NULL));// initialize random number generator
	
	cout << "Maximum operand value?"; cin >> maxOperandValue;
	cout << "Number of operations?"; cin >> numOperations;

	for (int i = 1; i <= numOperations; i++)
	{
		// randomly generate operands and operator
		operand1 = rand() % maxOperandValue + 1;
		operand2 = rand() % maxOperandValue + 1;
		operation = operators[rand() % 4];
		// calculate the correct result 
		switch (operation)
		{
		case '+': result = operand1 + operand2;
			break;
		case '-': result = operand1 - operand2;
			break;
		case '*': result = operand1 * operand2;
			break;

		case '/':
			result = operand1 / operand2;
			break;
		}
		// ask the answer from the user
		cout << operand1 << " " << operation << " " << operand2 << " ? ";
		cin >> answer;
		// verify if the answer of the user is correct
		if (answer == result)
		{
			cout << "Correct answer. Congratulations\n";
			numCorrectAnswers++;
		}
		else
			cout << "Wrong answer ...\n";
		//show final result
		cout << "Number of correct answers =" << numCorrectAnswers << endl;
	}
	//classify results
	if (numCorrectAnswers <= (int)(0.3 * numOperations))
		cout << "VERY BAD!!!\n";
	else
		if (numCorrectAnswers <= (int)(0.5 * numOperations))
			cout << "Poor...\n";
		else
			if (numCorrectAnswers <= (int)(0.7 * numOperations))
				cout << "Fair...\n";
			else
				if (numCorrectAnswers <= (int)(0.9 * numOperations))
					cout << "Good...\n";
				else
					cout << "Execellent..\n";

	return 0;
}