#pragma once
#include <vector>
#include "AVL_Tree.h"
#include "Row.h"
using namespace std;

class MainLibrary
{
private:
	AVL_Tree<Row*, int, nullptr>* ind;
	AVL_Tree<Row*, string, nullptr>* ind2;
	bool ind_type;
	bool ind2_type;

	int indx;

	//List<Row*> ro;
	int n_rows;
	int n_columns;

	vector<Row*> v_rows; //Filas tabla inicial <-

	vector<Row*> v_news; //Filas tabla secundaria <-



	//string* result;
public:
	MainLibrary(int column) {
		n_rows = 0;
		n_columns = column;
		ind = nullptr;
		ind2 = nullptr;
	}
	~MainLibrary() {

	}

	//Vectores
	void insert_row();
	void set_elements(string data, int row, int column);
	void index(int column, bool type);

	void search(string data);
	void search_all(string data);
	void search_upper(string data);
	void search_lower(string data);
	void search_startWith(string data);
	void search_endtWith(string data);
	void search_contain(string data);
	void search_NOcontain(string data);

	void ascending_order();
	void descending_order();

	void set_file();

};