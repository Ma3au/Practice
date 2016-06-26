#include "View/clientgui.h"
#include "Controller/client.h"
#include "View/masterview.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //Client *client = new Client();
    //ClientGUI w(client);
    //w.show();

    Controller controller;
    MasterView masterview(&controller);

    /*
    int check = 0;
    QString str = "$GPGSV,3,2,12,73,36,067,39,72,14,010,52,07,23,279,42,54,32,222,41*7C";

    for(int i = 1;; i++)
        if(str[i] != '*')
            check ^= str[i].unicode();
        else
            break;

    QString res(QString::number(check, 16).toUpper());
    qDebug() << res;
    */

    return a.exec();
}
