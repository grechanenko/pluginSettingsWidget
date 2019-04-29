#include <QIcon>
#include <QAction>
#include <QMenu>
#include <QApplication>

#include "pluginsettingswidget.h"
#include "wgtSettings.h"
#include "i_wsCore.h"

struct pluginSettingsWidget::SDATA
{
	i_wsCore* wsCore = Q_NULLPTR;
};
// ----------------------------------------------------------------
pluginSettingsWidget::pluginSettingsWidget()
{
	m_data = Q_NULLPTR;
	m_data = new SDATA;
}
// ----------------------------------------------------------------
pluginSettingsWidget::~pluginSettingsWidget()
{
	if (m_data != Q_NULLPTR)
	{
		m_data->wsCore = Q_NULLPTR;

		delete m_data;
		m_data = Q_NULLPTR;
	}
}
// ----------------------------------------------------------------
bool pluginSettingsWidget::initialize(QObject* wsCore)
{
	if (m_data == Q_NULLPTR)
		return false;

	if (wsCore == Q_NULLPTR)
		return false;

	m_data->wsCore = qobject_cast<i_wsCore*>(wsCore);
	if (m_data->wsCore == Q_NULLPTR)
		return false;

	

	QMenu* menuFile = Q_NULLPTR;
	menuFile = m_data->wsCore->getMenu("MenuFile");
	if (menuFile != Q_NULLPTR)
	{
		QAction* actionSettings = new QAction(tr("Settings..."));
		actionSettings->setObjectName("actionSettings");
		connect(actionSettings, SIGNAL(triggered()), SLOT(slot_showSettings()));
		menuFile->addAction(actionSettings);
	}
	return true;
}
// ----------------------------------------------------------------
QString pluginSettingsWidget::getName() const
{
	return QString("WidgetSettings");
}
// ----------------------------------------------------------------
QStringList pluginSettingsWidget::references() const
{
	return QStringList("MenuFile");
}
// ----------------------------------------------------------------
QIcon pluginSettingsWidget::getIcon() const
{
	return QIcon();
}
// ----------------------------------------------------------------
QString pluginSettingsWidget::about() const
{
	return QString(tr("Widget settings"));
}
// ----------------------------------------------------------------
void pluginSettingsWidget::slot_showSettings()
{
	if (m_data != Q_NULLPTR)
	{
		if (m_data->wsCore != Q_NULLPTR)
		{
			QWidget* activeWindow = qApp->activeWindow();
			if (activeWindow != Q_NULLPTR)
			{
				WGTSettings* wgtSetting = Q_NULLPTR;
				wgtSetting = new WGTSettings(m_data->wsCore, activeWindow);
				if (wgtSetting != Q_NULLPTR)
				{
					if (wgtSetting->exec() == QDialog::Accepted)
					{

					}
					delete wgtSetting;
					wgtSetting = Q_NULLPTR;
				}
			}
		}
	}
}
// ----------------------------------------------------------------