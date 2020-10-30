#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template <typename T>
vector<T> qsorter(vector<T>& v)
{
	if (v.size() < 2)
		return v;

	int mid = v.size() / 2;

	vector<T> temp;
	vector<T> result;
	copy_if(v.begin(), v.end(), back_inserter(temp), [=](auto& temp)
	{
		return temp < v[mid];
	});
	auto a = qsorter(temp);

	copy(a.begin(), a.end(), back_inserter(result));
	result.push_back(v[mid]);

	temp.clear();
	copy_if(v.begin(), v.end(), back_inserter(temp), [=](auto& temp)
	{
		return temp > v[mid];
	});
	auto b = qsorter(temp);

	copy(b.begin(), b.end(), back_inserter(result));
	return result;
}

int main()
{
	vector<double> v{ 2.3, 5.1, 1.932472, 8.18, 7, 16, 10.128, 4, 6, 80.0912, 33 };

	for (auto& i : qsorter(v))
		cout << i << " ";
	
	system("pause");
}