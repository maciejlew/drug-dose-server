#include "Handler.h"

Handler::Handler(SettingsParser settings) : settings(settings) {}

SettingsParser Handler::getSettings() {
    return settings;
}
