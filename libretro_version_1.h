/*  RetroArch - A frontend for libretro.
 *  Copyright (C) 2010-2014 - Hans-Kristian Arntzen
 *  Copyright (C) 2011-2016 - Daniel De Matteis
 *  Copyright (C) 2012-2015 - Michael Lelli
 *
 *  RetroArch is free software: you can redistribute it and/or modify it under the terms
 *  of the GNU General Public License as published by the Free Software Found-
 *  ation, either version 3 of the License, or (at your option) any later version.
 *
 *  RetroArch is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 *  without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 *  PURPOSE.  See the GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License along with RetroArch.
 *  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _RETRO_IMPLEMENTATION_V1_H
#define _RETRO_IMPLEMENTATION_V1_H

#ifdef __cplusplus
extern "C" {
#endif

#include <boolean.h>

#include "libretro.h"

enum
{
   /* Polling is performed before call to retro_run */
   POLL_TYPE_EARLY = 0,
   /* Polling is performed when requested. */
   POLL_TYPE_NORMAL,
   /* Polling is performed on first call to 
    * retro_input_state per frame. */
   POLL_TYPE_LATE
};

enum core_ctl_state
{
   CORE_CTL_NONE = 0,

   CORE_CTL_INIT,

   CORE_CTL_DEINIT,

   CORE_CTL_SET_CBS,

   CORE_CTL_SET_CBS_REWIND,

   /* Runs the core for one frame. */
   CORE_CTL_RUN
};

typedef struct retro_callbacks
{
   retro_video_refresh_t frame_cb;
   retro_audio_sample_t sample_cb;
   retro_audio_sample_batch_t sample_batch_cb;
   retro_input_state_t state_cb;
   retro_input_poll_t poll_cb;
} retro_callbacks_t;

extern retro_callbacks_t retro_ctx;

bool core_ctl(enum core_ctl_state state, void *data);

#ifdef __cplusplus
}
#endif

#endif
