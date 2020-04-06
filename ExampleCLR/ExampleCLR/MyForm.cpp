#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Data::OleDb;

[STAThread]
int main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	
	ExampleCLR::MyForm form;
	Application::Run(% form);
	
}

System::Void ExampleCLR::MyForm::button_download_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	//connection DB
	String^ connectionString = "provider=Microsoft.Jet.OLEDB.4.0;Data Source=database11.mdb"; 	//connection
	OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

	//query DB
	dbConnection->Open();
	String^ query = "SELECT * FROM [table_name]";

	// Task One
	//String^ query = "SELECT * FROM [table_name] WHERE country='Poland'";   //  "SELECT building_name FROM [table_name] WHERE country='Poland'";
																			 
	// Extra task															 
	//String^ query = "SELECT * FROM [table_name] WHERE Building="+0;        // "SELECT Country FROM [table_name] WHERE Building="+0;

	//select all where building > 100 Task 2
	//String^ query = "SELECT * FROM [table_name] WHERE building>=100";

	OleDbCommand^ dbComand = gcnew OleDbCommand(query, dbConnection);
	OleDbDataReader^ dbReader = dbComand->ExecuteReader();

	//checking data
	if (dbReader->HasRows == false) {
		MessageBox::Show("Error reading data!");
	}
	else {
		while (dbReader->Read())
		{
			dataGridView1->Rows->Add(dbReader["ID"], dbReader["Country"], dbReader["City"], dbReader["Building Name"], dbReader["Building"]);
		}
	}

	//close the connection
	dbReader->Close();
	dbConnection->Close();

	return System::Void();
}

System::Void ExampleCLR::MyForm::button_add_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	//select the desired line to add
	if (dataGridView1->SelectedRows->Count != 1) {
		MessageBox::Show("Select one row to add", "Attention");
		return;
	}

	//index of the selected row
	int index = dataGridView1->SelectedRows[0]->Index;

	//checking data
	if (dataGridView1->Rows[index]->Cells[0]->Value == nullptr ||
		dataGridView1->Rows[index]->Cells[1]->Value == nullptr ||
		dataGridView1->Rows[index]->Cells[2]->Value == nullptr ||
		dataGridView1->Rows[index]->Cells[3]->Value == nullptr ||
		dataGridView1->Rows[index]->Cells[4]->Value == nullptr) {
		MessageBox::Show("Not all data added", "Attention");
		return;
	}

	//read data
	String^ id = dataGridView1->Rows[index]->Cells[0]->Value->ToString();
	String^ country = dataGridView1->Rows[index]->Cells[1]->Value->ToString();
	String^ city = dataGridView1->Rows[index]->Cells[2]->Value->ToString();
	String^ building_name = dataGridView1->Rows[index]->Cells[3]->Value->ToString();
	String^ building = dataGridView1->Rows[index]->Cells[4]->Value->ToString();

	//connection DB
	String^ connectionString = "provider=Microsoft.Jet.OLEDB.4.0;Data Source=database11.mdb"; 	//connection
	OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

	//query DB
	dbConnection->Open();
	String^ query = "INSERT INTO [table_name] VALUES ("+id+", '"+country+"', '"+city+"', '"+building_name+"', "+building+")";
	OleDbCommand^ dbComand = gcnew OleDbCommand(query, dbConnection);

	//request in progress
	if (dbComand->ExecuteNonQuery() != 1)
		MessageBox::Show("Request Execution Error!");
	else
		MessageBox::Show("Data added");

	//close the connection
	dbConnection->Close();

	return System::Void();
}

System::Void ExampleCLR::MyForm::button_edit_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	//select the desired line to add
	if (dataGridView1->SelectedRows->Count != 1) {
		MessageBox::Show("Select one row to add", "Attention");
		return;
	}

	//index of the selected row
	int index = dataGridView1->SelectedRows[0]->Index;

	//checking data
	if (dataGridView1->Rows[index]->Cells[0]->Value == nullptr ||
		dataGridView1->Rows[index]->Cells[1]->Value == nullptr ||
		dataGridView1->Rows[index]->Cells[2]->Value == nullptr ||
		dataGridView1->Rows[index]->Cells[3]->Value == nullptr ||
		dataGridView1->Rows[index]->Cells[4]->Value == nullptr) {
		MessageBox::Show("Not all data added", "Attention");
		return;
	}

	//read data
	String^ id = dataGridView1->Rows[index]->Cells[0]->Value->ToString();
	String^ country = dataGridView1->Rows[index]->Cells[1]->Value->ToString();
	String^ city = dataGridView1->Rows[index]->Cells[2]->Value->ToString();
	String^ building_name = dataGridView1->Rows[index]->Cells[3]->Value->ToString();
	String^ building = dataGridView1->Rows[index]->Cells[3]->Value->ToString();

	//connection DB
	String^ connectionString = "provider=Microsoft.Jet.OLEDB.4.0;Data Source=database.mdb"; 	//connection
	OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

	//query DB
	dbConnection->Open();
	String^ query = "UPDATE [table_name] SET Country='" + country + "', City='" + city + "', Building-Name='"+building_name+"', Building=" + building +" WHERE id=" + id;
	OleDbCommand^ dbComand = gcnew OleDbCommand(query, dbConnection);

	//request in progress
	if (dbComand->ExecuteNonQuery() != 1)
		MessageBox::Show("Request Execution Error!");
	else
		MessageBox::Show("Data changed");

	//close the connection
	dbConnection->Close();

	return System::Void();
}

System::Void ExampleCLR::MyForm::button_delete_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	//select the desired line to add
	if (dataGridView1->SelectedRows->Count != 1) {
		MessageBox::Show("Select one row to add", "Attention");
		return;
	}

	//index of the selected row
	int index = dataGridView1->SelectedRows[0]->Index;

	//checking data
	if (dataGridView1->Rows[index]->Cells[0]->Value == nullptr) {
		MessageBox::Show("Not all data added", "Attention");
		return;
	}

	//read data
	String^ id = dataGridView1->Rows[index]->Cells[0]->Value->ToString();

	//connection DB
	String^ connectionString = "provider=Microsoft.Jet.OLEDB.4.0;Data Source=database.mdb"; 	//connection
	OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

	//query DB
	dbConnection->Open();
	String^ query = "DELETE FROM [table_name] WHERE id=" + id;
	OleDbCommand^ dbComand = gcnew OleDbCommand(query, dbConnection);

	//request in progress
	if (dbComand->ExecuteNonQuery() != 1)
		MessageBox::Show("Request Execution Error!");
	else {
		MessageBox::Show("Data deleted");
		dataGridView1->Rows->RemoveAt(index);  //delete line from form
	}

	//close the connection
	dbConnection->Close();

	return System::Void();
}