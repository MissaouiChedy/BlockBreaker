#ifndef GESTWINDOW_H
#define GESTWINDOW_H

#include <QtGui>
class MainWindow;
class GestWindow: public QWidget{
	Q_OBJECT

public:
	GestWindow(MainWindow *window);
	~GestWindow();

private slots: 
	

signals:
	

private: 
	QPushButton *valideButton;
	QLineEdit *nameText;
	QComboBox *levelBox;
	QSlider *volumeSlider;

	QLabel *nameLabel;
	QLabel *levelLabel;
	QLabel *volumeLabel;


};

#endif
