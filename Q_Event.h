#ifndef Q_EVENT_H
#define Q_EVENT_H

#include <stdio.h>
#include <unistd.h>
#include <functional>
#include <SDL2/SDL.h>

class Q_Event
{
    public:
        void BindEvent(Uint32 eventType, std::function<void(SDL_Event)> pointer)
        {
            pointers[EventToIndex(eventType)] = pointer;
        }
        Q_Event()
        {
            std::function<void(SDL_Event)> notImplemented = [](SDL_Event) {
                printf("Not Implemented Event\n");
            };

            for(int i = 0; i < 38; i++) {
                pointers[i] = notImplemented;
            }
        }
        Q_Event(std::function<void(SDL_Event)> pointer)
        {
            for(int i = 0; i < 38; i++) {
                pointers[i] = pointer;
            }
        }
        void PoolEvents()
        {
            while(SDL_PollEvent(&event) > 0)
            {
                int x = EventToIndex(event.type);
                pointers[x](event);
			}
        }
        static int EventToIndex(Uint32 eventType)
        {
            int x = 38;
            switch(eventType)
            {
                default:                            //   0
                printf("Uncought event\n");
                x--;
                case SDL_AUDIODEVICEADDED:          //   1
                x--;
                case SDL_AUDIODEVICEREMOVED:        //   2
                x--;
                case SDL_CONTROLLERAXISMOTION:      //   3
                x--;
                case SDL_CONTROLLERBUTTONDOWN:      //   4
                x--;
                case SDL_CONTROLLERBUTTONUP:        //   5
                x--;
                case SDL_CONTROLLERDEVICEADDED:     //   6
                x--;
                case SDL_CONTROLLERDEVICEREMOVED:   //   7
                x--;
                case SDL_CONTROLLERDEVICEREMAPPED:  //   8
                x--;
                case SDL_DOLLARGESTURE:             //   9
                x--;
                case SDL_DOLLARRECORD:              //  10
                x--;
                case SDL_DROPFILE:                  //  11
                x--;
                case SDL_DROPTEXT:                  //  12
                x--;
                case SDL_DROPBEGIN:                 //  13
                x--;
                case SDL_DROPCOMPLETE:              //  14
                x--;
                case SDL_FINGERMOTION:              //  15
                x--;
                case SDL_FINGERDOWN:                //  16
                x--;
                case SDL_FINGERUP:                  //  17
                x--;
                case SDL_KEYDOWN:                   //  18
                x--;
                case SDL_KEYUP:                     //  19
                x--;
                case SDL_JOYAXISMOTION:             //  20
                x--;
                case SDL_JOYBALLMOTION:             //  21
                x--;
                case SDL_JOYHATMOTION:              //  22
                x--;
                case SDL_JOYBUTTONDOWN:             //  23
                x--;
                case SDL_JOYBUTTONUP:               //  24
                x--;
                case SDL_JOYDEVICEADDED:            //  25
                x--;
                case SDL_JOYDEVICEREMOVED:          //  26
                x--;
                case SDL_MOUSEMOTION:               //  27
                x--;
                case SDL_MOUSEBUTTONDOWN:           //  28
                x--;
                case SDL_MOUSEBUTTONUP:             //  29
                x--;
                case SDL_MOUSEWHEEL:                //  30
                x--;
                case SDL_MULTIGESTURE:              //  31
                x--;
                case SDL_QUIT:                      //  32
                x--;
                case SDL_SYSWMEVENT:                //  33
                x--;
                case SDL_TEXTEDITING:               //  34
                x--;
                case SDL_TEXTINPUT:                 //  35
                x--;
                case SDL_USEREVENT:                 //  36
                x--;
                case SDL_WINDOWEVENT:               //  37
                x--;
            }
            return x;
        }
    private:
        std::function<void(SDL_Event)> pointers[38];
        SDL_Event event;
};

#endif