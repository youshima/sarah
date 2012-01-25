#pragma once

#include "SentenceParser.h"
#include "Environment.h"
#include "Browser.h"
#include "WindowRule.h"
#include "WindowDatabase.h"


#define PROFILE "user.profile"

#define tostring(x) (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(x)

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

namespace SpeechAnalysis1 {

	

	/// <summary>
	/// Description résumée de Form1
	///
	/// AVERTISSEMENT : si vous modifiez le nom de cette classe, vous devrez modifier la
	///          propriété 'Nom du fichier de ressources' de l'outil de compilation de ressource managée
	///          pour tous les fichiers .resx dont dépend cette classe. Dans le cas contraire,
	///          les concepteurs ne pourront pas interagir correctement avec les ressources
	///          localisées associées à ce formulaire.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			RefreshElements();
			//
			//TODO : ajoutez ici le code du constructeur
			//
		}

	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
			//nettoyage
		}
	private: System::Windows::Forms::TextBox^  textEntry;
	protected: 


	private: System::Collections::Generic::List<System::Windows::Forms::Button^>^  ButtonElements;
	private: System::Windows::Forms::MenuStrip^  menu;


	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  exitToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  addToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ruleToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  viewToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  dialogTreeToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  rulesToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  wordsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  databaseToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  addToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  removeToolStripMenuItem;
	private: System::Windows::Forms::GroupBox^  ElementContainer;
	private: System::Windows::Forms::Panel^  dialogTree;
	private: System::Windows::Forms::DataGridView^  rules;







	private : AI::Environment* environment;
	private: WindowRule^ ruleForm;
	private: WindowDatabase^ dataForm;




	private: System::Windows::Forms::ContextMenuStrip^  contextMenuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  editToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  deleteToolStripMenuItem;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  order;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  name;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  result;
	private: System::Windows::Forms::DataGridViewCheckBoxColumn^  active;
	private: System::ComponentModel::BackgroundWorker^  browserThread;
	private: System::Windows::Forms::TextBox^  textOut;
	private: System::ComponentModel::IContainer^  components;

			  




	protected: 


	private:
		/// <summary>
		/// Variable nécessaire au concepteur.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Méthode requise pour la prise en charge du concepteur - ne modifiez pas
		/// le contenu de cette méthode avec l'éditeur de code.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->textEntry = (gcnew System::Windows::Forms::TextBox());
			this->menu = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->addToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ruleToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->addToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->removeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->viewToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->dialogTreeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->rulesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->wordsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->databaseToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ElementContainer = (gcnew System::Windows::Forms::GroupBox());
			this->dialogTree = (gcnew System::Windows::Forms::Panel());
			this->rules = (gcnew System::Windows::Forms::DataGridView());
			this->order = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->name = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->result = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->active = (gcnew System::Windows::Forms::DataGridViewCheckBoxColumn());
			this->contextMenuStrip1 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->editToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->deleteToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->browserThread = (gcnew System::ComponentModel::BackgroundWorker());
			this->textOut = (gcnew System::Windows::Forms::TextBox());
			this->menu->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->rules))->BeginInit();
			this->contextMenuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// textEntry
			// 
			this->textEntry->ForeColor = System::Drawing::Color::Black;
			this->textEntry->Location = System::Drawing::Point(12, 404);
			this->textEntry->MaxLength = 200;
			this->textEntry->Name = L"textEntry";
			this->textEntry->Size = System::Drawing::Size(258, 20);
			this->textEntry->TabIndex = 0;
			this->textEntry->Text = L"hello, i am superman !";
			this->textEntry->PreviewKeyDown += gcnew System::Windows::Forms::PreviewKeyDownEventHandler(this, &Form1::textEntry_PreviewKeyDown);
			// 
			// menu
			// 
			this->menu->BackColor = System::Drawing::Color::Gainsboro;
			this->menu->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->fileToolStripMenuItem, 
				this->addToolStripMenuItem, this->viewToolStripMenuItem});
			this->menu->Location = System::Drawing::Point(0, 0);
			this->menu->Name = L"menu";
			this->menu->RenderMode = System::Windows::Forms::ToolStripRenderMode::Professional;
			this->menu->Size = System::Drawing::Size(1090, 24);
			this->menu->TabIndex = 3;
			this->menu->Text = L"menu";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->BackColor = System::Drawing::Color::Transparent;
			this->fileToolStripMenuItem->Checked = true;
			this->fileToolStripMenuItem->CheckState = System::Windows::Forms::CheckState::Checked;
			this->fileToolStripMenuItem->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->exitToolStripMenuItem});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->ForeColor = System::Drawing::Color::Black;
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(92, 22);
			this->exitToolStripMenuItem->Text = L"Exit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::exitToolStripMenuItem_Click);
			// 
			// addToolStripMenuItem
			// 
			this->addToolStripMenuItem->BackColor = System::Drawing::Color::Transparent;
			this->addToolStripMenuItem->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->addToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->ruleToolStripMenuItem});
			this->addToolStripMenuItem->Name = L"addToolStripMenuItem";
			this->addToolStripMenuItem->Size = System::Drawing::Size(48, 20);
			this->addToolStripMenuItem->Text = L"Tools";
			// 
			// ruleToolStripMenuItem
			// 
			this->ruleToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->addToolStripMenuItem1, 
				this->removeToolStripMenuItem});
			this->ruleToolStripMenuItem->ForeColor = System::Drawing::Color::Black;
			this->ruleToolStripMenuItem->Name = L"ruleToolStripMenuItem";
			this->ruleToolStripMenuItem->Size = System::Drawing::Size(98, 22);
			this->ruleToolStripMenuItem->Text = L"New";
			// 
			// addToolStripMenuItem1
			// 
			this->addToolStripMenuItem1->ForeColor = System::Drawing::Color::Black;
			this->addToolStripMenuItem1->Name = L"addToolStripMenuItem1";
			this->addToolStripMenuItem1->Size = System::Drawing::Size(104, 22);
			this->addToolStripMenuItem1->Text = L"Rule";
			this->addToolStripMenuItem1->Click += gcnew System::EventHandler(this, &Form1::addToolStripMenuItem1_Click);
			// 
			// removeToolStripMenuItem
			// 
			this->removeToolStripMenuItem->ForeColor = System::Drawing::Color::Black;
			this->removeToolStripMenuItem->Name = L"removeToolStripMenuItem";
			this->removeToolStripMenuItem->Size = System::Drawing::Size(104, 22);
			this->removeToolStripMenuItem->Text = L"Script";
			// 
			// viewToolStripMenuItem
			// 
			this->viewToolStripMenuItem->BackColor = System::Drawing::Color::Transparent;
			this->viewToolStripMenuItem->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->viewToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {this->dialogTreeToolStripMenuItem, 
				this->rulesToolStripMenuItem, this->wordsToolStripMenuItem, this->databaseToolStripMenuItem});
			this->viewToolStripMenuItem->Name = L"viewToolStripMenuItem";
			this->viewToolStripMenuItem->Size = System::Drawing::Size(44, 20);
			this->viewToolStripMenuItem->Text = L"View";
			// 
			// dialogTreeToolStripMenuItem
			// 
			this->dialogTreeToolStripMenuItem->ForeColor = System::Drawing::Color::Black;
			this->dialogTreeToolStripMenuItem->Name = L"dialogTreeToolStripMenuItem";
			this->dialogTreeToolStripMenuItem->ShowShortcutKeys = false;
			this->dialogTreeToolStripMenuItem->Size = System::Drawing::Size(124, 22);
			this->dialogTreeToolStripMenuItem->Text = L"Dialog tree";
			this->dialogTreeToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::dialogTreeToolStripMenuItem_Click);
			// 
			// rulesToolStripMenuItem
			// 
			this->rulesToolStripMenuItem->ForeColor = System::Drawing::Color::Black;
			this->rulesToolStripMenuItem->Name = L"rulesToolStripMenuItem";
			this->rulesToolStripMenuItem->Size = System::Drawing::Size(124, 22);
			this->rulesToolStripMenuItem->Text = L"Rules";
			this->rulesToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::rulesToolStripMenuItem_Click);
			// 
			// wordsToolStripMenuItem
			// 
			this->wordsToolStripMenuItem->ForeColor = System::Drawing::Color::Black;
			this->wordsToolStripMenuItem->Name = L"wordsToolStripMenuItem";
			this->wordsToolStripMenuItem->Size = System::Drawing::Size(124, 22);
			this->wordsToolStripMenuItem->Text = L"Words";
			this->wordsToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::wordsToolStripMenuItem_Click);
			// 
			// databaseToolStripMenuItem
			// 
			this->databaseToolStripMenuItem->ForeColor = System::Drawing::Color::Black;
			this->databaseToolStripMenuItem->Name = L"databaseToolStripMenuItem";
			this->databaseToolStripMenuItem->Size = System::Drawing::Size(124, 22);
			this->databaseToolStripMenuItem->Text = L"Database";
			this->databaseToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::databaseToolStripMenuItem_Click);
			// 
			// ElementContainer
			// 
			this->ElementContainer->Location = System::Drawing::Point(12, 27);
			this->ElementContainer->Name = L"ElementContainer";
			this->ElementContainer->Size = System::Drawing::Size(258, 326);
			this->ElementContainer->TabIndex = 4;
			this->ElementContainer->TabStop = false;
			this->ElementContainer->Visible = false;
			// 
			// dialogTree
			// 
			this->dialogTree->BackColor = System::Drawing::SystemColors::ActiveBorder;
			this->dialogTree->Location = System::Drawing::Point(276, 36);
			this->dialogTree->Name = L"dialogTree";
			this->dialogTree->Size = System::Drawing::Size(366, 388);
			this->dialogTree->TabIndex = 5;
			this->dialogTree->Visible = false;
			// 
			// rules
			// 
			this->rules->AllowUserToAddRows = false;
			this->rules->AllowUserToDeleteRows = false;
			this->rules->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->rules->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {this->order, this->name, 
				this->result, this->active});
			this->rules->Location = System::Drawing::Point(648, 36);
			this->rules->Name = L"rules";
			this->rules->ReadOnly = true;
			this->rules->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->rules->Size = System::Drawing::Size(435, 388);
			this->rules->TabIndex = 6;
			this->rules->Visible = false;
			this->rules->CellMouseDoubleClick += gcnew System::Windows::Forms::DataGridViewCellMouseEventHandler(this, &Form1::rules_CellMouseDoubleClick);
			this->rules->CellMouseDown += gcnew System::Windows::Forms::DataGridViewCellMouseEventHandler(this, &Form1::rules_CellMouseDown);
			this->rules->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::rules_Paint);
			// 
			// order
			// 
			this->order->DividerWidth = 2;
			this->order->HeaderText = L"order";
			this->order->MaxInputLength = 5;
			this->order->Name = L"order";
			this->order->ReadOnly = true;
			this->order->Width = 50;
			// 
			// name
			// 
			this->name->DividerWidth = 2;
			this->name->HeaderText = L"name";
			this->name->MaxInputLength = 200;
			this->name->Name = L"name";
			this->name->ReadOnly = true;
			this->name->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->name->Width = 200;
			// 
			// result
			// 
			this->result->DividerWidth = 2;
			this->result->HeaderText = L"result";
			this->result->Name = L"result";
			this->result->ReadOnly = true;
			// 
			// active
			// 
			this->active->HeaderText = L"active";
			this->active->Name = L"active";
			this->active->ReadOnly = true;
			this->active->Width = 40;
			// 
			// contextMenuStrip1
			// 
			this->contextMenuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->editToolStripMenuItem, 
				this->deleteToolStripMenuItem});
			this->contextMenuStrip1->Name = L"contextMenuStrip1";
			this->contextMenuStrip1->Size = System::Drawing::Size(108, 48);
			// 
			// editToolStripMenuItem
			// 
			this->editToolStripMenuItem->Name = L"editToolStripMenuItem";
			this->editToolStripMenuItem->Size = System::Drawing::Size(107, 22);
			this->editToolStripMenuItem->Text = L"Edit";
			this->editToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::editToolStripMenuItem_Click);
			// 
			// deleteToolStripMenuItem
			// 
			this->deleteToolStripMenuItem->Name = L"deleteToolStripMenuItem";
			this->deleteToolStripMenuItem->Size = System::Drawing::Size(107, 22);
			this->deleteToolStripMenuItem->Text = L"Delete";
			this->deleteToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::deleteToolStripMenuItem_Click);
			// 
			// browserThread
			// 
			this->browserThread->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &Form1::browserThread_DoWork);
			// 
			// textOut
			// 
			this->textOut->ForeColor = System::Drawing::Color::Black;
			this->textOut->Location = System::Drawing::Point(12, 378);
			this->textOut->MaxLength = 200;
			this->textOut->Name = L"textOut";
			this->textOut->ReadOnly = true;
			this->textOut->Size = System::Drawing::Size(258, 20);
			this->textOut->TabIndex = 7;
			// 
			// Form1
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->AutoSize = true;
			this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->BackColor = System::Drawing::Color::Gray;
			this->ClientSize = System::Drawing::Size(1090, 440);
			this->Controls->Add(this->textOut);
			this->Controls->Add(this->rules);
			this->Controls->Add(this->dialogTree);
			this->Controls->Add(this->ElementContainer);
			this->Controls->Add(this->textEntry);
			this->Controls->Add(this->menu);
			this->ForeColor = System::Drawing::Color::Black;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->MainMenuStrip = this->menu;
			this->Name = L"Form1";
			this->Text = L"Speech analysis 0.5b";
			this->TransparencyKey = System::Drawing::Color::Lime;
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Form1::Form1_FormClosing);
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->menu->ResumeLayout(false);
			this->menu->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->rules))->EndInit();
			this->contextMenuStrip1->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

//mes méthodes
public:
			void RefreshElements();

			void GenerateButtons(vector<Element*>* elements);

			void EditRule();

			void DeleteRule();

			void RedrawRules();

private: 
			System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e);

			System::Void exitToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);

			System::Void textEntry_PreviewKeyDown(System::Object^  sender, System::Windows::Forms::PreviewKeyDownEventArgs^  e);

			System::Void dialogTreeToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);

			System::Void rulesToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);

			System::Void wordsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);

			System::Void addToolStripMenuItem1_Click(System::Object^  sender, System::EventArgs^  e);

			System::Void Form1_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e);

			

			System::Void rules_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e);

			System::Void rules_CellMouseDoubleClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellMouseEventArgs^  e);

			System::Void editToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);

			System::Void deleteToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);

			System::Void rules_CellMouseDown(System::Object^  sender, System::Windows::Forms::DataGridViewCellMouseEventArgs^  e);

			System::Void databaseToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);


			System::Void data_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e);

			System::Void buttonAdd_Click(System::Object^  sender, System::EventArgs^  e);

			System::Void WindowRule_buttonOK_Click(System::Object^  sender, System::EventArgs^  e);

			System::Void WordTextChanged(System::Object^ sender, System::EventArgs^ e);

			System::Void browserThread_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e);

};
}

