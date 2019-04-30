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
    int RedValue();
    int GreenValue();
    int BlueValue();
    int AlphaValue();

private slots:
    void on_Button_SetWhite_clicked();

    void on_Button_SetGrey_clicked();

    void on_Button_SetBlack_clicked();

    void on_fontComboBox_currentFontChanged(const QFont &f);

private:
    Ui::Clocks *ui;
};

#endif // CLOCKS_H
