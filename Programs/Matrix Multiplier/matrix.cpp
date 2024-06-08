#include <iostream>
#include <string>
#include <vector>

class matrix
{
	std::vector< std::vector<int> > data;
	
	public:
	
	matrix()
	{
	}
	
	matrix(std::vector< std::vector<int> > const & d) : data(d)
	{
	}
	
	matrix(int m, int n)
	{
		set_size(m, n);
	}
	
	int & at(int i, int j)
	{
		return data.at(i).at(j);
	}
	
	int get_num_rows()
	{
		return data.size();
	}
	
	int get_num_cols()
	{
		return data.size() ? data.at(0).size() : 0;
	}
	
	void set_size(int m, int n)
	{
		data.resize(m);
		for(int i = 0; i < m; i++)
		{
			data.at(i).resize(n);
		}
	}
	
	std::string serialize()
	{
		std::string output;
		for(int i = 0; i < data.size(); i++)
		{
			for(int j = 0; j < data.at(i).size(); j++)
			{
				output += std::to_string(data.at(i).at(j)) + ' ';
			}
			output += '\n';
		}
		return output;
	}
	
	matrix operator*(matrix & other)
	{
		//TODO
		return matrix();
	}
};

int main()
{
	matrix x({{ 4,  8, 20},
			  {-2,  0,  6},
			  {13, -5,  7},
			  { 1, 15, -1}});
	
	matrix y({{ 2, -4,  1},
			  {19, 13, -7},
			  { 5,  6, 12}});
	
	matrix z = x * y;
	
	std::cout << z.serialize() << '\n';
	
	return 0;
}
