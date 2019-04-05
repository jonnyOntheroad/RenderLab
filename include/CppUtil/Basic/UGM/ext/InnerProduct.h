#ifndef _CPPUTIL_BASIC_MATH_UGM_EXT_INNER_PRODUCT_H_
#define _CPPUTIL_BASIC_MATH_UGM_EXT_INNER_PRODUCT_H_

#include <CppUtil/Basic/UGM/ext/InnerProduct_Base.h>

namespace CppUtil {
	namespace Basic {
		namespace EXT {
			template<int N, typename T, InnerProductType innerProductType, typename BaseT, typename ImplT>
			class InnerProduct : public InnerProduct_Base<N, T, innerProductType, BaseT, ImplT> {
			public:
				using InnerProduct_Base<N, T, innerProductType, BaseT, ImplT>::InnerProduct_Base;

			public:
				const ImplT Dot(const ImplT & v) const {
					return Dot(*static_cast<const ImplT*>(this), v);
				}

				T Norm() const {
					return Dot(*static_cast<const ImplT*>(this));
				}

				const ImplT Normalize() const {
					return (*this) / Norm();
				}

				ImplT & NormalizeSelf() {
					return (*this) /= Norm();
				}
			};
		}
	}

}


#endif // !_CPPUTIL_BASIC_MATH_UGM_EXT_INNER_PRODUCT_H_
