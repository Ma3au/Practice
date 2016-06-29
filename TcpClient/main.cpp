#include "View/clientgui.h"
#include "Controller/client.h"
#include "View/masterview.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Controller controller;
    MasterView masterview(&controller);
    masterview.show();

    return a.exec();
}
