/*
 * Carla Plugin Host
 * Copyright (C) 2011-2023 Filipe Coelho <falktx@falktx.com>
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

#pragma once

#include "CarlaBackend.h"

#ifdef __cplusplus
using CARLA_BACKEND_NAMESPACE::PluginType;
extern "C" {
#endif

// --------------------------------------------------------------------------------------------------------------------

typedef struct {
    const char* command;
    const char* name;
    const char* labelSetup;
} JackAppDialogResults;

typedef struct _HostSettings {
    bool showPluginBridges;
    bool showWineBridges;
    bool useSystemIcons;
    bool wineAutoPrefix;
    const char* wineExecutable;
    const char* wineFallbackPrefix;
} HostSettings;

typedef struct {
    uint build;
    uint type;
    uint hints;
    const char* category;
    const char* filename;
    const char* name;
    const char* label;
    const char* maker;
    uint64_t uniqueId;
    uint audioIns;
    uint audioOuts;
    uint cvIns;
    uint cvOuts;
    uint midiIns;
    uint midiOuts;
    uint parameterIns;
    uint parameterOuts;
} PluginListDialogResults;

struct PluginListDialog;

// --------------------------------------------------------------------------------------------------------------------

CARLA_PLUGIN_EXPORT void
carla_frontend_createAndExecAboutJuceDialog(void* parent);

CARLA_PLUGIN_EXPORT const JackAppDialogResults*
carla_frontend_createAndExecJackAppDialog(void* parent, const char* projectFilename);

CARLA_PLUGIN_EXPORT PluginListDialog*
carla_frontend_createPluginListDialog(void* parent, const HostSettings* hostSettings);

CARLA_PLUGIN_EXPORT void
carla_frontend_destroyPluginListDialog(PluginListDialog* dialog);

// TODO get favorites

CARLA_PLUGIN_EXPORT void
carla_frontend_setPluginListDialogPath(PluginListDialog* dialog, int ptype, const char* path);

CARLA_PLUGIN_EXPORT const PluginListDialogResults*
carla_frontend_execPluginListDialog(PluginListDialog* dialog);

// CARLA_PLUGIN_EXPORT const PluginListDialogResults*
// carla_frontend_createAndExecPluginListDialog(void* parent, const HostSettings* hostSettings);

// --------------------------------------------------------------------------------------------------------------------

#ifdef __cplusplus
}
#endif
