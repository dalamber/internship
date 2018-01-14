#ifndef SETTINGSWIDGET_H
#define SETTINGSWIDGET_H

#include <QLineEdit>
#include <QtWidgets>

class SettingsWidget : public QWidget
{
    Q_OBJECT
public:
    SettingsWidget(QWidget *parent);
signals:
    void settingsChanged(quint32 min, quint32 max, quint32 spacing);
    void itemMinWidthChanged(quint32 min);
    void itemMaxWidthChanged(quint32 max);
    void spacingChanged(quint32 spacing);
public slots:
    void newSettings();
private:
    QVBoxLayout *layout;
    QLineEdit *lineItemMin;
    QLineEdit *lineItemMax;
    QLineEdit *lineSpacing;
    QPushButton *button;
};

#endif // SETTINGSWIDGET_H
