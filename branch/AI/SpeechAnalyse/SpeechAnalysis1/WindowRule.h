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
	private: System::Windows::Forms::RichTextBox^  scriptEntry;
	protected: 
	private: System::Windows::Forms::Label^  Name;
	private: System::Windows::Forms::TextBox^  labelName;
	private: System::Windows::Forms::Button^  buttonOK;
	private: System::Windows::Forms::Button^  buttonCompile;

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
			this->scriptEntry = (gcnew System::Windows::Forms::RichTextBox());
			this->Name = (gcnew System::Windows::Forms::Label());
			this->labelName = (gcnew System::Windows::Forms::TextBox());
			this->buttonOK = (gcnew System::Windows::Forms::Button());
			this->buttonCompile = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// scriptEntry
			// 
			this->scriptEntry->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->scriptEntry->Location = System::Drawing::Point(12, 45);
			this->scriptEntry->Name = L"scriptEntry";
			this->scriptEntry->Size = System::Drawing::Size(512, 182);
			this->scriptEntry->TabIndex = 0;
			this->scriptEntry->Text = L"";
			// 
			// Name
			// 
			this->Name->AutoSize = true;
			this->Name->Location = System::Drawing::Point(12, 15);
			this->Name->Name = L"Name";
			this->Name->Size = System::Drawing::Size(35, 13);
			this->Name->TabIndex = 1;
			this->Name->Text = L"Name";
			// 
			// labelName
			// 
			this->labelName->Location = System::Drawing::Point(53, 12);
			this->labelName->Name = L"labelName";
			this->labelName->Size = System::Drawing::Size(161, 20);
			this->labelName->TabIndex = 2;
			// 
			// buttonOK
			// 
			this->buttonOK->Location = System::Drawing::Point(445, 278);
			this->buttonOK->Name = L"buttonOK";
			this->buttonOK->Size = System::Drawing::Size(75, 23);
			this->buttonOK->TabIndex = 3;
			this->buttonOK->Text = L"OK";
			this->buttonOK->UseVisualStyleBackColor = true;
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
			// WindowRule
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(532, 313);
			this->Controls->Add(this->buttonCompile);
			this->Controls->Add(this->buttonOK);
			this->Controls->Add(this->labelName);
			this->Controls->Add(this->Name);
			this->Controls->Add(this->scriptEntry);
			this->Name->Text = L"WindowRule";
			this->Text = L"WindowRule";
			this->Load += gcnew System::EventHandler(this, &WindowRule::WindowRule_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void WindowRule_Load(System::Object^  sender, System::EventArgs^  e) {
			 }
};
}
