#include <iostream>
#include <fstream>

int rows = 0, cols = 0;
int main() {
	std::ifstream file("/Users/tr/Desktop/advent_of_code/2015day3/input.txt");
	std::ifstream amount("/Users/tr/Desktop/advent_of_code/2015day3/input.txt");
	
	int housecounter = 1, house = 0;
	

	char n = '^', e = '>', w = '<', s = 'v';
	

	char check;
	char aaaa;
	int counter=0;

	while (1) {
		amount >> aaaa;
		if (!file) {
			break;
		}
		counter++;
	}
	
	int** table = new int* [counter];
	for (int i = 0;i < counter;i++) {
		table[i] = new int[counter];
	}
	for (int i = 0;i < counter;i++) {
		for (int j = 0;j < counter;j++) {
			table[i][j] = 0;
		}
	}
	
	while (1) {
		file >> check;
		if (!file) {
			break;
		}
		else if (check == n) {
			cols++;
			table[rows][cols] += 1;
		}
		else if (check == s) {
			cols--;
			table[rows][cols] += 1;
		}
		else if (check == e) {
			rows++;
			table[rows][cols] += 1;
		}
		else if (check == w) {
			rows--;
			table[rows][cols] += 1;
		}
		
	}

	for (int i = 0;i < counter;i++) {
		for (int j = 0;j < counter;j++) {
			if (table[i][j] != 0) {
				housecounter++;
			}
		}
	}

	std::cout << housecounter << std::endl;

	for (int i = 0;i < counter;i++) {
		delete[]table[i];
	}
	delete[]table;
	table = NULL;

	system("pause");
	return 0;

	

}