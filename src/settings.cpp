#include "settings.h"
#include <QFile>
#include <QSettings>

Settings settings;


/**
  Loads the application settings, or, if no saved settings are available,
  loads default values for the settings. You can change the defaults here.
**/
void Settings::loadSettingsOrDefaults() {
    // Set the default values below
    QSettings s("CS123", "Final");
    scale = s.value("scale", 20).toInt();
    useMountains = s.value("showMountains", false).toBool();
    usePlains = s.value("showPlains", false).toBool();
    useHills = s.value("showHills", false).toBool();
    octaves = s.value("octaves", 4).toInt();
    useNormalMapping = s.value("useNormalMapping", true).toBool();
    useTextureMapping = s.value("useTextureMapping", true).toBool();
    useFog = s.value("useFog", true).toBool();
    sky = s.value("shape", DAY).toInt();

}

void Settings::saveSettings() {
    QSettings s("CS123", "Final");
    s.setValue("scale", scale);
    s.setValue("showMountains", false);
    s.setValue("showPlains", false);
    s.setValue("showHills", false);
    s.setValue("octaves", octaves);
    s.setValue("useNormalMapping", true);
    s.setValue("useTextureMapping", true);
    s.setValue("useFog", true);
    s.setValue("sky", sky);
}
