#pragma once
#include "D3DObject.h"
namespace Direct3DEngine {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	void bla(Object ^ form);
	/// <summary>
	/// —водка дл€ Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			GameIsGoing = true;
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	protected: 

	private:
		bool GameIsGoing;
	private: System::Windows::Forms::Label^  textBox1;

			 /// <summary>
		/// “ребуетс€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ќб€зательный метод дл€ поддержки конструктора - не измен€йте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(231, 97);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(53, 27);
			this->button1->TabIndex = 0;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->AutoSize = true;
			this->textBox1->Location = System::Drawing::Point(526, 4);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(0, 13);
			this->textBox1->TabIndex = 1;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(784, 401);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->KeyPreview = true;
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Form1::Form1_FormClosing);
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->Resize += gcnew System::EventHandler(this, &Form1::Form1_Resize);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) 
			 {
				 
			 }
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 Application::DoEvents();
				if( g_D3D.SetHistance((HWND) (void *)this->Handle) == false)  return;
				 if(g_D3D.InitD3D() == false) return;
			
				 while(GameIsGoing == true) // main game loop
				 {
					 
					 g_D3D.ProcessKeyPressed(); // main function, where we actually check keys pressed and make our game to respond to those changes, like jumping and moving
					 g_D3D.RenewSurface = true;
					
					 g_D3D.Render();
					 
					Application::DoEvents(); // щоб в≥кно не зависало :)
					Threading::Thread::Sleep(10);
				 }
			 }
	
	private: System::Void Form1_Resize(System::Object^  sender, System::EventArgs^  e) 
			 {
				 g_D3D.RenewSurface = true;
				 g_D3D.Render();
			 }



	private: System::Void Form1_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
				 GameIsGoing = false;
				 g_D3D.CleanupD3D();
			 }

};
}

