#ifndef TEST_H
#define TEST_H

#include "ui_test.h"
#include <QDesktopWidget>
#include <qamflightinstrument.h>
#include <qairspeed.h>
#include <qaltimeter.h>
#include <qamchronograph.h>
#include <qamturncoordinator.h>
#include <qamtachymeter.h>
#include <iostream>
#include <QFile>

class test : public QWidget, private Ui::test
{
    Q_OBJECT

public:
    explicit test(QWidget *parent = 0);

    void createAirSpeed(int id, int x, int y, int widht, int height) ;
    void createAltimeter(int id, int x, int y, int widht, int height) ;
    void createChronograph(int id, int x, int y, int widht, int height) ;
    void createTurnCoordinator(int id, int x, int y, int widht, int height) ;
    void createTachymeter(int id, int x, int y, int widht, int height) ;

    void setQFI(int x, int y, int width, int height) ;
    void loadConf(QString& file) ;

private :
   QList<QamFlightInstrument *> QListQFI ;

};

#endif // TEST_H