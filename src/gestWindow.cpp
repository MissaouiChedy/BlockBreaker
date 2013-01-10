#include "gestWindow.h"
#include "mainWindow.h"

GestWindow::GestWindow(MainWindow *window){
	this->setParent(window);
	valideButton = new QPushButton("Valider");
	//connect(valideButton, SIGNAL(clicked()), this, SLOT());
	nameLabel = new QLabel("Saisissez Votre Nom: ");
	nameText = new QLineEdit();
	
	levelLabel = new QLabel("Niveau de Difficulté: ");
	levelBox = new QComboBox();

	volumeLabel = new QLabel("Volume: ");
	volumeSlider = new QSlider();
	volumeSlider->setTickInterval(10);
	
	QHBoxLayout *nameLayout = new QHBoxLayout;
	nameLayout->addWidget(nameLabel);
	nameLayout->addWidget(nameText);
	
	QHBoxLayout *levelLayout = new QHBoxLayout;
	levelLayout->addWidget(levelLabel);
	levelLayout->addWidget(levelBox);	

	QHBoxLayout *volumeLayout = new QHBoxLayout;
	volumeLayout->addWidget(volumeLabel);
	volumeLayout->addWidget(volumeSlider);	
	
	QHBoxLayout *valideLayout = new QHBoxLayout;
	valideLayout->addWidget(valideButton);
	
	QVBoxLayout *mainLayout = new QVBoxLayout;
	mainLayout->addLayout(nameLayout);
	mainLayout->addLayout(levelLayout);
	mainLayout->addLayout(volumeLayout);
	mainLayout->addLayout(valideLayout);
	
//	QWidget *mainWidget = new QWidget;
//	mainWidget->setLayout(mainLayout);
	setLayout(mainLayout);
	
}

GestWindow::~GestWindow(){

	delete valideButton;
	delete nameText;
	delete levelBox;
	delete volumeSlider;

}
