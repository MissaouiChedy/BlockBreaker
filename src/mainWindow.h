#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui>
#include "gestWindow.h"
#include "menu.h"
class GameSpace;
class MainWindow: public QMainWindow {
	Q_OBJECT
public:
	MainWindow();
	~MainWindow();

public slots:
	void playGameWindow();
	void openMenuWindow();
	bool close();
        void mainMenu(); 	

signals:
	void closing();
private:
	Menu *menu;
	GameSpace *gameSpace;
	GestWindow *menuWin;
        QLabel *labelImage;
	QImage image;
};

#endif
