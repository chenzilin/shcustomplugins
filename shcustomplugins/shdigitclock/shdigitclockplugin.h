#ifndef SHDIGITCLOCKPLUGIN_H
#define SHDIGITCLOCKPLUGIN_H

#include<QtGui>
#include <QDesignerCustomWidgetInterface>

class SHDigitClockPlugin : public QObject, public QDesignerCustomWidgetInterface
{
	Q_OBJECT
	Q_INTERFACES(QDesignerCustomWidgetInterface)

public:
	SHDigitClockPlugin(QObject *parent = 0);

	bool isContainer() const;
	bool isInitialized() const;
	QIcon icon() const;
	QString domXml() const;
	QString group() const;
	QString includeFile() const;
	QString name() const;
	QString toolTip() const;
	QString whatsThis() const;
	QWidget *createWidget(QWidget *parent);
	void initialize(QDesignerFormEditorInterface *core);

private:
	bool initialized;
};

#endif
