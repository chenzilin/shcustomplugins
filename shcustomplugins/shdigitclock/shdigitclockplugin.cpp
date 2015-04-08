#include <QtPlugin>
#include <QDesignerFormWindowInterface>

#include "shdigitclockplugin.h"
#include "shdigitclock.h"

SHDigitClockPlugin::SHDigitClockPlugin(QObject *parent)
	: QObject(parent)
{
	initialized = false;
}

void SHDigitClockPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
	if (initialized)
		return;

	initialized = true;

}

bool SHDigitClockPlugin::isInitialized() const
{
	return initialized;
}

QWidget *SHDigitClockPlugin::createWidget(QWidget *parent)
{
	return new SHDigitClock(parent);
}

QString SHDigitClockPlugin::name() const
{
	return "SHDigitClock";
}

QString SHDigitClockPlugin::group() const
{
	return "SHCustomPlugins";
}

QIcon SHDigitClockPlugin::icon() const
{
    return QIcon(":/image/digitClock.png");
}

QString SHDigitClockPlugin::toolTip() const
{
	return "";
}

QString SHDigitClockPlugin::whatsThis() const
{
	return "";
}

bool SHDigitClockPlugin::isContainer() const
{
	return false;
}

QString SHDigitClockPlugin::domXml() const
{
	return "<widget class=\"SHDigitClock\" name=\"shdigitClock\">\n"
			" <property name=\"geometry\">\n"
			"  <rect>\n"
			"   <x>0</x>\n"
			"   <y>0</y>\n"
			"   <width>120</width>\n"
			"   <height>50</height>\n"
			"  </rect>\n"
			" </property>\n"
			"</widget>\n";
}

QString SHDigitClockPlugin::includeFile() const
{
	return "SHQtCustom/shdigitclock.h";
}
