#ifndef _MENU_H
#define _MENU_H
#include <QtGui>
#include <QWidget>
class MainWindow;
class Menu : public QWidget{
Q_OBJECT

public : 
        Menu(MainWindow *window);
        ~Menu();
private :
	QPushButton *playButton;
	QPushButton *menuButton;
	QPushButton *closeButton;
};
#endif
