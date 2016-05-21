#ifndef PREFERENCE_H
#define PREFERENCE_H

#include <QDialog>

namespace Ui {
class Preference;
}

class Preference : public QDialog
{
    Q_OBJECT

public:
    explicit Preference(QWidget *parent = 0);
    ~Preference();

private:
    Ui::Preference *ui;

private slots:
    void onAccepted();

};

#endif // PREFERENCE_H
