#ifndef CLOCKS_H
#define CLOCKS_H

#include <QWidget>

namespace Ui {
class Clocks;
}

class Clocks : public QWidget
{
    Q_OBJECT

public:
    explicit Clocks(QWidget *parent = nullptr);
    ~Clocks();
    int TransparentValue();

private:
    Ui::Clocks *ui;
};

#endif // CLOCKS_H
