#include "shratetable.h"
#include "shratetableplugin.h"

#include <QtPlugin>

SHRateTablePlugin::SHRateTablePlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void SHRateTablePlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;
    
    // Add extension registrations, etc. here
    
    m_initialized = true;
}

bool SHRateTablePlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *SHRateTablePlugin::createWidget(QWidget *parent)
{
    return new SHRateTable(parent);
}

QString SHRateTablePlugin::name() const
{
    return QLatin1String("SHRateTable");
}

QString SHRateTablePlugin::group() const
{
    return QLatin1String("SHCustomPlugins");
}

QIcon SHRateTablePlugin::icon() const
{
    return QIcon(QLatin1String(":/image/rateTable.ico"));
}

QString SHRateTablePlugin::toolTip() const
{
    return QLatin1String("rate table");
}

QString SHRateTablePlugin::whatsThis() const
{
    return QLatin1String("this is a rate table.");
}

bool SHRateTablePlugin::isContainer() const
{
    return false;
}

QString SHRateTablePlugin::domXml() const
{
    return QLatin1String("<widget class=\"SHRateTable\" name=\"shrateTable\">\n"
                             "  <property name=\"geometry\">\n"
                             "   <rect>\n"
                             "    <x>0</x>\n"
                             "    <y>0</y>\n"
                             "    <width>200</width>\n"
                             "    <height>200</height>\n"
                             "   </rect>\n"
                             "  </property>\n"
                             "</widget>\n");}

QString SHRateTablePlugin::includeFile() const
{
    return QLatin1String("SHQtCustom/shratetable.h");
}

