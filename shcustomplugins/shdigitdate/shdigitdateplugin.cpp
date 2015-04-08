#include "shdigitdateplugin.h"
#include "shdigitdate.h"

#include <QtPlugin>
#include <QDesignerFormWindowInterface>

SHDigitDatePlugin::SHDigitDatePlugin(QObject *parent)
	: QObject(parent)
{
	initialized = false;
}

void SHDigitDatePlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
	if (initialized)
		return;

	initialized = true;

}

bool SHDigitDatePlugin::isInitialized() const
{
	return initialized;
}

QWidget *SHDigitDatePlugin::createWidget(QWidget *parent)
{
    return new SHDigitDate(parent);
}

QString SHDigitDatePlugin::name() const
{
    return "SHDigitDate";
}

QString SHDigitDatePlugin::group() const
{
	return "SHCustomPlugins";
}

QIcon SHDigitDatePlugin::icon() const
{
    return QIcon(":/image/digitdate.png");
}

QString SHDigitDatePlugin::toolTip() const
{
	return "";
}

QString SHDigitDatePlugin::whatsThis() const
{
	return "";
}

bool SHDigitDatePlugin::isContainer() const
{
	return false;
}

QString SHDigitDatePlugin::domXml() const
{
    return "<widget class=\"SHDigitDate\" name=\"shdigitDate\">\n"
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

QString SHDigitDatePlugin::includeFile() const
{
    return "SHQtCustom/shdigitdate.h";
}
