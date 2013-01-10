#ifndef _GAMEVIEW_H
#define _GAMEVIEW_H
#include <QGraphicsView>
#include <QList>
#include <SFML/Audio.hpp>
#include "GameScene.h"
#include "Ball.h"
#include "Stick.h"
#include "Block.h"
class GameView : public QGraphicsView{
Q_OBJECT

public :    
    GameView(QWidget *parent = 0);
    ~GameView();
signals:
    void scoreChanger(int score);
    void endGame();
public slots :
    void pause();
private slots :
    void handleInteractions(const QList<QRectF> &region);
private :
    QPointF horizontalSymetricPoint(QPointF center, QPointF aPoint);
    QPointF verticalSymetricPoint(QPointF center, QPointF aPoint);
    QPointF affineFunction(QPointF p1, QPointF p2, qreal x);
    bool ballCollidesWithBlock();
    bool ballCollidesWithLaterals();
    qreal verticalMouvementLimit(QPointF p1, QPointF p2);
    qreal horizontalMouvementLimit(QPointF p1, QPointF p2);
    bool lockBlock;
    bool lockLateral;
    bool lockStick;
    void lockBlockCollsion();
    void lockLateralCollision();
    void lockStickCollision();
    int score;
    GameScene *scene;
    Ball *ball;
    Stick *stick;
    QList<Block*> *list;
	sf::Music myMusic;
	sf::SoundBuffer myBlockBuffer;
	sf::Sound mySoundBlock;
	sf::SoundBuffer myStickBuffer;
	sf::Sound mySoundStick;
	sf::SoundBuffer myLateralBuffer;
	sf::Sound mySoundLateral;
};
#endif
