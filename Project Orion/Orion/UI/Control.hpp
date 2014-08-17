#ifndef _CONTROL_HPP_
#define _CONTROL_HPP_

#include <memory>
#include <SFML\Graphics.hpp>
#include "..\Core\DrawableEntity.hpp"
#include "..\Resources\ResourceManager.hpp"

using namespace std;
using namespace Orion::Resources;

namespace Orion
{
	namespace UI
	{

		class Control
		{
		public:
			Control();
			Control(string);
			~Control();

			bool				IsVisible();
			void				SetVisible(bool);

			int					GetAlpha();
			void				SetAlpha(int);

			shared_ptr<Control> GetParent();
			void				SetParent(shared_ptr<Control>);

			void				SetPosition(const sf::Vector2f&);
			void				SetSize(const sf::Vector2f&);
			void				SetColor(const sf::Color&);

			virtual void		Update();
			virtual void		Draw(sf::RenderWindow&);

		protected:
			string					mTextureRef;
			sf::IntRect				mControlRect;
			shared_ptr<Control>		mParent;
			bool					mVisible;
			sf::Color				mColor;
		};

	}
}

#endif //_CONTROL_HPP_