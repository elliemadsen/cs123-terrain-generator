/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionQuit;
    QAction *actionExport;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QDockWidget *settingsDock;
    QWidget *settingsDockContent;
    QVBoxLayout *settingsLayout;
    QWidget *scale;
    QPushButton *exportButton;
    QGroupBox *texturesGroupBox;
    QCheckBox *useNormalMapping;
    QFrame *line_4;
    QCheckBox *useTextureMapping;
    QGroupBox *environmentGroupBox;
    QCheckBox *useFog;
    QGroupBox *biomesGroupBox;
    QCheckBox *showPlains;
    QWidget *octaves;
    QLabel *octavesLabel;
    QSlider *octavesSlider;
    QLineEdit *octavesTextbox;
    QFrame *line;
    QFrame *line_2;
    QCheckBox *showMountains;
    QFrame *line_3;
    QSlider *scaleSlider;
    QLabel *scaleLabel;
    QCheckBox *showHills;
    QLineEdit *scaleTextbox;
    QGroupBox *skyGroupBox;
    QWidget *sky;
    QRadioButton *daySky;
    QFrame *line_5;
    QRadioButton *nightSky;
    QFrame *line_6;
    QRadioButton *sunsetSky;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(177, 717);
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QStringLiteral("actionQuit"));
        actionExport = new QAction(MainWindow);
        actionExport->setObjectName(QStringLiteral("actionExport"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 177, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        MainWindow->setMenuBar(menuBar);
        settingsDock = new QDockWidget(MainWindow);
        settingsDock->setObjectName(QStringLiteral("settingsDock"));
        settingsDock->setMinimumSize(QSize(160, 211));
        settingsDock->setFeatures(QDockWidget::DockWidgetMovable);
        settingsDockContent = new QWidget();
        settingsDockContent->setObjectName(QStringLiteral("settingsDockContent"));
        settingsDockContent->setAutoFillBackground(false);
        settingsLayout = new QVBoxLayout(settingsDockContent);
        settingsLayout->setSpacing(6);
        settingsLayout->setContentsMargins(11, 11, 11, 11);
        settingsLayout->setObjectName(QStringLiteral("settingsLayout"));
        scale = new QWidget(settingsDockContent);
        scale->setObjectName(QStringLiteral("scale"));
        exportButton = new QPushButton(scale);
        exportButton->setObjectName(QStringLiteral("exportButton"));
        exportButton->setGeometry(QRect(30, 600, 201, 32));
        texturesGroupBox = new QGroupBox(scale);
        texturesGroupBox->setObjectName(QStringLiteral("texturesGroupBox"));
        texturesGroupBox->setGeometry(QRect(0, 410, 251, 101));
        useNormalMapping = new QCheckBox(texturesGroupBox);
        useNormalMapping->setObjectName(QStringLiteral("useNormalMapping"));
        useNormalMapping->setGeometry(QRect(10, 30, 171, 20));
        line_4 = new QFrame(texturesGroupBox);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setGeometry(QRect(10, 50, 221, 16));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);
        useTextureMapping = new QCheckBox(texturesGroupBox);
        useTextureMapping->setObjectName(QStringLiteral("useTextureMapping"));
        useTextureMapping->setGeometry(QRect(10, 70, 171, 20));
        environmentGroupBox = new QGroupBox(scale);
        environmentGroupBox->setObjectName(QStringLiteral("environmentGroupBox"));
        environmentGroupBox->setGeometry(QRect(0, 520, 251, 61));
        useFog = new QCheckBox(environmentGroupBox);
        useFog->setObjectName(QStringLiteral("useFog"));
        useFog->setGeometry(QRect(10, 30, 87, 20));
        biomesGroupBox = new QGroupBox(scale);
        biomesGroupBox->setObjectName(QStringLiteral("biomesGroupBox"));
        biomesGroupBox->setGeometry(QRect(0, 0, 251, 241));
        showPlains = new QCheckBox(biomesGroupBox);
        showPlains->setObjectName(QStringLiteral("showPlains"));
        showPlains->setGeometry(QRect(10, 170, 87, 20));
        octaves = new QWidget(biomesGroupBox);
        octaves->setObjectName(QStringLiteral("octaves"));
        octaves->setGeometry(QRect(10, 70, 191, 41));
        octavesLabel = new QLabel(octaves);
        octavesLabel->setObjectName(QStringLiteral("octavesLabel"));
        octavesLabel->setGeometry(QRect(0, 10, 60, 16));
        octavesSlider = new QSlider(octaves);
        octavesSlider->setObjectName(QStringLiteral("octavesSlider"));
        octavesSlider->setGeometry(QRect(60, 10, 81, 22));
        octavesSlider->setMinimum(1);
        octavesSlider->setMaximum(6);
        octavesSlider->setValue(4);
        octavesSlider->setOrientation(Qt::Horizontal);
        octavesSlider->setTickPosition(QSlider::TicksBothSides);
        octavesTextbox = new QLineEdit(octaves);
        octavesTextbox->setObjectName(QStringLiteral("octavesTextbox"));
        octavesTextbox->setGeometry(QRect(150, 10, 31, 21));
        line = new QFrame(biomesGroupBox);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(10, 150, 221, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(biomesGroupBox);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(10, 190, 221, 16));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        showMountains = new QCheckBox(biomesGroupBox);
        showMountains->setObjectName(QStringLiteral("showMountains"));
        showMountains->setGeometry(QRect(10, 130, 87, 20));
        line_3 = new QFrame(biomesGroupBox);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setGeometry(QRect(10, 110, 221, 16));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        scaleSlider = new QSlider(biomesGroupBox);
        scaleSlider->setObjectName(QStringLiteral("scaleSlider"));
        scaleSlider->setGeometry(QRect(70, 40, 131, 22));
        scaleSlider->setMinimum(1);
        scaleSlider->setMaximum(100);
        scaleSlider->setValue(20);
        scaleSlider->setOrientation(Qt::Horizontal);
        scaleLabel = new QLabel(biomesGroupBox);
        scaleLabel->setObjectName(QStringLiteral("scaleLabel"));
        scaleLabel->setGeometry(QRect(10, 40, 60, 16));
        showHills = new QCheckBox(biomesGroupBox);
        showHills->setObjectName(QStringLiteral("showHills"));
        showHills->setGeometry(QRect(10, 210, 87, 20));
        scaleTextbox = new QLineEdit(biomesGroupBox);
        scaleTextbox->setObjectName(QStringLiteral("scaleTextbox"));
        scaleTextbox->setGeometry(QRect(210, 40, 31, 21));
        skyGroupBox = new QGroupBox(scale);
        skyGroupBox->setObjectName(QStringLiteral("skyGroupBox"));
        skyGroupBox->setGeometry(QRect(0, 250, 251, 141));
        sky = new QWidget(skyGroupBox);
        sky->setObjectName(QStringLiteral("sky"));
        sky->setGeometry(QRect(0, 20, 251, 121));
        daySky = new QRadioButton(sky);
        daySky->setObjectName(QStringLiteral("daySky"));
        daySky->setGeometry(QRect(10, 10, 100, 20));
        line_5 = new QFrame(sky);
        line_5->setObjectName(QStringLiteral("line_5"));
        line_5->setGeometry(QRect(10, 30, 221, 16));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);
        nightSky = new QRadioButton(sky);
        nightSky->setObjectName(QStringLiteral("nightSky"));
        nightSky->setGeometry(QRect(10, 50, 100, 20));
        line_6 = new QFrame(sky);
        line_6->setObjectName(QStringLiteral("line_6"));
        line_6->setGeometry(QRect(10, 70, 221, 16));
        line_6->setFrameShape(QFrame::HLine);
        line_6->setFrameShadow(QFrame::Sunken);
        sunsetSky = new QRadioButton(sky);
        sunsetSky->setObjectName(QStringLiteral("sunsetSky"));
        sunsetSky->setGeometry(QRect(10, 90, 100, 20));

        settingsLayout->addWidget(scale);

        settingsDock->setWidget(settingsDockContent);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(1), settingsDock);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionQuit);

        retranslateUi(MainWindow);
        QObject::connect(actionQuit, SIGNAL(triggered()), MainWindow, SLOT(close()));
        QObject::connect(exportButton, SIGNAL(clicked()), MainWindow, SLOT(exportTerrain()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "CS 123 Final - Terrain Generator", Q_NULLPTR));
        actionQuit->setText(QApplication::translate("MainWindow", "&Quit", Q_NULLPTR));
        actionQuit->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", Q_NULLPTR));
        actionExport->setText(QApplication::translate("MainWindow", "Export", Q_NULLPTR));
        menuFile->setTitle(QApplication::translate("MainWindow", "Fi&le", Q_NULLPTR));
        exportButton->setText(QApplication::translate("MainWindow", "Export Terrain as .OBJ", Q_NULLPTR));
        texturesGroupBox->setTitle(QApplication::translate("MainWindow", "Textures", Q_NULLPTR));
        useNormalMapping->setText(QApplication::translate("MainWindow", "Normal Mapping", Q_NULLPTR));
        useTextureMapping->setText(QApplication::translate("MainWindow", "Texture Mapping", Q_NULLPTR));
        environmentGroupBox->setTitle(QApplication::translate("MainWindow", "Environment", Q_NULLPTR));
        useFog->setText(QApplication::translate("MainWindow", "Fog", Q_NULLPTR));
        biomesGroupBox->setTitle(QApplication::translate("MainWindow", "Terrain", Q_NULLPTR));
        showPlains->setText(QApplication::translate("MainWindow", "Plains", Q_NULLPTR));
        octavesLabel->setText(QApplication::translate("MainWindow", "Octaves", Q_NULLPTR));
        showMountains->setText(QApplication::translate("MainWindow", "Mountains", Q_NULLPTR));
        scaleLabel->setText(QApplication::translate("MainWindow", "Scale", Q_NULLPTR));
        showHills->setText(QApplication::translate("MainWindow", "Hills", Q_NULLPTR));
        skyGroupBox->setTitle(QApplication::translate("MainWindow", "Sky", Q_NULLPTR));
        daySky->setText(QApplication::translate("MainWindow", "Day", Q_NULLPTR));
        nightSky->setText(QApplication::translate("MainWindow", "Night", Q_NULLPTR));
        sunsetSky->setText(QApplication::translate("MainWindow", "Sunset", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
