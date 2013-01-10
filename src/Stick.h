#ifndef _STICK_H
#define _STICK_H

#include <QGraphicsRectItem>

class Stick :public QGraphicsRectItem{
	
	public :
    		void keyPressEvent(QKeyEvent *event);
    		Stick(const QRectF &rect, QGraphicsItem *parent = 0);
                bool isListening();
		void setListening(bool listening);
	private :
	        bool listening;
};

#endif
