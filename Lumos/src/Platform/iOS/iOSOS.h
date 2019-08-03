#include "LM.h"
#include "Core/OS.h"

namespace Lumos
{
    class iOSOS : public OS
    {
    public:
        iOSOS();
        ~iOSOS();

        void Run() override {}
        
        void* GetIOSView() const { return m_IOSView; }
        void SetIOSView(void* view) { m_IOSView = view; }
        
        String GetAssetPath() const;
        
        void OnFrame();
        void OnQuit();
        void OnKeyPressed(u32 keycode);
        
    private:
        
        void* m_IOSView;
    };
}
