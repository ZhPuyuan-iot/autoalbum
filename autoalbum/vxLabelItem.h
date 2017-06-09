#ifndef VXLABELITEM_H
#define VXLABELITEM_H

// ÿһ��С�Ĵ�Ҷ

#include <QLabel>
#include <QTimeLine>
class vxLabelItem : public QLabel 
{
	Q_OBJECT

public:
	vxLabelItem(QWidget* parent = 0);
	~vxLabelItem();

    //void setImage(const QImage& image);// ����ͼƬ��Ƭ�ϵ���ʼλ�á����
    void setImage(const QPixmap& image);
    void setEffect(int val);
	void startDraw();

public slots:
    void	slot_timeOut(int);

protected:
	void	paintEvent ( QPaintEvent * ev );

private:
    //QImage	mDrawImage;
    //QImage	mCurrentImage;
    QPixmap	mDrawImage;
    QPixmap	mCurrentImage;

    QTimeLine* mTimeline;
    int m_currentHeight;
    int effect;
};
#endif
