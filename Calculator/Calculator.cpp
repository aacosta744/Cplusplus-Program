#include <iostream>

using namespace std;

int main()
{
	double op1, op2;

	char operation;

	char answer = 'Y';

	while (answer == 'Y' || answer == 'y')
	{
		cout << "Enter expression (Example: 2 + 2): " << endl;

		cin >> op1 >> operation >> op2;

		if (operation == '+')
		{
			cout << op1 << " + " << op2
				<< " = " << op1 + op2 << endl;
		}
		else if (operation == '-')
		{
			cout << op1 << " - " << op2
				<< " = " << op1 - op2 << endl;
		}
		else if (operation == '*')
		{
			cout << op1 << " * " << op2
				<< " =" << op1 * op2 << endl;
		}
		else if (operation == '/')
		{
			if (op2 != 0)
			{
				cout << op1 << " / " << op2
					<< " = " << op1 / op2 << endl;
			}
			else
			{
				cout << "Error: Cannot divide by zero." << endl;
			}
		}
		else
		{
			cout << "Invalid operator entered." << endl;
		}

		cout << "Do you wish to evaluate another experession? (Y/N): ";
		cin >> answer;
	}

	cout << "Program Finished." << endl;

	return 0;
}