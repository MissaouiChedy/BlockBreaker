#ifndef _BALL_H
#define _BALL_H

#include <QObject>
#include <QGraphicsEllipseItem>
#include <QPropertyAnimation>
class Ball : public QObject, public QGraphicsEllipseItem{
 	
	Q_OBJECT
 	Q_PROPERTY(QPointF pos READ pos WRITE setPos)
 
 	public : 
 		Ball(QPointF beginPoint, qreal segment, QPointF endPoint, int duration, QGraphicsItem *parent = 0);
                void setTrajectory(QPointF start, QPointF end);
 		void setDuration(qreal duration);
		void startMovement();
		void stopMovement();
		void pauseMovement();
		void resumeMovement();
		QPointF movementStartPoint() const;
		QPointF movementEndPoint() const;
		qreal size() const;
		bool isMoving() const;
		~Ball();
        private :
	int getDuration();
	QPropertyAnimation *animation;
        qreal speed;

};

#endif
