//Luis Ruiz
#include <iostream>
#include <vector>

using namespace std;

vector<int> mergeSorted(vector<int> v1, vector<int> v2)
{
	vector<int> merged{};

	int index = 0;
	while (index < v1.size() && index < v2.size())//make sure not to go out of vector range
	{
		if (v1[index] < v2[index])
		{
			merged.push_back(v1.front());//push back front value in merged vector
			v1.erase(v1.begin());//erase the front element from v1
		}
		else
		{
			merged.push_back(v2.front());//push back front value in merged vector
			v2.erase(v2.begin());//erase the front element from v2
		}
	}

	//if one of the vectors is empty before all values have been compared
	//push back remaining elements of said vector.
	if (v1.empty())
	{
		while (v2.empty() == false)
		{
			merged.push_back(v2.front());
			v2.erase(v2.begin());
		}
	}
	else if (v2.empty())
	{
		while (v1.empty() == false)
		{
			merged.push_back(v1.front());
			v1.erase(v1.begin());
		}
	}

	//**test** 
	//print elements of merged vector to screen to verify
	for (int i = 0; i < merged.size(); i++)
	{
		cout << merged[i] << ' ';
	}

	return merged;//return the new vector
}

int main()
{
	vector<int> v1{ 1, 7, 9 };
	vector<int> v2{ 4, 5, 11 };
	vector<int> v3{ 12, 13, 14 , 99};
	vector<int> v4{ 2, 3, 11 };

	mergeSorted(v1, v2);
	cout << endl;
	mergeSorted(v3, v4);
	cout << endl;
	mergeSorted(v2, v1);
	cout << endl;
	mergeSorted(v4, v3);
	
	//this is how it should look when saving your new vector in main
	//vector<int> mergedVector = mergeSorted(v1, v2);

	return 0;
}