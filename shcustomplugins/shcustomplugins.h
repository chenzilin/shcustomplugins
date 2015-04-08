#ifndef SHCUSTOMPLUGINS_H
#define SHCUSTOMPLUGINS_H

#include <QtPlugin>
#include <QtDesigner>

class SHCustomPlugins : public QObject, public QDesignerCustomWidgetCollectionInterface
{
    Q_OBJECT
    Q_INTERFACES(QDesignerCustomWidgetCollectionInterface)
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QDesignerCustomWidgetCollectionInterface.SHCustomPlugins")
public:
    explicit SHCustomPlugins(QObject *parent = 0);
    
    virtual QList<QDesignerCustomWidgetInterface*> customWidgets() const;
    
private:
    QList<QDesignerCustomWidgetInterface*> m_widgets;
};

#endif
