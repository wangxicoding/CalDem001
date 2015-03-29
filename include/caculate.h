#ifndef CACULATE_H
#define CACULATE_H

#include <QWidget>

class Caculate : public QWidget
{
    Q_OBJECT
public:
    explicit Caculate(QWidget *parent = 0);
    ~Caculate();
public:
    void unitInit();
    void calculate();

signals:
    void sendProgressValue(int);

public slots:
    void maintemp();
};

#endif // CACULATE_H
