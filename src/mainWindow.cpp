/**********************************************************************
* Cette classe initialise le Menu proncipale du jeu
**********************************************************************/

#include "mainWindow.h"
#include <QtGui>
#include "gameSpace.h" 
MainWindow::MainWindow(){
	
/*
	QLCDNumber *number = new QLCDNumber();	
	number->setFixedSize(800, 245);
	number->setDigitCount(12);
	number->display(QTime::currentTime().toString(QString("hh:mm:ss.zzz")));
*/

    	this->setFocusPolicy(Qt::ClickFocus);
	this->setWindowTitle("Jeu Casse Brique");
    	this->setMinimumSize(QSize(900, 610));

        menu = new Menu(this);
	setCentralWidget(menu);


	QPalette *palette = new QPalette();
	palette->setBrush(QPalette::Background, *(new QBrush(*(new QImage("/home/chaasof/laboratoireDev/labEsprit/Gp3A16/src/block.jpg")))));
	this->setPalette(*palette);
//	palette->setFixedSize(800,245);
//	this->setPalette(palette);
//	setStyleSheet("MainWindow {background-image: url('/home/chaasof/laboratoireDev/labEsprit/Gp3A16/logo.png');}");

	this->setWindowIcon(QIcon("/home/chaasof/laboratoireDev/labEsprit/Gp3A16/src/logo.png"));
}
MainWindow::~MainWindow(){
      delete menu;
      delete gameSpace;
      delete menuWin;
}

void MainWindow::playGameWindow(){
	
	gameSpace = new GameSpace(this);
	connect(gameSpace, SIGNAL(closing()), this , SLOT(close()));
        setCentralWidget(gameSpace);
        gameSpace->show();
	menu->hide();

}

void MainWindow::openMenuWindow(){

	menuWin = new GestWindow(this);
	setCentralWidget(menuWin);
	menu->hide();
        menuWin->show();

}
bool MainWindow::close(){
	emit closing();
        return QWidget::close();

}

void MainWindow::mainMenu(){
        QWidget *currentWidget = this->centralWidget();
        currentWidget->setVisible(false);
        delete currentWidget;
        menu = new Menu(this);
        setCentralWidget(menu);
        menu->setVisible(true); 
} 	
