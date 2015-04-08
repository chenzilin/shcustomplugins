#include <QtPlugin>

#include "shslider.h"
#include "shsliderplugin.h"

SHSliderPlugin::SHSliderPlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void SHSliderPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;
    
    // Add extension registrations, etc. here
    
    m_initialized = true;
}

bool SHSliderPlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *SHSliderPlugin::createWidget(QWidget *parent)
{
    return new SHSlider(parent);
}

QString SHSliderPlugin::name() const
{
    return QLatin1String("SHSlider");
}

QString SHSliderPlugin::group() const
{
    return QLatin1String("SHCustomPlugins");
}

QIcon SHSliderPlugin::icon() const
{
    return QIcon(QLatin1String(":/image/slider.png"));
}

QString SHSliderPlugin::toolTip() const
{
    return QLatin1String("slider");
}

QString SHSliderPlugin::whatsThis() const
{
    return QLatin1String("this is a slider.");
}

bool SHSliderPlugin::isContainer() const
{
    return false;
}

QString SHSliderPlugin::domXml() const
{
    return QLatin1String("<widget class=\"SHSlider\" name=\"shslider\">\n"
                             "  <property name=\"geometry\">\n"
                             "   <rect>\n"
                             "    <x>0</x>\n"
                             "    <y>0</y>\n"
                             "    <width>200</width>\n"
                             "    <height>200</height>\n"
                             "   </rect>\n"
                             "  </property>\n"
                             "</widget>\n");}

QString SHSliderPlugin::includeFile() const
{
    return QLatin1String("SHQtCustom/shslider.h");
}

