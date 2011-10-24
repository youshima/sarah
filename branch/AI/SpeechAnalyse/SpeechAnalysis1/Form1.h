#pragma once

#include "SentenceParser.h"

#include "WindowRule.h"
#include "Environment.h"

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
	private: Form^ ruleForm;




	private: System::Windows::Forms::ContextMenuStrip^  contextMenuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  editToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  deleteToolStripMenuItem;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  order;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  name;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  result;
	private: System::Windows::Forms::DataGridViewCheckBoxColumn^  active;
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
			this->contextMenuStrip1 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->editToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->deleteToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->order = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->name = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->result = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->active = (gcnew System::Windows::Forms::DataGridViewCheckBoxColumn());
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
			this->fileToolStripMenuItem->Size = System::Drawing::Size(41, 20);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->ForeColor = System::Drawing::Color::Black;
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(99, 22);
			this->exitToolStripMenuItem->Text = L"Exit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::exitToolStripMenuItem_Click);
			// 
			// addToolStripMenuItem
			// 
			this->addToolStripMenuItem->BackColor = System::Drawing::Color::Transparent;
			this->addToolStripMenuItem->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->addToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->ruleToolStripMenuItem});
			this->addToolStripMenuItem->Name = L"addToolStripMenuItem";
			this->addToolStripMenuItem->Size = System::Drawing::Size(50, 20);
			this->addToolStripMenuItem->Text = L"Tools";
			// 
			// ruleToolStripMenuItem
			// 
			this->ruleToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->addToolStripMenuItem1, 
				this->removeToolStripMenuItem});
			this->ruleToolStripMenuItem->ForeColor = System::Drawing::Color::Black;
			this->ruleToolStripMenuItem->Name = L"ruleToolStripMenuItem";
			this->ruleToolStripMenuItem->Size = System::Drawing::Size(101, 22);
			this->ruleToolStripMenuItem->Text = L"New";
			// 
			// addToolStripMenuItem1
			// 
			this->addToolStripMenuItem1->ForeColor = System::Drawing::Color::Black;
			this->addToolStripMenuItem1->Name = L"addToolStripMenuItem1";
			this->addToolStripMenuItem1->Size = System::Drawing::Size(110, 22);
			this->addToolStripMenuItem1->Text = L"Rule";
			this->addToolStripMenuItem1->Click += gcnew System::EventHandler(this, &Form1::addToolStripMenuItem1_Click);
			// 
			// removeToolStripMenuItem
			// 
			this->removeToolStripMenuItem->ForeColor = System::Drawing::Color::Black;
			this->removeToolStripMenuItem->Name = L"removeToolStripMenuItem";
			this->removeToolStripMenuItem->Size = System::Drawing::Size(110, 22);
			this->removeToolStripMenuItem->Text = L"Script";
			// 
			// viewToolStripMenuItem
			// 
			this->viewToolStripMenuItem->BackColor = System::Drawing::Color::Transparent;
			this->viewToolStripMenuItem->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->viewToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {this->dialogTreeToolStripMenuItem, 
				this->rulesToolStripMenuItem, this->wordsToolStripMenuItem, this->databaseToolStripMenuItem});
			this->viewToolStripMenuItem->Name = L"viewToolStripMenuItem";
			this->viewToolStripMenuItem->Size = System::Drawing::Size(48, 20);
			this->viewToolStripMenuItem->Text = L"View";
			// 
			// dialogTreeToolStripMenuItem
			// 
			this->dialogTreeToolStripMenuItem->ForeColor = System::Drawing::Color::Black;
			this->dialogTreeToolStripMenuItem->Name = L"dialogTreeToolStripMenuItem";
			this->dialogTreeToolStripMenuItem->ShowShortcutKeys = false;
			this->dialogTreeToolStripMenuItem->Size = System::Drawing::Size(131, 22);
			this->dialogTreeToolStripMenuItem->Text = L"Dialog tree";
			this->dialogTreeToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::dialogTreeToolStripMenuItem_Click);
			// 
			// rulesToolStripMenuItem
			// 
			this->rulesToolStripMenuItem->ForeColor = System::Drawing::Color::Black;
			this->rulesToolStripMenuItem->Name = L"rulesToolStripMenuItem";
			this->rulesToolStripMenuItem->Size = System::Drawing::Size(131, 22);
			this->rulesToolStripMenuItem->Text = L"Rules";
			this->rulesToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::rulesToolStripMenuItem_Click);
			// 
			// wordsToolStripMenuItem
			// 
			this->wordsToolStripMenuItem->ForeColor = System::Drawing::Color::Black;
			this->wordsToolStripMenuItem->Name = L"wordsToolStripMenuItem";
			this->wordsToolStripMenuItem->Size = System::Drawing::Size(131, 22);
			this->wordsToolStripMenuItem->Text = L"Words";
			this->wordsToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::wordsToolStripMenuItem_Click);
			// 
			// databaseToolStripMenuItem
			// 
			this->databaseToolStripMenuItem->ForeColor = System::Drawing::Color::Black;
			this->databaseToolStripMenuItem->Name = L"databaseToolStripMenuItem";
			this->databaseToolStripMenuItem->Size = System::Drawing::Size(131, 22);
			this->databaseToolStripMenuItem->Text = L"Database";
			// 
			// ElementContainer
			// 
			this->ElementContainer->Location = System::Drawing::Point(12, 27);
			this->ElementContainer->Name = L"ElementContainer";
			this->ElementContainer->Size = System::Drawing::Size(258, 371);
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
			this->rules->CellMouseDown += gcnew System::Windows::Forms::DataGridViewCellMouseEventHandler(this, &Form1::rules_CellMouseDown);
			this->rules->CellMouseDoubleClick += gcnew System::Windows::Forms::DataGridViewCellMouseEventHandler(this, &Form1::rules_CellMouseDoubleClick);
			this->rules->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::rules_Paint);
			// 
			// contextMenuStrip1
			// 
			this->contextMenuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->editToolStripMenuItem, 
				this->deleteToolStripMenuItem});
			this->contextMenuStrip1->Name = L"contextMenuStrip1";
			this->contextMenuStrip1->Size = System::Drawing::Size(114, 48);
			// 
			// editToolStripMenuItem
			// 
			this->editToolStripMenuItem->Name = L"editToolStripMenuItem";
			this->editToolStripMenuItem->Size = System::Drawing::Size(113, 22);
			this->editToolStripMenuItem->Text = L"Edit";
			this->editToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::editToolStripMenuItem_Click);
			// 
			// deleteToolStripMenuItem
			// 
			this->deleteToolStripMenuItem->Name = L"deleteToolStripMenuItem";
			this->deleteToolStripMenuItem->Size = System::Drawing::Size(113, 22);
			this->deleteToolStripMenuItem->Text = L"Delete";
			this->deleteToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::deleteToolStripMenuItem_Click);
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
			// Form1
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->AutoSize = true;
			this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->BackColor = System::Drawing::Color::Gray;
			this->ClientSize = System::Drawing::Size(1090, 440);
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
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Form1::Form1_FormClosing);
			this->menu->ResumeLayout(false);
			this->menu->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->rules))->EndInit();
			this->contextMenuStrip1->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				

			 }
		//mes méthodes
	 public:
		 void RefreshElements()
		 {
			 if(this->ElementContainer->Visible)
				this->textEntry->Location = System::Drawing::Point(12, 404);
			 else
				this->textEntry->Location = System::Drawing::Point(12, 40);

			 if(this->dialogTree->Visible)
				this->rules->Location = System::Drawing::Point(648, 36);
			 else
				 this->rules->Location = System::Drawing::Point(648 - this->dialogTree->Width, 36);

			// ToolStripMenuItem^ item = (ToolStripMenuItem^)this->menu->Items[this->menu->Items->IndexOfKey("dialogTreeToolStripMenuItem")];
			 ToolStripMenuItem^ item = (ToolStripMenuItem^)this->menu->Items->Find("dialogTreeToolStripMenuItem",true)[0];
			 item->Checked = this->dialogTree->Visible;
		
			 item = (ToolStripMenuItem^)this->menu->Items->Find("rulesToolStripMenuItem",true)[0];
			 item->Checked = this->rules->Visible;
			
			 item = (ToolStripMenuItem^)this->menu->Items->Find("wordsToolStripMenuItem",true)[0];
			 item->Checked = this->ElementContainer->Visible;
		 }

		 void GenerateButtons(vector<Element*>* elements) {
			
			 //enlever les boutons d'abord

			 for(UINT i = 0; i < (UINT)ButtonElements->Count; i++)
				 this->ElementContainer->Controls->Remove(ButtonElements[i]);

			 ButtonElements->Clear();

			 UINT offset = 0; //decalage depuis la gauche
			 UINT topOffset = 0; //decalage depuis le haut

			 for(UINT i = 0; i < elements->size(); i++)
			 {
				
				Button^ button = (gcnew System::Windows::Forms::Button());
				UINT size = 5 * elements->at(i)->getLength();

				if(offset + size + 25 >= (UINT)this->ElementContainer->Size.Width - 5)
				{
					offset = 0;
					topOffset += 35;
				}

				button->Location = System::Drawing::Point(5 + offset, 10 + topOffset);
				button->Name = L"ButtonAnalyse";
				button->Size = System::Drawing::Size(size+25,30);
				button->TabIndex = 1+i;
				button->Text = gcnew String(elements->at(i)->getString()->c_str());
				button->UseVisualStyleBackColor = true;

				if(elements->at(i)->isSeparator())
					button->BackColor = Color::Red;
				
		//	    button->Click += gcnew System::EventHandler(this, &Form1::buttonElements_Click);
				this->ElementContainer->Controls->Add(button);
				
				
				ButtonElements->Add(button);

				offset += (size + 25);
			 }
				
		 }
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
				 ButtonElements = gcnew Collections::Generic::List<Button^>();
				 environment = new AI::Environment(); //chargement de l'environnement
				 File file; //chargement des données utilisateur
				 bool existed;
				 file.open(PROFILE,existed);
				 if(existed)
				 {
					 bool boolean;
					 file.read(boolean);
					 this->dialogTree->Visible = boolean;
					 file.read(boolean);
					 this->rules->Visible = boolean;
					 file.read(boolean);
					 this->ElementContainer->Visible = boolean;
				 }
				 file.close();
				 ruleForm = gcnew WindowRule();
				 int elementIndex = ruleForm->Controls->IndexOfKey("buttonOK");
				 Control^ buttonOK = (Control^)ruleForm->Controls[elementIndex];
				 
				 buttonOK->Click += gcnew System::EventHandler(this, &Form1::WindowRule_buttonOK_Click);

				 RedrawRules();
				 RefreshElements();
				
			 }

private: System::Void exitToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Close();
		 }

private: System::Void textEntry_PreviewKeyDown(System::Object^  sender, System::Windows::Forms::PreviewKeyDownEventArgs^  e) {
			 if(e->KeyCode == Keys::Enter)
			 {
				SentenceParser* sp = new SentenceParser();
				vector<Element*>* elements = sp->Analyse(this->textEntry->Text);
				
				GenerateButtons(elements);
			 }
		 }

private: System::Void dialogTreeToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

			 this->dialogTree->Visible = !this->dialogTree->Visible; //toogle la visibilité
			 RefreshElements();
		 }
private: System::Void rulesToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->rules->Visible = !this->rules->Visible; //toogle la visibilité
			 RefreshElements();
		 }

private: System::Void wordsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->ElementContainer->Visible = !this->ElementContainer->Visible; //toogle la visibilité
			 RefreshElements();
		 }
private: System::Void addToolStripMenuItem1_Click(System::Object^  sender, System::EventArgs^  e) {
			 ruleForm->Show();
		 }
private: System::Void Form1_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
			 environment->~Environment(); // sauvegarde et destruction de l'environnement
			 File file; //sauvegarde des données utilisateur
			 bool existed;
		     file.open(PROFILE,existed);
			 file.empty();
			 file.write(this->dialogTree->Visible);
			 file.write(this->rules->Visible);
			 file.write(this->ElementContainer->Visible);
		     file.close();
			 
		 }
private : System::Void WindowRule_buttonOK_Click(System::Object^  sender, System::EventArgs^  e) {
			  WindowRule^ window = (WindowRule^)this->ruleForm;
			  
			  
			  AI::Rule* rule = new AI::Rule();
			  
			  std::string str = tostring(window->LName->Text);
			  rule->setName(str);
			  str = tostring(window->LDef->Text);
			  rule->setAbout(str);
			  str = tostring(window->LScript->Text);
			  rule->setScript(str);
			  bool enabled = true;
			  rule->setEnabled(enabled);
			  environment->AddRule(*rule); //ajouter ou modifier la regle

			  rule->~Rule();

			  str.~basic_string();
			  window->Hide();
			  RedrawRules();
		  }
private: System::Void rules_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
			 
		 }
private: System::Void RedrawRules() {
			 this->rules->Rows->Clear();

			 for(UINT i = 0; i < environment->getRulesCount(); i++)
			 {
				 this->rules->Rows->Add();
				//array< System::Object^>^  values;
				
				// this->rules->Rows[i]->SetValues(values);
				 this->rules->Rows[i]->Cells[0]->Value = i;
				 this->rules->Rows[i]->Cells[1]->Value = gcnew String(environment->getRule(i)->getName()->c_str());
				// this->rules->Rows[i]->Cells[2]->Value = gcnew String(environment->getRule(i)->getAbout()->c_str());
				 this->rules->Rows[i]->Cells[3]->Value = environment->getRule(i)->getEnabled();
			 }
		 }
private: System::Void rules_CellMouseDoubleClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellMouseEventArgs^  e) {

			 EditRule();
		 }
private: System::Void editToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 EditRule();
		 }
		 void EditRule()
		 {
			WindowRule^ window = (WindowRule^)this->ruleForm;
			 //recuperer la regle selectionnée par l'utilisateur
			 
			 UINT index = (UINT)this->rules->SelectedRows[0]->Index;
			 AI::Rule* rule = environment->getRule(index);
			 window->LName->Text = gcnew String(rule->getName()->c_str());
			 window->LDef->Text = gcnew String(rule->getAbout()->c_str());
			 window->LScript->Text = gcnew String(rule->getScript()->c_str());
			 window->Show();
		 }
		 void DeleteRule()
		 {
			WindowRule^ window = (WindowRule^)this->ruleForm;
			 //recuperer la regle selectionnée par l'utilisateur
			 
			 UINT index = (UINT)this->rules->SelectedRows[0]->Index;
			 environment->RemoveRule(index);
		 }
private: System::Void deleteToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 DeleteRule();
			 this->RedrawRules();
		 }
private: System::Void rules_CellMouseDown(System::Object^  sender, System::Windows::Forms::DataGridViewCellMouseEventArgs^  e) {

			 if(e->Button == System::Windows::Forms::MouseButtons::Right)
			 {
				 this->contextMenuStrip1->Location = Point(e->Location.X + this->Location.X, e->Location.Y + this->Location.Y);
				 this->contextMenuStrip1->Refresh();
				 this->contextMenuStrip1->Show();
			 }
		 }
};
}

