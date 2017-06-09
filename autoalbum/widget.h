#ifndef WIDGET_H
#define WIDGET_H

#include <QMainWindow>
#include <QLabel>
#include <QString>
#include <QStringList>
#include <QPoint>
#include <QLabel>
#include <QMovie>
#include <QRect>
#include <QDesktopWidget>
#include <QTimer>
#include <QStringList>
#include <QFileDialog>
#include <QDesktopServices>
#include <QFileInfo>
#include <QDesktopServices>
#include <QDir>
#include <QDebug>
#include <QDirIterator>
#include <QProcess>
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT
    
public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
private:
    QPixmap pix;
    QString pic;
    QTimer *timer,*timer_play,*point;
    QString imageList[1000];
    QStringList::Iterator it;
    QFileInfoList::Iterator itf;
    int i,k;
    QPoint just,now;
    bool is;
    void openfile();
    void Mountusb();

private slots:
    void PictureShow();

    void on_pushButton_play_clicked();

    void disappear();

    void btnshow();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
