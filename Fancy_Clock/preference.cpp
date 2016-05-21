#include "preference.h"
#include "ui_preference.h"
#include <QSettings>
Preference::Preference(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Preference)
{
    ui->setupUi(this);

    QSettings sts;
    ui->colourBox->setCurrentIndex(sts.value("Colour").toInt());
    connect(ui->buttonBox,&QDialogButtonBox::accepted,this,&Preference::onAccepted);
}

Preference::~Preference()
{
    delete ui;
}

void Preference::onAccepted()
{
    QSettings sts;
    sts.setValue("Colour",ui->colourBox->currentIndex());
}
