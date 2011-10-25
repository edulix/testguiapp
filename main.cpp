#include <QtGui/QApplication>
#include "testguiapp.h"


int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    testguiapp foo;
    foo.show();
    return app.exec();
}
