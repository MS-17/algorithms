#include <iostream>
/*#include <cmath>
#include <fstream>
#include <map>
#include <chrono>*/
#include "NDArray.h"


int main(){

	std::vector<int> shape{10};

	NDArray<double> ndarr(shape, 1);

	// ndarr.print();

	NDArray ndarr_copy(ndarr);
	std::cout << ndarr_copy.getShape()[0] << "\n";
	ndarr += ndarr_copy;
	NDArray a = ndarr_copy;
	a *= (ndarr * 3);
	a.print();
	a /= 40.0;
	NDArray b = a / 10;
	a.print();
	b.print();
	// std::vector<int> indeces{0};
	// std::cout << indeces[0];
	// std::cout << a[*indeces[0]];

	// ndarr.print();
	// ndarr_copy.print();

	// std::cout << std::is_same<int, int>::value;
	// std::cout << ndarr[{0, 2}];
	// std::cout << ndarr.getShape()[0];
	// std::cout << "Hello";

	return 0;

}