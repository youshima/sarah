#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace SpeechAnalysis1 {

	/// <summary>
	/// Description résumée de WindowDatabase
	///
	/// AVERTISSEMENT : si vous modifiez le nom de cette classe, vous devrez modifier la
	///          propriété 'Nom du fichier de ressources' de l'outil de compilation de ressource managée
	///          pour tous les fichiers .resx dont dépend cette classe. Dans le cas contraire,
	///          les concepteurs ne pourront pas interagir correctement avec les ressources
	///          localisées associées à ce formulaire.
	/// </summary>
	public ref class WindowDatabase : public System::Windows::Forms::Form
	{
	public:
		WindowDatabase(void)
		{
			InitializeComponent();
			//
			//TODO : ajoutez ici le code du constructeur
			//
		}

	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~WindowDatabase()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	public: System::Windows::Forms::TextBox^  textWord;
	private: System::Windows::Forms::ListBox^  listWords;


	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::ComboBox^  comboType;

	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::GroupBox^  mainInfo;

	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::ListBox^  listBox2;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::GroupBox^  addword;
	public: System::Windows::Forms::Button^  buttonAdd;
	private: System::ComponentModel::BackgroundWorker^  browserThread;
	public: 



	protected: 

	private:
		/// <summary>
		/// Variable nécessaire au concepteur.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Méthode requise pour la prise en charge du concepteur - ne modifiez pas
		/// le contenu de cette méthode avec l'éditeur de code.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textWord = (gcnew System::Windows::Forms::TextBox());
			this->listWords = (gcnew System::Windows::Forms::ListBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->comboType = (gcnew System::Windows::Forms::ComboBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->mainInfo = (gcnew System::Windows::Forms::GroupBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->listBox2 = (gcnew System::Windows::Forms::ListBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->addword = (gcnew System::Windows::Forms::GroupBox());
			this->buttonAdd = (gcnew System::Windows::Forms::Button());
			this->browserThread = (gcnew System::ComponentModel::BackgroundWorker());
			this->groupBox1->SuspendLayout();
			this->mainInfo->SuspendLayout();
			this->groupBox2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->BeginInit();
			this->addword->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(1, 22);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(39, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Word :";
			// 
			// textWord
			// 
			this->textWord->Location = System::Drawing::Point(38, 19);
			this->textWord->Name = L"textWord";
			this->textWord->Size = System::Drawing::Size(151, 20);
			this->textWord->TabIndex = 1;
			// 
			// listWords
			// 
			this->listWords->FormattingEnabled = true;
			this->listWords->Location = System::Drawing::Point(6, 45);
			this->listWords->Name = L"listWords";
			this->listWords->Size = System::Drawing::Size(339, 316);
			this->listWords->TabIndex = 2;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->comboType);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->textWord);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->listWords);
			this->groupBox1->Location = System::Drawing::Point(12, 12);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(351, 363);
			this->groupBox1->TabIndex = 3;
			this->groupBox1->TabStop = false;
			// 
			// comboType
			// 
			this->comboType->FormattingEnabled = true;
			this->comboType->Location = System::Drawing::Point(238, 19);
			this->comboType->Name = L"comboType";
			this->comboType->Size = System::Drawing::Size(107, 21);
			this->comboType->TabIndex = 4;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(195, 22);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(37, 13);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Type :";
			// 
			// mainInfo
			// 
			this->mainInfo->Controls->Add(this->label4);
			this->mainInfo->Controls->Add(this->label5);
			this->mainInfo->Controls->Add(this->textBox3);
			this->mainInfo->Controls->Add(this->textBox2);
			this->mainInfo->Controls->Add(this->label2);
			this->mainInfo->Controls->Add(this->listBox2);
			this->mainInfo->Location = System::Drawing::Point(369, 12);
			this->mainInfo->Name = L"mainInfo";
			this->mainInfo->Size = System::Drawing::Size(338, 137);
			this->mainInfo->TabIndex = 4;
			this->mainInfo->TabStop = false;
			this->mainInfo->Visible = false;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(2, 45);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(30, 13);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Def :";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(174, 22);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(37, 13);
			this->label5->TabIndex = 4;
			this->label5->Text = L"Type :";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(38, 19);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(133, 20);
			this->textBox2->TabIndex = 1;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(1, 22);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(39, 13);
			this->label2->TabIndex = 0;
			this->label2->Text = L"Word :";
			// 
			// listBox2
			// 
			this->listBox2->FormattingEnabled = true;
			this->listBox2->Location = System::Drawing::Point(38, 45);
			this->listBox2->Name = L"listBox2";
			this->listBox2->Size = System::Drawing::Size(294, 82);
			this->listBox2->TabIndex = 2;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(211, 19);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(112, 20);
			this->textBox3->TabIndex = 5;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->dataGridView1);
			this->groupBox2->Location = System::Drawing::Point(369, 155);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(338, 267);
			this->groupBox2->TabIndex = 5;
			this->groupBox2->TabStop = false;
			this->groupBox2->Visible = false;
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(6, 10);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(326, 248);
			this->dataGridView1->TabIndex = 0;
			// 
			// addword
			// 
			this->addword->Controls->Add(this->buttonAdd);
			this->addword->Location = System::Drawing::Point(12, 379);
			this->addword->Name = L"addword";
			this->addword->Size = System::Drawing::Size(351, 43);
			this->addword->TabIndex = 6;
			this->addword->TabStop = false;
			this->addword->Visible = false;
			// 
			// buttonAdd
			// 
			this->buttonAdd->Location = System::Drawing::Point(270, 11);
			this->buttonAdd->Name = L"buttonAdd";
			this->buttonAdd->Size = System::Drawing::Size(75, 23);
			this->buttonAdd->TabIndex = 0;
			this->buttonAdd->Text = L"Add";
			this->buttonAdd->UseVisualStyleBackColor = true;
			// 
			// WindowDatabase
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->ClientSize = System::Drawing::Size(713, 433);
			this->Controls->Add(this->addword);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->mainInfo);
			this->Controls->Add(this->groupBox1);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"WindowDatabase";
			this->ShowIcon = false;
			this->Text = L"WindowDatabase";
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->mainInfo->ResumeLayout(false);
			this->mainInfo->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->EndInit();
			this->addword->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion

};
}
