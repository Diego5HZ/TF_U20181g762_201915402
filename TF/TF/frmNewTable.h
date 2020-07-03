#pragma once
#include "frmMenu.h"
namespace TF {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for frmNewTable
	/// </summary>
	public ref class frmNewTable : public System::Windows::Forms::Form
	{
	public:
		frmNewTable(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
	//public: void frmNewTable::InsertTable(DataGridView^ data) {
	//	dataGridView1 = data;
	//}
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~frmNewTable()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	protected:


	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button2;


	private: System::Windows::Forms::TextBox^ txtColumnName;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ lblWarning;
	private: System::Windows::Forms::Label^ lblEmpty;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column3;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::ComboBox^ cbxDataType;


	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;
		int nVeces = 0;
		int n = 0;
#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->txtColumnName = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->lblWarning = (gcnew System::Windows::Forms::Label());
			this->lblEmpty = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->cbxDataType = (gcnew System::Windows::Forms::ComboBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->Column1,
					this->Column2, this->Column3
			});
			this->dataGridView1->Location = System::Drawing::Point(12, 97);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(343, 219);
			this->dataGridView1->TabIndex = 0;
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &frmNewTable::dataGridView1_CellContentClick);
			this->dataGridView1->SortCompare += gcnew System::Windows::Forms::DataGridViewSortCompareEventHandler(this, &frmNewTable::dataGridView1_SortCompare);
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"Column ID";
			this->Column1->Name = L"Column1";
			this->Column1->ReadOnly = true;
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"Column Element";
			this->Column2->Name = L"Column2";
			this->Column2->ReadOnly = true;
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"Data Type";
			this->Column3->Name = L"Column3";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(133, 340);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(101, 23);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Create Table";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &frmNewTable::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(110, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(162, 24);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Create New Table";
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(257, 62);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(99, 21);
			this->button2->TabIndex = 3;
			this->button2->Text = L"Add Column";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &frmNewTable::button2_Click);
			// 
			// txtColumnName
			// 
			this->txtColumnName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtColumnName->Location = System::Drawing::Point(12, 62);
			this->txtColumnName->Name = L"txtColumnName";
			this->txtColumnName->Size = System::Drawing::Size(100, 26);
			this->txtColumnName->TabIndex = 4;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 46);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(73, 13);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Column Name";
			// 
			// lblWarning
			// 
			this->lblWarning->AutoSize = true;
			this->lblWarning->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblWarning->ForeColor = System::Drawing::Color::Red;
			this->lblWarning->Location = System::Drawing::Point(57, 319);
			this->lblWarning->Name = L"lblWarning";
			this->lblWarning->Size = System::Drawing::Size(231, 18);
			this->lblWarning->TabIndex = 6;
			this->lblWarning->Text = L"Column Name Already EXIST!";
			this->lblWarning->Visible = false;
			// 
			// lblEmpty
			// 
			this->lblEmpty->AutoSize = true;
			this->lblEmpty->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblEmpty->ForeColor = System::Drawing::Color::Red;
			this->lblEmpty->Location = System::Drawing::Point(83, 319);
			this->lblEmpty->Name = L"lblEmpty";
			this->lblEmpty->Size = System::Drawing::Size(189, 18);
			this->lblEmpty->TabIndex = 7;
			this->lblEmpty->Text = L"Column Name is Empty!";
			this->lblEmpty->Visible = false;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(129, 46);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(57, 13);
			this->label3->TabIndex = 8;
			this->label3->Text = L"Data Type";
			// 
			// cbxDataType
			// 
			this->cbxDataType->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cbxDataType->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->cbxDataType->FormattingEnabled = true;
			this->cbxDataType->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Word", L"Number" });
			this->cbxDataType->Location = System::Drawing::Point(132, 62);
			this->cbxDataType->Name = L"cbxDataType";
			this->cbxDataType->Size = System::Drawing::Size(121, 28);
			this->cbxDataType->TabIndex = 9;
			this->cbxDataType->Tag = L"";
			// 
			// frmNewTable
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(368, 372);
			this->Controls->Add(this->cbxDataType);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->lblEmpty);
			this->Controls->Add(this->lblWarning);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->txtColumnName);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->dataGridView1);
			this->Name = L"frmNewTable";
			this->Text = L"frmNewTable";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {

	}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	lblWarning->Visible == false;
	if ((txtColumnName->Text == "" && cbxDataType->Text == "")||
		txtColumnName->Text == "" || cbxDataType->Text == "")
		lblEmpty->Visible = true;
	else 
	{
		lblEmpty->Visible = false;
		//if (n > 0)
		//{
		//	for (int i = 0; i < n; i++)
		//	{
		//		if (dataGridView1->Rows[i]->Cells[1]->Value == txtColumnName->Text)
		//		{
		//			lblWarning->Visible = true;
		//		}
		//	}
		//}
		
		if (lblWarning->Visible == false)
		{
			n = dataGridView1->Rows->Add();
			dataGridView1->Rows[n]->Cells[0]->Value = n + 1;
			dataGridView1->Rows[n]->Cells[1]->Value = txtColumnName->Text;
			dataGridView1->Rows[n]->Cells[2]->Value = cbxDataType->Text;
			txtColumnName->Clear();
			nVeces = n + 1;
		}
	}
	



}
private: System::Void dataGridView1_SortCompare(System::Object^ sender, System::Windows::Forms::DataGridViewSortCompareEventArgs^ e) {
	;
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	frmMenu^ newMenu = gcnew frmMenu;
	this->Hide();
	newMenu->InsertTable(dataGridView1,nVeces);
	newMenu->GetDataType(dataGridView1, nVeces);
	newMenu->ShowDialog();
	this->Visible = true;
	nVeces = 0;
	txtColumnName->Clear();
	dataGridView1->Rows->Clear();
}

};
}
