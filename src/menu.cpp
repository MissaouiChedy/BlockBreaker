#include "menu.h"
#include "mainWindow.h"
Menu::Menu(MainWindow *window){
	this->setParent(window);
        playButton = new QPushButton("Jouer");
	connect(playButton, SIGNAL(clicked()), this->parent(), SLOT(playGameWindow()));

	menuButton = new QPushButton("Menu");
	connect(menuButton, SIGNAL(clicked()), this->parent(), SLOT(openMenuWindow()));

	closeButton = new QPushButton("Quitter");
	connect(closeButton, SIGNAL(clicked()), this->parent(), SLOT(close()));

	QFormLayout *formLayout = new QFormLayout;
	formLayout->addRow(playButton);
	formLayout->addRow(menuButton);
	formLayout->addRow(closeButton);

	QVBoxLayout *mainLayout = new QVBoxLayout;
	mainLayout->addLayout(formLayout);

	this->setLayout(mainLayout);


/*
	QPalette *palette = new QPalette();
	palette->setBrush(QPalette::Background, *(new QBrush(*(new QImage("/home/chaasof/laboratoireDev/labEsprit/Gp3A16/src/block.jpg")))));
	this->setPalette(*palette);*/
//	palette->setFixedSize(800,245);
//	this->setPalette(palette);
//	setStyleSheet("MainWindow {background-image: url('/home/chaasof/laboratoireDev/labEsprit/Gp3A16/logo.png');}");

	//ithis->setWindowIcon(QIcon("/home/chaasof/laboratoireDev/labEsprit/Gp3A16/src/logo.png"));

}
Menu::~Menu(){
  delete playButton;
  delete menuButton;
  delete closeButton;
}
