#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main() {
	string enter_path = "enter_file.txt";
	string exit_path = "exit_file.txt";
	string str_first, temp_string;
	int number_of_string = 0;
	int value_of_repeats = 1;
	ifstream enter_file;
	ofstream exit_file;
	enter_file.open(enter_path);
	exit_file.open(exit_path);
	temp_string = "";
	exit_file << "Text First string Repeats \n";
	while (!enter_file.eof()) {
		getline(enter_file, str_first);
		number_of_string++;
		if (temp_string == str_first) {
			if (!str_first.empty()) {
				for (int i = 0; i < str_first.length(); i++) {
					if (str_first[i] < 48 || str_first[i] > 57) {
						str_first.clear();
						break;
					}
				}
				if (!str_first.empty()) {
					value_of_repeats++;
				}
			}
		}
		else {
			exit_file << value_of_repeats << " \n";
			value_of_repeats = 1;
			for (int i = 0; i < str_first.length(); i++) {
				if (str_first[i] < 48 || str_first[i] > 57) {
					str_first.clear();
					break;
				}
			}
			if (!str_first.empty()) {
				exit_file << str_first << " " << number_of_string << " ";
			}
		}
		if (str_first.empty())
			continue;
		temp_string = str_first;
	}

	enter_file.close();
	exit_file.close();
}







