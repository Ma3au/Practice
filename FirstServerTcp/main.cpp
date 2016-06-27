#include "Controller/controller.h"
#include "View/masterview.h"

#include <QApplication>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);

  Controller controller;
  MasterView masterView(&controller);

  return a.exec();
}
