/***************************************************************************
 *   Copyright (C) 2007,2009,2010 by Rick L. Vinyard, Jr.                  *
 *   rvinyard@cs.nmsu.edu                                                  *
 *                                                                         *
 *   This file is part of the dbus-cxx library.                            *
 *                                                                         *
 *   The dbus-cxx library is free software; you can redistribute it and/or *
 *   modify it under the terms of the GNU General Public License           *
 *   version 3 as published by the Free Software Foundation.               *
 *                                                                         *
 *   The dbus-cxx library is distributed in the hope that it will be       *
 *   useful, but WITHOUT ANY WARRANTY; without even the implied warranty   *
 *   of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU   *
 *   General Public License for more details.                              *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this software. If not see <http://www.gnu.org/licenses/>.  *
 ***************************************************************************/
#ifndef DBUSCXX_DBUS_H
#define DBUSCXX_DBUS_H

#if !(__cplusplus >= 201703L)
#error "dbus-cxx requires at least C++17.  Check your compiler flags(-std=c++17 for GCC/clang, /Zc:__cplusplus /std:c++17 for MSVC)"
#endif

#include <dbus-cxx/dbus-cxx-config.h>
#include <dbus-cxx/callmessage.h>
#include <dbus-cxx/connection.h>
#include <dbus-cxx/signal.h>
#include <dbus-cxx/dispatcher.h>
#include <dbus-cxx/enums.h>
#include <dbus-cxx/error.h>
#include <dbus-cxx/errormessage.h>
#include <dbus-cxx/interface.h>
#include <dbus-cxx/interfaceproxy.h>
#include <dbus-cxx/messageappenditerator.h>
#include <dbus-cxx/message.h>
#include <dbus-cxx/messageiterator.h>
#include <dbus-cxx/methodbase.h>
#include <dbus-cxx/methodproxybase.h>
#include <dbus-cxx/object.h>
#include <dbus-cxx/objectproxy.h>
#include <dbus-cxx/pendingcall.h>
#include <dbus-cxx/returnmessage.h>
#include <dbus-cxx/signalbase.h>
#include <dbus-cxx/signalmessage.h>
#include <dbus-cxx/signalproxy.h>
#include <dbus-cxx/signature.h>
#include <dbus-cxx/signatureiterator.h>
#include <dbus-cxx/utility.h>
#include <dbus-cxx/variant.h>
#include <dbus-cxx/filedescriptor.h>
#include <dbus-cxx/simplelogger_defs.h>
#include <dbus-cxx/standalonedispatcher.h>
#include <dbus-cxx/propertyproxy.h>
#include <dbus-cxx/property.h>

#endif
