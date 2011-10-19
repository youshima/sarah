#pragma once

#include "SentenceParser.h"

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

	private: System::Windows::Forms::Button^  ButtonAnalyse;
	private: System::Collections::Generic::List<System::Windows::Forms::Button^>^  ButtonElements;
	private: System::Windows::Forms::PictureBox^  painter;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
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
			this->textEntry = (gcnew System::Windows::Forms::TextBox());
			this->ButtonAnalyse = (gcnew System::Windows::Forms::Button());
			this->painter = (gcnew System::Windows::Forms::PictureBox());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->painter))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// textEntry
			// 
			this->textEntry->Location = System::Drawing::Point(12, 337);
			this->textEntry->MaxLength = 200;
			this->textEntry->Multiline = true;
			this->textEntry->Name = L"textEntry";
			this->textEntry->Size = System::Drawing::Size(258, 87);
			this->textEntry->TabIndex = 0;
			this->textEntry->Text = L"Hello, I am superman !";
			this->textEntry->TextChanged += gcnew System::EventHandler(this, &Form1::textEntry_TextChanged);
			// 
			// ButtonAnalyse
			// 
			this->ButtonAnalyse->Location = System::Drawing::Point(195, 429);
			this->ButtonAnalyse->Name = L"ButtonAnalyse";
			this->ButtonAnalyse->Size = System::Drawing::Size(75, 23);
			this->ButtonAnalyse->TabIndex = 1;
			this->ButtonAnalyse->Text = L"Analyse";
			this->ButtonAnalyse->UseVisualStyleBackColor = true;
			this->ButtonAnalyse->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// painter
			// 
			this->painter->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->painter->Location = System::Drawing::Point(289, 27);
			this->painter->Name = L"painter";
			this->painter->Size = System::Drawing::Size(449, 425);
			this->painter->TabIndex = 2;
			this->painter->TabStop = false;
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->fileToolStripMenuItem, 
				this->addToolStripMenuItem, this->viewToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(766, 24);
			this->menuStrip1->TabIndex = 3;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->exitToolStripMenuItem});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(41, 20);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(99, 22);
			this->exitToolStripMenuItem->Text = L"Exit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::exitToolStripMenuItem_Click);
			// 
			// addToolStripMenuItem
			// 
			this->addToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->ruleToolStripMenuItem});
			this->addToolStripMenuItem->Name = L"addToolStripMenuItem";
			this->addToolStripMenuItem->Size = System::Drawing::Size(50, 20);
			this->addToolStripMenuItem->Text = L"Tools";
			// 
			// ruleToolStripMenuItem
			// 
			this->ruleToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->addToolStripMenuItem1, 
				this->removeToolStripMenuItem});
			this->ruleToolStripMenuItem->Name = L"ruleToolStripMenuItem";
			this->ruleToolStripMenuItem->Size = System::Drawing::Size(109, 22);
			this->ruleToolStripMenuItem->Text = L"Rules";
			this->ruleToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::ruleToolStripMenuItem_Click);
			// 
			// addToolStripMenuItem1
			// 
			this->addToolStripMenuItem1->Name = L"addToolStripMenuItem1";
			this->addToolStripMenuItem1->Size = System::Drawing::Size(122, 22);
			this->addToolStripMenuItem1->Text = L"Add";
			// 
			// removeToolStripMenuItem
			// 
			this->removeToolStripMenuItem->Name = L"removeToolStripMenuItem";
			this->removeToolStripMenuItem->Size = System::Drawing::Size(122, 22);
			this->removeToolStripMenuItem->Text = L"Remove";
			// 
			// viewToolStripMenuItem
			// 
			this->viewToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {this->dialogTreeToolStripMenuItem, 
				this->rulesToolStripMenuItem, this->wordsToolStripMenuItem, this->databaseToolStripMenuItem});
			this->viewToolStripMenuItem->Name = L"viewToolStripMenuItem";
			this->viewToolStripMenuItem->Size = System::Drawing::Size(48, 20);
			this->viewToolStripMenuItem->Text = L"View";
			// 
			// dialogTreeToolStripMenuItem
			// 
			this->dialogTreeToolStripMenuItem->Name = L"dialogTreeToolStripMenuItem";
			this->dialogTreeToolStripMenuItem->Size = System::Drawing::Size(138, 22);
			this->dialogTreeToolStripMenuItem->Text = L"Dialog tree";
			// 
			// rulesToolStripMenuItem
			// 
			this->rulesToolStripMenuItem->Name = L"rulesToolStripMenuItem";
			this->rulesToolStripMenuItem->Size = System::Drawing::Size(138, 22);
			this->rulesToolStripMenuItem->Text = L"Rules";
			// 
			// wordsToolStripMenuItem
			// 
			this->wordsToolStripMenuItem->Name = L"wordsToolStripMenuItem";
			this->wordsToolStripMenuItem->Size = System::Drawing::Size(138, 22);
			this->wordsToolStripMenuItem->Text = L"Words";
			// 
			// databaseToolStripMenuItem
			// 
			this->databaseToolStripMenuItem->Name = L"databaseToolStripMenuItem";
			this->databaseToolStripMenuItem->Size = System::Drawing::Size(138, 22);
			this->databaseToolStripMenuItem->Text = L"Database";
			// 
			// ElementContainer
			// 
			this->ElementContainer->Location = System::Drawing::Point(12, 27);
			this->ElementContainer->Name = L"ElementContainer";
			this->ElementContainer->Size = System::Drawing::Size(258, 300);
			this->ElementContainer->TabIndex = 4;
			this->ElementContainer->TabStop = false;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(766, 473);
			this->Controls->Add(this->ElementContainer);
			this->Controls->Add(this->painter);
			this->Controls->Add(this->ButtonAnalyse);
			this->Controls->Add(this->textEntry);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"Form1";
			this->Text = L"Speech analysis 0.5b";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Form1::Form1_FormClosing);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->painter))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				SentenceParser* sp = new SentenceParser();
				vector<Element*>* elements = sp->Analyse(this->textEntry->Text);
				
				GenerateButtons(elements);

			 }
		//mes méthodes
	 public:
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
				UINT size = 5 * *elements->at(i)->getLength();

				if(offset + size + 25 >= this->ElementContainer->Size.Width)
				{
					offset = 0;
					topOffset += 35;
				}

				button->Location = System::Drawing::Point(offset, 10 + topOffset);
				button->Name = L"ButtonAnalyse";
				button->Size = System::Drawing::Size(size+25,30);
				button->TabIndex = 1+i;
				button->Text = gcnew String(elements->at(i)->getString()->getString());
				button->UseVisualStyleBackColor = true;

				if(elements->at(i)->isSeparator())
					button->BackColor = Color::Red;
				
			    button->Click += gcnew System::EventHandler(this, &Form1::buttonElements_Click);
				this->ElementContainer->Controls->Add(button);
				
				
				ButtonElements->Add(button);

				offset += (size + 25);
			 }
				
		 }
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
				 ButtonElements = gcnew Collections::Generic::List<Button^>();
			 }

   private: System::Void buttonElements_Click(System::Object^  sender, System::EventArgs^  e) {
			}
private: System::Void textEntry_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void ruleToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void exitToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Close();
		 }
private: System::Void Form1_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {

		 }
};
}

