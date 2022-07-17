#include "ball.h"

ball::ball()
{
    // random start rotation
        angle = (qrand() % 360);
        setRotation(angle);
        // set the speed
        speed = 5; // go 5 pixels at a time
        // random start poition
        int StartX = 0;
        int StartY = 0;
        if ((qrand() % 1)) {
            StartX = (qrand() % 200);
            StartY = (qrand() % 200);
        }
        else {
            StartX = (qrand() % -100);
            StartY = (qrand() % -100);
        }// to be very random
        setPos(mapToParent(StartX, StartY));
}

QRectF ball::boundingRect() const
{
     return QRect(0, 0, 20, 20);  //20 pixels
}

void ball::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
   QRectF rec = boundingRect();
   QBrush Brush(Qt::gray);
   if (scene()->collidingItems(this).isEmpty())    {
           //no collision
           Brush.setColor(Qt::blue);
       }
       else {
           //collision
           Brush.setColor(Qt::red);
           // set the new position
           doCollison();
       }
   painter->fillRect(rec, Brush);
   painter->drawRect(rec); //very simple object

}

void ball::advance(int phase)
{
    if (!phase) return;
    QPointF location = this->pos();
    setPos(mapToParent(0, -(speed)));

}

void ball::doCollison()
{
    if ((qrand() % 1))
    {
        // if it hits something spin it around in the opposite direction
        setRotation(rotation() + (180 + (qrand() % 10)));//rotation gets current rotation
    }
    else {
        setRotation(rotation() + (180 + (qrand() % -10)));
    }
    QPointF newpoint = mapToParent(-(boundingRect().width()),-(boundingRect().width()+ 2));
        // + 2 to push it away from the object it is colliding with
     if(!scene()->sceneRect().contains(newpoint)) {
            // move it back in bounds
            newpoint = mapToParent(0, 0);
        }
        else
        {

         //set the new position
         setPos(newpoint);
        }

}
