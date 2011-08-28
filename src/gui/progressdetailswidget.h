/***************************************************************************
 *   Copyright (C) 2008 by Volker Lanz <vl@fidra.de>                       *
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
 *   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA            *
 ***************************************************************************/

#if !defined(PROGRESSDETAILSWIDGET__H)

#define PROGRESSDETAILSWIDGET__H

#include "ui_progressdetailswidgetbase.h"

/** @brief Details widget for the ProgressDialog.
	@author vl@fidra.de
*/
class ProgressDetailsWidget : public QWidget, public Ui::ProgressDetailsWidgetBase
{
	Q_OBJECT

	public:
		ProgressDetailsWidget(QWidget* parent) : QWidget(parent) { setupUi(this); }

	public:
		KTextEdit& editReport() { Q_ASSERT(m_EditReport); return *m_EditReport; }
		QPushButton& buttonSave() { Q_ASSERT(m_ButtonSave); return *m_ButtonSave; }
		QPushButton& buttonBrowser() { Q_ASSERT(m_ButtonBrowser); return *m_ButtonBrowser; }
};

#endif