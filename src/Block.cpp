#include "Block.h"
#include <QBrush>
#include <QList>

Block::Block(const QRectF &rect, QGraphicsItem *parent):QGraphicsRectItem(rect, parent){

 	QBrush brush(Qt::black);
 	setBrush(brush);
}

Block::Block(const Block &block){
	Q_UNUSED(block);
}

QList<Block*>* Block::buildBlockGroup(int width, int height){

  	int marginX = 20;
  	int marginY = 10;
  	int numberBlocksX = 10;
  	int numberLinesY = 3;
  	float blockWidth = (width / numberBlocksX) - marginX;
  	float blockHeight = (height / numberLinesY) - marginY;
  	QList<Block*> *list = new QList<Block*>;
  	int i = 0; int y = 0;
  	int j = 0; int x = 0;
  
	for (y = 0, i = 0; i < numberLinesY ; y += (blockHeight + marginY), ++i){
    		for (x = 0, j = 0; j < numberBlocksX ; ++j, x += (blockWidth + marginX)){
			Block *block = new Block( QRectF(x, y, blockWidth, blockHeight) );
			list->append(block);
    		}
  	}
  	return list;
}
