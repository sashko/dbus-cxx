/***************************************************************************
 *   Copyright (C) 2007,2008,2009 by Rick L. Vinyard, Jr.                  *
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

#ifndef DBUSUTILITY_H
#define DBUSUTILITY_H

#include <dbus/dbus.h>
#include <dbus-cxx/pointer.h>

#define DBUS_CXX_PARAM_LIMIT 7

#ifdef DBUS_CXX_DEBUG_ENABLED
  #include <iostream>

 #define DEBUG_OUT(x,y) if (DEBUG) std::cout << x << " " << pthread_self() << ": " << y << std::endl
 #define DBUS_CXX_DEBUG(x) std::cout << pthread_self() << ": " << x << std::endl
//   #define DEBUG_OUT(x,y) ;
//   #define DBUS_CXX_DEBUG(x) ;
#else
  #define DEBUG_OUT(x,y) ;
  #define DBUS_CXX_DEBUG(x) ;
#endif

#define DBUS_CXX_INTROSPECTABLE_INTERFACE "org.freedesktop.DBus.Introspectable"

/**
 * \def DBUS_CXX_ITERATOR_SUPPORT(CppType,DBusType)
 * Provides support for unsupported types that can be cast to DBus supported types
 *
 * This macro provides message iterator and introspection support for types that are
 * not supported by the DBus native types, but can be \c static_cast<> to a DBus
 * native type. Typically, this is an enum.
 *
 * @param CppType The unsupported type. Must be able to static_cast<> to DBusType
 *
 * @param DBusType One of the types inherently supported by dbus-cxx
 *
 * Example supporting an enum as a 32-bit int:
 * \code
 * typedef MyEnum { ZERO, ONE, TWO, THREE } MyEnum;
 * 
 * DBUS_CXX_ITERATOR_SUPPORT( MyEnum, uint32_t )
 * \endcode
 */
#define DBUS_CXX_ITERATOR_SUPPORT( CppType, DBusType )                                                \
  inline                                                                                              \
  DBus::MessageIterator& operator>>(DBus::MessageIterator& __msgiter, CppType& __cpptype)             \
  {                                                                                                   \
    DBusType __dbustype;                                                                              \
    __msgiter >> __dbustype;                                                                          \
    __cpptype = static_cast< CppType >( __dbustype );                                                 \
    return __msgiter;                                                                                 \
  }                                                                                                   \
                                                                                                      \
  inline                                                                                              \
  DBus::MessageAppendIterator& operator<<(DBus::MessageAppendIterator& __msgiter, CppType& __cpptype) \
  {                                                                                                   \
    __msgiter << static_cast< DBusType >( __cpptype );                                                \
    return __msgiter;                                                                                 \
  }                                                                                                   \
                                                                                                      \
  namespace DBus {                                                                                    \
    template<> inline std::string signature< CppType >() { return signature< DBusType >(); }          \
  }


namespace DBus
{

  extern dbus_int32_t connection_weak_pointer_slot;

  void init(bool threadsafe=true);
  
  bool initialized();

  class Connection;
  
  DBusCxxPointer<Connection> connection(DBusConnection * c);

}

#endif
