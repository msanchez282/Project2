#include <iostream>
using namespace std;

// CPSC 240-05
// 
// Matthew Sanchez and Alexander Gomez
//

int main()
{
	//Q1
	int drinks;
	int sandwiches;
	int drinksPrice = 2;
	int sandwichesPrice = 4;
	int bill, bill2, finalbill;


	cout << "--------------------MENU------------------ " << endl;
	cout << " Drinks...............................$" << drinksPrice << endl;
	cout << " Sandwiches........................... $" << sandwichesPrice << endl;
	cout << "          How many drinks: " << endl;
	cin >> drinks;
	cout << "          How many sandwiches: " << endl;
	cin >> sandwiches;
	_asm {
		// bill = drinks * drinkPrice + sandwiches * sandwichesPrice
		mov eax, sandwichesPrice;            // eax = sandwichesPrice
		imul sandwiches;                     // edx:eax = sandwiches * sandwichPrice
		mov bill, eax;                      // bill = sandwichesPrice
		mov eax, drinksPrice;             // eax = drinkPrice
		imul drinks;                      // edx:eax = drinks * drinkPrice
		mov bill2, eax;                  // bill2 = drinkPrice

		mov eax, bill;
		add eax, bill2;
		mov finalbill, eax;

	}
	cout << "       Your total bill $" << finalbill << endl;


	//Q2

	int a, b, c, h, length1, width, rPerimeter, tPerimeter, tArea, rArea;
	cout << "Enter the values of a,b,c, and h  for the triangle: " << endl;
	cin >> a >> b >> c >> h;
	cout << "Enter the length and the width of the rectangle: " << endl;
	cin >> length1 >> width;
	short two = 2;
	_asm {
		// Calculate tPerimeter
		mov eax, a;				// eax == a
		add eax, b;				// eax == a + b
		add eax, c;				// eax == a + b + c
		mov tPerimeter, eax;	// tPerimeter == a + b + c

		// Calculate rPerimeter
		mov eax, length1;		// eax == length
		add eax, width;			// eax == length + width
		add eax, eax;			// eax == (2 * length) + ( 2 * width)
		mov rPerimeter, eax;	// rPerimeter == (2 * length) + ( 2 * width)

		// Calculate rArea
		mov eax, length1;		// eax = length
		imul eax, width;		// eax = length * width
		mov rArea, eax;			// rArea = length * width

		// Calculate tArea
		mov eax, c;				// eax == c
		mov ebx, h;				// ebx == h
		imul ebx;				// eax == c * h
		cdq;					// edx:eax == c * h
		idiv two;				// eax == quotient, edx == remainder
		mov tArea, eax;			// tArea == quotient
	}
	cout << "Triangle" << endl;
	cout << "    Area........................................." << tArea << endl;
	cout << "    Perimeter...................................." << tPerimeter << endl;
	cout << "Rectangle" << endl;
	cout << "    Area........................................." << rArea << endl;
	cout << "    Perimeter...................................." << rPerimeter << endl;



	// Q3

	short C, F, five, nine;
	five = 5;
	nine = 9;
	cout << "Enter temperature in Fahrenheight: ";
	cin >> F;
	_asm {
		mov ax, F;				// ax == F
		sub ax, 32;				// ax == F - 32
		imul five;				// ax == 5(F - 32)
		cwd;					// dx:ax == 5(F -32)
		idiv nine;				// ax == quotient, dx == remainder
		mov C, ax;				// ax == quotient
	}
	cout << F << "F is " << C << "C" << endl;



	// Q4
	short input;
	short output;
	cout << "Enter a 3 digit int number : "<< endl;
	cin >> input;
	short hundred = 100;
	short ten = 10;
	short d3, d2, d1;
	_asm {
		// digit 3
		mov ax, input;			// ax = input
		cwd;						// dx:ax = input
		idiv hundred;				// ax = quotient, dx = remainder
		mov d3, ax;					// d3 = quotient

		// digit 2
		mov ax, dx;					// ax = previous remainder
		cwd;						// dx:ax = previous remainder
		idiv ten;					// ax = quotient, dx = remainder
		mov d2, ax;					// d2 = quotient

		// digit 1
		mov ax, dx;					// ax = remainder
		mov d1, ax;					// d1 = remainder

		//sum
		add ax, d2;					// ax = d1 + d2
		add ax, d3;					// ax = d1 + d2 + d3
		mov output, ax;				// output = sum
	}
	cout << "The total of digits in " << input << " is " << output << endl;


	return 0;
}