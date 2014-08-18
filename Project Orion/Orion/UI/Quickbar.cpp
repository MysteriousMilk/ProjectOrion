#include "Quickbar.hpp"

namespace Orion
{
	namespace UI
	{
		Quickbar::Quickbar(int slots)
		{
			sf::RectangleShape drawRect;
			drawRect.setSize(sf::Vector2f(32, 32));

			mToolbarTexture.create(slots * 32, 32);
			mToolbarTexture.clear(sf::Color::Transparent);

			drawRect.setPosition(sf::Vector2f(0, 0));
			drawRect.setTexture(&ResourceManager::getInstance().Textures.get("ToolbarLeft"));
			mToolbarTexture.draw(drawRect);

			for (int i = 1; i < slots - 1; i++)
			{
				drawRect.setPosition(sf::Vector2f(i*32.0f, 0));
				drawRect.setTexture(&ResourceManager::getInstance().Textures.get("ToolbarCenter"));
				mToolbarTexture.draw(drawRect);
			}

			drawRect.setPosition(sf::Vector2f((slots - 1) * 32.0f, 0));
			drawRect.setTexture(&ResourceManager::getInstance().Textures.get("ToolbarRight"));
			mToolbarTexture.draw(drawRect);

			mToolbarTexture.display();

			SetSize(static_cast<sf::Vector2f>(mToolbarTexture.getSize()));
		}

		Quickbar::~Quickbar()
		{

		}

		void Quickbar::Add(shared_ptr<QuickbarItem> ctrl)
		{
			float x = mControlRect.left + (32 * ctrl->GetSlot()) + 4;
			float y = mControlRect.top + 4;
			ctrl->SetPosition(sf::Vector2f(x, y));
			ctrl->SetAlpha(this->GetAlpha());

			mItems.push_back(ctrl);
			sort(mItems.begin(), mItems.end(), SortQuickbar);
		}

		void Quickbar::ProcessEvents(const sf::Event& e)
		{
			for (auto iterator = mItems.begin(); iterator != mItems.end(); ++iterator)
			{
				iterator->get()->ProcessEvents(e);
			}
			Control::ProcessEvents(e);
		}

		void Quickbar::Update()
		{
			for (auto iterator = mItems.begin(); iterator != mItems.end(); ++iterator)
			{
				iterator->get()->Update();
			}
		}

		void Quickbar::Draw(sf::RenderWindow& window)
		{
			sf::RectangleShape drawRect;
			drawRect.setSize(static_cast<sf::Vector2f>(mToolbarTexture.getSize()));
			drawRect.setPosition(sf::Vector2f((float)mControlRect.left, (float)mControlRect.top));
			drawRect.setTexture(&mToolbarTexture.getTexture());
			drawRect.setFillColor(mColor);
			window.draw(drawRect);

			for (auto iterator = mItems.begin(); iterator != mItems.end(); ++iterator)
			{
				iterator->get()->Draw(window);
			}
		}

		bool SortQuickbar(shared_ptr<QuickbarItem> one, shared_ptr<QuickbarItem> two)
		{
			return one->GetSlot() < two->GetSlot();
		}
	}
}