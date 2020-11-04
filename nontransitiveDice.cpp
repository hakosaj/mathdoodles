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
std::mt19937 rng(rd());
std::uniform_int_distribution<int> uni(0,9);

bool thisWinsThat(vector<int> die1, vector<int> die2, int repeats=10000, int sides=6) {
	int firstwins=0;
	int secondwins=0;
	std::uniform_int_distribution<int> side(0,sides);
	for (int i=0;i<repeats;i++) {

		auto sd1=die1[side(rng)];
		auto sd2=die2[side(rng)];
		if (sd1>sd2) {
			firstwins++;
		}else if (sd1==sd2) {
			;
		}else {
			secondwins++;
		}
	}
	return firstwins*10>(secondwins*11);

}	


vector<int> testNonTransitiveness(vector<int> die1,vector<int> die2,vector<int> die3,int sides=6) {

	//First and second
	bool w21=thisWinsThat(die2,die1);
	bool w32=thisWinsThat(die3,die2);
	bool w13=thisWinsThat(die1,die3);

	//if (w21&&w32&&w13) 

	return {0,1};
}

int main() {	
	auto start_time = std::chrono::high_resolution_clock::now();

	int sides=6;




	vector<int> dices;

	vector<int> die1;
	vector<int> die2;
	vector<int> die3;


	bool found=false;

	//Tries
	int trie1=0;
	int trie2=0;
	int trie3=0;

	int maxtries=100;
	while (!found) {
		//First one
		die1=vector<int>(sides);
		std::generate(die1.begin(),die1.end(),[](){return uni(rng);});

		//die 2
		die2=vector<int>(sides);
		std::generate(die2.begin(),die2.end(),[](){return uni(rng);});
		while (!thisWinsThat(die2,die1)) {
			die2=vector<int>(sides);
			std::generate(die2.begin(),die2.end(),[](){return uni(rng);});
			
		}
		found=true;
		

		//die 3
		die3=vector<int>(sides);
		std::generate(die3.begin(),die3.end(),[](){return uni(rng);});
		while (!(thisWinsThat(die3,die2) && thisWinsThat(die1,die3))) {
			die3=vector<int>(sides);
			std::generate(die3.begin(),die3.end(),[](){return uni(rng);});
			trie3++;
			if (trie3==maxtries) {
				die2=vector<int>(sides);
				std::generate(die2.begin(),die2.end(),[](){return uni(rng);});
				trie3=0;
				trie2++;
				if (trie2==maxtries) {
					die2=vector<int>(sides);
					std::generate(die1.begin(),die1.end(),[](){return uni(rng);});
					trie2=0;
				}

			}
		}
		found=true;
		








		

	}

	for (int i=0;i<die1.size();i++) {
		cout<<die1[i]<<" and "<< die2[i]<<" and " << die3[i]<<endl;
	}




	auto end_time = std::chrono::high_resolution_clock::now();
	cout <<"\nElapsed: "<< std::chrono::duration_cast<std::chrono::seconds>(end_time - start_time).count() << ".";
	cout << std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count() << " seconds." <<endl;




}