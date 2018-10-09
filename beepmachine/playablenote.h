#ifndef PLAYABLENOTE_H
#define PLAYABLENOTE_H


class PlayableNote
{
public:
    PlayableNote(float pitch, float duration);
    PlayableNote(float duration);
    PlayableNote();
    float getPitch();
    float getDuration();

private:
    float _pitch;
    float _duration;
};

#endif // PLAYABLENOTE_H
