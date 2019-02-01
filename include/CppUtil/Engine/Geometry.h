#ifndef _GEOMETRY_H_
#define _GEOMETRY_H_

#include <CppUtil/Engine/Component.h>

namespace CppUtil {
	namespace Engine {
		class Primitive;

		class Geometry : public Component {
			COMPONENT_SETUP(Geometry)
		public:
			Geometry(Basic::Ptr<SObj> sobj = nullptr, Basic::Ptr<Primitive> primitive = nullptr)
				: Component(sobj), primitive(primitive) { }

			Basic::Ptr<Primitive> GetPrimitive() { return primitive; }
			void SetPrimitive(Basic::Ptr<Primitive> primitive) { this->primitive = primitive; }

		private:
			Basic::Ptr<Primitive> primitive;
		};
	}
}

#endif//!_GEOMETRY_H_