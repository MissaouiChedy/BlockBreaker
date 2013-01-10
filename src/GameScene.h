#ifndef _GAMESCENE_H
#define _GAMESCENE_H
#include <QGraphicsScene>
class Ball;
class Stick;
class Block;
class GameScene : public QGraphicsScene{
public : 
  GameScene(const QRectF &sceneRect, QObject *parent = 0);
  ~GameScene();
  void addItem(Ball *item);
  void addItem(Stick *item);
  void addItem(Block *item);
 //void addItem(QGraphicsPixmapItem *item);
  qreal leftLimit() const;
  qreal rightLimit() const;
  qreal topLimit() const;
  qreal bottomLimit() const;
private :
  QPointF origin;
};
#endif
