#pragma once
namespace TrabajoFinal {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class menu : public System::Windows::Forms::Form
	{
		short* vidas;
		short* tiempo;
		short* n;
		bool* jugar;
	private: System::Windows::Forms::Button^ btn_jugar;
	private: System::Windows::Forms::NumericUpDown^ nud_aliados;
	private: System::Windows::Forms::NumericUpDown^ nud_vidas;
	private: System::Windows::Forms::NumericUpDown^ nud_tiempo;
	private: System::Windows::Forms::Label^ lbl_vidas;
	private: System::Windows::Forms::Label^ lbl_aliados;
	private: System::Windows::Forms::Label^ lbl_tiempo;

	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ btn_creditos;
	private: System::Windows::Forms::Button^ btn_salir;
	private: System::Windows::Forms::Button^ btn_historia;



	public:
		menu(short* vidas, short* tiempo, short* n, bool* jugar)
		{
			InitializeComponent();
			this->vidas = vidas;
			*vidas = 3;
			this->tiempo = tiempo;
			*tiempo = 30;
			this->n = n;
			*n = 10;
			this->jugar = jugar;
		}

	protected:
		~menu()
		{
			*vidas = Int16::Parse(this->nud_vidas->Text);
			*tiempo = Int16::Parse(this->nud_tiempo->Text);
			*n = Int16::Parse(this->nud_aliados->Text);
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pcb_comojugar;
	protected:

	protected:

	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(menu::typeid));
			this->pcb_comojugar = (gcnew System::Windows::Forms::PictureBox());
			this->btn_jugar = (gcnew System::Windows::Forms::Button());
			this->nud_aliados = (gcnew System::Windows::Forms::NumericUpDown());
			this->nud_vidas = (gcnew System::Windows::Forms::NumericUpDown());
			this->nud_tiempo = (gcnew System::Windows::Forms::NumericUpDown());
			this->lbl_vidas = (gcnew System::Windows::Forms::Label());
			this->lbl_aliados = (gcnew System::Windows::Forms::Label());
			this->lbl_tiempo = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->btn_creditos = (gcnew System::Windows::Forms::Button());
			this->btn_salir = (gcnew System::Windows::Forms::Button());
			this->btn_historia = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pcb_comojugar))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nud_aliados))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nud_vidas))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nud_tiempo))->BeginInit();
			this->SuspendLayout();
			// 
			// pcb_comojugar
			// 
			this->pcb_comojugar->BackColor = System::Drawing::Color::Transparent;
			this->pcb_comojugar->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pcb_comojugar.BackgroundImage")));
			this->pcb_comojugar->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pcb_comojugar->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pcb_comojugar->Location = System::Drawing::Point(0, -1);
			this->pcb_comojugar->Name = L"pcb_comojugar";
			this->pcb_comojugar->Size = System::Drawing::Size(1601, 966);
			this->pcb_comojugar->TabIndex = 0;
			this->pcb_comojugar->TabStop = false;
			// 
			// btn_jugar
			// 
			this->btn_jugar->BackColor = System::Drawing::Color::Transparent;
			this->btn_jugar->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn_jugar.BackgroundImage")));
			this->btn_jugar->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btn_jugar->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_jugar->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_jugar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 22));
			this->btn_jugar->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->btn_jugar->Location = System::Drawing::Point(648, 645);
			this->btn_jugar->Name = L"btn_jugar";
			this->btn_jugar->Size = System::Drawing::Size(326, 134);
			this->btn_jugar->TabIndex = 1;
			this->btn_jugar->Text = L"Jugar";
			this->btn_jugar->TextImageRelation = System::Windows::Forms::TextImageRelation::TextAboveImage;
			this->btn_jugar->UseVisualStyleBackColor = true;
			this->btn_jugar->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &menu::entrar);
			// 
			// nud_aliados
			// 
			this->nud_aliados->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16));
			this->nud_aliados->Location = System::Drawing::Point(853, 455);
			this->nud_aliados->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 20, 0, 0, 0 });
			this->nud_aliados->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->nud_aliados->Name = L"nud_aliados";
			this->nud_aliados->Size = System::Drawing::Size(79, 32);
			this->nud_aliados->TabIndex = 3;
			this->nud_aliados->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			// 
			// nud_vidas
			// 
			this->nud_vidas->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16));
			this->nud_vidas->Location = System::Drawing::Point(853, 392);
			this->nud_vidas->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->nud_vidas->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 3, 0, 0, 0 });
			this->nud_vidas->Name = L"nud_vidas";
			this->nud_vidas->Size = System::Drawing::Size(79, 32);
			this->nud_vidas->TabIndex = 4;
			this->nud_vidas->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
			// 
			// nud_tiempo
			// 
			this->nud_tiempo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16));
			this->nud_tiempo->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->nud_tiempo->Location = System::Drawing::Point(853, 519);
			this->nud_tiempo->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 360, 0, 0, 0 });
			this->nud_tiempo->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 30, 0, 0, 0 });
			this->nud_tiempo->Name = L"nud_tiempo";
			this->nud_tiempo->Size = System::Drawing::Size(79, 32);
			this->nud_tiempo->TabIndex = 5;
			this->nud_tiempo->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 60, 0, 0, 0 });
			// 
			// lbl_vidas
			// 
			this->lbl_vidas->AutoSize = true;
			this->lbl_vidas->BackColor = System::Drawing::Color::Transparent;
			this->lbl_vidas->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16));
			this->lbl_vidas->Location = System::Drawing::Point(692, 394);
			this->lbl_vidas->Name = L"lbl_vidas";
			this->lbl_vidas->Size = System::Drawing::Size(67, 26);
			this->lbl_vidas->TabIndex = 6;
			this->lbl_vidas->Text = L"Vidas";
			// 
			// lbl_aliados
			// 
			this->lbl_aliados->AutoSize = true;
			this->lbl_aliados->BackColor = System::Drawing::Color::Transparent;
			this->lbl_aliados->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16));
			this->lbl_aliados->Location = System::Drawing::Point(692, 457);
			this->lbl_aliados->Name = L"lbl_aliados";
			this->lbl_aliados->Size = System::Drawing::Size(121, 26);
			this->lbl_aliados->TabIndex = 7;
			this->lbl_aliados->Text = L"No. aliados";
			// 
			// lbl_tiempo
			// 
			this->lbl_tiempo->AutoSize = true;
			this->lbl_tiempo->BackColor = System::Drawing::Color::Transparent;
			this->lbl_tiempo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16));
			this->lbl_tiempo->Location = System::Drawing::Point(692, 519);
			this->lbl_tiempo->Name = L"lbl_tiempo";
			this->lbl_tiempo->Size = System::Drawing::Size(84, 26);
			this->lbl_tiempo->TabIndex = 8;
			this->lbl_tiempo->Text = L"Tiempo";
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Transparent;
			this->button1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.BackgroundImage")));
			this->button1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 22));
			this->button1->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->button1->Location = System::Drawing::Point(34, 805);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(326, 134);
			this->button1->TabIndex = 9;
			this->button1->Text = L"Como Jugar";
			this->button1->TextImageRelation = System::Windows::Forms::TextImageRelation::TextAboveImage;
			this->button1->UseVisualStyleBackColor = true;
			this->button1->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &menu::comojugar);
			// 
			// btn_creditos
			// 
			this->btn_creditos->BackColor = System::Drawing::Color::Transparent;
			this->btn_creditos->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn_creditos.BackgroundImage")));
			this->btn_creditos->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btn_creditos->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_creditos->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_creditos->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 22));
			this->btn_creditos->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->btn_creditos->Location = System::Drawing::Point(34, 645);
			this->btn_creditos->Name = L"btn_creditos";
			this->btn_creditos->Size = System::Drawing::Size(326, 134);
			this->btn_creditos->TabIndex = 10;
			this->btn_creditos->Text = L"Creditos";
			this->btn_creditos->TextImageRelation = System::Windows::Forms::TextImageRelation::TextAboveImage;
			this->btn_creditos->UseVisualStyleBackColor = true;
			this->btn_creditos->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &menu::creditos);
			// 
			// btn_salir
			// 
			this->btn_salir->BackColor = System::Drawing::Color::Transparent;
			this->btn_salir->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn_salir.BackgroundImage")));
			this->btn_salir->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btn_salir->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_salir->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_salir->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 22));
			this->btn_salir->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->btn_salir->Location = System::Drawing::Point(1262, 39);
			this->btn_salir->Name = L"btn_salir";
			this->btn_salir->Size = System::Drawing::Size(326, 134);
			this->btn_salir->TabIndex = 11;
			this->btn_salir->Text = L"Salir";
			this->btn_salir->TextImageRelation = System::Windows::Forms::TextImageRelation::TextAboveImage;
			this->btn_salir->UseVisualStyleBackColor = true;
			this->btn_salir->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &menu::salir);
			// 
			// btn_historia
			// 
			this->btn_historia->BackColor = System::Drawing::Color::Transparent;
			this->btn_historia->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn_historia.BackgroundImage")));
			this->btn_historia->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btn_historia->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_historia->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_historia->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 22));
			this->btn_historia->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->btn_historia->Location = System::Drawing::Point(648, 805);
			this->btn_historia->Name = L"btn_historia";
			this->btn_historia->Size = System::Drawing::Size(326, 134);
			this->btn_historia->TabIndex = 12;
			this->btn_historia->Text = L"Historia";
			this->btn_historia->TextImageRelation = System::Windows::Forms::TextImageRelation::TextAboveImage;
			this->btn_historia->UseVisualStyleBackColor = true;
			this->btn_historia->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &menu::historia);
			// 
			// menu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1600, 960);
			this->Controls->Add(this->btn_historia);
			this->Controls->Add(this->btn_salir);
			this->Controls->Add(this->btn_creditos);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->lbl_tiempo);
			this->Controls->Add(this->lbl_aliados);
			this->Controls->Add(this->lbl_vidas);
			this->Controls->Add(this->nud_tiempo);
			this->Controls->Add(this->nud_vidas);
			this->Controls->Add(this->nud_aliados);
			this->Controls->Add(this->btn_jugar);
			this->Controls->Add(this->pcb_comojugar);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"menu";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"menu";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pcb_comojugar))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nud_aliados))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nud_vidas))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nud_tiempo))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void salir(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	Close();
}
private: System::Void entrar(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	*jugar = true;
	Close();
}
private: System::Void btn_historia_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {

}
private: System::Void historia(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	
	MessageBox::Show("Richard Wick, el rey de su mundo, era amado por todos sus súbditos debido a que era muy carismático y bondadoso. Sin embargo, algunos asesores corruptos, con intención de chantajearlo para dejar el trono, secuestraron a su perro Benji y lo encerraron en la mansión Zion, la representación cultural de riqueza de su mundo. Además, los corruptos amenazaron con contratar a una mafia de sicarios si el rey no deja su puesto. En vez de atemorizarlo, ellos llenaron de ira al monarca, que, con ayuda de sus aliados infiltrados en el lugar, y ,pese a las amenazas, piensa rescatar a su mejor amigo, aunque le cueste la vida.");
}
private: System::Void creditos(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	MessageBox::Show("Este juego ha sido creado por: Leonardo Goyas, Tyrone Sotil, Mauricio Tuesta, Diego Villafuerte");
}
private: System::Void comojugar(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	MessageBox::Show("Te mueves con las teclas WASD, camina hacia tus aliados para que te sigan. Si un corrupto toca un aliado tuyo lo convertira en otro corrupto. Si se acaba tu tiempo, los corruptos traeran a los asesinos para matarte mas rapido. Para ganar, rescata a Benji, tu perro, y espera un minuto para que te rescaten. Para ayudarte apareceran portales cuando estes en peligro");
}
};
}
