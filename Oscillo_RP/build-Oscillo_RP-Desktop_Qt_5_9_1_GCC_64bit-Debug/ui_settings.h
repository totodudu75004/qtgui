/********************************************************************************
** Form generated from reading UI file 'settings.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGS_H
#define UI_SETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Settings
{
public:
    QLabel *label_R0;
    QLineEdit *lineEdit_R0;
    QLabel *label_Rf;
    QLineEdit *lineEdit_Rf;
    QLabel *label_dec;
    QLineEdit *lineEdit_dec;
    QLabel *label_Nline;
    QLineEdit *lineEdit_Nline;
    QLineEdit *lineEdit_sector;
    QLabel *label_sector;
    QLabel *label_mode;
    QPushButton *pushButton_edit;
    QPushButton *pushButton_change;
    QComboBox *comboBox_mode;

    void setupUi(QDialog *Settings)
    {
        if (Settings->objectName().isEmpty())
            Settings->setObjectName(QStringLiteral("Settings"));
        Settings->resize(400, 300);
        label_R0 = new QLabel(Settings);
        label_R0->setObjectName(QStringLiteral("label_R0"));
        label_R0->setGeometry(QRect(20, 14, 71, 16));
        lineEdit_R0 = new QLineEdit(Settings);
        lineEdit_R0->setObjectName(QStringLiteral("lineEdit_R0"));
        lineEdit_R0->setEnabled(false);
        lineEdit_R0->setGeometry(QRect(90, 10, 51, 22));
        lineEdit_R0->setMaxLength(3);
        label_Rf = new QLabel(Settings);
        label_Rf->setObjectName(QStringLiteral("label_Rf"));
        label_Rf->setGeometry(QRect(20, 44, 81, 16));
        lineEdit_Rf = new QLineEdit(Settings);
        lineEdit_Rf->setObjectName(QStringLiteral("lineEdit_Rf"));
        lineEdit_Rf->setEnabled(false);
        lineEdit_Rf->setGeometry(QRect(90, 40, 51, 22));
        lineEdit_Rf->setMaxLength(3);
        label_dec = new QLabel(Settings);
        label_dec->setObjectName(QStringLiteral("label_dec"));
        label_dec->setGeometry(QRect(20, 74, 91, 16));
        lineEdit_dec = new QLineEdit(Settings);
        lineEdit_dec->setObjectName(QStringLiteral("lineEdit_dec"));
        lineEdit_dec->setEnabled(false);
        lineEdit_dec->setGeometry(QRect(110, 70, 51, 22));
        lineEdit_dec->setMaxLength(2);
        label_Nline = new QLabel(Settings);
        label_Nline->setObjectName(QStringLiteral("label_Nline"));
        label_Nline->setGeometry(QRect(20, 104, 111, 16));
        lineEdit_Nline = new QLineEdit(Settings);
        lineEdit_Nline->setObjectName(QStringLiteral("lineEdit_Nline"));
        lineEdit_Nline->setEnabled(false);
        lineEdit_Nline->setGeometry(QRect(130, 100, 51, 22));
        lineEdit_Nline->setMaxLength(3);
        lineEdit_sector = new QLineEdit(Settings);
        lineEdit_sector->setObjectName(QStringLiteral("lineEdit_sector"));
        lineEdit_sector->setEnabled(false);
        lineEdit_sector->setGeometry(QRect(160, 130, 51, 22));
        lineEdit_sector->setMaxLength(3);
        label_sector = new QLabel(Settings);
        label_sector->setObjectName(QStringLiteral("label_sector"));
        label_sector->setGeometry(QRect(20, 134, 131, 16));
        label_mode = new QLabel(Settings);
        label_mode->setObjectName(QStringLiteral("label_mode"));
        label_mode->setGeometry(QRect(20, 164, 171, 16));
        pushButton_edit = new QPushButton(Settings);
        pushButton_edit->setObjectName(QStringLiteral("pushButton_edit"));
        pushButton_edit->setGeometry(QRect(60, 220, 80, 22));
        pushButton_change = new QPushButton(Settings);
        pushButton_change->setObjectName(QStringLiteral("pushButton_change"));
        pushButton_change->setGeometry(QRect(200, 220, 111, 22));
        comboBox_mode = new QComboBox(Settings);
        comboBox_mode->setObjectName(QStringLiteral("comboBox_mode"));
        comboBox_mode->setEnabled(false);
        comboBox_mode->setGeometry(QRect(190, 160, 101, 22));

        retranslateUi(Settings);

        QMetaObject::connectSlotsByName(Settings);
    } // setupUi

    void retranslateUi(QDialog *Settings)
    {
        Settings->setWindowTitle(QApplication::translate("Settings", "Dialog", Q_NULLPTR));
        label_R0->setText(QApplication::translate("Settings", "R0 (mm) =", Q_NULLPTR));
        lineEdit_R0->setText(QApplication::translate("Settings", "0", Q_NULLPTR));
        label_Rf->setText(QApplication::translate("Settings", "Rf (mm) =", Q_NULLPTR));
        lineEdit_Rf->setText(QApplication::translate("Settings", "0", Q_NULLPTR));
        label_dec->setText(QApplication::translate("Settings", "Decimation =", Q_NULLPTR));
        lineEdit_dec->setText(QApplication::translate("Settings", "1", Q_NULLPTR));
        label_Nline->setText(QApplication::translate("Settings", "Number of line =", Q_NULLPTR));
        lineEdit_Nline->setText(QApplication::translate("Settings", "1", Q_NULLPTR));
        lineEdit_sector->setText(QApplication::translate("Settings", "0", Q_NULLPTR));
        label_sector->setText(QApplication::translate("Settings", "Angle of the sector =", Q_NULLPTR));
        label_mode->setText(QApplication::translate("Settings", "Type of data send via TCP:", Q_NULLPTR));
        pushButton_edit->setText(QApplication::translate("Settings", "Edit settings", Q_NULLPTR));
        pushButton_change->setText(QApplication::translate("Settings", "Change settings", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Settings: public Ui_Settings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGS_H
