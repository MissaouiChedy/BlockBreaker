#include "GameView.h"
#include <iostream>
#include <cassert>
#include <QSound>
#include <QtGui>
#define printPoint(p) std::cout << #p".x : " << p.x() << " "#p".y() :  " << p.y() << std::endl;
GameView::GameView(QWidget *parent)
:QGraphicsView(parent)
{
	score = 0;
        lockBlock = false;
        lockLateral = false;
        lockStick = false;
	scene = new GameScene(QRectF(0, 0, 790, 590));
	this->setScene(scene);

	ball = new Ball(QPointF(500,500), 20, QPointF(200, -500), 3000);
	stick = new Stick(QRectF(50, 550, 100, 20));
   	list = Block::buildBlockGroup(800,100);
    	this->setMinimumSize(QSize(800,600));
    //	this->setFocusPolicy(Qt::ClickFocus);
    	for (QList<Block*>::iterator it = list->begin(); it != list->end(); ++it)
	{
      		scene->addItem(*it); 
    	}
	scene->addItem(stick);
    	scene->addItem(ball);
	this->setFocus();
    	scene->setFocus();
    	//scene->setFocusItem(stick);
	GameView::connect(scene, SIGNAL(changed(const QList<QRectF> &)), this, SLOT(handleInteractions(const QList<QRectF> &)));
	ball->startMovement();
	QImage img("/home/chaasof/laboratoireDev/labEsprit/Gp3A16/src/mur.jpg"); 
	scene->setBackgroundBrush(QBrush(img));
	myMusic.OpenFromFile("/home/chaasof/laboratoireDev/labEsprit/Gp3A16/src/Acrostics.ogg");
	myMusic.Play();
	
	
	myBlockBuffer.LoadFromFile("/home/chaasof/laboratoireDev/labEsprit/Gp3A16/src/effet/Laser.wav");
	mySoundBlock.SetBuffer(myBlockBuffer);
	myStickBuffer.LoadFromFile("/home/chaasof/laboratoireDev/labEsprit/Gp3A16/src/effet/up.wav");
	mySoundStick.SetBuffer(myStickBuffer);
	myLateralBuffer.LoadFromFile("/home/chaasof/laboratoireDev/labEsprit/Gp3A16/src/effet/Jump.wav");
	mySoundLateral.SetBuffer(myLateralBuffer);
        update(); 

/*	QPalette *palette = new QPalette();
	palette->setBrush(QPalette::Background, *(new QBrush(*(new QImage("/home/chaasof/laboratoireDev/labEsprit/Gp3A16/src/block.jpg")))));
	this->setPalette(*palette);*/
}

GameView::~GameView()
{
    	delete list;
    	delete stick;
    	delete ball;
    	delete scene;
}


void GameView::handleInteractions(const QList<QRectF> &region){
	Q_UNUSED(region);
	QPointF animationStartPos = ball->movementStartPoint();
	if (ball->collidesWithItem(stick) && !lockStick){
		QPointF targetPoint =  affineFunction(ball->pos(), 
		horizontalSymetricPoint(ball->pos(), animationStartPos), 
		horizontalMouvementLimit(ball->pos(), animationStartPos));
		
		ball->setTrajectory(ball->pos(), targetPoint);
		lockStickCollision();
		mySoundStick.Play();
	}
  	else if ( ( (ball->pos().y() <= scene->topLimit())|| ballCollidesWithBlock()) && !lockBlock){
		QList<QGraphicsItem *> cList = scene->collidingItems(ball);
		if (cList.size() == 1){
		   ++score;
		   emit scoreChanger(score);
		   list->removeOne(dynamic_cast<Block*>(cList[0]));
		   delete cList[0];
		}
		QPointF targetPoint =  affineFunction(ball->pos(), 
		horizontalSymetricPoint(ball->pos(), animationStartPos), 
		horizontalMouvementLimit(ball->pos(), animationStartPos));
		
		ball->setTrajectory(ball->pos(), targetPoint);
		lockBlockCollsion();
     
  	}
  	else if (ballCollidesWithLaterals() && !lockLateral){
      	        QPointF targetPoint =  affineFunction(ball->pos(), 
		verticalSymetricPoint(ball->pos(), animationStartPos), 
		verticalMouvementLimit(ball->pos(), animationStartPos));
		
		ball->setTrajectory(ball->pos(), targetPoint);
		lockLateralCollision();	
  	}
	else if (ball->pos().y() > scene->bottomLimit() ){
		emit endGame();       
	}
}

void GameView::pause()
{
  if (ball->isMoving() && stick->isListening()){
      ball->pauseMovement();
      stick->setListening(false);
	myMusic.Pause();
  }
  else {
      ball->resumeMovement();
      stick->setListening(true);
	myMusic.Play();
  }
}

bool GameView::ballCollidesWithBlock(){
  	bool collides = false;
  	
	for (QList<Block*>::iterator it = list->begin();it != list->end();++it){

    		if (ball->collidesWithItem(*it)){
        		collides = true;
			mySoundBlock.Play();
			break;
    		}
  	}
  	return collides;  
}


bool GameView::ballCollidesWithLaterals(){
	bool collides = false;
	if ((ball->x() <= scene->leftLimit()) || (ball->x() >= scene->rightLimit() - ball->size())){
     		collides = true;
		mySoundLateral.Play();
  	}
     	return collides;
}


QPointF GameView::horizontalSymetricPoint(QPointF center, QPointF aPoint){

  	QPointF point(0,0);
  	if (center.x() <= aPoint.x()){
    		point.setX( center.x() - (aPoint.x() - center.x()));
  	}
  	else {
    		point.setX( center.x() + (center.x() - aPoint.x()));
  	}
  	point.setY(aPoint.y());
  	return point;
}


QPointF GameView::verticalSymetricPoint(QPointF center, QPointF aPoint){

  	QPointF point(0,0);
  	if (center.y() <= aPoint.y()){
    		point.setY( center.y() - (aPoint.y() - center.y()));
  	}
  	else {
    		point.setY( center.y() + (center.y() - aPoint.y()));
  	}
  	point.setX(aPoint.x());
  	return point;
}


QPointF GameView::affineFunction(QPointF p1, QPointF p2, qreal x){
        assert((p2.x() - p1.x()) != 0);
  	qreal pente = (p2.y() - p1.y() ) / (p2.x() - p1.x());
  	qreal ordonne_origine = ((p2.x() * p1.y()) - (p1.x() * p2.y())) / (p2.x() - p1.x());
  	qreal y = (pente * x) + ordonne_origine;
  	QPointF result(x, y);
  	return result;
}


qreal GameView::verticalMouvementLimit(QPointF p1, QPointF p2)
{
    qreal limit = 0;
    if (p1.x() <= p2.x()){
       limit = scene->rightLimit() + 10;
    }
    else {
       limit = scene->leftLimit() - 10 ;
    }
    return limit;
}
qreal GameView::horizontalMouvementLimit(QPointF p1, QPointF p2)
{
    qreal limit = 0;
    if (p1.x() <= p2.x()){
       limit = scene->leftLimit() - 10;
    }
    else {
       limit = scene->rightLimit() + 10;
    }
    return limit;

}
void GameView::lockBlockCollsion()
{
    lockStick = false;
    lockBlock = true;
    lockLateral = false;
}
void GameView::lockLateralCollision()
{
    lockStick = false;
    lockBlock = false;
    lockLateral = true;
}
void GameView::lockStickCollision()
{
    lockStick = true;
    lockBlock = false;
    lockLateral = false;	
}
