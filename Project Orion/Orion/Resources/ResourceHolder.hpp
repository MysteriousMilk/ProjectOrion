#ifndef _RESOURCEHOLDER_HPP_
#define _RESOURCEHOLDER_HPP_

#include <map>
#include <string>
#include <memory>
#include <stdexcept>
#include <cassert>

namespace Orion
{
	namespace Resources
	{

		template <typename Resource, typename Identifier>
		class ResourceHolder
		{
		public:
			void						load(Identifier id, const std::string& filename);

			template <typename Parameter>
			void						load(Identifier id, const std::string& filename, const Parameter& secondParam);

			Resource&					get(Identifier id);
			const Resource&				get(Identifier id) const;

			bool						contains(Identifier id);

		private:
			void						insertResource(Identifier id, std::unique_ptr<Resource> resource);


		private:
			std::map<Identifier, std::unique_ptr<Resource>>	mResourceMap;
		};

#include "ResourceHolder.inl"

	}
}

#endif // _RESOURCEHOLDER_HPP_