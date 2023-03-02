#include <iostream>
#include <cmath>
#include <fstream>
#include <map>
#include <chrono>


int main(){

	std::map<int, int> myMap {};
	std::fstream fout("data.txt", std::fstream::out);

	int n = 0;
	int iterations = 7;
	for (int i{}; i < iterations + 1; i++){

		auto t1 = std::chrono::high_resolution_clock::now();

		n = std::ceil(std::pow(10, i));
		for(int j{}; j < n; j++){
			myMap[j] = j;
		}

		auto t2 = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double, std::milli> elapsed = t2 - t1;

		fout << n << " " << elapsed.count() << " " << (2 * sizeof(int) + sizeof(std::_Rb_tree_node_base)) * n << "\n";

		myMap.clear();

	}

	fout.close();
	std::cout << std::endl;
	return 0;
}