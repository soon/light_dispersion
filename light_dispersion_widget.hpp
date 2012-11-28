#ifndef LIGHT_DISPERSION_WIDGET_HPP
#define LIGHT_DISPERSION_WIDGET_HPP

#include <QtGui/QWidget>
#include <QString>

class light_dispersion_widget : public QWidget
{
    Q_OBJECT
public:
    explicit light_dispersion_widget(QWidget *parent = 0);
    
protected:
    void paintEvent(QPaintEvent *);
    void closeEvent(QCloseEvent *);
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void wheelEvent(QWheelEvent *);
    void keyPressEvent(QKeyEvent *);

private:
    void _setDataFromFile();
    void _writeDataToFile();
    static QString _getFileName()
    {
        return "ligth_dispersion.dat";
    }

private:
    int _current_x;
    int _width;

    static const int _DELTA_WIDTH = 2;
};

#endif // LIGHT_DISPERSION_WIDGET_HPP
