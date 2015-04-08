#include "shanalogclock.h"
#include "shanalogclockplugin.h"

#include <QtPlugin>

SHAnalogClockPlugin::SHAnalogClockPlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void SHAnalogClockPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;
    
    // Add extension registrations, etc. here
    
    m_initialized = true;
}

bool SHAnalogClockPlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *SHAnalogClockPlugin::createWidget(QWidget *parent)
{
    return new SHAnalogClock(parent);
}

QString SHAnalogClockPlugin::name() const
{
    return QLatin1String("SHAnalogClock");
}

QString SHAnalogClockPlugin::group() const
{
    return QLatin1String("SHCustomPlugins");
}

QIcon SHAnalogClockPlugin::icon() const
{
    return QIcon(QLatin1String(":/image/analogClock.ico"));
}

QString SHAnalogClockPlugin::toolTip() const
{
    return QLatin1String("analog clock");
}

QString SHAnalogClockPlugin::whatsThis() const
{
    return QLatin1String("this is an analog clock.");
}

bool SHAnalogClockPlugin::isContainer() const
{
    return false;
}

QString SHAnalogClockPlugin::domXml() const
{
    return QLatin1String("<widget class=\"SHAnalogClock\" name=\"shanalogClock\">\n"
                             "  <property name=\"geometry\">\n"
                             "   <rect>\n"
                             "    <x>0</x>\n"
                             "    <y>0</y>\n"
                             "    <width>200</width>\n"
                             "    <height>200</height>\n"
                             "   </rect>\n"
                             "  </property>\n"
                             "</widget>\n");

}

QString SHAnalogClockPlugin::includeFile() const
{
    return QLatin1String("SHQtCustom/shanalogclock.h");
}

