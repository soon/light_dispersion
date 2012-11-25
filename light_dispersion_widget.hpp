#ifndef LIGHT_DISPERSION_WIDGET_HPP
#define LIGHT_DISPERSION_WIDGET_HPP

#include <QtGui/QWidget>
#include <QPoint>
#include <QtGlobal>
#include <QString>

class light_dispersion_widget : public QWidget
{
    Q_OBJECT
public:
    explicit light_dispersion_widget(QWidget *parent = 0);
    
protected:
    void paintEvent(QPaintEvent*);
    void closeEvent(QCloseEvent*);
    void mousePressEvent(QMouseEvent*);
    void mouseMoveEvent(QMouseEvent*);

private:
    void _setDataFromFile();
    void _writeDataToFile();
    static QString _getFileName()
    {
        return "ligth_dispersion.dat";
    }

signals:
    
public slots:

private:
    unsigned int _current_x;
    unsigned int _width;

    // static const QString _file_name;
};

// const QString light_dispersion_widget::_file_name = "light_dispersion.dat";

#endif // LIGHT_DISPERSION_WIDGET_HPP
