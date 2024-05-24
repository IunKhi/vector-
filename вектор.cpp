#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

int main() {
	std::ifstream infile("input.txt");
	if (!infile) {
		std::cerr << "Error opening file" << std::endl;
		return 0;
	}
	std::vector<int> vec;
	int num;
	while (infile >> num) {
		vec.push_back(num);
	}

	infile.close();

	 
	std::reverse(vec.begin(), vec.end()); //реверсируем последовательность элементов 

	
	int min_element = *std::min_element(vec.begin(), vec.end()); //минимальный элемент
	std::cout << "Minimum element: " << min_element << std::endl;


	vec.erase(std::remove_if(vec.begin(), vec.end(), [](int i) { return i % 2 == 0; }), vec.end()); //удаляем все четные элементы

	std::sort(vec.begin(), vec.end()); //сортируем в убывающем порядке

	int new_element = 14; 
	vec.push_back(new_element);
	std::sort(vec.begin(), vec.end());

	int element_to_find = 50;
	auto it = std::find(vec.begin(), vec.end(), element_to_find);
	if (it != vec.end()) {
		int index = std::distance(vec.begin(), it);
		std::cout << "Index of " << element_to_find << ": " << index << std::endl;
	}
	else {
		std::cout << "Element not found" << std::endl;
	}

	vec.erase(std::unique(vec.begin(), vec.end()), vec.end()); //удаляем дубли


	std::cout << "Final vector:" << std::endl;
	for (int i : vec) {
		std::cout << i << " ";
	}
	std::cout << std::endl;

	infile.close();

	return 0;
}