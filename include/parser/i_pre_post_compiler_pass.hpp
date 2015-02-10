#ifndef CION_I_PRE_POST_COMPILER_PASS_HEADER
#define CION_I_PRE_POST_COMPILER_PASS_HEADER

namespace cion {
	class IASTVisitor;

	class IPrePostCompilerPass {
	public:
		virtual IASTVisitor & pre_pass() = 0;
		virtual IASTVisitor & post_pass() = 0;
	};

} // namespace cion

#endif // CION_I_PRE_POST_COMPILER_PASS_HEADER
