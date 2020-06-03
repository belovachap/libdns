#pragma once

#if defined(LIBDNS_STATIC)         // Using static.
#  define LIBDNS_SYMEXPORT
#elif defined(LIBDNS_STATIC_BUILD) // Building static.
#  define LIBDNS_SYMEXPORT
#elif defined(LIBDNS_SHARED)       // Using shared.
#  ifdef _WIN32
#    define LIBDNS_SYMEXPORT __declspec(dllimport)
#  else
#    define LIBDNS_SYMEXPORT
#  endif
#elif defined(LIBDNS_SHARED_BUILD) // Building shared.
#  ifdef _WIN32
#    define LIBDNS_SYMEXPORT __declspec(dllexport)
#  else
#    define LIBDNS_SYMEXPORT
#  endif
#else
// If none of the above macros are defined, then we assume we are being used
// by some third-party build system that cannot/doesn't signal the library
// type. Note that this fallback works for both static and shared but in case
// of shared will be sub-optimal compared to having dllimport.
//
#  define LIBDNS_SYMEXPORT         // Using static or shared.
#endif
