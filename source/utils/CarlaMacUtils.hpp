/*
 * Carla macOS utils
 * Copyright (C) 2018-2022 Filipe Coelho <falktx@falktx.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * For a full copy of the GNU General Public License see the doc/GPL.txt file.
 */

#ifndef CARLA_MAC_UTILS_HPP_INCLUDED
#define CARLA_MAC_UTILS_HPP_INCLUDED

#ifndef CARLA_OS_MAC
# error wrong include
#endif

#ifdef __MAC_10_12
# define Component CocoaComponent
# define MemoryBlock CocoaMemoryBlock
# define Point CocoaPoint
#endif

#import <Foundation/Foundation.h>

#undef Component
#undef MemoryBlock
#undef Point

#include "CarlaBackend.h"
 
CARLA_BACKEND_START_NAMESPACE

// --------------------------------------------------------------------------------------------------------------------

/*
 * ...
 */
void initStandaloneApplication();

/*
 * ...
 */
const char* findBinaryInBundle(const char* const bundleDir);

/*
 * ...
 */
bool removeFileFromQuarantine(const char* const filename);

// --------------------------------------------------------------------------------------------------------------------

/*
 * ...
 */
class AutoNSAutoreleasePool {
public:
    AutoNSAutoreleasePool();
    ~AutoNSAutoreleasePool();

private:
    void* const pool;
};

// --------------------------------------------------------------------------------------------------------------------

struct BundleLoader {
    CFBundleRef ref;
    CFBundleRefNum refNum;

    BundleLoader() noexcept;
    ~BundleLoader();
    bool load(const char* const filename);
};

// --------------------------------------------------------------------------------------------------------------------

CARLA_BACKEND_END_NAMESPACE

#endif // CARLA_MAC_UTILS_HPP_INCLUDED
