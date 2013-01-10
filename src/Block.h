#ifndef _BLOCK_H
#define _BLOCK_H

#include <QGraphicsRectItem>

class Block : public QGraphicsRectItem{
  	
	public : 
  		Block(const QRectF &rect, QGraphicsItem *parent = 0);
  		Block(const Block &block);
  		static QList<Block*>* buildBlockGroup(int width, int height);

};

#endif
