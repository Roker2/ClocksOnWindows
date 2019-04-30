#ifndef CLOCKS_H
#define CLOCKS_H

#include <QWidget>
#include <QDialog>

namespace Ui {
class Clocks;
}

class Clocks : public QDialog
{
    Q_OBJECT

public:
    explicit Clocks(QDialog *parent = nullptr);
    ~Clocks();
    int TransparentValue();
    int RedValue();
    int GreenValue();
    int BlueValue();

private slots:
    void on_Button_SetWhite_clicked();

    void on_Button_SetGrey_clicked();

    void on_Button_SetBlack_clicked();

    void on_fontComboBox_currentFontChanged(const QFont &f);

private:
    Ui::Clocks *ui;
};

#endif // CLOCKS_H
