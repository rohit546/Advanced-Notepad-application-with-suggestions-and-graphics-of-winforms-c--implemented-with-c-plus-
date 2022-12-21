#pragma once
#include<iostream>
#include"trie_tree.h"
#include<fstream>
#include<vector>
#include"huffman_coding.h"
#include"PriorityQ.h"

using namespace std;
namespace data {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		trie *dict;
		huffmtree* hufftree;
		string* suggg;
		string* encod;


	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	public:
	private: System::Windows::Forms::ToolStripMenuItem^ fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ toolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^ toolStripMenuItem2;
	private: System::Windows::Forms::ToolStripMenuItem^ toolStripMenuItem3;
	private: System::Windows::Forms::ToolStripMenuItem^ toolStripMenuItem4;
	private: System::Windows::Forms::ToolStripMenuItem^ newToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ openToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ saveToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ printToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ exitToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ redoToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ copyToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ pasteToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ cutToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ undoToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ fontToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ wordWrapToolStripMenuItem;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::FontDialog^ fontDialog1;
	private: System::Windows::Forms::ColorDialog^ colorDialog1;
	private: System::Windows::Forms::PrintDialog^ printDialog1;
	private: System::Windows::Forms::SaveFileDialog^ saveFileDialog1;
	private: System::Windows::Forms::ToolStripMenuItem^ encodeToolStripMenuItem;
	private: System::Windows::Forms::ListView^ listView1;
	private: System::Windows::Forms::ColumnHeader^ columnHeader1;
	private: System::Windows::Forms::ColumnHeader^ columnHeader2;
	private: System::Windows::Forms::ColumnHeader^ columnHeader3;
	private: System::Windows::Forms::ToolStripMenuItem^ decodeToolStripMenuItem;



	public:

		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//

			hufftree = new huffmtree;
			dict = new trie;
			suggg = new string;
			this->encod = new string;
			std::ifstream inFile("Dictionary.txt");
			std::string words;

			while (inFile >> words) {
				dict->insert(words);
			}

		}
		void MarshalString(String^ s, std::string& os) {
			using namespace Runtime::InteropServices;
			const char* chars =
				(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
			os = chars;
			Marshal::FreeHGlobal(IntPtr((void*)chars));
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)                                
			{
				delete components;
			}

			fstream FileName,data1;
			FileName.open("tree.txt", ios::out);
			data1.open("data1.txt", ios::out);
			if (!FileName) {
				MessageBox::Show("tree not saved to file  ", "saving tree ", MessageBoxButtons::OK, MessageBoxIcon::Information);
			}
			else {
				Pnode* temp = hufftree->get_tree().front;
				while ((temp != NULL)) {

			
					if (temp->info == ' ') {
						FileName << '$' << " " << temp->freq << endl;
						
					}
				
					else 
					FileName << temp->info << " " << temp->freq << endl;
			

					temp = temp->link;
				}

			}
			FileName.close();

		

		}
	private: System::Windows::Forms::RichTextBox^ richTextBox1;
	protected:

	private: System::Windows::Forms::ListView^ all_contacts_list;
	private: System::Windows::Forms::ColumnHeader^ words;
	private: System::Windows::Forms::Button^ button2;




	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->all_contacts_list = (gcnew System::Windows::Forms::ListView());
			this->words = (gcnew System::Windows::Forms::ColumnHeader());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->toolStripMenuItem4 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->newToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->printToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->redoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->copyToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->pasteToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->cutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->undoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem2 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->fontToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->wordWrapToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem3 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->encodeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->decodeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->fontDialog1 = (gcnew System::Windows::Forms::FontDialog());
			this->colorDialog1 = (gcnew System::Windows::Forms::ColorDialog());
			this->printDialog1 = (gcnew System::Windows::Forms::PrintDialog());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->listView1 = (gcnew System::Windows::Forms::ListView());
			this->columnHeader1 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader2 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader3 = (gcnew System::Windows::Forms::ColumnHeader());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(0, 36);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->ScrollBars = System::Windows::Forms::RichTextBoxScrollBars::ForcedVertical;
			this->richTextBox1->Size = System::Drawing::Size(584, 504);
			this->richTextBox1->TabIndex = 0;
			this->richTextBox1->Text = L"";
			this->richTextBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::richTextBox1_TextChanged);
			// 
			// all_contacts_list
			// 
			this->all_contacts_list->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(35)),
				static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(45)));
			this->all_contacts_list->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(1) { this->words });
			this->all_contacts_list->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->all_contacts_list->ForeColor = System::Drawing::Color::Chocolate;
			this->all_contacts_list->HideSelection = false;
			this->all_contacts_list->Location = System::Drawing::Point(590, 36);
			this->all_contacts_list->Name = L"all_contacts_list";
			this->all_contacts_list->Size = System::Drawing::Size(285, 478);
			this->all_contacts_list->TabIndex = 14;
			this->all_contacts_list->UseCompatibleStateImageBehavior = false;
			this->all_contacts_list->View = System::Windows::Forms::View::Details;
			this->all_contacts_list->Visible = false;
			this->all_contacts_list->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::all_contacts_list_SelectedIndexChanged);
			// 
			// words
			// 
			this->words->Text = L"Suggestions";
			this->words->Width = 267;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(664, 520);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(142, 39);
			this->button2->TabIndex = 15;
			this->button2->Text = L"change ";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// menuStrip1
			// 
			this->menuStrip1->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->menuStrip1->GripMargin = System::Windows::Forms::Padding(2, 2, 0, 2);
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(24, 24);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(7) {
				this->toolStripMenuItem4,
					this->toolStripMenuItem1, this->toolStripMenuItem2, this->toolStripMenuItem3, this->fileToolStripMenuItem, this->encodeToolStripMenuItem,
					this->decodeToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(888, 38);
			this->menuStrip1->TabIndex = 16;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// toolStripMenuItem4
			// 
			this->toolStripMenuItem4->BackColor = System::Drawing::SystemColors::Control;
			this->toolStripMenuItem4->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->newToolStripMenuItem,
					this->openToolStripMenuItem, this->saveToolStripMenuItem, this->printToolStripMenuItem, this->exitToolStripMenuItem
			});
			this->toolStripMenuItem4->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->toolStripMenuItem4->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
			this->toolStripMenuItem4->Name = L"toolStripMenuItem4";
			this->toolStripMenuItem4->Size = System::Drawing::Size(59, 34);
			this->toolStripMenuItem4->Text = L"File";
			this->toolStripMenuItem4->Click += gcnew System::EventHandler(this, &MyForm::toolStripMenuItem4_Click);
			// 
			// newToolStripMenuItem
			// 
			this->newToolStripMenuItem->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
			this->newToolStripMenuItem->Name = L"newToolStripMenuItem";
			this->newToolStripMenuItem->Size = System::Drawing::Size(270, 36);
			this->newToolStripMenuItem->Text = L"New ";
			this->newToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::newToolStripMenuItem_Click);
			// 
			// openToolStripMenuItem
			// 
			this->openToolStripMenuItem->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
			this->openToolStripMenuItem->Name = L"openToolStripMenuItem";
			this->openToolStripMenuItem->Size = System::Drawing::Size(270, 36);
			this->openToolStripMenuItem->Text = L"Open";
			this->openToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::openToolStripMenuItem_Click);
			// 
			// saveToolStripMenuItem
			// 
			this->saveToolStripMenuItem->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
			this->saveToolStripMenuItem->Name = L"saveToolStripMenuItem";
			this->saveToolStripMenuItem->Size = System::Drawing::Size(270, 36);
			this->saveToolStripMenuItem->Text = L"save";
			this->saveToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::saveToolStripMenuItem_Click);
			// 
			// printToolStripMenuItem
			// 
			this->printToolStripMenuItem->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
			this->printToolStripMenuItem->Name = L"printToolStripMenuItem";
			this->printToolStripMenuItem->Size = System::Drawing::Size(270, 36);
			this->printToolStripMenuItem->Text = L"Print";
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(270, 36);
			this->exitToolStripMenuItem->Text = L"exit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::exitToolStripMenuItem_Click);
			// 
			// toolStripMenuItem1
			// 
			this->toolStripMenuItem1->BackColor = System::Drawing::SystemColors::Control;
			this->toolStripMenuItem1->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->redoToolStripMenuItem,
					this->copyToolStripMenuItem, this->pasteToolStripMenuItem, this->cutToolStripMenuItem, this->undoToolStripMenuItem
			});
			this->toolStripMenuItem1->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->toolStripMenuItem1->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
			this->toolStripMenuItem1->Name = L"toolStripMenuItem1";
			this->toolStripMenuItem1->Size = System::Drawing::Size(62, 34);
			this->toolStripMenuItem1->Text = L"Edit";
			this->toolStripMenuItem1->Click += gcnew System::EventHandler(this, &MyForm::toolStripMenuItem1_Click);
			// 
			// redoToolStripMenuItem
			// 
			this->redoToolStripMenuItem->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
			this->redoToolStripMenuItem->Name = L"redoToolStripMenuItem";
			this->redoToolStripMenuItem->Size = System::Drawing::Size(162, 36);
			this->redoToolStripMenuItem->Text = L"Redo";
			// 
			// copyToolStripMenuItem
			// 
			this->copyToolStripMenuItem->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
			this->copyToolStripMenuItem->Name = L"copyToolStripMenuItem";
			this->copyToolStripMenuItem->Size = System::Drawing::Size(162, 36);
			this->copyToolStripMenuItem->Text = L"Copy";
			// 
			// pasteToolStripMenuItem
			// 
			this->pasteToolStripMenuItem->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
			this->pasteToolStripMenuItem->Name = L"pasteToolStripMenuItem";
			this->pasteToolStripMenuItem->Size = System::Drawing::Size(162, 36);
			this->pasteToolStripMenuItem->Text = L"Paste";
			// 
			// cutToolStripMenuItem
			// 
			this->cutToolStripMenuItem->ForeColor = System::Drawing::SystemColors::ControlDark;
			this->cutToolStripMenuItem->Name = L"cutToolStripMenuItem";
			this->cutToolStripMenuItem->Size = System::Drawing::Size(162, 36);
			this->cutToolStripMenuItem->Text = L"Cut";
			// 
			// undoToolStripMenuItem
			// 
			this->undoToolStripMenuItem->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
			this->undoToolStripMenuItem->Name = L"undoToolStripMenuItem";
			this->undoToolStripMenuItem->Size = System::Drawing::Size(162, 36);
			this->undoToolStripMenuItem->Text = L"undo";
			// 
			// toolStripMenuItem2
			// 
			this->toolStripMenuItem2->BackColor = System::Drawing::SystemColors::Control;
			this->toolStripMenuItem2->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->fontToolStripMenuItem,
					this->wordWrapToolStripMenuItem
			});
			this->toolStripMenuItem2->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->toolStripMenuItem2->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
			this->toolStripMenuItem2->Name = L"toolStripMenuItem2";
			this->toolStripMenuItem2->Size = System::Drawing::Size(92, 34);
			this->toolStripMenuItem2->Text = L"Format";
			// 
			// fontToolStripMenuItem
			// 
			this->fontToolStripMenuItem->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
			this->fontToolStripMenuItem->Name = L"fontToolStripMenuItem";
			this->fontToolStripMenuItem->Size = System::Drawing::Size(217, 36);
			this->fontToolStripMenuItem->Text = L"Font ";
			// 
			// wordWrapToolStripMenuItem
			// 
			this->wordWrapToolStripMenuItem->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
			this->wordWrapToolStripMenuItem->Name = L"wordWrapToolStripMenuItem";
			this->wordWrapToolStripMenuItem->Size = System::Drawing::Size(217, 36);
			this->wordWrapToolStripMenuItem->Text = L"Word Wrap";
			// 
			// toolStripMenuItem3
			// 
			this->toolStripMenuItem3->BackColor = System::Drawing::SystemColors::Control;
			this->toolStripMenuItem3->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->toolStripMenuItem3->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
			this->toolStripMenuItem3->Name = L"toolStripMenuItem3";
			this->toolStripMenuItem3->Size = System::Drawing::Size(71, 34);
			this->toolStripMenuItem3->Text = L"Help";
			this->toolStripMenuItem3->Click += gcnew System::EventHandler(this, &MyForm::toolStripMenuItem3_Click);
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->BackColor = System::Drawing::SystemColors::Control;
			this->fileToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->fileToolStripMenuItem->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(140, 34);
			this->fileToolStripMenuItem->Text = L"Suggestions";
			this->fileToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::fileToolStripMenuItem_Click);
			// 
			// encodeToolStripMenuItem
			// 
			this->encodeToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 11, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->encodeToolStripMenuItem->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
			this->encodeToolStripMenuItem->Name = L"encodeToolStripMenuItem";
			this->encodeToolStripMenuItem->Size = System::Drawing::Size(101, 34);
			this->encodeToolStripMenuItem->Text = L"Encode";
			this->encodeToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::encodeToolStripMenuItem_Click);
			// 
			// decodeToolStripMenuItem
			// 
			this->decodeToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->decodeToolStripMenuItem->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
			this->decodeToolStripMenuItem->Name = L"decodeToolStripMenuItem";
			this->decodeToolStripMenuItem->Size = System::Drawing::Size(97, 34);
			this->decodeToolStripMenuItem->Text = L"Decode";
			this->decodeToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::decodeToolStripMenuItem_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// printDialog1
			// 
			this->printDialog1->UseEXDialog = true;
			// 
			// listView1
			// 
			this->listView1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(35)), static_cast<System::Int32>(static_cast<System::Byte>(40)),
				static_cast<System::Int32>(static_cast<System::Byte>(45)));
			this->listView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(3) {
				this->columnHeader1, this->columnHeader2,
					this->columnHeader3
			});
			this->listView1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->listView1->ForeColor = System::Drawing::Color::Chocolate;
			this->listView1->HideSelection = false;
			this->listView1->Location = System::Drawing::Point(590, 36);
			this->listView1->Name = L"listView1";
			this->listView1->Size = System::Drawing::Size(298, 486);
			this->listView1->TabIndex = 17;
			this->listView1->UseCompatibleStateImageBehavior = false;
			this->listView1->View = System::Windows::Forms::View::Details;
			this->listView1->Visible = false;
			this->listView1->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::listView1_SelectedIndexChanged);
			// 
			// columnHeader1
			// 
			this->columnHeader1->Text = L"characters";
			this->columnHeader1->Width = 65;
			// 
			// columnHeader2
			// 
			this->columnHeader2->Text = L"frequencies";
			this->columnHeader2->Width = 73;
			// 
			// columnHeader3
			// 
			this->columnHeader3->Text = L"codes";
			this->columnHeader3->Width = 165;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->AutoSize = true;
			this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->ClientSize = System::Drawing::Size(888, 566);
			this->Controls->Add(this->listView1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->all_contacts_list);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->Text = L"NotePad";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {


	}
	private: System::Void richTextBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void all_contacts_list_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {

	if (this->all_contacts_list->Items->Count < 1) {
			return;
		}

		if (this->all_contacts_list->SelectedItems->Count < 1) {
			return;
		}

		int selected_index = this->all_contacts_list->FocusedItem->Index;
	
		vector<string> suggestions = dict->search(*suggg);
		string ok = suggestions[selected_index];
		string final;
		int j = 0;
		for (int i = suggg->size(); i < ok.size(); i++) {
			final += ok[i];
			j++;
		}
		String^ ap = gcnew String(final.c_str());

		this->richTextBox1->AppendText(gcnew String(final.c_str()));

		this->all_contacts_list->Visible = false;
}

private: System::Void toolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void toolStripMenuItem3_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void fileToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {

	std::string conv;
	String^ input = this->richTextBox1->Text->ToString();
	if (!(input->Length == 0)) {
		MarshalString(input, conv);

	}
	string sug;
	//for (int i = 0; i < conv.size(); i++) {
	//	if (!(conv[i] >= 'a' && conv[i] <= 'z'))
	//	{
	//		MessageBox::Show(" your word hasnt any suggestion  ", "suggestions ", MessageBoxButtons::OK, MessageBoxIcon::Information);
	//		return;
	//	}
	//}
	for (int i = conv.size(); i >= 0; i--) {

		if (conv[i] == ' ')
			break;
		sug += conv[i];

	}
	if (sug.size()==1||sug == " ") {

		MessageBox::Show(" your word hasnt any suggestion  ", "suggestions ", MessageBoxButtons::OK, MessageBoxIcon::Information);
		return;
	}
		
	string sug2;
	for (int i = sug.size() - 1; i > 0; i--)
		sug2 += sug[i];



	std::vector<std::string> suggestions = dict->search(sug2);

	*suggg = sug2;
	this->all_contacts_list->Items->Clear();



	if (suggestions.size() == 0)
	{
		MessageBox::Show(" your word hasnt any suggestion  ", "suggestions ", MessageBoxButtons::OK, MessageBoxIcon::Information);
		return;
	}
	for (int i = 0; i < suggestions.size(); i++) {

		if (i == 10)
			break;
		

		this->all_contacts_list->Items->Add(gcnew String(suggestions[i].c_str()));
		this->all_contacts_list->Items[i]->SubItems->Add(gcnew String(suggestions[i].c_str()));
	}


	this->listView1->Visible = false;
	this->all_contacts_list->Refresh();

	this->all_contacts_list->Visible = true;

	int i = 0;

}
private: System::Void newToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {

	richTextBox1->Clear();
}
private: System::Void exitToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {

	exit(0);
}
private: System::Void openToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {


	std::string conv;
	
	this->richTextBox1->Clear();

	fstream FileName;
	FileName.open("data.txt", ios::in);
	if (!FileName) {
		return;
	}
	else {

		FileName >> conv;

		if ((conv[0] == '1' || conv[0] == '0') && (conv[1] == '1' || conv[1] == '0')) {

			if (hufftree->huffroot == NULL) {





				fstream tree;
				tree.open("tree.txt", ios::in);
				if (!FileName) {
					return;
				}
				else {
					int i = 0;
					

					while (!tree.eof()) {
						char data;
						int freq;
						tree >> data >> freq;
						if (data == '$')
							data = ' ';

						hufftree->Pq.insert(data, freq);

					}


				}




				if(hufftree->Pq.front!=NULL)
				hufftree->buildQtree();
			}


			
			string decoded = hufftree->get_decoded_string(conv);

			this->richTextBox1->AppendText(gcnew String(decoded.c_str()));
		}
		else {
			string tp;
			while (getline(FileName, tp));

			MessageBox::Show(" already decoded  ", " ", MessageBoxButtons::OK, MessageBoxIcon::Information);


			this->richTextBox1->AppendText(gcnew String(tp.c_str()));
			return;
		}
	}
	FileName.close();
	


}
	private: System::Void encodeToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {




		std::string conv = "";
		String^ input = "";
		input = this->richTextBox1->Text->ToString();
		this->richTextBox1->Clear();
		if (!(input->Length == 0)) {
			MarshalString(input, conv);

		}
		if (conv.size() == 1) {
			MessageBox::Show(" cannot encoding of one character  ", "encoding ", MessageBoxButtons::OK, MessageBoxIcon::Information);

			return;
		}

		for (int i = 0; i < conv.size(); i++) {

			if ((conv[i] == '1' || conv[i] == '0')) {

				MessageBox::Show(" already encoded  ", "encoding ", MessageBoxButtons::OK, MessageBoxIcon::Information);

				this->richTextBox1->AppendText(gcnew String(conv.c_str()));
				return;

			}

		}

		for (int i = 0; i < conv.size(); i++) {

			if (!((conv[i] >= 'a' && conv[i] <= 'z') || (conv[i] == ' '||conv[i]=='\n'))) {

				MessageBox::Show(" cant encoded your string contains special characters  ", "encoding ", MessageBoxButtons::OK, MessageBoxIcon::Information);

				this->richTextBox1->AppendText(gcnew String(conv.c_str()));
				return;

			}

		}
		if (hufftree->huffroot != NULL)
			hufftree->huffroot = NULL;



		hufftree->buildtree(conv);

		std::string encoded = hufftree->get_encoded_string(conv);


		*(this->encod) = encoded;

		this->richTextBox1->AppendText(gcnew String(encoded.c_str()));

	
		this->listView1->Items->Clear();
		this->listView1->Refresh();
		int ind = 0;
		Pnode *temp = hufftree->get_tree().front;
		while ((temp!=NULL)){

			string charc ;
			char chh;
			charc += temp->info;

			chh = temp->info;

			string cod = "";
			if(chh==' ')
			cod = hufftree->code.str[26];

			else if(chh=='\n')
			cod = hufftree->code.str[27];

			else 	cod = hufftree->code.str[chh - 'a'];



			if (chh == ' ')
				charc = "space";
			if (chh == '\n')
				charc = "linefeed";
			/*if (chh == '{') {
				ind++;
				temp = temp->link;
				continue;
			}*/
			this->listView1->Items->Add(gcnew String(charc.c_str()));
			int freq= temp->freq;
			charc = to_string(freq);

		this->listView1->Items[ind]->SubItems->Add(gcnew String(charc.c_str()));

		this->listView1->Items[ind]->SubItems->Add(gcnew String(cod.c_str()));

		ind++;
		temp = temp->link;

	}
		this->listView1->Refresh();
		this->listView1->Visible = true;
		
}
private: System::Void decodeToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {

	std::string conv = "";
	String^ input = "";
	input = this->richTextBox1->Text->ToString();

	if (!(input->Length == 0)) {
		MarshalString(input, conv);

	}



	for (int i = 0; i <conv.size(); i++) {

		if (!(conv[i] == '1' || conv[i] == '0')) {

			MessageBox::Show(" already decoded  ", "decoding", MessageBoxButtons::OK, MessageBoxIcon::Information);

			return;

		}

	}
	this->richTextBox1->Clear();

	hufftree->code.decoded = "";
	std::string final = hufftree->get_decoded_string(conv);
	
	this->richTextBox1->AppendText(gcnew String(final.c_str()));



}
private: System::Void saveToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {

	std::string conv;
	String^ input = this->richTextBox1->Text->ToString();

	if (!(input->Length == 0)) {
		MarshalString(input, conv);

	}


	fstream FileName;
	FileName.open("data.txt", ios::out);
	if (!FileName) {
		return;
	}
	else {
		
		FileName << conv;

		MessageBox::Show("  Sucessfully saved  ", "save file ", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
	FileName.close();

}
private: System::Void listView1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void toolStripMenuItem4_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
