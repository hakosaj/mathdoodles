#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <omp.h>
#include <fstream>
#include <string>
#include <sstream>
#include <iterator>
#include <chrono>
#include <cstring>
#include <random>
#include <unordered_map>

using std::cout;
using std::endl;
using std::vector;
using std::string;

std::random_device rd;
std::default_random_engine eng(rd());
std::uniform_real_distribution<> distr(0,1);


int main() {	
	auto start_time = std::chrono::high_resolution_clock::now();



	vector<double> lens;
	int poscount=0;
	int g=100000000;
//lens.push_back(std::abs(2*sin(distr(eng)*90.0))<<endl);
	for (int i=0;i<g;i++) {
		if (std::abs(2*sin(distr(eng)*90.0))>1)
			poscount++;

	}
	cout<<poscount<<endl;
	cout<<g<<endl;
	double spec=double(poscount)/double(g);
	cout<<spec<<endl;


	auto end_time = std::chrono::high_resolution_clock::now();
	cout <<"\nElapsed: "<< std::chrono::duration_cast<std::chrono::seconds>(end_time - start_time).count() << ".";
	cout << std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count() << " seconds." <<endl;




}