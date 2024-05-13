#include "include/burbage.h"
#include "include/ecs.h"

bool Burbage::App::Init()
{
	
    // FILE PATHS
    fsSetPathForResourceDir(pSystemFileIO, RM_CONTENT, RD_SHADER_BINARIES, "CompiledShaders");
    fsSetPathForResourceDir(pSystemFileIO, RM_CONTENT, RD_GPU_CONFIG, "GPUCfg");
    fsSetPathForResourceDir(pSystemFileIO, RM_CONTENT, RD_TEXTURES, "Textures");
    fsSetPathForResourceDir(pSystemFileIO, RM_CONTENT, RD_FONTS, "Fonts");
    fsSetPathForResourceDir(pSystemFileIO, RM_DEBUG, RD_SCREENSHOTS, "Screenshots");
    fsSetPathForResourceDir(pSystemFileIO, RM_CONTENT, RD_SCRIPTS, "Scripts");
    fsSetPathForResourceDir(pSystemFileIO, RM_DEBUG, RD_DEBUG, "Debug");

    // window and renderer setup
    RendererDesc settings;
    memset(&settings, 0, sizeof(settings));
    initRenderer(GetName(), &settings, &pRenderer);
    // check for init success
    if (!pRenderer)
        return false;

    return true;
}

void Burbage::App::Exit()
{
    exitProfiler();
    exitResourceLoaderInterface(pRenderer);
    exitRenderer(pRenderer);
    pRenderer = NULL;
}

bool Burbage::App::Load(ReloadDesc* pReloadDesc)
{
    return true;
}

void Burbage::App::Unload(ReloadDesc* pReloadDesc)
{
}

void Burbage::App::Update(float deltaTime)
{
}

void Burbage::App::Draw()
{
}


DEFINE_APPLICATION_MAIN(Burbage::App);