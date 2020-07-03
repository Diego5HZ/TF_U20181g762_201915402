#pragma once
#include "MainLibrary.h"
#include "vector"
#include "string"
namespace TF {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace std;
	using namespace System;
	/// <summary>
	/// Summary for frmMenu
	/// </summary>
	public ref class frmMenu : public System::Windows::Forms::Form
	{
		
	public:
		frmMenu(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
	public: void frmMenu::InsertTable(DataGridView^ data, int nVeces) {
		for (int i = 0; i < nVeces; i++)
		{
			//cbxSearch->Items->Add(data->Rows[i]->Cells[1]->Value->ToString());
			cbxIndex->Items->Add(data->Rows[i]->Cells[1]->Value->ToString());
			dpiNew = gcnew ToolStripMenuItem;
			dpUp = gcnew ToolStripMenuItem;
			dpDown = gcnew ToolStripMenuItem;
			tsmEdit->DropDownItems->Add(dpiNew);
			dpiNew->Text = data->Rows[i]->Cells[1]->Value->ToString();
			dpUp->Text = "Ascending order";
			dpDown->Text = "Descending order";
			dpUp->Click += gcnew System::EventHandler(this, &TF::frmMenu::ClickUp);
			dpDown->Click += gcnew System::EventHandler(this, &TF::frmMenu::ClickDown);
			dpiNew->DropDownItems->Add(dpUp);
			dpiNew->DropDownItems->Add(dpDown);
			grdvData->Columns->Add(data->Rows[i]->Cells[1]->Value->ToString(), data->Rows[i]->Cells[1]->Value->ToString());
			grdvSearch->Columns->Add(data->Rows[i]->Cells[1]->Value->ToString(), data->Rows[i]->Cells[1]->Value->ToString());
		}
		mainL = new MainLibrary(nVeces);
	}
	public: void frmMenu::GetDataType(DataGridView^ data, int nVeces) {
		arrS = new vector<string>;
		string asd;
		for (int i = 0; i < nVeces; i++) {
			//abc = data->Rows[i]->Cells[2]->Value->ToString();
			MarshalString(data->Rows[i]->Cells[2]->Value->ToString(), asd);
			arrS->push_back(asd);

		}
	}
	private: void MarshalString(String^ s, string& os) {
		using namespace Runtime::InteropServices;
		const char* chars =	(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
		os = chars;
		Marshal::FreeHGlobal(IntPtr((void*)chars));
	}
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~frmMenu()
		{
			if (components)
			{
				delete components;
			}
		}



	private: System::Windows::Forms::DataGridView^ grdvData;

	private: System::Windows::Forms::Button^ btnSearch;
	private: System::Windows::Forms::TextBox^ txtSearch;

	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ newToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ openToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ exitToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ tsmEdit;

	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::ToolStripMenuItem^ toolStripMenuItem1;
	private: System::ComponentModel::IContainer^ components;
	private: System::Windows::Forms::Button^ btnSave;


	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		MainLibrary* mainL;
		ToolStripMenuItem^ dpiNew;
		ToolStripMenuItem^ dpUp;
		ToolStripMenuItem^ dpDown;
		vector<string>* arrS;
	private: System::Windows::Forms::Button^ btnBack;
	private: System::Windows::Forms::DataGridView^ grdvSearch;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ btnIndex;
	private: System::Windows::Forms::Label^ label2;

	private: System::Windows::Forms::ComboBox^ cbxIndex;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;


	private: System::Windows::Forms::TextBox^ txtFileBox;
		   

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->grdvData = (gcnew System::Windows::Forms::DataGridView());
			this->btnSearch = (gcnew System::Windows::Forms::Button());
			this->txtSearch = (gcnew System::Windows::Forms::TextBox());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->newToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tsmEdit = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->btnSave = (gcnew System::Windows::Forms::Button());
			this->btnBack = (gcnew System::Windows::Forms::Button());
			this->grdvSearch = (gcnew System::Windows::Forms::DataGridView());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->txtFileBox = (gcnew System::Windows::Forms::TextBox());
			this->btnIndex = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->cbxIndex = (gcnew System::Windows::Forms::ComboBox());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->grdvData))->BeginInit();
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->grdvSearch))->BeginInit();
			this->SuspendLayout();
			// 
			// grdvData
			// 
			this->grdvData->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->grdvData->Location = System::Drawing::Point(12, 70);
			this->grdvData->Name = L"grdvData";
			this->grdvData->RowHeadersWidth = 51;
			this->grdvData->Size = System::Drawing::Size(503, 293);
			this->grdvData->TabIndex = 2;
			this->grdvData->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &frmMenu::grdvData_CellContentClick);
			// 
			// btnSearch
			// 
			this->btnSearch->Location = System::Drawing::Point(440, 43);
			this->btnSearch->Name = L"btnSearch";
			this->btnSearch->Size = System::Drawing::Size(75, 23);
			this->btnSearch->TabIndex = 3;
			this->btnSearch->Text = L"Search";
			this->btnSearch->UseVisualStyleBackColor = true;
			this->btnSearch->Click += gcnew System::EventHandler(this, &frmMenu::btnSearch_Click);
			// 
			// txtSearch
			// 
			this->txtSearch->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtSearch->Location = System::Drawing::Point(220, 41);
			this->txtSearch->Name = L"txtSearch";
			this->txtSearch->Size = System::Drawing::Size(100, 26);
			this->txtSearch->TabIndex = 4;
			this->txtSearch->TextChanged += gcnew System::EventHandler(this, &frmMenu::textBox1_TextChanged);
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->fileToolStripMenuItem,
					this->tsmEdit
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Padding = System::Windows::Forms::Padding(4, 2, 0, 2);
			this->menuStrip1->Size = System::Drawing::Size(525, 24);
			this->menuStrip1->TabIndex = 5;
			this->menuStrip1->Text = L"menuStrip1";
			this->menuStrip1->ItemClicked += gcnew System::Windows::Forms::ToolStripItemClickedEventHandler(this, &frmMenu::menuStrip1_ItemClicked);
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->newToolStripMenuItem,
					this->toolStripMenuItem1, this->openToolStripMenuItem, this->exitToolStripMenuItem
			});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// newToolStripMenuItem
			// 
			this->newToolStripMenuItem->Name = L"newToolStripMenuItem";
			this->newToolStripMenuItem->Size = System::Drawing::Size(103, 22);
			this->newToolStripMenuItem->Text = L"New";
			this->newToolStripMenuItem->Click += gcnew System::EventHandler(this, &frmMenu::newToolStripMenuItem_Click);
			// 
			// toolStripMenuItem1
			// 
			this->toolStripMenuItem1->Name = L"toolStripMenuItem1";
			this->toolStripMenuItem1->Size = System::Drawing::Size(103, 22);
			this->toolStripMenuItem1->Text = L"Save";
			this->toolStripMenuItem1->Click += gcnew System::EventHandler(this, &frmMenu::toolStripMenuItem1_Click);
			// 
			// openToolStripMenuItem
			// 
			this->openToolStripMenuItem->Name = L"openToolStripMenuItem";
			this->openToolStripMenuItem->Size = System::Drawing::Size(103, 22);
			this->openToolStripMenuItem->Text = L"Open";
			this->openToolStripMenuItem->Click += gcnew System::EventHandler(this, &frmMenu::openToolStripMenuItem_Click);
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(103, 22);
			this->exitToolStripMenuItem->Text = L"Exit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &frmMenu::exitToolStripMenuItem_Click);
			// 
			// tsmEdit
			// 
			this->tsmEdit->Name = L"tsmEdit";
			this->tsmEdit->Size = System::Drawing::Size(39, 20);
			this->tsmEdit->Text = L"Edit";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(217, 24);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(44, 13);
			this->label1->TabIndex = 6;
			this->label1->Text = L"Search ";
			// 
			// btnSave
			// 
			this->btnSave->Location = System::Drawing::Point(440, 369);
			this->btnSave->Name = L"btnSave";
			this->btnSave->Size = System::Drawing::Size(75, 23);
			this->btnSave->TabIndex = 7;
			this->btnSave->Text = L"Save";
			this->btnSave->UseVisualStyleBackColor = true;
			this->btnSave->Click += gcnew System::EventHandler(this, &frmMenu::btnSave_Click);
			// 
			// btnBack
			// 
			this->btnBack->Location = System::Drawing::Point(363, 44);
			this->btnBack->Name = L"btnBack";
			this->btnBack->Size = System::Drawing::Size(75, 23);
			this->btnBack->TabIndex = 13;
			this->btnBack->Text = L"Go Back";
			this->btnBack->UseVisualStyleBackColor = true;
			this->btnBack->Click += gcnew System::EventHandler(this, &frmMenu::btnBack_Click);
			// 
			// grdvSearch
			// 
			this->grdvSearch->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->grdvSearch->Location = System::Drawing::Point(12, 70);
			this->grdvSearch->Name = L"grdvSearch";
			this->grdvSearch->RowHeadersWidth = 51;
			this->grdvSearch->Size = System::Drawing::Size(503, 293);
			this->grdvSearch->TabIndex = 14;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(12, 374);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(72, 13);
			this->label3->TabIndex = 15;
			this->label3->Text = L"File Saved As";
			// 
			// txtFileBox
			// 
			this->txtFileBox->Location = System::Drawing::Point(90, 372);
			this->txtFileBox->Name = L"txtFileBox";
			this->txtFileBox->Size = System::Drawing::Size(100, 20);
			this->txtFileBox->TabIndex = 16;
			// 
			// btnIndex
			// 
			this->btnIndex->Location = System::Drawing::Point(139, 44);
			this->btnIndex->Name = L"btnIndex";
			this->btnIndex->Size = System::Drawing::Size(75, 23);
			this->btnIndex->TabIndex = 24;
			this->btnIndex->Text = L"Index";
			this->btnIndex->UseVisualStyleBackColor = true;
			this->btnIndex->Click += gcnew System::EventHandler(this, &frmMenu::btnIndex_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 27);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(33, 13);
			this->label2->TabIndex = 23;
			this->label2->Text = L"Index";
			// 
			// cbxIndex
			// 
			this->cbxIndex->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cbxIndex->FormattingEnabled = true;
			this->cbxIndex->Location = System::Drawing::Point(12, 43);
			this->cbxIndex->Name = L"cbxIndex";
			this->cbxIndex->Size = System::Drawing::Size(121, 21);
			this->cbxIndex->TabIndex = 21;
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// frmMenu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(525, 411);
			this->Controls->Add(this->btnIndex);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->cbxIndex);
			this->Controls->Add(this->txtFileBox);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->grdvSearch);
			this->Controls->Add(this->btnBack);
			this->Controls->Add(this->btnSave);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->txtSearch);
			this->Controls->Add(this->btnSearch);
			this->Controls->Add(this->grdvData);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"frmMenu";
			this->Text = L"frmMenu";
			this->Load += gcnew System::EventHandler(this, &frmMenu::frmMenu_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->grdvData))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->grdvSearch))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnNewTable_Click(System::Object^ sender, System::EventArgs^ e) {
		//frmNewTable ^newTable = gcnew frmNewTable;
		//this->Visible = true;
		//newTable->ShowDialog();
		//this->Visible = true;
	}
	private: System::Void newToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Visible = false;
	}
private: System::Void menuStrip1_ItemClicked(System::Object^ sender, System::Windows::Forms::ToolStripItemClickedEventArgs^ e) {
}
private: System::Void frmMenu_Load(System::Object^ sender, System::EventArgs^ e) {
	grdvSearch->Visible = false;
	btnBack->Visible = false;
}
private: System::Void exitToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Visible = false;
}
private: System::Void grdvData_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
}
private: System::Void btnSave_Click(System::Object^ sender, System::EventArgs^ e) {
	grdvData->Update();
	grdvSearch->Update();
	if (txtFileBox->Text != "")
	{
		if (grdvSearch->Visible == false)
		{
			TextWriter^ writer = gcnew StreamWriter(txtFileBox->Text + ".txt");
			for (int i = 0; i < grdvData->Columns->Count; i++)
			{
				writer->Write("\t" + grdvData->Columns[i]->Name->ToString() + "\t" + "|");
			}
			writer->WriteLine("");
			for (int i = 0; i < grdvData->Rows->Count - 1; i++)
			{
				for (int j = 0; j < grdvData->ColumnCount; j++) {
					if (grdvData->Rows[i]->Cells[j]->Value != nullptr)
					{
						writer->Write("\t" + grdvData->Rows[i]->Cells[j]->Value->ToString() + "\t" + "|");
					}
					else
					{
						writer->Write("\t" + "\t" + "|");
					}
				}
				writer->WriteLine("");
			}
			writer->Close();
			MessageBox::Show("Data Saved!");
		}
		else
		{
			TextWriter^ writer = gcnew StreamWriter(txtFileBox->Text + ".txt");
			for (int i = 0; i < grdvData->Columns->Count; i++)
			{
				writer->Write("\t" + grdvData->Columns[i]->Name->ToString() + "\t" + "|");
			}
			writer->WriteLine("");
			for (int i = 0; i < grdvSearch->Rows->Count - 1; i++)
			{
				for (int j = 0; j < grdvSearch->ColumnCount; j++) {
					if (grdvSearch->Rows[i]->Cells[j]->Value != nullptr)
					{
						writer->Write("\t" + grdvSearch->Rows[i]->Cells[j]->Value->ToString() + "\t" + "|");
					}
					else
					{
						writer->Write("\t" + "\t" + "|");
					}
				}
				writer->WriteLine("");
			}
			writer->Close();
			MessageBox::Show("Data Saved!");
		}
	}
	else
		MessageBox::Show("Please Insert File Name :(");
}
private: System::Void btnSearch_Click(System::Object^ sender, System::EventArgs^ e) {
	
	if (txtSearch->Text != "")
	{
		string parameter;
		string data;
		int n_d = 0;
		MarshalString(txtSearch->Text, parameter);

		for (int i = 0; i < parameter.size(); ++i) {
			if ((parameter[i] != '%') && (parameter[i] != '!') && (parameter[i] != '<') && (parameter[i] != '>')) {
				data.push_back(parameter[i]);
			}
		}

		if (parameter[0] == '%') {
			if (parameter[parameter.size() - 1] == '%')
				parameter = "contain";
			else parameter = "endWith";
		}
		else if (parameter[parameter.size() - 1] == '%')
			parameter = "startWith";
		else if ((parameter[0] == '!') && (parameter[parameter.size() - 1] == '!'))
			parameter = "noContain";
		else if (parameter[0] == '<')
			parameter = "lower";
		else if (parameter[0] == '>')
			parameter = "upper";
		else
			parameter = "find";

		ofstream archivo;
		archivo.open("parametro.txt");
		archivo << parameter << endl;
		archivo << "data: " << data << " ||";
		archivo.close();

		if (parameter == "contain")
			mainL->search_contain(data);
		else if (parameter == "endWith")
			mainL->search_endtWith(data);
		else if (parameter == "startWith")
			mainL->search_startWith(data);
		else if (parameter == "noContain")
			mainL->search_NOcontain(data);
		else if (parameter == "lower")
			mainL->search_lower(data);
		else if (parameter == "upper")
			mainL->search_upper(data);
		else if (parameter == "find")
			mainL->search_all(data);
	}
	//------------------------------------------------------
	grdvSearch->Columns->Clear();
	grdvSearch->Rows->Clear();
	grdvSearch->Visible = true;
	btnBack->Visible = true;
	String^ txt;
	string text;
	string text2;
	char newLine = '\n';
	char newLine2 = '|';
	int numLines = 0;
	int numLines2 = 0;
	string word;
	size_t found;
	TextReader^ reader = gcnew StreamReader(LR"(registro.txt)");
	txt = reader->ReadToEnd()->Trim();
	MarshalString(txt, text);
	text.erase(remove(text.begin(), text.end(), '\t'), text.end());
	ifstream openFile("registro.txt");
	while (getline(openFile, text2, '.'))
	{
		for (unsigned int i = 0; i < text2.length(); i++)
		{
			if (text2.at(i) == newLine)
				numLines++;
			if (text2.at(i) == newLine2 && numLines == 0)
			{
				numLines2++;
			}
		}
	}
	for (int i = 0; i < numLines2; i++)
	{
		grdvSearch->Columns->Add(grdvData->Columns[i]->Name, grdvData->Columns[i]->Name);
	}
	text.erase(remove_if(text.begin(), text.end(), isspace), text.end());
	found = 0;
	for (int i = 0; i < numLines; i++)
	{
		grdvSearch->Rows->Add(1);
		for (int j = 0; j < numLines2; j++)
		{
			text.erase(0, found);
			found = text.find("|") + 1;
			word = text;
			word.erase(found - 1, text.length());
			String^ newone = gcnew String(word.c_str());
			grdvSearch->Rows[i]->Cells[j]->Value = newone;
		}
	}
	reader->Close();
	grdvSearch->Update();
}
private: System::Void btnBack_Click(System::Object^ sender, System::EventArgs^ e) {
	grdvSearch->Visible = false;
	btnBack->Visible = false;
}
private: System::Void toolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e) {
	btnSave_Click(sender, e);
}
private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {

	
}
private: System::Void openToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	openFileDialog1->Title = "Search";
	auto result = openFileDialog1->ShowDialog();
	if (result == System::Windows::Forms::DialogResult::Cancel)
	{
		delete openFileDialog1;
		return;
	}
	grdvSearch->Columns->Clear();
	grdvSearch->Rows->Clear();
	grdvSearch->Visible = true;
	btnBack->Visible = true;
	String^ strText = openFileDialog1->FileName;
	string strTextito;
	MarshalString(strText, strTextito);
	String^ txt;
	string text;
	string text2;
	char newLine = '\n';
	char newLine2 = '|';
	int numLines = 0;
	int numLines2 = 0;
	string word;
	size_t found;
	TextReader^ reader = gcnew StreamReader(strText);
	txt = reader->ReadToEnd()->Trim();
	MarshalString(txt, text);
	text.erase(remove(text.begin(), text.end(), '\t'), text.end());
	ifstream openFile(strTextito);
	while (getline(openFile, text2, '.'))
	{
		for (unsigned int i = 0; i < text2.length(); i++)
		{
			if (text2.at(i) == newLine)
				numLines++;
			if (text2.at(i) == newLine2 && numLines == 0)
			{
				numLines2++;
			}
		}
	}
	for (int i = 0; i < numLines2; i++)
	{
		text.erase(0, found);
		found = text.find("|") + 1;
		word = text;
		word.erase(found - 1, text.length());
		String^ newone = gcnew String(word.c_str());
		grdvSearch->Columns->Add(newone, newone);
		if (i == numLines2 - 1)
			text.erase(0, found);
	}
	text.erase(remove_if(text.begin(), text.end(), isspace), text.end());
	found = 0;
	for (int i = 0; i < numLines - 1; i++)
	{
		grdvSearch->Rows->Add(1);
		for (int j = 0; j < numLines2; j++)
		{
			text.erase(0, found);
			found = text.find("|") + 1;
			word = text;
			word.erase(found - 1, text.length());
			String^ newone = gcnew String(word.c_str());
			grdvSearch->Rows[i]->Cells[j]->Value = newone;
		}
	}
	reader->Close();
	grdvSearch->Update();
	
}
private: System::Void btnIndex_Click(System::Object^ sender, System::EventArgs^ e) {
	int var = 0;
	bool dataType;
	for (int i = 0; i < cbxIndex->Items->Count; i++)
	{
		if (cbxIndex->Items[i] == cbxIndex->SelectedItem)
		{
			var = i;

			if (arrS->at(i) == "Word") 
				dataType = true;
			else dataType = false;

			break;
		}
	}
	//cbxSearch->Items->Add(cbxIndex->Items[var]);
	for (int i = 0; i < grdvData->Rows->Count - 1; i++) {
		mainL->insert_row();
		for (int j = 0; j < grdvData->ColumnCount; j++) {
			string aux = "";
			if (grdvData->Rows[i]->Cells[j]->Value != nullptr)
				MarshalString(grdvData->Rows[i]->Cells[j]->Value->ToString(), aux);

			mainL->set_elements(aux, i, j);
		}
	}
	mainL->index(var, dataType);

}
	   void ClickUp(System::Object^ sender, System::EventArgs^ e) {
		   MessageBox::Show("YASTA");
		   grdvSearch->Columns->Clear();
		   grdvSearch->Rows->Clear();
		   grdvSearch->Visible = true;
		   btnBack->Visible = true;
		   mainL->ascending_order();
		   String^ txt;
		   string text;
		   string text2;
		   char newLine = '\n';
		   char newLine2 = '|';
		   int numLines = 0;
		   int numLines2 = 0;
		   string word;
		   size_t found;
		   TextReader^ reader = gcnew StreamReader(LR"(registro.txt)");
		   txt = reader->ReadToEnd()->Trim();	
		   MarshalString(txt, text);
		   text.erase(remove(text.begin(), text.end(), '\t'), text.end());
		   ifstream openFile("registro.txt");
		   while (getline(openFile, text2, '.'))
		   {
			   for (unsigned int i = 0; i < text2.length(); i++)
			   {
				   if (text2.at(i) == newLine)
					   numLines++;
				   if (text2.at(i) == newLine2 && numLines == 0)
				   {
					   numLines2++;
				   }
			   }
		   }
		   for (int i = 0; i < numLines2; i++)
		   {
			   grdvSearch->Columns->Add(grdvData->Columns[i]->Name, grdvData->Columns[i]->Name);
		   }
		   text.erase(remove_if(text.begin(), text.end(), isspace), text.end());
		   found = 0;
		   for (int i = 0; i < numLines; i++)
		   {
			   grdvSearch->Rows->Add(1);
			   for (int j = 0; j < numLines2; j++)
			   {
				   text.erase(0, found);
				   found = text.find("|") + 1;
				   word = text;
				   word.erase(found - 1, text.length());
				   String^ newone = gcnew String(word.c_str());
				   grdvSearch->Rows[i]->Cells[j]->Value = newone;
			   }
		   }
		   reader->Close();
		   grdvSearch->Update();
	   }
	   void ClickDown(System::Object^ sender, System::EventArgs^ e) {
		   grdvSearch->Columns->Clear();
		   grdvSearch->Rows->Clear();
		   grdvSearch->Visible = true;
		   btnBack->Visible = true;
		   mainL->descending_order();
		   MessageBox::Show("YASTAMOS");
		   String^ txt;
		   string text;
		   string text2;
		   char newLine = '\n';
		   char newLine2 = '|';
		   int numLines = 0;
		   int numLines2 = 0;
		   string word;
		   size_t found;
		   TextReader^ reader = gcnew StreamReader(LR"(registro.txt)");
		   txt = reader->ReadToEnd()->Trim();
		   MarshalString(txt, text);
		   text.erase(remove(text.begin(), text.end(), '\t'), text.end());
		   ifstream openFile("registro.txt");
		   while (getline(openFile, text2, '.'))
		   {
			   for (unsigned int i = 0; i < text2.length(); i++)
			   {
				   if (text2.at(i) == newLine)
					   numLines++;
				   if (text2.at(i) == newLine2 && numLines == 0)
				   {
					   numLines2++;
				   }
			   }
		   }
		   for (int i = 0; i < numLines2; i++)
		   {
			   grdvSearch->Columns->Add(grdvData->Columns[i]->Name, grdvData->Columns[i]->Name);
		   }
		   text.erase(remove_if(text.begin(), text.end(), isspace), text.end());
		   found = 0;
		   for (int i = 0; i < numLines; i++)
		   {
			   grdvSearch->Rows->Add(1);
			   for (int j = 0; j < numLines2; j++)
			   {
				   text.erase(0, found);
				   found = text.find("|") + 1;
				   word = text;
				   word.erase(found - 1, text.length());
				   String^ newone = gcnew String(word.c_str());
				   grdvSearch->Rows[i]->Cells[j]->Value = newone;
			   }
		   }
		   reader->Close();
		   grdvSearch->Update();
	   }
};
}
