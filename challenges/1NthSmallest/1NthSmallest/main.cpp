#include <iostream>
#include <vector>

using namespace std;

int findNthSmallest(vector<int> numbers, int n)
{
	if (numbers.empty())//check for emtptyness
	{
		return 0;
	}
	else if (n > numbers.size())
	{
		cout << n << " is out of vector range." << endl;
		return n;
	}

	//set minimum = first element in vector
	//set next = numbers[0 + 1]
	int minimum, next, current;
	minimum = next = current = numbers[0];

	for (auto number : numbers)
	{
		if (number < minimum)//if current number is less than current minimum
		{
			minimum = number;//set the new minimum
		}
	}

	//find the nth smallest number in vector
	if (n == 1) return minimum;

	for (int i = 0; i < (n - 1); i++)
	{
		for (auto number : numbers)
		{
			if (number > minimum && number <= next)
			{
				next = number;
			}
		}
		minimum = next;
		next = numbers[0];
	}

	return minimum;
}

int main()
{
	vector<int> numbers{ 1, 3, 2, 5, 9, 8, 6 };

	int out_of_range = findNthSmallest(numbers, 8);
	int result2 = findNthSmallest(numbers, 0);
	int result3 = findNthSmallest(numbers, 3);
	int result4 = findNthSmallest(numbers, 4);


	cout << "Return n for out of range: " << out_of_range << endl;
	cout << result2;
	cout << result3;
	cout << result4;

	return 0;
}