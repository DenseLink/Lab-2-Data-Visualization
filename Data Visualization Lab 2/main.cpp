
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <iomanip>
#include <cctype>
//FIXME: stream manipulation library
using namespace std;



int main()
{
	/* Type code here. */
	/* Overall flow of the program:
	Get some input for the title
	Get some input for column header #1
	Get some input for column header #2

	Until the user types "-1":
	Get input for a string
	Validate input
	If valid...
	   Split
	   Validate second half of input
	   If also valid...
		  Store separate pieces

	Print out data in table format

	Print out data in chart format
	*/
	string input;

	//Prompt the user for a title for data. Output the title. (1 pt) 
	cout << "Enter a title for the data:" << endl;
	getline(cin, input);
	cout << "You entered: " << input << endl << endl;

	//Prompt the user for the headers of two columns of a table. Output the column headers. (1 pt) 
	string header;
	string header2;
	cout << "Enter the column 1 header:" << endl;
	getline(cin, header);

	cout << "You entered: " << header << endl;
	cout << endl;
	cout << "Enter the column 2 header:" << endl;
	getline(cin, header2);
	cout << "You entered: " << header2 << endl << endl;
	//Prompt the user for data points. Data points must be in this format: string, int. 
	//Store the information before the comma into a string variable and the information after the comma into an integer.
	//The user will enter -1 when they have finished entering data points. Output the 
	//data points. Store the string components of the data points in a vector of strings. Store the integer components of 
	//the data points in a vector of integers.


	int test3While;
	test3While = 0;
	vector<string> dataString;//this vector needs to be able to change size
	vector<int> dataInt;
	while (test3While != -1)
	{
		try {
			cout << "Enter a data point (-1 to stop input):" << endl;
			string test3;
			getline(cin, test3);

			int exitWhile;
			exitWhile = test3.find("-1");


			if (exitWhile == 0)
			{
				test3While = -1;


			}
			else// if (preventTheElse == 0)
			{

				//begin try/catch statements for user input

				//try {
				int tryCatch1;
				tryCatch1 = test3.find(',');
				if (!(tryCatch1 >= 0))// || tryCatch1 <= 0))
				{
					throw runtime_error("Error: No comma in string.");
				}


				//int tryCatch1;
				//tryCatch1 = test3.find(',');
				int tryCatch2;
				int tryCatch3;
				string tryCatch4;
				tryCatch2 = test3.find(','); //This value searches for where the first , is
				tryCatch3 = test3.rfind(','); //This value searches for where a second , is
				//try {
				if (tryCatch2 != tryCatch3) // if the comma that is found does not match locations then an error is thrown
				{
					throw runtime_error("Error: Too many commas in input.");
				}
				//}

				//end try catch statements for user input



				int x;
				x = test3.find(','); //this variable determines at what location the , is at
				string y;
				int test3Size;
				test3Size = sizeof(test3);
				int x2;
				x2 = x + 2; //This value takes the location of , and adds 2 to that number so to incorporate the space before where the number begins
				y = test3.substr(x2, test3Size); // This value extracts the number from where it begins to where it ends
				//try {
				//cout << y.at(1);
				bool finalCatch;
				finalCatch = false;
				for (unsigned int i = 0; i < y.size(); i++)
				{
					//int k;

					if (isdigit(y.at(i)) || isspace(y.at(i)))
					{
						finalCatch = true;
						//cout << y.at(i) << endl;
					}
				}
				if (finalCatch == 0)
				{
					throw invalid_argument("Error: Comma not followed by an integer.");
				}
				//cout << finalCatch << "this is testing the for statement" << endl;
				int z;
				z = stoi(y);
				/*if (!(z <= 0 || z >= 0)) {

					throw invalid_argument("Error: Comma not followed by an integer");
				}*/

				//}

				//cout << y << " testing variable y" << endl;
				//int z;
				//z = stoi(y); // this value converts the number that user inputs as a string and turns it into an integer.


				//cout << z << " testing variable z" << endl;
				dataInt.push_back(z); //this increases the size of the vector while incorporating the string y
				string a;
				a = test3.substr(0, x);
				dataString.push_back(a);
				cout << "Data string: " << a << endl; // << "This is the string vector repeating for " << i << " times" << endl;
				cout << "Data integer: " << z << endl << endl; // "this is the int vector repeating for " << i << " times" << endl;
			}
		}
		catch (runtime_error& excpt) {
			//cout << "Error: No comma in string." << endl << endl;
			cout << excpt.what() << endl << endl;
		}
		/*catch (int 2) {
			cout << "Error: Too many commas in input.";
		}*/
		catch (invalid_argument& excpt) {
			//cout << "Error: Comma not followed by an integer" << endl;
			cout << excpt.what() << endl << endl;
		}

		/*Output the information in a formatted table.The title is right justified with a setw() value of 33.
		Column 1 has a setw() value of 20. Column 2 has a setw() value of 23.*/
	}


	cout << endl << setw(33) << right << input << endl;
	cout << setw(20) << left << header << "|" << setw(23) << right << header2 << endl;
	for (unsigned int i = 0; i < 44; i++)
	{

		cout << "-";
	}
	cout << endl;

	for (unsigned int i = 0; i < dataString.size(); i++)
	{

		cout << setw(20) << left << dataString[i] << "|" << setw(23) << right << dataInt[i] << endl; // "Data string: " << dataString[k] << endl; // << "This is the string vector repeating for " << i << " times" << endl;
		//cout << "Data integer: " << dataInt[k] << endl; // "this is the int vector repeating for " << i << " times" << endl;

	}
	cout << endl;
	for (unsigned int i = 0; i < dataString.size(); i++)
	{
		cout << setw(20) << dataString[i] << " ";
		dataInt[i];
		for (int k = 0; k < dataInt.at(i); k++)
		{
			cout << "*";
		}
		cout << endl;
	}
	return 0;
}


