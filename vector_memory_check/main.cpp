#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>


int main(){

	std::vector<float> vec;

	std::fstream fout("data.txt", std::fstream::out);
	if(!fout.is_open()){
		return -1;
	}

	int n = 0;
	for(int i{}; i < 9; i++){
		n = std::ceil(std::pow(10, i));
		for (int j{}; j < n; j++){
			vec.push_back(j);
		}
		std::cout << "Elements number: " << n << "\t\tVector size: " <<  sizeof(std::vector<float>) + sizeof(float) * vec.size() << "\tWrite to file" << std::endl;
		fout << n << " " << sizeof(std::vector<float>) + sizeof(float) * vec.size() << "\n";
	}

    std::cout << "End\n\n";
    fout.close();
	return 0;
}