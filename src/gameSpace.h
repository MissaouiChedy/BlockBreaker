#ifndef GAMESPACE_H
#define GAMESPACE_H

#include "GameView.h"
#include "mainWindow.h"

class GameSpace: public QWidget{
	Q_OBJECT

public:
	GameSpace(MainWindow *window);
	~GameSpace();
private slots:
	void returnMainWindow();
	QLabel *createLabel(const QString &text);
        bool close();
signals:
	void endGame();
        void closing();
private: 
	QPushButton *returnButton;
	QPushButton *pauseButton;
	QPushButton *closeButton;
	GameView *view;
	QLCDNumber *scoreLcd;
	

};
#endif
