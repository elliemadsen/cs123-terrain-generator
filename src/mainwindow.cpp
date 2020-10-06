#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSettings>
#include <assert.h>
#include "databinding.h"
#include "settings.h"

#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    m_ui(new Ui::MainWindow)
{
    QGLFormat qglFormat;
    qglFormat.setVersion(4,0);
    qglFormat.setProfile(QGLFormat::CoreProfile);
    m_ui->setupUi(this);
    QGridLayout *gridLayout = new QGridLayout(m_ui->centralWidget);
    m_glWidget = new GLWidget(qglFormat, this);
    m_glWidget->setMinimumSize(50, 50);
    gridLayout->addWidget(m_glWidget, 0, 1);

    settings.loadSettingsOrDefaults();
    dataBind();

    // Restore the UI settings
    QSettings qtSettings("CS123", "Final");
    restoreGeometry(qtSettings.value("geometry").toByteArray());
    restoreState(qtSettings.value("windowState").toByteArray());
}

MainWindow::~MainWindow()
{
    foreach (DataBinding *b, m_bindings) {
        delete b;
    }
    delete m_ui;
    delete m_glWidget;
}

void MainWindow::dataBind() {
#define BIND(b) { DataBinding *_b = (b); m_bindings.push_back(_b); assert(connect(_b, SIGNAL(dataChanged()), this, SLOT(settingsChanged()))); }

    BIND(IntBinding::bindSliderAndTextbox(
             m_ui->scaleSlider, m_ui->scaleTextbox, settings.scale, 1.f, 100.f));

    BIND(BoolBinding::bindCheckbox(m_ui->showMountains, settings.useMountains));
    BIND(IntBinding::bindSliderAndTextbox(
             m_ui->octavesSlider, m_ui->octavesTextbox, settings.octaves, 1.f, 6.f));

    BIND(BoolBinding::bindCheckbox(m_ui->showPlains, settings.usePlains));
    BIND(BoolBinding::bindCheckbox(m_ui->showHills, settings.useHills));

    BIND(BoolBinding::bindCheckbox(m_ui->useNormalMapping, settings.useNormalMapping));
    BIND(BoolBinding::bindCheckbox(m_ui->useTextureMapping, settings.useTextureMapping));

    BIND(BoolBinding::bindCheckbox(m_ui->useFog, settings.useFog));

    BIND(ChoiceBinding::bindRadioButtons(3, settings.sky,
                                    m_ui->daySky,
                                    m_ui->nightSky,
                                    m_ui->sunsetSky));

#undef BIND
}

void MainWindow::settingsChanged() {
    m_glWidget->update();
    m_glWidget->updateTerrain();
    m_glWidget->updateSky();
}

void MainWindow::closeEvent(QCloseEvent *event) {
    // Save the settings before we quit
    settings.saveSettings();
    QSettings qtSettings("CS123", "Final");
    qtSettings.setValue("geometry", saveGeometry());
    qtSettings.setValue("windowState", saveState());

    QMainWindow::closeEvent(event);
}

void MainWindow::exportTerrain() {
    m_glWidget->exportTerrain();
}
