#pragma once

#include "LM.h"
#include "Utilities/TSingleton.h"

//#define LUMOS_LIMIT_FRAMERATE

namespace Lumos
{
    class Timer;

    class LUMOS_EXPORT Engine : public TSingleton<Engine>
    {
        friend class TSingleton<Engine>;

    public:
        Engine();
        ~Engine();

        u32  GetFPS() const { return m_FramesPerSecond;  }
        u32  GetUPS() const { return m_UpdatesPerSecond; }
        float GetFrametime() const { return m_Frametime;  }
        float TargetFrameRate() const { return m_MaxFramesPerSecond; }

        void SetFPS(u32 fps) { m_FramesPerSecond = fps;  }
        void SetUPS(u32 ups) { m_UpdatesPerSecond = ups; }
        void SetFrametime(float frameTime) { m_Frametime = frameTime;  }
        void SetTargetFrameRate(float targetFPS) { m_MaxFramesPerSecond = targetFPS; }

    private:

        u32  m_UpdatesPerSecond;
        u32  m_FramesPerSecond;
        float m_Frametime = 0.1f;
        float m_MaxFramesPerSecond;
    };
}
