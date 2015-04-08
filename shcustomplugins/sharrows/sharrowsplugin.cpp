#include <QtPlugin>

#include "sharrows.h"
#include "sharrowsplugin.h"


SHArrowsPlugin::SHArrowsPlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void SHArrowsPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;
    
    // Add extension registrations, etc. here
    
    m_initialized = true;
}

bool SHArrowsPlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *SHArrowsPlugin::createWidget(QWidget *parent)
{
    return new SHArrows(parent);
}

QString SHArrowsPlugin::name() const
{
    return QLatin1String("SHArrows");
}

QString SHArrowsPlugin::group() const
{
    return QLatin1String("SHCustomPlugins");
}

QIcon SHArrowsPlugin::icon() const
{
    return QIcon(QLatin1String(":/image/arrows.ico"));
}

QString SHArrowsPlugin::toolTip() const
{
    return QLatin1String("arrows");
}

QString SHArrowsPlugin::whatsThis() const
{
    return QLatin1String("this is a arrows.");
}

bool SHArrowsPlugin::isContainer() const
{
    return false;
}

QString SHArrowsPlugin::domXml() const
{
    return QLatin1String("<widget class=\"SHArrows\" name=\"sharrows\">\n"
                             "  <property name=\"geometry\">\n"
                             "   <rect>\n"
                             "    <x>0</x>\n"
                             "    <y>0</y>\n"
                             "    <width>200</width>\n"
                             "    <height>100</height>\n"
                             "   </rect>\n"
                             "  </property>\n"
                             "</widget>\n");}

QString SHArrowsPlugin::includeFile() const
{
    return QLatin1String("SHQtCustom/sharrows.h");
}

