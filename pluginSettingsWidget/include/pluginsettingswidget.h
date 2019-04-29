#ifndef PLUGINSETTINGSWIDGET_H
#define PLUGINSETTINGSWIDGET_H

#include <QObject>
#include "i_wsPlugin.h"
#include "pluginsettingswidget_global.h"

class PLUGINSETTINGSWIDGET_EXPORT pluginSettingsWidget : public QObject, public virtual i_wsPlugin
{
	Q_OBJECT
	Q_INTERFACES(i_wsPlugin)
	Q_PLUGIN_METADATA(IID "pluginSettingsWidget")

public:
	pluginSettingsWidget();
	~pluginSettingsWidget();

	/*!
        Инициализация плагина        
    */
    virtual bool initialize( QObject* wsCore);


	/*!
		Возвращает название плагина
		Используется для механизма зависимостей
	*/
	virtual QString getName() const;


    /*
        Зависимости от других плагинов
    */
    virtual QStringList references() const;


	/*!
		Возвращает иконку плагина
	*/
	virtual QIcon getIcon() const;


	/*!
		Возвращает описание планига
	*/
	virtual QString about() const;

private:

	struct SDATA;
	SDATA* m_data;

private slots:

	/*!
		Отобразить окно настроек
	*/
	void slot_showSettings();
};

#endif // PLUGINSETTINGSWIDGET_H
