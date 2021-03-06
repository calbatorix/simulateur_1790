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
#include <QHA.h>
#include <iostream>
#include <QFile>
#include <QString>
#include <QTextStream>
#include <dataref.h>
#include <xplaneudpworker.h>

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
    void createQHA(int id, int x, int y, int width, int height) ;
    void setQFI(int x, int y, int width, int height, QamFlightInstrument* QFI) ;
    void createRrefQfi(int iId, int aId, QString path,int freq = 0, int scale, int offset ) ;
    bool loadConf(QString& file) ;

private :
    QString configFile ;
    QList<QamFlightInstrument *> QListQFI ;
    QList<Dataref *> QListDat ;

};

#endif // TEST_H
