#include "widgets.h"

StringWidget::~StringWidget()
{
	if(mListModel)
		delete mListModel;
};

int StringWidget::getNumberOfElements()
{
	if(mListModel)
		return mListModel->getNumberOfElements();
	else
		return -1;
};

void StringWidget::setListModel(StringListModel* listModel)
{
	if(mListModel);
	delete mListModel;
	mListModel = listModel;
	setSelected(-1);
}

std::string StringWidget::getElementAt(int i)
{
	if(mListModel)
		return mListModel->getElementAt(i);
	else
		return 0;
};
void StringWidget::addString(std::string str)
{
	if(mListModel)
		mListModel->add(str);
	adjustSize();
};

int StringWidget::getSelected()
{
	return mSelected;
}

StringListModel* StringWidget::getListModel()
{
	return mListModel;
}

Spin::Spin()
{
	mSelected = -1;
	mListModel = NULL;
	setWidth(150);
	setFocusable(false);
	mListModel = new StringListModel;
};

void Spin::draw(gcn::Graphics* graphics)
{
	graphics->setColor(getBackgroundColor());
	graphics->fillRectangle(gcn::Rectangle(0, 0, getWidth(), getHeight()));

	if (mListModel == NULL)
		return;

	graphics->setColor(getForegroundColor());
	graphics->setFont(getFont());

	if(0 <= mSelected && mSelected < mListModel->getNumberOfElements())
		graphics->drawText(mListModel->getElementAt(mSelected), 1, 0);
};

void Spin::adjustSize()
{
	setHeight(getFont()->getHeight());
};

void Spin::logic()
{
	adjustSize();
};

void Spin::setSelected(int selected)
{
	if (mListModel == NULL)
		mSelected = -1;
	else
	{
		if (selected < 0)
			mSelected = -1;
		else if (selected >= mListModel->getNumberOfElements())
			mSelected = mListModel->getNumberOfElements() - 1;
		else
			mSelected = selected;
	};

	gcn::BasicContainer *par = (gcn::BasicContainer*) getParent();
	if (par == NULL)
		return;

	gcn::Rectangle scroll;

	scroll.height = getFont()->getHeight();
	par->showWidgetPart(this, scroll);

}

void Spin::drawBorder(gcn::Graphics* graphics)
{
	gcn::Color faceColor = getBaseColor();
	gcn::Color highlightColor, shadowColor;
	int alpha = getBaseColor().a;
	int width = getWidth() + getBorderSize() * 2 - 1;
	int height = getHeight() + getBorderSize() * 2 - 1;
	highlightColor = faceColor + 0x303030;
	highlightColor.a = alpha;
	shadowColor = faceColor - 0x303030;
	shadowColor.a = alpha;
	unsigned int i;
	for (i = 0; i < getBorderSize(); ++i)
	{
		graphics->setColor(shadowColor);
		graphics->drawLine(i,i, width - i, i);
		graphics->drawLine(i,i + 1, i, height - i - 1);
		graphics->setColor(highlightColor);
		graphics->drawLine(width - i,i + 1, width - i, height - i);
		graphics->drawLine(i,height - i, width - i - 1, height - i);
	}
};

void Spin::moveSelection(int move)
{
	if (mListModel == NULL)
		mSelected = -1;
	else
	{
		int i = mSelected + move;
		if(i < 0)
			setSelected(mListModel->getNumberOfElements()-1);
		else if( i >= mListModel->getNumberOfElements())
			setSelected(0);
		else
			setSelected(i);
	}
};

SubMenu::SubMenu()
{
	mSelected = -1;
	mListModel = new StringListModel;
	setWidth(150);
	setFocusable(true);

	addKeyListener(this);
}

void SubMenu::draw(gcn::Graphics* graphics)
{
	graphics->setColor(getBackgroundColor());
	graphics->fillRectangle(gcn::Rectangle(0, 0, getWidth(), getHeight()));

	if (mListModel == NULL)
	{
		return;
	}

	graphics->setColor(getForegroundColor());
	graphics->setFont(getFont());

	int i, fontHeight;
	int y = 0;

	fontHeight = getFont()->getHeight();

	for (i = 0; i < mListModel->getNumberOfElements(); ++i)
	{
		if (i == mSelected)
		{
			graphics->drawRectangle(gcn::Rectangle(0, y, getWidth(), fontHeight));
		}

		graphics->drawText(mListModel->getElementAt(i), 1, y);

		y += fontHeight;
	}
}

void SubMenu::drawBorder(gcn::Graphics* graphics)
{
	gcn::Color faceColor = getBaseColor();
	gcn::Color highlightColor, shadowColor;
	int alpha = getBaseColor().a;
	int width = getWidth() + getBorderSize() * 2 - 1;
	int height = getHeight() + getBorderSize() * 2 - 1;
	highlightColor = faceColor + 0x303030;
	highlightColor.a = alpha;
	shadowColor = faceColor - 0x303030;
	shadowColor.a = alpha;

	unsigned int i;
	for (i = 0; i < getBorderSize(); ++i)
	{
		graphics->setColor(shadowColor);
		graphics->drawLine(i,i, width - i, i);
		graphics->drawLine(i,i + 1, i, height - i - 1);
		graphics->setColor(highlightColor);
		graphics->drawLine(width - i,i + 1, width - i, height - i);
		graphics->drawLine(i,height - i, width - i - 1, height - i);
	}
}

void SubMenu::logic()
{
	adjustSize();
}

void SubMenu::setSelected(int selected)
{
	if (mListModel == NULL)
	{
		mSelected = -1;
	}
	else
	{
		if (selected < 0)
		{
			mSelected = -1;
		}
		else if (selected >= mListModel->getNumberOfElements())
		{
			mSelected = mListModel->getNumberOfElements() - 1;
		}
		else
		{
			mSelected = selected;
		}

		gcn::BasicContainer *par = getParent();
		if (par == NULL)
		{
			return;
		}

		gcn::Rectangle scroll;

		if (mSelected < 0)
		{
			scroll.y = 0;
		}
		else
		{
			scroll.y = getFont()->getHeight() * mSelected;
		}

		scroll.height = getFont()->getHeight();
		par->showWidgetPart(this, scroll);
	}
}

void SubMenu::keyPressed(gcn::KeyEvent& keyEvent)
{
	gcn::Key key = keyEvent.getKey();

	if (key.getValue() == gcn::Key::ENTER || key.getValue() == gcn::Key::SPACE)
	{
		generateAction();
		keyEvent.consume();
	}
	else if (key.getValue() == gcn::Key::UP)
	{
		setSelected(mSelected - 1);

		if (mSelected == -1)
		{
         setSelected(getListModel()->getNumberOfElements() - 1);
		}

		keyEvent.consume();
	}
	else if (key.getValue() == gcn::Key::DOWN)
	{
		if (getSelected() == getListModel()->getNumberOfElements() - 1)
		{
			setSelected(0);
		}
		else
		{
			setSelected(getSelected() + 1);
		}

		keyEvent.consume();
	}
}

void SubMenu::adjustSize()
{
	if (mListModel != NULL)
	{
		setHeight(getFont()->getHeight() * mListModel->getNumberOfElements());
	}
}
