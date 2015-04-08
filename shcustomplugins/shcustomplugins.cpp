#include "./shcustomplugins.h"
#include "./shdigitdate/shdigitdateplugin.h"
#include "./sharrows/sharrowsplugin.h"
#include "./shslider/shsliderplugin.h"
#include "./shratetable/shratetableplugin.h"
#include "./shdigitclock/shdigitclockplugin.h"
#include "./shanalogclock/shanalogclockplugin.h"

SHCustomPlugins::SHCustomPlugins(QObject *parent)
    : QObject(parent)
{
    m_widgets.append(new SHDigitClockPlugin(this));
    m_widgets.append(new SHDigitDatePlugin(this));
    m_widgets.append(new SHArrowsPlugin(this));
    m_widgets.append(new SHAnalogClockPlugin(this));
    m_widgets.append(new SHRateTablePlugin(this));
    m_widgets.append(new SHSliderPlugin(this));
}

QList<QDesignerCustomWidgetInterface*> SHCustomPlugins::customWidgets() const
{
    return m_widgets;
}
