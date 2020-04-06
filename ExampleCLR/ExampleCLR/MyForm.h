#pragma once

namespace ExampleCLR {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
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
		}
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	protected:




	private: System::Windows::Forms::GroupBox^  groupBox_action;
	private: System::Windows::Forms::Button^  button_delete;
	private: System::Windows::Forms::Button^  button_edit;
	private: System::Windows::Forms::Button^  button_add;
	private: System::Windows::Forms::Button^  button_download;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  id;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  country;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  city;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  building_name;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  building;


















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
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->groupBox_action = (gcnew System::Windows::Forms::GroupBox());
			this->button_download = (gcnew System::Windows::Forms::Button());
			this->button_delete = (gcnew System::Windows::Forms::Button());
			this->button_edit = (gcnew System::Windows::Forms::Button());
			this->button_add = (gcnew System::Windows::Forms::Button());
			this->id = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->country = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->city = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->building_name = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->building = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->groupBox_action->SuspendLayout();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				this->id, this->country,
					this->city, this->building_name, this->building
			});
			this->dataGridView1->Location = System::Drawing::Point(12, 38);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(557, 381);
			this->dataGridView1->TabIndex = 0;
			// 
			// groupBox_action
			// 
			this->groupBox_action->Controls->Add(this->button_download);
			this->groupBox_action->Controls->Add(this->button_delete);
			this->groupBox_action->Controls->Add(this->button_edit);
			this->groupBox_action->Controls->Add(this->button_add);
			this->groupBox_action->Font = (gcnew System::Drawing::Font(L"Matura MT Script Capitals", 15, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->groupBox_action->Location = System::Drawing::Point(587, 57);
			this->groupBox_action->Name = L"groupBox_action";
			this->groupBox_action->Size = System::Drawing::Size(267, 345);
			this->groupBox_action->TabIndex = 1;
			this->groupBox_action->TabStop = false;
			this->groupBox_action->Text = L"ACTION";
			// 
			// button_download
			// 
			this->button_download->Location = System::Drawing::Point(28, 41);
			this->button_download->Name = L"button_download";
			this->button_download->Size = System::Drawing::Size(200, 50);
			this->button_download->TabIndex = 3;
			this->button_download->Text = L"Download";
			this->button_download->UseVisualStyleBackColor = true;
			this->button_download->Click += gcnew System::EventHandler(this, &MyForm::button_download_Click);
			// 
			// button_delete
			// 
			this->button_delete->Location = System::Drawing::Point(28, 269);
			this->button_delete->Name = L"button_delete";
			this->button_delete->Size = System::Drawing::Size(200, 50);
			this->button_delete->TabIndex = 2;
			this->button_delete->Text = L"Delete";
			this->button_delete->UseVisualStyleBackColor = true;
			this->button_delete->Click += gcnew System::EventHandler(this, &MyForm::button_delete_Click);
			// 
			// button_edit
			// 
			this->button_edit->Location = System::Drawing::Point(28, 193);
			this->button_edit->Name = L"button_edit";
			this->button_edit->Size = System::Drawing::Size(200, 50);
			this->button_edit->TabIndex = 1;
			this->button_edit->Text = L"Edit";
			this->button_edit->UseVisualStyleBackColor = true;
			this->button_edit->Click += gcnew System::EventHandler(this, &MyForm::button_edit_Click);
			// 
			// button_add
			// 
			this->button_add->Location = System::Drawing::Point(28, 117);
			this->button_add->Name = L"button_add";
			this->button_add->Size = System::Drawing::Size(200, 50);
			this->button_add->TabIndex = 0;
			this->button_add->Text = L"Add";
			this->button_add->UseVisualStyleBackColor = true;
			this->button_add->Click += gcnew System::EventHandler(this, &MyForm::button_add_Click);
			// 
			// id
			// 
			this->id->HeaderText = L"ID";
			this->id->MinimumWidth = 10;
			this->id->Name = L"id";
			this->id->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->id->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->id->Width = 50;
			// 
			// country
			// 
			this->country->HeaderText = L"Country";
			this->country->MinimumWidth = 10;
			this->country->Name = L"country";
			this->country->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->country->Width = 115;
			// 
			// city
			// 
			this->city->HeaderText = L"City";
			this->city->MinimumWidth = 10;
			this->city->Name = L"city";
			this->city->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->city->Width = 115;
			// 
			// building_name
			// 
			this->building_name->HeaderText = L"Building Name";
			this->building_name->MinimumWidth = 10;
			this->building_name->Name = L"building_name";
			this->building_name->Width = 115;
			// 
			// building
			// 
			this->building->HeaderText = L"Building";
			this->building->MinimumWidth = 10;
			this->building->Name = L"building";
			this->building->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->building->Width = 115;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(887, 455);
			this->Controls->Add(this->groupBox_action);
			this->Controls->Add(this->dataGridView1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->groupBox_action->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
private: System::Void button_download_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void button_add_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void button_edit_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void button_delete_Click(System::Object^  sender, System::EventArgs^  e);
};
}
