#include "light_dispersion_widget.hpp"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    light_dispersion_widget ldw;
    
    return a.exec();
}
