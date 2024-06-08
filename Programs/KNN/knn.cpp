#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct Point
{
	double x = 0.0;
	double y = 0.0;
	int    c = 0;
	
	Point(double _x, double _y, int _c) : x(_x), y(_y), c(_c) {}
};

struct Neighbour
{
	double d = 0.0;
	int    c = 0;
	
	Neighbour(int _d, double _c) : d(_d), c(_c) {}
};

int get_mode(vector<int> & valores)
{
	double maisRepetido = 0.0;
	int indiceDoMaisRepetido = 0;
	for(int i = 0; i < valores.size(); ++i)
	{
		int numRepeticoes = 0;
		for(int j = i + 1; j < valores.size(); ++j)
		{
			if(valores[i] == valores[j])
			{
				numRepeticoes++;
			}
		}
		if(numRepeticoes > maisRepetido)
		{
			maisRepetido = numRepeticoes;
			indiceDoMaisRepetido = i;
		}
	}
	return valores[indiceDoMaisRepetido];
}

template <int k = 3>
int knn(vector<Point> const & points, double x, double y)
{
	vector<Neighbour> neighbours;
	
	for(int i = 0; i < points.size(); ++i)
	{
		double distance = sqrt(pow(x - points[i].x, 2) + pow(y - points[i].y, 2));
		neighbours.push_back(Neighbour(distance, points[i].c));
	}
	
	sort(neighbours.begin(), neighbours.end(), [&](Neighbour & a, Neighbour & b){return a.d < b.d;});
	
	vector<int> categories;
	
	for(int i = 0; i < k; i++)
	{
		categories.push_back(neighbours[i].c);
	}
	
	return get_mode(categories);
}

int main()
{
	vector<Point> points = {{32.44, 15.55, 2},
							{24.45, 55.00, 2},
							{64.13, 35.71, 5},
							{13.76, 75.24, 1},
							{67.47,  5.65, 5},
							{76.85, 35.45, 3},
							{52.35, 65.23, 6},
							{45.46, 65.78, 2},
							{87.95, 75.13, 4},
							{93.11, 25.70, 4},
							{78.31, 15.01, 3},
							{47.11, 55.23, 2},
							{22.04,  5.05, 1},
							{12.00, 45.47, 1},
							{54.19, 25.23, 5},
							{98.19, 75.69, 4},
							{12.78, 25.02, 1},
							{18.64, 35.10, 2},
							{ 9.93, 85.47, 1},
							{67.01, 55.19, 5},
							{56.51, 25.76, 6},
							{94.29,  5.45, 4},
							{13.34, 55.52, 2},
							{42.44, 15.43, 2},
							{78.54, 25.23, 3},
							{65.68, 25.55, 5},
							{22.87, 85.12, 1},
							{23.98, 65.32, 3},
							{41.33, 85.78, 5},
							{19.05, 25.02, 1},
							{ 2.13, 95.00, 1},
							{43.54, 25.12, 2},
							{87.43,  5.32, 4},
							{67.27, 15.54, 5},
							{79.72, 25.85, 5},
							{71.78, 85.35, 4},
							{90.45, 45.49, 4},
							{20.66, 65.41, 1},
							{23.26, 95.68, 2}};
	
	cout << knn2<3>(points, 20.00, 10.00) << '\n';
	cout << knn2<3>(points, 10.00, 20.00) << '\n';
	cout << knn2<3>(points, 40.00, 40.00) << '\n';
	cout << knn2<3>(points, 20.00, 50.00) << '\n';
	cout << knn2<3>(points, 10.00, 60.00) << '\n';
	cout << knn2<3>(points, 90.00, 20.00) << '\n';
	cout << knn2<3>(points, 40.00, 80.00) << '\n';
	cout << knn2<3>(points, 70.00, 70.00) << '\n';
	
	return 0;
}

