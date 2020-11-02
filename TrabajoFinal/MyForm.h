#pragma once
#include "CJuego.hpp"
namespace TrabajoFinal {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MyForm : public System::Windows::Forms::Form
	{
		Graphics^ graficador;
		BufferedGraphics^ buffer;
		CJuego^ juego;
	public:
		MyForm(void)
		{
			InitializeComponent();
			this->graficador = this->CreateGraphics();
			this->buffer = BufferedGraphicsManager::Current->Allocate(this->graficador, this->ClientRectangle);
			this->juego = gcnew CJuego(this->ClientRectangle);
		}

	protected:
		~MyForm()
		{
			delete graficador;
			delete buffer;
			delete juego;
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^ tim_animador;
	protected:
	private: System::ComponentModel::IContainer^ components;

	private:


#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->tim_animador = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// tim_animador
			// 
			this->tim_animador->Enabled = true;
			this->tim_animador->Tick += gcnew System::EventHandler(this, &MyForm::animar);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(980, 555);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::caminar);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void animar(System::Object^ sender, System::EventArgs^ e) {
		this->juego->renderizar(this->buffer->Graphics);
		this->juego->mover_rey(0, 0);
		this->buffer->Render();
	}
	private: System::Void caminar(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		switch (e->KeyCode)
		{
		case Keys::W: this->juego->mover_rey(0, -10); break;
		case Keys::A: this->juego->mover_rey(-10, 0); break;
		case Keys::S: this->juego->mover_rey(0, 10); break;
		case Keys::D: this->juego->mover_rey(10, 0); break;
		}
	}
	};
}
