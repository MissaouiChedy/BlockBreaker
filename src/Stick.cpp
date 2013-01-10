#include "Stick.h"
#include <QBrush>
#include <QKeyEvent>
#include <iostream>

Stick::Stick(const QRectF &rect, QGraphicsItem *parent):QGraphicsRectItem(rect, parent){

 	setFlags(QGraphicsItem::ItemIsFocusable);
 	QBrush brush(Qt::black);
 	setBrush(brush);
        listening = true;
}

void Stick::keyPressEvent(QKeyEvent *event){
   	if (isListening()){
		qreal newX = x();
		qreal newY = y();
		switch (event->key()){
			case Qt::Key_Right :
				newX += 10;
				break;
			case Qt::Key_Left :
				newX -= 10;
				break;
			default : break;
		}
	   
		this->setPos(newX, newY);
		update();
	}
}
bool Stick::isListening(){
   return listening;
}
void Stick::setListening(bool listening){
   this->listening = listening;
}
