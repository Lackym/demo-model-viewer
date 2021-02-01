#include "Application.h"
#include <iostream>
#include <exception>
#include "Exceptions.h"
#include "Config.h"

// stb_image required to define it here
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

Config g_config;
Config parseConfig(int argc, char* argv[]);

int main(int argc, char* argv[])
{
    g_config = parseConfig(argc, argv);

    auto app = new Application(g_config.GetModelPath());

    app->Init();

    app->Start();

    app->Shutdown();

    return 0;
}

Config parseConfig(int argc, char* argv[])
{
    std::string appPath = std::string(argv[0]);

    Config params;

    //params.modelPath = "/assets/models/derringer22/derringer.fbx";
    //params.modelPath = "/assets/models/cube.obj";
    params.modelPath = "/assets/models/backpack/Survival_BackPack_2.fbx";
    //params.modelPath = "/assets/models/men/men.fbx";

    params.textures.diffuseName = "1001_albedo.jpg";
    params.textures.specularName = "1001_metallic.jpg";

    //params.textures.diffuseName = "GAP_2DAE03_Moldovan_Alexia_C.png";
    //params.textures.specularName = "GAP_2DAE03_Moldovan_Alexia_M.png";

    params.rootFolder = appPath.substr(0, appPath.find_last_of("\\"));
    params.modelFolder = params.rootFolder
        + params.modelPath.substr(0, params.modelPath.find_last_of("/")) + "/";

    return params;
}