#include <iostream>
#include "NDArray.h"


int main(){

	std::vector<int> shape{10};

	NDArray<double> ndarr1(shape);
	std::cout << "Fill with zeros: ";
	ndarr1.print();
	std::cout << std::endl;

	NDArray<double> ndarr2(shape, 1);
	std::cout << "Fill with ones: ";
	ndarr2.print();
	std::cout << std::endl;

	NDArray<double> ndarr3(shape, 0, 1);
	std::cout << "Fill with some random stuff: ";
	ndarr3.print();
	std::cout << std::endl;


	std::cout << "ndarr2 + 3 = "; (ndarr2 + 3).print(); std::cout << std::endl;
	std::cout << "ndarr2 - 8 = "; (ndarr2 - 8).print(); std::cout << std::endl;
	std::cout << "ndarr2 * 15 = "; (ndarr2 * 15).print(); std::cout << std::endl;
	std::cout << "ndarr2 / 24 = "; (ndarr2 / 24).print(); std::cout << std::endl;

	std::cout << "ndarr2 + ndarr3 = "; (ndarr2 + ndarr3).print(); std::cout << std::endl;
	std::cout << "ndarr2 - ndarr3 = "; (ndarr2 - ndarr3).print(); std::cout << std::endl;
	std::cout << "ndarr2 * ndarr3 = "; (ndarr2 * ndarr3).print(); std::cout << std::endl;
	std::cout << "ndarr2 / ndarr3 = "; (ndarr2 / ndarr3).print(); std::cout << std::endl;
	std::cout << "-ndarr3 = "; (-ndarr3).print(); std::cout << std::endl;

	return 0;

}
