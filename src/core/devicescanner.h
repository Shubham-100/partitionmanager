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
 *   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA            *
 ***************************************************************************/

#ifndef DEVICESCANNER_H
#define DEVICESCANNER_H

#include <QThread>

#include "core/libparted.h"

class OperationStack;

/** @brief Thread to scan for all available Devices on this computer.

	This class is used to find all Devices on the computer and to create new Device instances for each of them. It's subclassing QThread to run asynchronously.

	@author vl@fidra.de
*/
class DeviceScanner : public QThread
{
	Q_OBJECT

	public:
		DeviceScanner(OperationStack& ostack);

	public:
		void clear(); /**< clear Devices and the OperationStack */

	signals:
		void progressChanged(const QString& device_node, int progress);
		void devicesChanged();
		void operationsChanged();

	protected:
		virtual void run();

		OperationStack& operationStack() { return m_OperationStack; }
		const OperationStack& operationStack() const { return m_OperationStack; }

		LibParted& libParted() { return m_LibParted; }
		const LibParted& libParted() const { return m_LibParted; }

	private:
		LibParted m_LibParted;
		OperationStack& m_OperationStack;
};

#endif