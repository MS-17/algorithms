#pragma once

#include <iostream>
#include <vector>

template<typename T>
class NDArray{

	std::vector<int> shape;
	std::vector<T> array;

public:

	NDArray(std::vector<int> _shape, bool fill_ones = false, bool fill_random = false){

		shape = _shape;
		int length = 1;
		for(auto& i : shape){
			length *= i;
		}

		array.reserve(length);

		if(fill_ones){

			for(int i{}; i < length; i++){
				array.push_back(1);
			}

		} else if(fill_random){

			for(int i{}; i < length; i++){
				array.push_back(rand() % 1000001);
			}

		} else{

			for(int i{}; i < length; i++){
				array.push_back(0);
			}

		}

	}

	~NDArray(){}//std::cout << "\nAaaa"; }


	NDArray(const NDArray& ndarr){
		shape = ndarr.shape;
		array = ndarr.array;
	}

	/*NDArray operator [] (int indeces){
		// int i = indeces[0];
		return array[indeces];
	}*/

	// operator += is a base operator for +, -=, -(binary)
	template<typename T1>
	NDArray& operator += (const T1& arg){

		if constexpr (std::is_arithmetic_v<T1>){
			for(int i{}; i < array.size(); i++){
				array[i] += arg;
			}
		} else if (std::is_same<T1, NDArray>::value){
			for(int i{}; i < array.size(); i++){
				array[i] += arg.array[i];
			}
		} else std::cout << "This didn't work";

		return *this;

	}

	template<typename T1>
	NDArray operator + (const T1& arg){
		NDArray result(*this);
		result += arg;
		return result;
	}

	NDArray operator - () const {

		NDArray result(*this);
		for(int i{}; i < result.array.size(); i++){
			result.array[i] *= -1;
		}

		return result;

	}

	template<typename T1>
	NDArray& operator -= (const T1& arg){
		(*this) += -arg;
		return (*this);
	}

	template<typename T1>
	NDArray operator - (const T1& arg){
		NDArray result(*this);
		result -= arg;
		return result;
	}

	//a base operator for * operator
	template<typename T1>
	NDArray& operator *= (const T1& arg){

		if constexpr (std::is_arithmetic_v<T1>){
			for(int i{}; i < array.size(); i++){
				array[i] *= arg;
			}
		} else if (std::is_same<T1, NDArray>::value){
			for(int i{}; i < array.size(); i++){
				array[i] *= arg.array[i];
			}
		} else std::cout << "This didn't work";

		return *this;

	}

	template<typename T1>
	NDArray operator * (const T1& arg){
		NDArray result(*this);
		result *= arg;
		return result;
	}

	//a base operator for / operator
	template<typename T1>
	NDArray& operator /= (const T1& arg){
		if constexpr (std::is_arithmetic_v<T1>){
			for (int i = 0; i < array.size(); ++i){
				array[i] /= arg;
			}
		} else if (std::is_same<T1, NDArray>::value){
			for (int i = 0; i < array.size(); ++i){
				array[i] /= arg.array[i];
			}
		}
		return (*this);
	}

	template<typename T1>
	NDArray operator / (const T1& arg){
		NDArray result(*this);
		result /= arg;
		return result;
	}

/*	NDArray mul(const T& arg){

		std::vector s{shape[1], arg.shape[0]};
		NDArray result(s);

		for (int i{}; i < array.size(); ++i){
			for (int j{}; j < arg.array.size(); ++j){
				result.array[i] += array[i  + j] * arg.array[i];
			}
		}

	}
*/

	void print(){
		std::cout << "[";
		for(int i{}; i < array.size() - 1; i++){
			std::cout << array[i] << " ";
		}
		std::cout << array.back() << "]";
	}

	std::vector<int> getShape(){
		return shape;
	}

};



