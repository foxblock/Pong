
#pragma once

#ifdef NETWORK_SUPPORT
#include <enet/enet.h>
#endif

#ifdef DOWNLOAD_SUPPORT
#include <curl/curl.h>
#endif

#include <allegro5/allegro.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>

#include <string>
#include "../library/maths.h"