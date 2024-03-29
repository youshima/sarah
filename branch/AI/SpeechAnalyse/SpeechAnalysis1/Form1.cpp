#include "StdAfx.h"
#include "Form1.h"
#include "WordNet.h"
#include <vcclr.h>

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

	bool Form1::To_CharStar( String^ source, char*& target )
{
    pin_ptr<const wchar_t> wch = PtrToStringChars( source );
    int len = (( source->Length+1) * 2);
    target = new char[ len ];
    return wcstombs( target, wch, len ) != -1;
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
				
			    button->Click += gcnew System::EventHandler(this, &Form1::buttonAdd_Click);
				this->ElementContainer->Controls->Add(button);
				
				ButtonElements->Add(button);

				offset += (size + 25);
			 }
				
}
void Form1::EditRule() {

			WindowRule^ window = (WindowRule^)this->ruleForm;
			 //recuperer la regle selectionn�e par l'utilisateur
			 
			 UINT index = (UINT)this->rules->SelectedRows[0]->Index;
			 AI::Rule* rule = environment->getRule(index);
			 window->LName->Text = gcnew String(rule->getName().c_str());
			 window->LDef->Text = gcnew String(rule->getAbout().c_str());
			 window->LScript->Text = gcnew String(rule->getScript().c_str());
			 window->Show();
}
void Form1::DeleteRule() {

			WindowRule^ window = (WindowRule^)this->ruleForm;
			 //recuperer la regle selectionn�e par l'utilisateur
			 
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
				 this->rules->Rows[i]->Cells[1]->Value = gcnew String(environment->getRule(i)->getName().c_str());
				 this->rules->Rows[i]->Cells[2]->Value = gcnew String(environment->getRule(i)->getResult().c_str());
				 this->rules->Rows[i]->Cells[3]->Value = environment->getRule(i)->getEnabled();
			 }
}
System::Void Form1::Form1_Load(System::Object^  sender, System::EventArgs^  e) {

				 ButtonElements = gcnew Collections::Generic::List<Button^>();
				 environment = new AI::Environment(); //chargement de l'environnement
				 File file; //chargement des donn�es utilisateur
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
				 VAR sentence;
				 sentence = VAR("SENTENCE");
				 std::string fastStr = "";
					for(UINT i = 0; i < (UINT)this->textEntry->Text->Length; i++) //boucle simple de copie
						fastStr += (char)this->textEntry->Text[i];
					Value v;
					v = fastStr;
				 sentence.setValue(v);

				 environment->AddVar(sentence);
				 
				 environment->setVar(std::string("SENTENCE"),v);
				SentenceParser* sp = new SentenceParser();
				vector<Element*>* elements = sp->Analyse(this->textEntry->Text);

				HRESULT hr;
				for(int i = 0; i < environment->getRulesCount(); i++)
				{
					hr = environment->executer(environment->getRule(i));
					if(hr == E_FAIL)
						environment->getRule(i)->setResult(std::string("ECHEC"));
					else
						environment->getRule(i)->setResult(std::string("OK"));
						
				}
				
				VAR* var = environment->getVar(std::string("ANSWER"));
				if(var)
					this->textOut->Text = gcnew String(var->getValue().getValue());
				GenerateButtons(elements);

				RedrawRules();
			 }
}

System::Void Form1::dialogTreeToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

			 this->dialogTree->Visible = !this->dialogTree->Visible; //toogle la visibilit�
			 RefreshElements();
}
System::Void Form1::rulesToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->rules->Visible = !this->rules->Visible; //toogle la visibilit�
			 RefreshElements();
}

System::Void Form1::wordsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->ElementContainer->Visible = !this->ElementContainer->Visible; //toogle la visibilit�
			 RefreshElements();
}
System::Void Form1::addToolStripMenuItem1_Click(System::Object^  sender, System::EventArgs^  e) {

			 ruleForm->Show();
}
System::Void Form1::Form1_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {

			 environment->~Environment(); // sauvegarde et destruction de l'environnement
			 File file; //sauvegarde des donn�es utilisateur
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


		Button^ b = (Button^)sender;
		char* name = "";

		To_CharStar(b->Text, name);

		WordNet* wd = new WordNet();
		DBWORDLIST* DBWL= new DBWORDLIST(new DBWORD);
		int nb = 0;
		char buffer[33];
	//	System::String^ out = gcnew System::String(name);
		//	MessageBox::Show(b->Text);
		wd->find(DBWL,name,nb); 
		System::String^ out = gcnew System::String(itoa(nb,buffer,10));
			MessageBox::Show(out);
			DBWORD* word;
				word = DBWL->getWord();
		for (int i = 0; i < nb; i++)
		{
			if (word)
			{
				DBWL = DBWL->getNext();
				System::String^ out = gcnew System::String(word->getName()->c_str());
				MessageBox::Show(out);
				word = DBWL->getWord();
			}
		}
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

//this->environment->findWords(tostring(this->dataForm->textWord->Text));
}

