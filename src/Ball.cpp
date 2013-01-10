#include "Ball.h"
#include <QBrush>
#include <iostream>
Ball::Ball(QPointF beginPoint, qreal segment, QPointF endPoint, int duration, QGraphicsItem *parent)
:QGraphicsEllipseItem(QRectF(beginPoint.x(), beginPoint.y(), segment, segment), parent)
{
 	QBrush brush(Qt::black);
 	setBrush(brush);
	animation = new QPropertyAnimation(this, "pos");
        animation->setStartValue(pos());
        animation->setEndValue(endPoint);
	setDuration(duration);
        animation->setLoopCount(-1);
} 

void Ball::setTrajectory(QPointF start, QPointF end)
{
	QLineF trajectory(start, end);
	animation->stop();
	animation->setStartValue(start);
      	animation->setEndValue(end);
      	animation->setDuration(getDuration());
      	animation->start();
}
void Ball::setDuration(qreal duration)
{
   QLineF line(movementStartPoint(), movementEndPoint());
   speed = duration / line.length(); 
   animation->setDuration(duration);
}
int Ball::getDuration()
{
   QLineF line(movementStartPoint(), movementEndPoint());
   return static_cast<int>(speed * line.length());
}
void Ball::startMovement()
{
   animation->start();
}
void Ball::stopMovement()
{
   animation->stop();
}
void Ball::pauseMovement()
{
  animation->pause();
}
void Ball::resumeMovement()
{
  animation->resume();
}
QPointF Ball::movementStartPoint() const 
{
   return (animation->startValue()).toPointF();
}
QPointF Ball::movementEndPoint() const
{
   return (animation->endValue()).toPointF(); 
}
Ball::~Ball(){
   delete animation;
}

qreal Ball::size() const {
 QRectF ballRect = this->rect();
 return ballRect.width();
}

bool Ball::isMoving() const {
 bool moving = false;
 if (animation->state() == QAbstractAnimation::Running){
    moving = true;
 }
 return moving;
}
