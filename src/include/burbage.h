#ifndef  BURBAGE_h
#define BURBAGE_H

#include <IApp.h>
#include <IProfiler.h>
#include <IGraphics.h>
#include <ILog.h>
#include <ITime.h>
#include <IResourceLoader.h>


namespace Burbage {
	class App : public IApp {
	public:
		bool Init();
		void Exit();
		bool Load(ReloadDesc* pReloadDesc);
		void Unload(ReloadDesc* pReloadDesc);
		void Update(float deltaTime);
		void Draw();
		const char* GetName() { return "burbage"; }

	private:
		Renderer* pRenderer;
	};
}

#endif // ! BURBAGE_h
