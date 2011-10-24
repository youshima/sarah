#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace SpeechAnalysis1 {

	/// <summary>
	/// Description résumée de WindowRule
	///
	/// AVERTISSEMENT : si vous modifiez le nom de cette classe, vous devrez modifier la
	///          propriété 'Nom du fichier de ressources' de l'outil de compilation de ressource managée
	///          pour tous les fichiers .resx dont dépend cette classe. Dans le cas contraire,
	///          les concepteurs ne pourront pas interagir correctement avec les ressources
	///          localisées associées à ce formulaire.
	/// </summary>
	public ref class WindowRule : public System::Windows::Forms::Form
	{
	public:
		WindowRule(void)
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
		~WindowRule()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::RichTextBox^  LScript;
	protected: 

	protected: 
	private: System::Windows::Forms::Label^  Name;
	public: System::Windows::Forms::TextBox^  LName;

	public: System::Windows::Forms::Button^  buttonOK;
	public: System::Windows::Forms::Button^  buttonCompile;
	public: System::Windows::Forms::TextBox^  LDef;

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;

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
			this->LScript = (gcnew System::Windows::Forms::RichTextBox());
			this->Name = (gcnew System::Windows::Forms::Label());
			this->LName = (gcnew System::Windows::Forms::TextBox());
			this->buttonOK = (gcnew System::Windows::Forms::Button());
			this->buttonCompile = (gcnew System::Windows::Forms::Button());
			this->LDef = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// LScript
			// 
			this->LScript->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->LScript->Location = System::Drawing::Point(84, 98);
			this->LScript->Name = L"LScript";
			this->LScript->Size = System::Drawing::Size(440, 129);
			this->LScript->TabIndex = 0;
			this->LScript->Text = L"";
			// 
			// Name
			// 
			this->Name->AutoSize = true;
			this->Name->Location = System::Drawing::Point(12, 9);
			this->Name->Name = L"Name";
			this->Name->Size = System::Drawing::Size(68, 13);
			this->Name->TabIndex = 1;
			this->Name->Text = L"WindowRule";
			// 
			// LName
			// 
			this->LName->Location = System::Drawing::Point(84, 6);
			this->LName->Name = L"LName";
			this->LName->Size = System::Drawing::Size(161, 20);
			this->LName->TabIndex = 2;
			// 
			// buttonOK
			// 
			this->buttonOK->Location = System::Drawing::Point(445, 278);
			this->buttonOK->Name = L"buttonOK";
			this->buttonOK->Size = System::Drawing::Size(75, 23);
			this->buttonOK->TabIndex = 3;
			this->buttonOK->Text = L"OK";
			this->buttonOK->UseVisualStyleBackColor = true;
			this->buttonOK->Click += gcnew System::EventHandler(this, &WindowRule::buttonOK_Click);
			// 
			// buttonCompile
			// 
			this->buttonCompile->Location = System::Drawing::Point(12, 233);
			this->buttonCompile->Name = L"buttonCompile";
			this->buttonCompile->Size = System::Drawing::Size(75, 23);
			this->buttonCompile->TabIndex = 4;
			this->buttonCompile->Text = L"Compile";
			this->buttonCompile->UseVisualStyleBackColor = true;
			// 
			// LDef
			// 
			this->LDef->Location = System::Drawing::Point(84, 42);
			this->LDef->Multiline = true;
			this->LDef->Name = L"LDef";
			this->LDef->Size = System::Drawing::Size(436, 50);
			this->LDef->TabIndex = 6;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 45);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(66, 13);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Description :";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(9, 100);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(40, 13);
			this->label2->TabIndex = 7;
			this->label2->Text = L"Script :";
			// 
			// WindowRule
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(532, 313);
			this->ControlBox = false;
			this->Controls->Add(this->label2);
			this->Controls->Add(this->LDef);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->buttonCompile);
			this->Controls->Add(this->buttonOK);
			this->Controls->Add(this->LName);
			this->Controls->Add(this->Name);
			this->Controls->Add(this->LScript);
			this->Name->Text = L"WindowRule";
			this->Text = L"WindowRule";
			this->Load += gcnew System::EventHandler(this, &WindowRule::WindowRule_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void WindowRule_Load(System::Object^  sender, System::EventArgs^  e) {
			 }
private: System::Void buttonOK_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
};
}
