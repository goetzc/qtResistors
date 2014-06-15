#ifndef WRESISTORS_H
#define WRESISTORS_H

#include <QDialog>

namespace Ui {
    class wResistors;
}

class wResistors : public QDialog {
    Q_OBJECT
public:
    wResistors(QWidget *parent = 0);
    ~wResistors();

public slots:
    void convert();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::wResistors *ui;
    QIcon createIcon(QString colorName);

};

#endif // WRESISTORS_H
