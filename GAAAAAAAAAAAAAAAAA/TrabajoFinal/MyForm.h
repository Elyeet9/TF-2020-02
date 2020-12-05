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
		bool* ganaste;
	public:
		MyForm(short tiempo, short n, short vidas, bool* ganaste)
		{
			InitializeComponent();
			this->ganaste = ganaste;
			this->Size = System::Drawing::Size(CAS_ANCHO * (ANCHO + 1), CAS_ANCHO * (ALTO + 1));
			this->graficador = this->CreateGraphics();
			this->buffer = BufferedGraphicsManager::Current->Allocate(this->graficador, this->ClientRectangle);
			this->juego = gcnew CJuego(this->ClientRectangle, n, 5, vidas, tiempo);
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
			this->Enabled = false;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::caminar);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::parar);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void animar(System::Object^ sender, System::EventArgs^ e) {
		if (this->juego->jugar(this->buffer->Graphics, this->ClientRectangle.Width, this->ClientRectangle.Height, ganaste)) {
			Close();
		}
		else this->buffer->Render();
	}
	private: System::Void caminar(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		this->juego->mover_rey(true, e->KeyCode);
	}
	private: System::Void parar(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		this->juego->mover_rey(false, e->KeyCode);
	}
	};
}
