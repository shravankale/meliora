/* isl_config.h.  Generated from isl_config.h.in by configure.  */
/* isl_config.h.in.  Generated from configure.ac by autoheader.  */

/* Define if HeaderSearchOptions::AddPath takes 4 arguments */
#define ADDPATH_TAKES_4_ARGUMENTS /**/

/* Clang installation prefix */
#define CLANG_PREFIX "/disks/large/home/users/shravank/libs/llvm-14-meliora"

/* Define to sysroot if needed */
/* #undef CLANG_SYSROOT */

/* Define if CompilerInstance::createDiagnostics takes argc and argv */
/* #undef CREATEDIAGNOSTICS_TAKES_ARG */

/* Define if CompilerInstance::createPreprocessor takes TranslationUnitKind */
#define CREATEPREPROCESSOR_TAKES_TUKIND /**/

/* Define if TargetInfo::CreateTargetInfo takes pointer */
/* #undef CREATETARGETINFO_TAKES_POINTER */

/* Define if TargetInfo::CreateTargetInfo takes shared_ptr */
#define CREATETARGETINFO_TAKES_SHARED_PTR /**/

/* Define if CompilerInvocation::CreateFromArgs takes ArrayRef */
#define CREATE_FROM_ARGS_TAKES_ARRAYREF /**/

/* Define if Driver constructor takes default image name */
/* #undef DRIVER_CTOR_TAKES_DEFAULTIMAGENAME */

/* Define to Diagnostic for older versions of clang */
/* #undef DiagnosticsEngine */

/* Define if llvm/ADT/OwningPtr.h exists */
#define HAVE_ADT_OWNINGPTR_H /**/

/* Define if clang/Basic/DiagnosticOptions.h exists */
#define HAVE_BASIC_DIAGNOSTICOPTIONS_H /**/

/* define if the compiler supports basic C++11 syntax */
#define HAVE_CXX11 1

/* Define if Driver constructor takes CXXIsProduction argument */
/* #undef HAVE_CXXISPRODUCTION */

/* Define to 1 if you have the <dlfcn.h> header file. */
#define HAVE_DLFCN_H 1

/* Define to 1 if you have the <inttypes.h> header file. */
#define HAVE_INTTYPES_H 1

/* Define if Driver constructor takes IsProduction argument */
/* #undef HAVE_ISPRODUCTION */

/* Define if clang/Lex/PreprocessorOptions.h exists */
#define HAVE_LEX_PREPROCESSOROPTIONS_H /**/

/* Define if llvm/Option/Arg.h exists */
#define HAVE_LLVM_OPTION_ARG_H /**/

/* Define if SourceManager has a setMainFileID method */
#define HAVE_SETMAINFILEID /**/

/* Define to 1 if you have the <stdint.h> header file. */
#define HAVE_STDINT_H 1

/* Define to 1 if you have the <stdio.h> header file. */
#define HAVE_STDIO_H 1

/* Define to 1 if you have the <stdlib.h> header file. */
#define HAVE_STDLIB_H 1

/* Define to 1 if you have the <strings.h> header file. */
#define HAVE_STRINGS_H 1

/* Define to 1 if you have the <string.h> header file. */
#define HAVE_STRING_H 1

/* Define to 1 if you have the <sys/stat.h> header file. */
#define HAVE_SYS_STAT_H 1

/* Define to 1 if you have the <sys/types.h> header file. */
#define HAVE_SYS_TYPES_H 1

/* Define if llvm/TargetParser/Host.h exists */
/* #undef HAVE_TARGETPARSER_HOST_H */

/* Define to 1 if you have the <unistd.h> header file. */
#define HAVE_UNISTD_H 1

/* Return type of HandleTopLevelDeclReturn */
#define HandleTopLevelDeclContinue true

/* Return type of HandleTopLevelDeclReturn */
#define HandleTopLevelDeclReturn bool

/* Define to Language::C or InputKind::C for newer versions of clang */
#define IK_C Language::C

/* Define to the sub-directory where libtool stores uninstalled libraries. */
#define LT_OBJDIR ".libs/"

/* Name of package */
#define PACKAGE "isl-interface"

/* Define to the address where bug reports for this package should be sent. */
#define PACKAGE_BUGREPORT "isl-development@googlegroups.com"

/* Define to the full name of this package. */
#define PACKAGE_NAME "isl-interface"

/* Define to the full name and version of this package. */
#define PACKAGE_STRING "isl-interface 0"

/* Define to the one symbol short name of this package. */
#define PACKAGE_TARNAME "isl-interface"

/* Define to the home page for this package. */
#define PACKAGE_URL ""

/* Define to the version of this package. */
#define PACKAGE_VERSION "0"

/* Defined if CompilerInstance::setInvocation takes a shared_ptr */
#define SETINVOCATION_TAKES_SHARED_PTR /**/

/* Define to class with setLangDefaults method */
#define SETLANGDEFAULTS CompilerInvocation

/* Define if CompilerInvocation::setLangDefaults takes 5 arguments */
#define SETLANGDEFAULTS_TAKES_5_ARGUMENTS /**/

/* Define to 1 if all of the C90 standard headers exist (not just the ones
   required in a freestanding environment). This macro is provided for
   backward compatibility; new code need not use it. */
#define STDC_HEADERS 1

/* Define if Driver::BuildCompilation takes ArrayRef */
#define USE_ARRAYREF /**/

/* Version number of package */
#define VERSION "0"

/* Define to getParamType for newer versions of clang */
#define getArgType getParamType

/* Define to getHostTriple for older versions of clang */
/* #undef getDefaultTargetTriple */

/* Define to getInstantiationLineNumber for older versions of clang */
/* #undef getExpansionLineNumber */

/* Define to getImmediateInstantiationRange for older versions of clang */
/* #undef getImmediateExpansionRange */

/* Define to getNumParams for newer versions of clang */
#define getNumArgs getNumParams

/* Define to getResultType for older versions of clang */
/* #undef getReturnType */

/* Define to InitializeBuiltins for older versions of clang */
/* #undef initializeBuiltins */
