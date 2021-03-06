/*
 *  Quackle -- Crossword game artificial intelligence and analysis tool
 *  Copyright (C) 2005-2014 Jason Katz-Brown and John O'Laughlin.
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef QUACKER_HISTORY_H
#define QUACKER_HISTORY_H

#include <QMap>

#include <game.h>

#include "view.h"

class QTableWidget;
class QTableWidgetItem;
class QVBoxLayout;

namespace Quackle
{
	class Game;
	class GamePosition;
	class History;
}

class History : public HistoryView
{
Q_OBJECT

public:
	History(QWidget *parent = 0);
	virtual ~History()
	{
	}

public slots:
	virtual void historyChanged(const Quackle::History &history);

private slots:
	void itemActivated(QTableWidgetItem *item);

protected:
	QTableWidgetItem *createItem(const Quackle::GamePosition &position, const Quackle::Player &currentPlayer);
	QTableWidgetItem *createPlainItem(const QString &contentString);
	QMap<Quackle::HistoryLocation, QTableWidgetItem *> m_locationMap;

	QVBoxLayout *m_vlayout;
	QTableWidget *m_tableWidget;
};

#endif
