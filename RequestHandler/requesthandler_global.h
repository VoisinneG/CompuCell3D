#ifndef REQUESTHANDLER_GLOBAL_H
#define REQUESTHANDLER_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(REQUESTHANDLER_LIBRARY)
#  define REQUESTHANDLERSHARED_EXPORT Q_DECL_EXPORT
#else
#  define REQUESTHANDLERSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // REQUESTHANDLER_GLOBAL_H
