/*
	Kaya Lash
	Interactive Calculator
	
	Functions: 
		adding (+), substracting (-), multiplying (*), dividing (/), squareroot ($), power (^)
	How to use: 
		When you run the program it will ask you to input your expression separated by 
		first number, operation, and second number if needed.
		If you would like to square root use "$" character for the operation.
		To use power use "^" character with the first number as the base and the second as the exponent.
		When completed press enter and it will return the answer.
*/

#include <iostream>
#include <string>
using namespace std; 

// Defining functions
// Add function
float add(float x, float y)
{
	return x + y;
}

// Substract function
float sub(float x, float y)
{
	return x - y;
}

// Multiplication function
float mult(float x, float y)
{
	return x * y;
}

//Division Function
float divide(float x, float y)
{
	if (y == 0)
	{
		cout << "Error: Dividing by Zero" << endl;
		return 0;
	}
	else
	{
		return x / y;
	}
}

// Power function
float power(float base, float exp)
{
	float result = 1;
	for (int i = 0; i < exp; i++)
	{
		result = result * base;
	}
	return result; 
}

// Sqaureroot function
float root(float a, float result)
{ 	
	float epsilon = 0.00001;
	if ((result * result - a) < epsilon) {
		return result;
	}
	return root(a, (result + a / result) / 2.0);
	
}

// Printing output function
float result(float a, string opp, float b)
{
	float result = 0;
	if (opp == "+")
	{
		result = add(a, b);
	}
	else if (opp == "-")
	{
		result = sub(a, b);
	}
	else if (opp == "*")
	{
		result = mult(a, b);
	}
	else if (opp == "/")
	{
		result = divide(a, b);
	}
	else if (opp == "$")
	{
		result = root(a, a);
	}
	else if (opp == "^")
	{
		result = power(a, b);
	}
	else
	{
		cout << "Invalid operation!" << endl;
		return 0;
	}
	
	return result;
}



int main() 
{
	// Initializing variables
	float x = 0, y = 0;
	string expression = "";
	string a, opp, b;

	// Asks for user to input their expression
	cout << "Input your expression: +, -, *, /, $, ^" << endl << "First number: ";
	cin >> a;
	cout << "Operation: ";
	cin >> opp;

	if (opp != "$") // if the user uses squareroot it won't ask for the second number
	{
		cout << "Second number: ";
		cin >> b;
		float f = stof(a);
		float g = stof(b);
		cout << "Result: " << result(f, opp, g);
	}
	else
	{
		float f = stof(a);
		cout << "Result: " << result(f, opp, f);
	}
	
	return 0;
}

