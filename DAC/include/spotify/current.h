#pragma once

#include "lib/spotify/playback.h"

#include <QString>

namespace spt
{
    struct Current
    {
        lib::spt::playback playback;
        QString context;
    };
}
