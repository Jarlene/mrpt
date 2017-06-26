/* +---------------------------------------------------------------------------+
   |                     Mobile Robot Programming Toolkit (MRPT)               |
   |                          http://www.mrpt.org/                             |
   |                                                                           |
   | Copyright (c) 2005-2017, Individual contributors, see AUTHORS file        |
   | See: http://www.mrpt.org/Authors - All rights reserved.                   |
   | Released under BSD License. See details in http://www.mrpt.org/License    |
   +---------------------------------------------------------------------------+ */
#pragma once
#include <QWidget>

#include <memory>


class QListWidgetItem;
namespace Ui
{
class CConfigWidget;
}

class CConfigWidget: public QWidget
{
	Q_OBJECT
public:
	CConfigWidget(QWidget *parent = nullptr);
	virtual ~CConfigWidget();

signals:
	void updateConfig(QString configName);

private slots:
	void openConfig();
	void saveConfig();
	void addMap();
	void currentConfigChanged(QListWidgetItem *current, QListWidgetItem *);

private:
	enum TypeOfConfig
	{
		General = 0,
		PointsMap = 1,
		Occupancy = 2,
		Landmarks = 3,
		Beacon = 4,
		GasGrid = 5
	};
	std::unique_ptr<Ui::CConfigWidget> m_ui;
};
