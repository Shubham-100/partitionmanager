/***************************************************************************
 *   Copyright (C) 2010 by Volker Lanz <vl@fidra.de>                       *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.          *
 ***************************************************************************/

#if !defined(CREATEPARTITIONTABLEWIDGET__H)

#define CREATEPARTITIONTABLEWIDGET__H

#include "ui_createpartitiontablewidgetbase.h"

#include <QWidget>
#include <QRadioButton>
#include <QLabel>

class CreatePartitionTableWidget : public QWidget, public Ui::CreatePartitionTableWidgetBase
{
	Q_OBJECT

	public:
		CreatePartitionTableWidget(QWidget* parent);

	public:
		QRadioButton& radioMSDOS() { return *m_RadioMSDOS; }
		const QRadioButton& radioMSDOS() const { return *m_RadioMSDOS; }

		QRadioButton& radioMSDOSVista() { return *m_RadioMSDOSVista; }
		const QRadioButton& radioMSDOSVista() const { return *m_RadioMSDOSVista; }

		QRadioButton& radioGPT() { return *m_RadioGPT; }
		const QRadioButton& radioGPT() const { return *m_RadioGPT; }

		QLabel& iconLabel() { return *m_IconLabel; }
};

#endif