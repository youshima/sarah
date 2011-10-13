#pragma once

#include "SentenceParser.h"

namespace SpeechAnalysis1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

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
		}
	private: System::Windows::Forms::TextBox^  textEntry;
	protected: 

	private: System::Windows::Forms::Button^  ButtonAnalyse;
	private: System::Collections::Generic::List<System::Windows::Forms::Button^>^  ButtonElements;
	private: System::Windows::Forms::PictureBox^  painter;


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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->painter))->BeginInit();
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
			this->textEntry->Text = L"Hello, I am superman!";
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
			this->painter->Location = System::Drawing::Point(289, 20);
			this->painter->Name = L"painter";
			this->painter->Size = System::Drawing::Size(449, 432);
			this->painter->TabIndex = 2;
			this->painter->TabStop = false;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(766, 473);
			this->Controls->Add(this->painter);
			this->Controls->Add(this->ButtonAnalyse);
			this->Controls->Add(this->textEntry);
			this->Name = L"Form1";
			this->Text = L"Speech analysis 0.5b";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->painter))->EndInit();
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

			 for(UINT i = 0; i < ButtonElements->Count; i++)
				 this->Controls->Remove(ButtonElements[i]);
			 ButtonElements->Clear();
			 UINT offset = 0; //decalage depuis la gauche
			 UINT topOffset = 0; //decalage depuis le haut
			for(UINT i = 0; i < elements->size(); i++)
			{
				
				Button^ button = (gcnew System::Windows::Forms::Button());
				UINT size = 5 * elements->at(i)->getLength();
				if(offset + size + 25 >= 280)
				{
					offset = 0;
					topOffset += 35;
				}
				button->Location = System::Drawing::Point(10+offset, 10 + topOffset);
				button->Name = L"ButtonAnalyse";
				button->Size = System::Drawing::Size(size+25,30);
				button->TabIndex = 1+i;
				button->Text = gcnew String(elements->at(i)->getData());
				button->UseVisualStyleBackColor = true;
				if(elements->at(i)->isSeparator())
					button->BackColor = Color::Red;
				
			    button->Click += gcnew System::EventHandler(this, &Form1::buttonElements_Click);

				this->Controls->Add(button);
				
				ButtonElements->Add(button);
				offset += (size + 25);
			}
				
		 }
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
				 ButtonElements = gcnew Collections::Generic::List<Button^>();
			 }

   private: System::Void buttonElements_Click(System::Object^  sender, System::EventArgs^  e) {
			}
};
}

