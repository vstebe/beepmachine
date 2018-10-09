#include "playablenote.h"

PlayableNote::PlayableNote(float pitch, float duration)
{
    _pitch = pitch;
    _duration = duration;
}

PlayableNote::PlayableNote(float duration)
{
    _pitch = -1;
    _duration = duration;
}

PlayableNote::PlayableNote()
{
    _pitch = -1;
}

float PlayableNote::getPitch() {
    return _pitch;
}
float PlayableNote::getDuration() {
    return _duration;
}
