/*
	Matamoros, Corbin
	This program includes a class in which objects will be declared
	to hold a coporation's quarterly sales per 6 divisions in corporation.
	Objects will also hold static variables to hold the total coporate sales
	and the total sales for each quarter across all divisions.
*/

#include<iostream>
#include<fstream>
#include<iomanip>

using namespace std;

/*
	Class:		DivSales
	Purpose:	create objects with 5 static float variables
				and a float array of 4 elements
	Members:	DivSales, ~DivSales, setArray, getQuarter, getTotSales,
				getQuart1Sales, getQuart2Sales, getQuart3Sales, getQuart4Sales
*/
class DivSales
{
private:
	//static variable holds coporate sales total
	static float totSales, quart1Sales, quart2Sales, quart3Sales, quart4Sales;

	float quartSales[4]; //variable holds division's four quarterly sales
public:
	
	//constructor that initializes quartSales array elements to zero
	DivSales()
	{
		quartSales[0] = quartSales[1] = quartSales[2] = quartSales[3] = 0.0;
	}

	//obligatory destructor
	~DivSales()
	{

	}

	/*
	Function:	setArray
	Purpose:	fill array with a division's quarterly sales. Sums
				array and places it in totSales
	Parameters:	quart1, quart2, quart3, quart4; all are type float
	Return:		totSales
	*/
	void setArray(float quart1, float quart2, float quart3, float quart4)
	{
		quartSales[0] = quart1;
		quartSales[1] = quart2;
		quartSales[2] = quart3;
		quartSales[3] = quart4;
		quart1Sales += quart1;
		quart2Sales += quart2;
		quart3Sales += quart3;
		quart4Sales += quart4;
		totSales += quart1 + quart2 + quart3 + quart4;
	}

	/*
	Function:	getQuarter
	Purpose:	return from the quartSales array a specific quarter's sales
	Parameters:	index, type int. Index could be an integer from 1 to 4.
				This is more intuitive for the user than 0 - 3
	Return:		quartSales[index - 1]
	*/
	float getQuarter(int index)
	{
		return quartSales[index - 1];
	}

	/*
	Function:	getTotSales
	Purpose:	return total sales amount of all divisions over all quarters
	Parameters:	none
	Return:		totSales
	*/
	float getTotSales()
	{
		return totSales;
	}

	/*
	Functions:	getQuart#Sales
	Purposes:	group of methods that return total sales amount of all quarter # sales
	Parameters:	none
	Returns:	quart#Sales
	*/
	float getQuart1Sales()
	{
		return quart1Sales;
	}

	float getQuart2Sales()
	{
		return quart2Sales;
	}

	float getQuart3Sales()
	{
		return quart3Sales;
	}

	float getQuart4Sales()
	{
		return quart4Sales;
	}
};

//initializing all static variables from the DivSales class
float DivSales::totSales = 0; 
float DivSales::quart1Sales = 0;
float DivSales::quart2Sales = 0;
float DivSales::quart3Sales = 0;
float DivSales::quart4Sales = 0;

//function prototypes
void determineSize(DivSales divisionSales[], float salesSize[]);
void printTable(ofstream &outfile, DivSales divisionSales[], float salesSize[]);

int main()
{	
	//corporation's array with 6 elements for the 6 divisions
	DivSales divisionSales[6];

	int division, counter = 1;
	float quarter1, quarter2, quarter3, quarter4, salesSize[4]; //sales for each quarter
	char divCheck[6] = {'X', 'X', 'X', 'X', 'X', 'X'};
	bool divVal1 = false, divVal2 = false, divVal3 = false, divVal4 = false, 
		divVal5 = false, divVal6 = false;

	ofstream outfile;
	outfile.open("Corporate Sales.txt");
	
	cout << "Corporation Sales Spreadsheet\n" 
		<< "-----------------------------\n\n";

	/*once all divVal's are set to true in the switch statement, 
	while loop will stop. This method will allow user to re-input division 
	sales into a division (in case they made a mistake the first time).*/
	while (!divVal1 || !divVal2 || !divVal3 || !divVal4 || !divVal5 || !divVal6)
	{
		cout << "Divisions status ('O' = has values stored; "
			<< "'X' = no values stored):\n" << "Division 1: "
			<< divCheck[0] << "\nDivision 2: " << divCheck[1] << "\nDivision 3: " 
			<< divCheck[2] << "\nDivision 4: " << divCheck[3]
			<< "\nDivision 5: " << divCheck[4] << "\nDivision 6: " << divCheck[5]
			<< "\nPlease input division number (1 - 6): ";

		cin >> division;
		switch (division)
		{
		case 1: 
			divVal1 = true;
			break;
		case 2:
			divVal2 = true;
			break;
		case 3:
			divVal3 = true;
			break;
		case 4:
			divVal4 = true;
			break;
		case 5:
			divVal5 = true;
			break;
		case 6:
			divVal6 = true;
			break;
		default: cout << "Nice try, Donald Trump. The last thing we need is" 
			<< " more division(s).\n Please input an integer between 1 and 6: ";
		}
		cout << "Please input all four quarterly sales for division "
			<< division << ", pressing Enter after each entry:\n";

		cin >> quarter1 >> quarter2 >> quarter3 >> quarter4;
		
		/*call the setArray function within class and store in element 'division'
		in divisionSales array*/
		divisionSales[division - 1].setArray(quarter1, quarter2, quarter3, quarter4);
		divCheck[division - 1] = 'O';
	}
	//calls function to determine length of each quarter's sum
	determineSize(divisionSales, salesSize);

	//function to print results to output file
	printTable(outfile, divisionSales, salesSize);
	return 0;
}

/*
Functions:	printTable
Purposes:	print all quarterly sales for each division, the total quarterly sales across each 
			division, and the total sales for the corporation.
			Feel free to ignore this function. It's a lot of setwidths and dashes. All it does is 
			format and print to a file, so .......... yeah.
Parameters:	&outfile (to print to a file), divisionSales[], saleSize[]
Returns:	none
*/
void printTable(ofstream &outfile, DivSales divisionSales[], float salesSize[])
{
	/*declared variables for the elements of salesSize to make reading slightly easier
	An error will show up here since it's converting from float 'salesSize' to int*/
	int q1 = salesSize[0], q2 = salesSize[1], q3 = salesSize[2], q4 = salesSize[3];
	outfile << "Corbin Matamoros\n\n" << setprecision(2) << fixed
		<< setw(10) << " " << " " << setw(q1 + 1) << "Q1" << " " << setw(q2 + 1) << "Q2" << " " 
		<< setw(q3 + 1) << "Q3" << " " << setw(q4 + 1) << "Q4" << '\n' 
		<< "-----------------------------------------------------------------\n";

	//prints each division's quarterly sales, one per line
	for (int i = 0; i <= 5; i++)
	{
		outfile << setw(9) << "Division " << i + 1  << " $" << setw(q1) 
			<< divisionSales[i].getQuarter(1) << " $" << setw(q2) << divisionSales[i].getQuarter(2) 
			<< " $" << setw(q3) << divisionSales[i].getQuarter(3) << " $" << setw(q4) 
			<< divisionSales[i].getQuarter(4) << '\n';
	}

	//will print total quarterly sales across all divisions
	outfile << '\n' << "-----------------------------------------------------------------\n\n" 
		<< setw(10)  << left << "Q Totals  " << right <<  " $" << setw(q1) 
		<< divisionSales[0].getQuart1Sales() << " $" << setw(q2) << divisionSales[0].getQuart2Sales()
		<< " $" << setw(q3) << divisionSales[0].getQuart3Sales() << " $" << setw(q4) 
		<< divisionSales[0].getQuart4Sales();

	//will print the corporate total sales
	outfile << "\n\n-----------------------------------------------------------------\n\n" 
		<< "Corporate Total " << "$" << setw(10) << divisionSales[0].getTotSales();
}

/*
	Functions:	determineSize
	Purposes:	after main has finished reading in all the division's quarter sales and computed the
				total quarterly sales across all divisions, this function will take those totals
				and count how many digits are in each total. Those four sums will be used in the 
				printTable function in setw() functions. This function works when only positive values
				are entered in as quarterly sales (back in main). See NOTE at end of function.
	Parameters:	divisionSales[], saleSize[]
	Returns:	none
*/	
void determineSize(DivSales divisionSales[], float salesSize[])
{
	int counter = 0;

	salesSize[0] = divisionSales[0].getQuart1Sales();
	salesSize[1] = divisionSales[0].getQuart2Sales();
	salesSize[2] = divisionSales[0].getQuart3Sales();
	salesSize[3] = divisionSales[0].getQuart4Sales();

	for (int i = 0; i < 4; i++)
	{
		/*this loop will only count the digits before the decimal point,
		therefore the conditions check for numbers inbetween 1 and -1*/
		while (salesSize[i] >= 1 || salesSize[i] <= -1)
		{
			salesSize[i] /= 10;
			counter++;
		}

		/*the "+ 3" accounts for the decimal point (since the totals are floats)
		and the two digits after it. There will be an error here since I'm
		converting the integer variable 'counter' to a float.*/
		salesSize[i] = counter + 3;
		counter = 0;
	}
}	
/*
		NOTE: This function works as intended unless a larger negative number was
		entered as one of a division's quarterly sales. For example, if for quarter 4
		of division 1 the sales was as follows:

						    Q4
		----------------------
		Division 1 $   -100.00
		Division 2 $     25.00
		Division 3 $     25.00
		Division 4 $     25.00
		Division 5 $     24.00
		Division 6 $      0.00

		Q Total	   $      1.00

		The number of digits in the "Q Total" would be smaller (4 < 6) than the largest number 
		appearing in the Q4 column (100.00). Therefore, the setw function would set only 4 
		spaces for all of Q4 column, when 6 would be more appropriate, producing an output like so:

		Q4
		----------------------
		Division 1 $-100.00
		Division 2 $ 25.00
		Division 3 $ 25.00
		Division 4 $ 25.00
		Division 5 $ 24.00
		Division 6 $ 0.00

		Q Total	   $ 1.00

		where the decimal points are no longer aligned. I know a way to fix it, but for the purposes
		of this assignment. I'm not worried about it too much. 
*/
