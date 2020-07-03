#include "MainLibrary.h"
#include <fstream>
#include <iostream>
#include <functional>
using namespace std;

//Vectores
void MainLibrary::insert_row() {
	v_rows.push_back(new Row(n_columns));
}
void MainLibrary::set_elements(string data, int row, int column) {
	v_rows[row]->set_element(data, column);
}
void MainLibrary::index(int column, bool type) {
	indx = column;
	ind_type = type;
	ind2_type = type;

	if (type) {
		auto key = [&](Row* a) {return a->return_element(indx); };
		ind2 = new AVL_Tree<Row*, string, nullptr>(key);
		for (auto al : v_rows) {
			ind2->add(al);
		}
	}
	else {
		auto key = [&](Row* a) {
			int id;
			if (a->return_element(indx) != "")
				id = stoi(a->return_element(indx));
			else id = -131717171;

			return id;
		};

		ind = new AVL_Tree<Row*, int, nullptr>(key);
		for (auto al : v_rows) {
			ind->add(al);
		}
	}

}


void MainLibrary::search(string data) {

	if (ind_type) v_news.push_back(ind2->find(data));
	else {
		int num;
		if (data != "")
			num = stoi(data);
		else
			num = -131717171;
		v_news.push_back(ind->find(num));
	}

	ofstream archivo;
	archivo.open("registro.txt");

	set_file();
}

void MainLibrary::search_all(string data) {
	if (ind_type) v_news = ind2->find_all(data);
	else {
		int num;
		if (data != "")
			num = stoi(data);
		else
			num = -131717171;
		v_news = ind->find_all(num);
	}

	set_file();
}
void MainLibrary::search_upper(string data) {
	if (ind_type) v_news = ind2->find_upper(data);
	else {
		int num;
		if (data != "")
			num = stoi(data);
		else
			num = -131717171;
		v_news = ind->find_upper(num);
	}

	set_file();
}
void MainLibrary::search_lower(string data) {
	if (ind_type) v_news = ind2->find_lower(data);
	else {
		int num;
		if (data != "")
			num = stoi(data);
		else
			num = -131717171;
		v_news = ind->find_lower(num);
	}

	set_file();
}
void MainLibrary::set_file() {
	ofstream archivo;
	archivo.clear();
	archivo.open("registro.txt");
	for (int i = 0; i < v_news.size(); ++i) {
		if (v_news[i] != nullptr) {
			for (int j = 0; j < n_columns; ++j) {
				archivo << v_news[i]->return_element(j) << "\t|";
			}
			archivo << endl;
		}
	}
	archivo.close();
}
void MainLibrary::search_startWith(string data) {

	if (ind_type == true) {
		auto startWith = [&](Row* a) {
			if (a->return_element(indx) == "") return a->return_element(indx);
			for (int i = 0; i < data.size(); ++i) {
				if (data[i] != a->return_element(indx)[i]) return a->return_element(indx);
			}
			return data;
		};
		v_news = ind2->find_ContaiN(data, startWith);
	}
	else {
		int num;
		if (data != "")
			num = stoi(data);
		else
			num = -131717171;

		auto startWith = [&](Row* a) {
			if (a->return_element(indx) == "") return -131717171;
			for (int i = 0; i < data.size(); ++i) {
				if (data[i] != a->return_element(indx)[i]) return -131717171;
			}
			return num;
		};
		v_news = ind->find_ContaiN(num, startWith);
	}

	set_file();
}
void MainLibrary::search_endtWith(string data) {

	if (ind_type) {
		auto endtWith = [&](Row* a) {
			if (a->return_element(indx) == "") return a->return_element(indx);
			int j = 0;
			for (int i = (a->return_element(indx).size() - data.size()); i < a->return_element(indx).size(); ++i) {
				if (data[j] != a->return_element(indx)[i]) return a->return_element(indx);
				j++;
			}
			return data;
		};

		v_news = ind2->find_ContaiN(data, endtWith);
	}
	else {
		int num;
		if (data != "")
			num = stoi(data);
		else
			num = -131717171;

		auto endtWith = [&](Row* a) {
			if (a->return_element(indx) == "") return -131717171;
			int j = 0;
			for (int i = (a->return_element(indx).size() - data.size()); i < a->return_element(indx).size(); ++i) {
				if (data[j] != a->return_element(indx)[i]) return -131717171;
				j++;
			}
			return num;
		};

		v_news = ind->find_ContaiN(num, endtWith);
	}


	set_file();
}

void MainLibrary::search_contain(string data) {

	if (ind_type) {
		auto contain = [&](Row* a) {
			if (a->return_element(indx) == "") return a->return_element(indx);
			int j = 0;
			for (int i = 0; i < a->return_element(indx).size(); ++i) {
				if (data[j] == a->return_element(indx)[i]) j++;
				if (j == data.size()) return data;
			}

			return a->return_element(indx);
		};

		v_news = ind2->find_ContaiN(data, contain);
	}
	else {
		int num;
		if (data != "")
			num = stoi(data);
		else
			num = -131717171;

		auto contain = [&](Row* a) {
			if (a->return_element(indx) == "") return -131717171;
			int j = 0;
			for (int i = 0; i < a->return_element(indx).size(); ++i) {
				if (data[j] == a->return_element(indx)[i]) j++;
				if (j == data.size()) return num;
			}
			return -131717171;
		};

		v_news = ind->find_ContaiN(num, contain);
	}

	set_file();
}
void MainLibrary::search_NOcontain(string data) {

	if (ind_type) {
		auto NOcontain = [&](Row* a) {
			if (a->return_element(indx) == "") return data;

			int j = 0;
			for (int i = 0; i < a->return_element(indx).size(); ++i) {
				if (data[j] == a->return_element(indx)[i]) j++;
				if (j == data.size()) return a->return_element(indx);
			}
			return data;
		};

		v_news = ind2->find_ContaiN(data, NOcontain);
	}
	else {
		int num;
		if (data != "")
			num = stoi(data);
		else
			num = -131717171;

		auto NOcontain = [&](Row* a) {
			if (a->return_element(indx) == "") return num;

			int j = 0;
			for (int i = 0; i < a->return_element(indx).size(); ++i) {
				if (data[j] == a->return_element(indx)[i]) j++;
				if (j == data.size()) return -131717171;
			}
			return num;
		};

		v_news = ind->find_ContaiN(num, NOcontain);
	}

	set_file();
}

void MainLibrary::ascending_order() {

	v_news.clear();
	auto order = [&](Row* a) {
		v_news.push_back(a);
	};

	if (ind_type)
		ind2->inOrder(order);
	else
		ind->inOrder(order);

	set_file();
}
void MainLibrary::descending_order() {

	v_news.clear();
	auto order = [&](Row* a) {
		v_news.push_back(a);
	};

	if (ind_type)
		ind2->postOrder(order);
	else
		ind->postOrder(order);

	ofstream archivo;
	archivo.open("registro.txt");
	archivo.clear();
	for (int i = v_news.size() - 1; i >= 0; --i) {
		if (v_news[i] != nullptr) {
			for (int j = 0; j < n_columns; ++j) {
				archivo << v_news[i]->return_element(j) << "\t|";
			}
			archivo << endl;
		}
	}
	archivo.close();
}