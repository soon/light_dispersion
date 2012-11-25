#include <QtGui/QPainter>
#include <QtGui/QColor>
#include <QtGui/QBrush>
#include <QtGui/QMouseEvent>
#include <Qt>

#include <QDebug>
#include <QFile>
#include <QIODevice>

#include "light_dispersion_widget.hpp"

light_dispersion_widget::light_dispersion_widget(QWidget* parent)
    : QWidget(parent)
{
    showFullScreen();
    _setDataFromFile();
    qDebug() << "x: " << _current_x;
    qDebug() << "width: " << _width;
    // _current = QPoint( / 2, maximumHeight() / 2);
    // _current_x =
    // qDebug() << width() << ' ' << height();
}

void light_dispersion_widget::paintEvent(QPaintEvent*)
{
    QPainter painter(this);

    painter.setBrush(Qt::black);
    painter.drawRect(0, 0, width(), height());

    // qDebug() << _current.x();

    // qDebug() << width() << ' ' << height();

    painter.setBrush(Qt::white);
    painter.drawRect(_current_x, 0, _width, height());
}

void light_dispersion_widget::closeEvent(QCloseEvent *)
{
    _writeDataToFile();
}

void light_dispersion_widget::mousePressEvent(QMouseEvent* event)
{
    if(event -> button() == Qt::LeftButton)
        _current_x = event -> pos().x();
    update();
}

void light_dispersion_widget::mouseMoveEvent(QMouseEvent* event)
{
    if(event -> button() & Qt::LeftButton)
    {
        qDebug("mouseMoveEvent");
        _current_x = event -> pos().x();
    }
    update();
}

void light_dispersion_widget::_setDataFromFile()
{
    QFile file(_getFileName());
    if(file.open(QIODevice::ReadOnly))
    {
        qDebug("NOTE: File exists");
        if
        (
            file.read
            (
                reinterpret_cast<char*>(&_current_x),
                sizeof(_current_x)
            ) == -1
        )
        {
            qDebug("ERROR: Can't read position");
            _current_x = width() / 2;
            _width = 1;
            return;
        }

        if(_current_x > width())
        {
            qDebug("WARNING: Incorrect position");
            _current_x = width() / 2;
        }

        if
        (
            file.read
            (
                reinterpret_cast<char*>(&_width),
                sizeof(_width)
            ) == -1
        )
        {
            qDebug("ERROR: Can't read width");
            _width = 1;
            return;
        }

        if(_width > width() / 2)
        {
            qDebug("WARNING: Incorrect width");
            _width = 1;
        }
    }
    else
    {
        qDebug("WARNING: File doesn't exists");
        _current_x = width() / 2;
        _width = 1;
    }
}

void light_dispersion_widget::_writeDataToFile()
{
    QFile file(_getFileName());

    if(!file.open(QIODevice::WriteOnly))
        qDebug("ERROR: Can't open file for writing");
    else
    {
        file.write(reinterpret_cast<char*>(&_current_x), sizeof(_current_x));
        file.write(reinterpret_cast<char*>(&_width), sizeof(_width));
    }
}



