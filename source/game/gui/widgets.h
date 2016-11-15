/* minup - yet another pong-like game
 *
 * Copyright (C) 2005 Leonard Fischer (Crimson-Skies@gmx.de)
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef WIDGETS_H
#define WIDGETS_H

#include <guichan.hpp>

class StringListModel : public gcn::ListModel
{
	public:
		StringListModel() {}
		int getNumberOfElements()
		{
			return mStrings.size();
		}
		std::string getElementAt(int i)
		{
			return mStrings.at(i);
		}
		void add(std::string str)
		{
			mStrings.push_back(str);
		}
	private:
		std::vector<std::string> mStrings;
};


class StringWidget
{
	public:
		StringWidget(){};
		virtual ~StringWidget();
		int getSelected();
		int getNumberOfElements();
		StringListModel* getListModel();
		std::string getElementAt(int i);
		void addString(std::string str);
		virtual void setSelected(int selected){};
		void setListModel(StringListModel* listModel);
		virtual void adjustSize(){};
	protected:
		StringListModel* 	mListModel;
		int mSelected;
};


class Spin : public StringWidget, public gcn::Widget
{
	public:
		Spin();
		virtual~Spin(){};
		virtual void draw(gcn::Graphics* graphics);
		virtual void drawBorder(gcn::Graphics* graphics);
		virtual void logic();
		void setSelected(int selected);
		void moveSelection(int move);
		void adjustSize();
};

class SubMenu : public gcn::KeyListener, public StringWidget, public gcn::Widget
{
	public:

		SubMenu();

		virtual ~SubMenu() {};

		virtual void adjustSize();

		virtual void setSelected(int selected);

		virtual void draw(gcn::Graphics* graphics);

		virtual void drawBorder(gcn::Graphics* graphics);

		virtual void logic();

		virtual void keyPressed(gcn::KeyEvent& keyEvent);

};

#endif
