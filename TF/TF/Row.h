#pragma once
#include <string>
#include <string.h>
#include <fstream>
using namespace std;

class Row
{
private:
	//vector<string>* arr;
	string* arr;

public:
	Row(int n = 1) {
		//arr = new vector<string>[n];
		arr = new string[n];

		for (int i = 0; i < n; ++i) {
			arr[i] = "";
			//arr->insert(arr->begin() + i, "//");
		}
			
	}
	~Row() {
		delete arr;
	}

	//void set_element2(string dato, int columna) { arr->insert(arr->begin() + columna, dato); }
	void set_element(string data, int column) { arr[column] = data; }

	string return_element(int column) { return arr[column]; }


};
