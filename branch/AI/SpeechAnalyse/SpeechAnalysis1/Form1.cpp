#include "StdAfx.h"
#include "Form1.h"

using namespace SpeechAnalysis1;


void Form1::RefreshElements() {

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

void Form1::GenerateButtons(vector<Element*>* elements) {
			
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
void Form1::EditRule() {

			WindowRule^ window = (WindowRule^)this->ruleForm;
			 //recuperer la regle selectionnée par l'utilisateur
			 
			 UINT index = (UINT)this->rules->SelectedRows[0]->Index;
			 AI::Rule* rule = environment->getRule(index);
			 window->LName->Text = gcnew String(rule->getName()->c_str());
			 window->LDef->Text = gcnew String(rule->getAbout()->c_str());
			 window->LScript->Text = gcnew String(rule->getScript()->c_str());
			 window->Show();
}
void Form1::DeleteRule() {

			WindowRule^ window = (WindowRule^)this->ruleForm;
			 //recuperer la regle selectionnée par l'utilisateur
			 
			 UINT index = (UINT)this->rules->SelectedRows[0]->Index;
			 environment->RemoveRule(index);
}
void Form1::RedrawRules() {

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
System::Void Form1::Form1_Load(System::Object^  sender, System::EventArgs^  e) {

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
				 dataForm = gcnew WindowDatabase();
				 dataForm->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Form1::data_FormClosing);
				 dataForm->buttonAdd->Click += gcnew System::EventHandler(this, &Form1::buttonAdd_Click);
				 dataForm->textWord->TextChanged += gcnew System::EventHandler(this, &Form1::WordTextChanged);

					 
					 
				 
				 ruleForm->buttonOK->Click += gcnew System::EventHandler(this, &Form1::WindowRule_buttonOK_Click);

				 RedrawRules();
				 RefreshElements();
				
}

System::Void Form1::exitToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

			 this->Close();
}

System::Void Form1::textEntry_PreviewKeyDown(System::Object^  sender, System::Windows::Forms::PreviewKeyDownEventArgs^  e) {

			 if(e->KeyCode == Keys::Enter)
			 {
				SentenceParser* sp = new SentenceParser();
				vector<Element*>* elements = sp->Analyse(this->textEntry->Text);
				
				GenerateButtons(elements);
			 }
}

System::Void Form1::dialogTreeToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

			 this->dialogTree->Visible = !this->dialogTree->Visible; //toogle la visibilité
			 RefreshElements();
}
System::Void Form1::rulesToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->rules->Visible = !this->rules->Visible; //toogle la visibilité
			 RefreshElements();
}

System::Void Form1::wordsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->ElementContainer->Visible = !this->ElementContainer->Visible; //toogle la visibilité
			 RefreshElements();
}
System::Void Form1::addToolStripMenuItem1_Click(System::Object^  sender, System::EventArgs^  e) {

			 ruleForm->Show();
}
System::Void Form1::Form1_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {

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
System::Void Form1::rules_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
			 
}
System::Void Form1::rules_CellMouseDoubleClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellMouseEventArgs^  e) {

			 EditRule();
}
System::Void Form1::editToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

			 EditRule();
}
System::Void Form1::deleteToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

			 DeleteRule();
			 this->RedrawRules();
}
System::Void Form1::rules_CellMouseDown(System::Object^  sender, System::Windows::Forms::DataGridViewCellMouseEventArgs^  e) {

			 if(e->Button == System::Windows::Forms::MouseButtons::Right)
				 this->contextMenuStrip1->Show(Point(Cursor->Position.X, Cursor->Position.Y));
}
System::Void Form1::databaseToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

			 this->dataForm->Show();

}
/*



*/
System::Void Form1::data_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
				
}
System::Void Form1::buttonAdd_Click(System::Object^  sender, System::EventArgs^  e) {

}
/*


*/
System::Void Form1::WindowRule_buttonOK_Click(System::Object^  sender, System::EventArgs^  e) {

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

System::Void Form1::WordTextChanged(System::Object^ sender, System::EventArgs^ e) {
	this->browserThread->RunWorkerAsync();
}
System::Void Form1::browserThread_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e) {

	this->environment->findWords(tostring(this->dataForm->textWord->Text));
}