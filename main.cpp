#include <QApplication>
#include <card.h>

int main (int argc, char *argv[])
{
    QApplication a (argc, argv);

    Card* c = new Card ();
    c->show ();

    return a.exec ();
}
