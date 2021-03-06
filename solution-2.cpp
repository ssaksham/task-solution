#include <bits/stdc++.h>
using namespace std;



// Tomohiko Sakamoto’s Algorithm
// Help from Geeksforgeeks
int day_of_the_week(string date)
{
	int y = 0, m = 0, d = 0;

	for (int i = 0; i <= 3; i++) {
		y = y * 10 + (date[i] - '0');
	}
	m = m * 10 + (date[5] - '0');
	m = m * 10 + (date[6] - '0');

	d = d * 10 + (date[8] - '0');
	d = d * 10 + (date[9] - '0');

	int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
	if (m < 3)
		y -= 1;
	int dayNumber =  ((y + y / 4 - y / 100 + y / 400 + t[m - 1] + d) % 7);
	dayNumber--;
	if (dayNumber < 0)
		dayNumber = 6;
	return dayNumber;
}


vector < pair<string, int>> solution(unordered_map<string, int> D) {
	auto it = D.begin();
	int arr[7] {0};
	while (it != D.end()) {
		arr[day_of_the_week(it->first)] += it->second;
		it++;
	}

	int prevDay = arr[0];
	int i = 0;
	while (i < 7) {
		if (!(arr[i])) {
			int j = i;
			int nthTerm = 1;

			while (!(arr[j])) {
				j++;
				nthTerm++;
			}
			int d = (arr[j] - prevDay) / nthTerm;
			int temp = i;
			int x = 1;
			while (temp != j) {
				arr[temp] = prevDay + x * d;
				x++;
				temp++;
			}
		}
		else
			prevDay = arr[i];
		i++;
	}
	return vector<pair<string, int>> {
		make_pair("Mon", arr[0]), make_pair("Tue", arr[1]), make_pair("Wed", arr[2]), make_pair("Thu", arr[3]), make_pair("Fri", arr[4]), make_pair("Sat", arr[5]), make_pair("Sun", arr[6])
	};
}



signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	unordered_map<string, int>D{
		{
			"2020-01-06", 2
		},
		{
			"2020-01-08", 6
		},
		{
			"2020-01-09", 3
		},
		{
			"2020-01-11", 9
		},
		{
			"2020-01-12", 15
		}
	};
	vector<pair<string, int>> result = solution(D);
	for (int i = 0; i < 7; i++)
		cout << result[i].first << " " << result[i].second << "\n";
}

