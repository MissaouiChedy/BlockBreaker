#include <cassert>
#include "GameScene.h"
#include <QList>
#include <QGraphicsView>
#include <iostream>
#include "Ball.h"
#include "Block.h"
#include "Stick.h"
#define printP(p) std::cout << #p".x : " << p.x() << " "#p".y() :  " << p.y() << std::endl;
GameScene::GameScene(const QRectF &sceneRect, QObject *parent)
:QGraphicsScene(sceneRect, parent)
{
   origin = QPointF(0, 0);
 //   QImage image("/home/chaasof/laboratoireDev/labEsprit/Gp3A16/src/block.jpg");
   // QGraphicsPixmapItem item( QPixmap::fromImage(image));
}
GameScene:: ~GameScene(){}
void GameScene::addItem(Ball *item)
{
 QGraphicsScene::addItem(item); 
 origin = QPointF(item->rect().x(), item->rect().y());
}
void GameScene::addItem(Stick *item)
{
 QGraphicsScene::addItem(item); 
 origin = QPointF(item->rect().x(), item->rect().y());
}
void GameScene::addItem(Block *item)
{
 QGraphicsScene::addItem(item); 
 origin = QPointF(item->rect().x(), item->rect().y());
}
/*void GameScene::addItem(QGraphicsPixmapItem *item)
{
    QGraphicsScene::addItem(&item);
}*/

qreal GameScene::leftLimit() const
{
   return -origin.x();
}
qreal GameScene::rightLimit() const
{
   return width() - origin.x() ;
}
qreal GameScene::topLimit() const
{
  return -origin.y();
}
qreal GameScene::bottomLimit() const
{
  return height() - origin.y();
}
