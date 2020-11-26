#pragma once

namespace TrabajoFinal {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for ending
	/// </summary>
	public ref class ending : public System::Windows::Forms::Form
	{
	public:
		ending(bool ganaste)
		{
			InitializeComponent();
			if (ganaste) this->pcb_good->Visible = true;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ending()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::PictureBox^ pcb_good;
	protected:

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(ending::typeid));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pcb_good = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pcb_good))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.BackgroundImage")));
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox1->Location = System::Drawing::Point(0, 0);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(842, 518);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// pcb_good
			// 
			this->pcb_good->BackColor = System::Drawing::Color::Transparent;
			this->pcb_good->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pcb_good.BackgroundImage")));
			this->pcb_good->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pcb_good->Location = System::Drawing::Point(0, 0);
			this->pcb_good->Name = L"pcb_good";
			this->pcb_good->Size = System::Drawing::Size(842, 518);
			this->pcb_good->TabIndex = 1;
			this->pcb_good->TabStop = false;
			this->pcb_good->Visible = false;
			// 
			// ending
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(840, 517);
			this->Controls->Add(this->pcb_good);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"ending";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"ending";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pcb_good))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}
