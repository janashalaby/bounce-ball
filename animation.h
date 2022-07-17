#ifndef ANIMATION_H
#define ANIMATION_H

#include <QDialog>
#include <QtGui>
#include <QtCore>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>

QT_BEGIN_NAMESPACE
namespace Ui { class animation; }
QT_END_NAMESPACE

class animation : public QDialog
{
    Q_OBJECT

public:
    animation(QWidget *parent = nullptr);
    ~animation();

protected:
    void showEvent(QShowEvent* event);
    void timerEvent(QTimerEvent* event);

private:
    Ui::animation *ui;
    QGraphicsScene *scene;
    QTimer *timer;
    QGraphicsEllipseItem *ellipse;
};
#endif // ANIMATION_H
