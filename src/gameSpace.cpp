#include "gameSpace.h"
#include <QtGui>

GameSpace::GameSpace(MainWindow *window){
        this->setParent(window);	
 	view = new GameView;
        connect(view, SIGNAL(endGame()), this, SLOT(returnMainWindow()));
	scoreLcd = new QLCDNumber(5);
	scoreLcd->setSegmentStyle(QLCDNumber::Filled);
	connect(view, SIGNAL(scoreChanger(int)), scoreLcd, SLOT(display(int)));
     
	returnButton = new QPushButton("Retour");
	connect(returnButton, SIGNAL(clicked()), this, SIGNAL(endGame()));
	
	pauseButton = new QPushButton("Pause");
	connect(pauseButton, SIGNAL(clicked()), view, SLOT(pause()));

	closeButton = new QPushButton("Fermer");
	connect(closeButton, SIGNAL(clicked()), this , SLOT(close()));
	
	QGridLayout *layout = new QGridLayout;
	layout->addWidget(createLabel(tr("SCORE")),0,2);
	layout->addWidget(scoreLcd,1,2);
	layout->addWidget(view, 0,1,4,1);
	layout->addWidget(pauseButton,2,2);
	layout->addWidget(returnButton,3,2);
	layout->addWidget(closeButton,4,2);
	setLayout(layout);

	setWindowTitle(tr("Casse Brique"));
        connect(this, SIGNAL(endGame()), parent(), SLOT(mainMenu()));
/*


	QFormLayout *formLayout = new QFormLayout;
	formLayout->addRow(returnButton, closeButton);

	QHBoxLayout * mainLayout = new QHBoxLayout;
	mainLayout->addLayout(formLayout);

	GameView *game = new GameView();
	QWidget *mainWidget = new QWidget;
	QFormLayout *gameLayout = new QFormLayout;
	gameLayout->addRow(game);
	mainWidget->setLayout(gameLayout);
	QCentralWidget *centre = new QCentralWidget
	centre->setCentralWidget(mainWidget);

	QDockWidget *dockWidget = new QDockWidget(tr("Dock Widget"), this);

     	dockWidget->setAllowedAreas(Qt::BottomDockWidgetArea);
     	dockWidget->setLayout(mainLayout);
     	addDockWidget(Qt::BottomDockWidgetArea, dockWidget);
*/
}

GameSpace::~GameSpace(){
	delete closeButton;
	delete pauseButton;
	delete returnButton;
        delete scoreLcd;
	delete view;
}

void GameSpace::returnMainWindow(){
  /*      delete view;	
	MainWindow *mainWin = new MainWindow();
	mainWin->setFocusPolicy(Qt::ClickFocus);
	mainWin->setMinimumSize(QSize(800, 600));
	mainWin->show();
	QWidget::close();*/
	
}

QLabel *GameSpace::createLabel(const QString &text){

	QLabel *lbl = new QLabel(text);
	lbl->setAlignment(Qt::AlignHCenter | Qt::AlignBottom);
	return lbl;

}

bool GameSpace::close(){
	
	emit closing();
	return QWidget::close();


}
