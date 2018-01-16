#include "settingswidget.h"

SettingsWidget::SettingsWidget(QWidget *parent) : QWidget(parent, Qt::Window)
{
    layout = new QVBoxLayout(this);
    QLabel *label1 = new QLabel("Item Minimum Width", this);
    lineItemMin = new QLineEdit;
    QLabel *label2 = new QLabel("Item Maximum Width", this);
    lineItemMax = new QLineEdit;
    QLabel *label3 = new QLabel("Spacing", this);
    lineSpacing = new QLineEdit;
    button = new QPushButton("Apply");

    layout->addWidget(label1);
    layout->addWidget(lineItemMin);
    layout->addWidget(label2);
    layout->addWidget(lineItemMax);
    layout->addWidget(label3);
    layout->addWidget(lineSpacing);
    layout->addWidget(button);
    connect(button, &QPushButton::clicked, this, &SettingsWidget::newSettings);
}

void SettingsWidget::newSettings()
{
    quint32 min = (lineItemMin->text()).toInt();
    quint32 max = (lineItemMax->text()).toInt();
    if (max < min)
        max = min;
    quint32 spacing = (lineSpacing->text()).toInt();
    emit settingsChanged(min, max, spacing);
}
