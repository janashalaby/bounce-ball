#ifndef BALL_H
#define BALL_H

#include<QPainter>
#include<QGraphicsItem>
#include<QGraphicsScene>
#include <QtCore>
#include <QtGui>

class ball : public QGraphicsItem
{
public:
    ball();
    QRectF boundingRect() const;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
protected:
       void advance(int phase);
private:
        qreal angle;
        qreal speed; // speed of our object
        void doCollison();// we will create func to do anything when object hit another one

};

#endif // BALL_H
