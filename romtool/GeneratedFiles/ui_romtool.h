/********************************************************************************
** Form generated from reading UI file 'romtool.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROMTOOL_H
#define UI_ROMTOOL_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>
#include "image_button.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
	QGroupBox *gridGroupBox;
	QGroupBox *groupBox_2;
    QGridLayout *gridLayout;
    QGridLayout *gridLayout_3;
	QSpacerItem *verticalSpacer;
	QSplitter *splitter_2;
	QSplitter *splitter_3;

    QLabel *input_label;
	QLabel *output_label;
    QLineEdit *output_text;
    QLineEdit *input_text;

    QTextBrowser *console_out;

	ImageButton *input_button;
	ImageButton *output_button;
	ImageButton *extract_button;
	ImageButton *cancel_button;

    QCheckBox *exefs_select;
    QCheckBox *tmp_select;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(650, 398);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/romtool/default.png"));
        MainWindow->setWindowIcon(icon);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(-1, 0, -1, -1);
        gridGroupBox = new QGroupBox(centralwidget);
        gridGroupBox->setObjectName(QString::fromUtf8("gridGroupBox"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(gridGroupBox->sizePolicy().hasHeightForWidth());
        gridGroupBox->setSizePolicy(sizePolicy);
        gridGroupBox->setMinimumSize(QSize(0, 74));
        gridGroupBox->setMaximumSize(QSize(16777214, 74));
        gridLayout_3 = new QGridLayout(gridGroupBox);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setSizeConstraint(QLayout::SetMinAndMaxSize);
        output_label = new QLabel(gridGroupBox);
        output_label->setObjectName(QString::fromUtf8("output_label"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(output_label->sizePolicy().hasHeightForWidth());
        output_label->setSizePolicy(sizePolicy1);

        gridLayout_3->addWidget(output_label, 1, 0, 1, 1);

        output_button = new ImageButton(gridGroupBox);
        output_button->setObjectName(QString::fromUtf8("output_button"));
        QIcon folder(QString::fromUtf8(":/romtool/folder.png"));
		QIcon folder_a(QString::fromUtf8(":/romtool/folder_a.png"));
        output_button->setDefaultIcon(folder);
		output_button->setPressedIcon(folder_a);
        output_button->setIconSize(QSize(36, 16));

        gridLayout_3->addWidget(output_button, 1, 2, 1, 1);

        input_label = new QLabel(gridGroupBox);
        input_label->setObjectName(QString::fromUtf8("input_label"));
        sizePolicy1.setHeightForWidth(input_label->sizePolicy().hasHeightForWidth());
        input_label->setSizePolicy(sizePolicy1);

        gridLayout_3->addWidget(input_label, 0, 0, 1, 1);

        input_button = new ImageButton(gridGroupBox);
        input_button->setObjectName(QString::fromUtf8("input_button"));
        input_button->setDefaultIcon(folder);
		input_button->setPressedIcon(folder_a);
        input_button->setIconSize(QSize(36, 16));

        gridLayout_3->addWidget(input_button, 0, 2, 1, 1);

        output_text = new QLineEdit(gridGroupBox);
        output_text->setObjectName(QString::fromUtf8("output_text"));

        gridLayout_3->addWidget(output_text, 1, 1, 1, 1);

        input_text = new QLineEdit(gridGroupBox);
        input_text->setObjectName(QString::fromUtf8("input_text"));

        gridLayout_3->addWidget(input_text, 0, 1, 1, 1);


        gridLayout->addWidget(gridGroupBox, 3, 0, 1, 1);

        splitter_2 = new QSplitter(centralwidget);
        splitter_2->setObjectName(QString::fromUtf8("splitter_2"));
        splitter_2->setFrameShape(QFrame::NoFrame);
        splitter_2->setOrientation(Qt::Horizontal);
        splitter_2->setOpaqueResize(false);
        splitter_2->setHandleWidth(5);
        splitter_2->setChildrenCollapsible(true);
        console_out = new QTextBrowser(splitter_2);
        console_out->setObjectName(QString::fromUtf8("console_out"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(console_out->sizePolicy().hasHeightForWidth());
        console_out->setSizePolicy(sizePolicy2);
        console_out->setMinimumSize(QSize(0, 202));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(0, 0, 0, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Light, brush1);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush1);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush1);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush1);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush1);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush1);
        QBrush brush2(QColor(255, 255, 220, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush2);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush1);
        console_out->setPalette(palette);
        QFont font;
        font.setFamily(QString::fromUtf8("Courier"));
        console_out->setFont(font);
        console_out->setAutoFillBackground(false);
        splitter_2->addWidget(console_out);
        splitter_3 = new QSplitter(splitter_2);
        splitter_3->setObjectName(QString::fromUtf8("splitter_3"));
        splitter_3->setOrientation(Qt::Vertical);
        splitter_3->setOpaqueResize(false);
        splitter_3->setHandleWidth(0);
        splitter_3->setChildrenCollapsible(false);
        groupBox_2 = new QGroupBox(splitter_3);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy3);
        groupBox_2->setMinimumSize(QSize(103, 165));
        groupBox_2->setMaximumSize(QSize(103, 16777215));
        exefs_select = new QCheckBox(groupBox_2);
        exefs_select->setObjectName(QString::fromUtf8("exefs_select"));
        exefs_select->setGeometry(QRect(10, 20, 91, 17));
        tmp_select = new QCheckBox(groupBox_2);
        tmp_select->setObjectName(QString::fromUtf8("tmp_select"));
        tmp_select->setGeometry(QRect(10, 40, 91, 17));
        splitter_3->addWidget(groupBox_2);
        extract_button = new ImageButton(splitter_3);
        extract_button->setObjectName(QString::fromUtf8("extract_button"));
        QSizePolicy sizePolicy4(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(extract_button->sizePolicy().hasHeightForWidth());
        extract_button->setSizePolicy(sizePolicy4);
        extract_button->setMinimumSize(QSize(103, 25));
        extract_button->setMaximumSize(QSize(103, 25));
        extract_button->setAutoFillBackground(false);
        QIcon extract(QString::fromUtf8(":/romtool/extract.png"));
		QIcon extract_a(QString::fromUtf8(":/romtool/extract_a.png"));
        extract_button->setDefaultIcon(extract);
		extract_button->setPressedIcon(extract_a);
        extract_button->setIconSize(QSize(125, 16));
        splitter_3->addWidget(extract_button);
        cancel_button = new ImageButton(splitter_3);
        cancel_button->setObjectName(QString::fromUtf8("cancel_button"));
        cancel_button->setMinimumSize(QSize(103, 25));
        cancel_button->setMaximumSize(QSize(103, 25));
        QIcon stop(QString::fromUtf8(":/romtool/stop.png"));
		QIcon stop_a(QString::fromUtf8(":/romtool/stop_a.png"));
        cancel_button->setDefaultIcon(stop);
		cancel_button->setPressedIcon(stop_a);
        cancel_button->setIconSize(QSize(100, 16));
        splitter_3->addWidget(cancel_button);
        splitter_2->addWidget(splitter_3);

        gridLayout->addWidget(splitter_2, 5, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer, 4, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "RomFS Extractor", nullptr));
        output_label->setText(QCoreApplication::translate("MainWindow", "Output:", nullptr));
        output_button->setText(QString());
        input_label->setText(QCoreApplication::translate("MainWindow", "Input:", nullptr));
        input_button->setText(QString());
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "Options", nullptr));
        exefs_select->setText(QCoreApplication::translate("MainWindow", "Extract Exefs", nullptr));
        tmp_select->setText(QCoreApplication::translate("MainWindow", "Keep tmp files", nullptr));
        extract_button->setText(QString());
        cancel_button->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROMTOOL_H
