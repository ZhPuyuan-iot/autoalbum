#include "vxLabelItem.h"
#include <QPainter>
vxLabelItem::vxLabelItem(QWidget* parent)
: QLabel(parent)
, m_currentHeight(0)
{
    effect = 0;
    mTimeline = new QTimeLine(1000, this);//1 s
    mTimeline->setCurveShape(QTimeLine::LinearCurve);
    connect(mTimeline, SIGNAL(frameChanged(int)), this, SLOT(slot_timeOut(int)));
}

vxLabelItem::~vxLabelItem()
{

}

void vxLabelItem::paintEvent( QPaintEvent * ev )
{
	if(!mDrawImage.isNull())
	{
		QPainter p(this);
        p.setBrush(QBrush(mCurrentImage));
        p.setPen(Qt::NoPen);

        if(effect == 1)
        {
            p.setWindow(-(mDrawImage.width()-mDrawImage.width()*m_currentHeight/mDrawImage.height())/2,
                        -(mDrawImage.height()-m_currentHeight)/2,
                        mDrawImage.width(),
                        mDrawImage.height());

            p.drawRect(0, 0,
                       mDrawImage.width()*m_currentHeight/mDrawImage.height(),
                       m_currentHeight);
        }

        else if(effect == 2)
        {
            p.setWindow(0, 0,
                        mDrawImage.width(),
                        mDrawImage.height());

            p.drawRect(0, 0,
                       mDrawImage.width(),
                       m_currentHeight);
        }

        else if(effect == 3)
        {
            p.setWindow(0, 0,
                        mDrawImage.width(),
                        mDrawImage.height());

            p.drawRect(0, 0,
                       mDrawImage.width()*m_currentHeight/mDrawImage.height(),
                       mDrawImage.height());
        }

        else if(effect == 4)
        {
            p.setWindow(-(mDrawImage.width()-mDrawImage.width()*m_currentHeight/mDrawImage.height()),
                        -(mDrawImage.height()-m_currentHeight),
                        mDrawImage.width(),
                        mDrawImage.height());

            p.drawRect(0, 0,
                       mDrawImage.width()*m_currentHeight/mDrawImage.height(),
                       m_currentHeight);
        }

        else if(effect == 5)
        {
            p.setWindow(0, 0,
                        mDrawImage.width(),
                        mDrawImage.height());

            p.drawRect(0, 0,
                       mDrawImage.width()*m_currentHeight/mDrawImage.height(),
                       m_currentHeight);
        }

        else
        {
            p.setWindow(0, 0,
                        mDrawImage.width(),
                        mDrawImage.height());

            p.drawRect(0, 0,
                       mDrawImage.width(),
                       mDrawImage.height());
        }

    }

	QWidget::paintEvent(ev);
}

void vxLabelItem::setImage( const QPixmap& image )
{
	mDrawImage = image;

}

void vxLabelItem::setEffect(int val)
{
    effect = val;

}

void vxLabelItem::startDraw()
{
    //qDebug() << mDrawImage.width() <<mDrawImage.height();
	if(!mDrawImage.isNull())
	{
        //qDebug()<<"mDrawImage.width() = "<<mDrawImage.width()<<endl;
        //mTimeline->setFrameRange(0, mDrawImage.width());
        mTimeline->setFrameRange(0, mDrawImage.height()/8);
        mTimeline->start();
	}
}

void vxLabelItem::slot_timeOut( int val0)
{
    int val = val0*8+(mDrawImage.height())%8;
    if(effect == 1)
    {
        mCurrentImage = mDrawImage.copy((mDrawImage.width()-mDrawImage.width()*val/mDrawImage.height())/2,
                        (mDrawImage.height()-val)/2,
                        mDrawImage.width()*val/mDrawImage.height(),
                        val);
    }

    else if(effect == 2)
    {
        mCurrentImage = mDrawImage.copy(0, 0,
                        mDrawImage.width(), val);
    }

    else if(effect == 3)
    {
        mCurrentImage = mDrawImage.copy(0, 0,
                        mDrawImage.width()*val/mDrawImage.height(), mDrawImage.height());
    }

    else if(effect == 4)
    {
        mCurrentImage = mDrawImage.copy(0, 0,
                        mDrawImage.width()*val/mDrawImage.height(),
                        val);
    }

    else if(effect == 5)
    {
        mCurrentImage = mDrawImage.copy(mDrawImage.width()-mDrawImage.width()*val/mDrawImage.height(),
                        mDrawImage.height()-val,
                        mDrawImage.width()*val/mDrawImage.height(),
                        val);
    }

    else
    {
        mCurrentImage = mDrawImage;
    }
    //qDebug() << mCurrentImage.width() <<mCurrentImage.height();
    m_currentHeight = val;
	update();
}
