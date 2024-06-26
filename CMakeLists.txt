cmake_minimum_required(VERSION 3.28)
project(BurbageEngine)

add_library(gainput 
    "The-Forge/Common_3/Application/ThirdParty/OpenSource/gainput/lib/source/gainput/gainput.cpp"
    "The-Forge/Common_3/Application/ThirdParty/OpenSource/gainput/lib/source/gainput/GainputAllocator.cpp"
    "The-Forge/Common_3/Application/ThirdParty/OpenSource/gainput/lib/source/gainput/GainputInputDeltaState.cpp"
    "The-Forge/Common_3/Application/ThirdParty/OpenSource/gainput/lib/source/gainput/GainputInputDevice.cpp"
    "The-Forge/Common_3/Application/ThirdParty/OpenSource/gainput/lib/source/gainput/GainputInputManager.cpp"
    "The-Forge/Common_3/Application/ThirdParty/OpenSource/gainput/lib/source/gainput/GainputInputMap.cpp"
    "The-Forge/Common_3/Application/ThirdParty/OpenSource/gainput/lib/source/gainput/GainputInputState.cpp"
    "The-Forge/Common_3/Application/ThirdParty/OpenSource/gainput/lib/source/gainput/GainputMapFilters.cpp"
    "The-Forge/Common_3/Application/ThirdParty/OpenSource/gainput/lib/source/gainput/hid/GainputHID.cpp"
    "The-Forge/Common_3/Application/ThirdParty/OpenSource/gainput/lib/source/gainput/hid/GainputHIDWhitelist.cpp"
    "The-Forge/Common_3/Application/ThirdParty/OpenSource/gainput/lib/source/gainput/hid/hidparsers/HIDParserPS4Controller.cpp"
    "The-Forge/Common_3/Application/ThirdParty/OpenSource/gainput/lib/source/gainput/hid/hidparsers/HIDParserPS4Controller.cpp"
    "The-Forge/Common_3/Application/ThirdParty/OpenSource/gainput/lib/source/gainput/hid/hidparsers/HIDParserPS4Controller.h"
    "The-Forge/Common_3/Application/ThirdParty/OpenSource/gainput/lib/source/gainput/hid/hidparsers/HIDParserPS5Controller.cpp"
    "The-Forge/Common_3/Application/ThirdParty/OpenSource/gainput/lib/source/gainput/hid/hidparsers/HIDParserPS5Controller.cpp"
    "The-Forge/Common_3/Application/ThirdParty/OpenSource/gainput/lib/source/gainput/hid/hidparsers/HIDParserPS5Controller.h"
    "The-Forge/Common_3/Application/ThirdParty/OpenSource/gainput/lib/source/gainput/hid/hidparsers/HIDParserSwitchController.cpp"
    "The-Forge/Common_3/Application/ThirdParty/OpenSource/gainput/lib/source/gainput/hid/hidparsers/HIDParserSwitchController.h"
    "The-Forge/Common_3/Application/ThirdParty/OpenSource/gainput/lib/source/gainput/keyboard/GainputInputDeviceKeyboard.cpp"
    "The-Forge/Common_3/Application/ThirdParty/OpenSource/gainput/lib/source/gainput/mouse/GainputInputDeviceMouse.cpp"
    "The-Forge/Common_3/Application/ThirdParty/OpenSource/gainput/lib/source/gainput/pad/GainputInputDevicePad.cpp"
    "The-Forge/Common_3/Application/ThirdParty/OpenSource/gainput/lib/source/gainput/touch/GainputInputDeviceTouch.cpp"
    $<$<PLATFORM_ID:Windows>:
    "The-Forge/Common_3/Application/ThirdParty/OpenSource/gainput/lib/source/hidapi/windows/hid.c"
    >
    $<$<PLATFORM_ID:Linux>:
    "The-Forge/Common_3/Application/ThirdParty/OpenSource/gainput/lib/source/hidapi/linux/hid.c"
    >
)

if (MSVC)
    target_compile_definitions (gainput PRIVATE -D_CRT_SECURE_NO_WARNINGS)
endif ()

target_include_directories(gainput PUBLIC
    "The-Forge/Common_3/Application/ThirdParty/OpenSource/gainput/lib/source"
)

target_compile_features(gainput PRIVATE cxx_std_14)
set_property(TARGET gainput PROPERTY CXX_STANDARD 14)
set_property(TARGET gainput PROPERTY CXX_STANDARD_REQUIRED ON)

add_library(the-forge
    "The-Forge/Common_3/Application/CameraController.cpp"
    "The-Forge/Common_3/Application/Fonts/FontSystem.cpp"
    "The-Forge/Common_3/Application/Fonts/stbtt.cpp"
    "The-Forge/Common_3/Application/InputSystem.cpp"
    "The-Forge/Common_3/Application/Profiler/GpuProfiler.cpp"
    "The-Forge/Common_3/Application/Profiler/ProfilerBase.cpp"
    "The-Forge/Common_3/Application/RemoteControl.cpp"
    "The-Forge/Common_3/Application/Screenshot.cpp"
    "The-Forge/Common_3/Application/ThirdParty/OpenSource/imgui/imgui_demo.cpp"
    "The-Forge/Common_3/Application/ThirdParty/OpenSource/imgui/imgui_draw.cpp"
    "The-Forge/Common_3/Application/ThirdParty/OpenSource/imgui/imgui_tables.cpp"
    "The-Forge/Common_3/Application/ThirdParty/OpenSource/imgui/imgui_widgets.cpp"
    "The-Forge/Common_3/Application/ThirdParty/OpenSource/imgui/imgui.cpp"
    "The-Forge/Common_3/Application/UI/UI.cpp"
    "The-Forge/Common_3/Game/Scripting/LuaManager.cpp"
    "The-Forge/Common_3/Game/Scripting/LuaManagerImpl.cpp"
    "The-Forge/Common_3/Game/Scripting/LuaSystem.cpp"
    "The-Forge/Common_3/Game/ThirdParty/OpenSource/lua-5.3.5/src/lapi.c"
    "The-Forge/Common_3/Game/ThirdParty/OpenSource/lua-5.3.5/src/lauxlib.c"
    "The-Forge/Common_3/Game/ThirdParty/OpenSource/lua-5.3.5/src/lbaselib.c"
    "The-Forge/Common_3/Game/ThirdParty/OpenSource/lua-5.3.5/src/lbitlib.c"
    "The-Forge/Common_3/Game/ThirdParty/OpenSource/lua-5.3.5/src/lcode.c"
    "The-Forge/Common_3/Game/ThirdParty/OpenSource/lua-5.3.5/src/lcorolib.c"
    "The-Forge/Common_3/Game/ThirdParty/OpenSource/lua-5.3.5/src/lctype.c"
    "The-Forge/Common_3/Game/ThirdParty/OpenSource/lua-5.3.5/src/ldblib.c"
    "The-Forge/Common_3/Game/ThirdParty/OpenSource/lua-5.3.5/src/ldebug.c"
    "The-Forge/Common_3/Game/ThirdParty/OpenSource/lua-5.3.5/src/ldo.c"
    "The-Forge/Common_3/Game/ThirdParty/OpenSource/lua-5.3.5/src/ldump.c"
    "The-Forge/Common_3/Game/ThirdParty/OpenSource/lua-5.3.5/src/lfunc.c"
    "The-Forge/Common_3/Game/ThirdParty/OpenSource/lua-5.3.5/src/lgc.c"
    "The-Forge/Common_3/Game/ThirdParty/OpenSource/lua-5.3.5/src/linit.c"
    "The-Forge/Common_3/Game/ThirdParty/OpenSource/lua-5.3.5/src/liolib.c"
    "The-Forge/Common_3/Game/ThirdParty/OpenSource/lua-5.3.5/src/llex.c"
    "The-Forge/Common_3/Game/ThirdParty/OpenSource/lua-5.3.5/src/lmathlib.c"
    "The-Forge/Common_3/Game/ThirdParty/OpenSource/lua-5.3.5/src/lmem.c"
    "The-Forge/Common_3/Game/ThirdParty/OpenSource/lua-5.3.5/src/loadlib.c"
    "The-Forge/Common_3/Game/ThirdParty/OpenSource/lua-5.3.5/src/lobject.c"
    "The-Forge/Common_3/Game/ThirdParty/OpenSource/lua-5.3.5/src/lopcodes.c"
    "The-Forge/Common_3/Game/ThirdParty/OpenSource/lua-5.3.5/src/loslib.c"
    "The-Forge/Common_3/Game/ThirdParty/OpenSource/lua-5.3.5/src/lparser.c"
    "The-Forge/Common_3/Game/ThirdParty/OpenSource/lua-5.3.5/src/lstate.c"
    "The-Forge/Common_3/Game/ThirdParty/OpenSource/lua-5.3.5/src/lstring.c"
    "The-Forge/Common_3/Game/ThirdParty/OpenSource/lua-5.3.5/src/lstrlib.c"
    "The-Forge/Common_3/Game/ThirdParty/OpenSource/lua-5.3.5/src/ltable.c"
    "The-Forge/Common_3/Game/ThirdParty/OpenSource/lua-5.3.5/src/ltablib.c"
    "The-Forge/Common_3/Game/ThirdParty/OpenSource/lua-5.3.5/src/ltm.c"
    "The-Forge/Common_3/Game/ThirdParty/OpenSource/lua-5.3.5/src/lundump.c"
    "The-Forge/Common_3/Game/ThirdParty/OpenSource/lua-5.3.5/src/lutf8lib.c"
    "The-Forge/Common_3/Game/ThirdParty/OpenSource/lua-5.3.5/src/lvm.c"
    "The-Forge/Common_3/Game/ThirdParty/OpenSource/lua-5.3.5/src/lzio.c"
    "The-Forge/Common_3/Graphics/CommonShaderReflection.cpp"
    "The-Forge/Common_3/Graphics/Direct3D11/Direct3D11.cpp"
    "The-Forge/Common_3/Graphics/Direct3D11/Direct3D11ShaderReflection.cpp"
    "The-Forge/Common_3/Graphics/Direct3D12/Direct3D12.cpp"
    "The-Forge/Common_3/Graphics/Direct3D12/Direct3D12Hooks.cpp"
    "The-Forge/Common_3/Graphics/Direct3D12/Direct3D12Raytracing.cpp"
    "The-Forge/Common_3/Graphics/Direct3D12/Direct3D12ShaderReflection.cpp"
    "The-Forge/Common_3/Graphics/GraphicsConfig.cpp"
    "The-Forge/Common_3/Graphics/PickRenderingAPI.cpp"
    "The-Forge/Common_3/Graphics/ThirdParty/OpenSource/SPIRV_Cross/spirv_cfg.cpp"
    "The-Forge/Common_3/Graphics/ThirdParty/OpenSource/SPIRV_Cross/spirv_cpp.cpp"
    "The-Forge/Common_3/Graphics/ThirdParty/OpenSource/SPIRV_Cross/spirv_cross_parsed_ir.cpp"
    "The-Forge/Common_3/Graphics/ThirdParty/OpenSource/SPIRV_Cross/spirv_cross_util.cpp"
    "The-Forge/Common_3/Graphics/ThirdParty/OpenSource/SPIRV_Cross/spirv_cross.cpp"
    "The-Forge/Common_3/Graphics/ThirdParty/OpenSource/SPIRV_Cross/spirv_glsl.cpp"
    "The-Forge/Common_3/Graphics/ThirdParty/OpenSource/SPIRV_Cross/spirv_hlsl.cpp"
    "The-Forge/Common_3/Graphics/ThirdParty/OpenSource/SPIRV_Cross/spirv_msl.cpp"
    "The-Forge/Common_3/Graphics/ThirdParty/OpenSource/SPIRV_Cross/spirv_parser.cpp"
    "The-Forge/Common_3/Graphics/ThirdParty/OpenSource/SPIRV_Cross/spirv_reflect.cpp"
    "The-Forge/Common_3/Graphics/ThirdParty/OpenSource/SPIRV_Cross/SpirvTools.cpp"
    "The-Forge/Common_3/Graphics/Vulkan/Vulkan.cpp"
    "The-Forge/Common_3/Graphics/Vulkan/VulkanRaytracing.cpp"
    "The-Forge/Common_3/Graphics/Vulkan/VulkanShaderReflection.cpp"
    "The-Forge/Common_3/OS/CPUConfig.cpp"
    "The-Forge/Common_3/OS/WindowSystem/WindowSystem.cpp"
    "The-Forge/Common_3/Resources/ResourceLoader/ResourceLoader.cpp"
    "The-Forge/Common_3/Tools/Network/Network.c"
    "The-Forge/Common_3/Tools/ReloadServer/ReloadClient.cpp"
    "The-Forge/Common_3/Utilities/FileSystem/FileSystem.c"
    "The-Forge/Common_3/Utilities/FileSystem/SystemRun.c"
    "The-Forge/Common_3/Utilities/Log/Log.c"
    "The-Forge/Common_3/Utilities/Math/Algorithms.c"
    "The-Forge/Common_3/Utilities/Math/StbDs.c"
    "The-Forge/Common_3/Utilities/MemoryTracking/MemoryTracking.c"
    "The-Forge/Common_3/Utilities/ThirdParty/OpenSource/bstrlib/bstrlib.c"
    "The-Forge/Common_3/Utilities/ThirdParty/OpenSource/lz4/lz4.c"
    "The-Forge/Common_3/Utilities/ThirdParty/OpenSource/lz4/lz4.h"
    "The-Forge/Common_3/Utilities/ThirdParty/OpenSource/lz4/lz4hc.c"
    "The-Forge/Common_3/Utilities/ThirdParty/OpenSource/lz4/lz4hc.h"
    "The-Forge/Common_3/Utilities/ThirdParty/OpenSource/zstd/common/bits.h"
    "The-Forge/Common_3/Utilities/ThirdParty/OpenSource/zstd/common/bitstream.h"
    "The-Forge/Common_3/Utilities/ThirdParty/OpenSource/zstd/common/compiler.h"
    "The-Forge/Common_3/Utilities/ThirdParty/OpenSource/zstd/common/cpu.h"
    "The-Forge/Common_3/Utilities/ThirdParty/OpenSource/zstd/common/debug.c"
    "The-Forge/Common_3/Utilities/ThirdParty/OpenSource/zstd/common/debug.h"
    "The-Forge/Common_3/Utilities/ThirdParty/OpenSource/zstd/common/entropy_common.c"
    "The-Forge/Common_3/Utilities/ThirdParty/OpenSource/zstd/common/error_private.c"
    "The-Forge/Common_3/Utilities/ThirdParty/OpenSource/zstd/common/error_private.h"
    "The-Forge/Common_3/Utilities/ThirdParty/OpenSource/zstd/common/fse_decompress.c"
    "The-Forge/Common_3/Utilities/ThirdParty/OpenSource/zstd/common/fse.h"
    "The-Forge/Common_3/Utilities/ThirdParty/OpenSource/zstd/common/huf.h"
    "The-Forge/Common_3/Utilities/ThirdParty/OpenSource/zstd/common/mem.h"
    "The-Forge/Common_3/Utilities/ThirdParty/OpenSource/zstd/common/pool.c"
    "The-Forge/Common_3/Utilities/ThirdParty/OpenSource/zstd/common/pool.h"
    "The-Forge/Common_3/Utilities/ThirdParty/OpenSource/zstd/common/portability_macros.h"
    "The-Forge/Common_3/Utilities/ThirdParty/OpenSource/zstd/common/threading.c"
    "The-Forge/Common_3/Utilities/ThirdParty/OpenSource/zstd/common/threading.h"
    "The-Forge/Common_3/Utilities/ThirdParty/OpenSource/zstd/common/xxhash.c"
    "The-Forge/Common_3/Utilities/ThirdParty/OpenSource/zstd/common/xxhash.h"
    "The-Forge/Common_3/Utilities/ThirdParty/OpenSource/zstd/common/zstd_common.c"
    "The-Forge/Common_3/Utilities/ThirdParty/OpenSource/zstd/common/zstd_deps.h"
    "The-Forge/Common_3/Utilities/ThirdParty/OpenSource/zstd/common/zstd_internal.h"
    "The-Forge/Common_3/Utilities/ThirdParty/OpenSource/zstd/common/zstd_trace.h"
    "The-Forge/Common_3/Utilities/ThirdParty/OpenSource/zstd/decompress/huf_decompress_amd64.S"
    "The-Forge/Common_3/Utilities/ThirdParty/OpenSource/zstd/decompress/huf_decompress.c"
    "The-Forge/Common_3/Utilities/ThirdParty/OpenSource/zstd/decompress/zstd_ddict.c"
    "The-Forge/Common_3/Utilities/ThirdParty/OpenSource/zstd/decompress/zstd_ddict.h"
    "The-Forge/Common_3/Utilities/ThirdParty/OpenSource/zstd/decompress/zstd_decompress_block.c"
    "The-Forge/Common_3/Utilities/ThirdParty/OpenSource/zstd/decompress/zstd_decompress_block.h"
    "The-Forge/Common_3/Utilities/ThirdParty/OpenSource/zstd/decompress/zstd_decompress_internal.h"
    "The-Forge/Common_3/Utilities/ThirdParty/OpenSource/zstd/decompress/zstd_decompress.c"
    "The-Forge/Common_3/Utilities/Timer.c"

    $<$<PLATFORM_ID:Windows>:
    "The-Forge/Common_3/OS/ThirdParty/OpenSource/cpu_features/src/impl_x86_windows.c"
    "The-Forge/Common_3/OS/Windows/WindowsBase.cpp"
    "The-Forge/Common_3/OS/Windows/WindowsFileSystem.cpp"
    "The-Forge/Common_3/OS/Windows/WindowsLog.c"
    "The-Forge/Common_3/OS/Windows/WindowsStackTraceDump.cpp"
    "The-Forge/Common_3/OS/Windows/WindowsThread.c"
    "The-Forge/Common_3/OS/Windows/WindowsTime.c"
    "The-Forge/Common_3/OS/Windows/WindowsToolsFileSystem.cpp"
    "The-Forge/Common_3/OS/Windows/WindowsWindow.cpp"
    >

    $<$<PLATFORM_ID:Linux>:
    "The-Forge/Common_3/OS/ThirdParty/OpenSource/cpu_features/src/impl_x86_linux_or_android.c"
    "The-Forge/Common_3/OS/Linux/LinuxBase.cpp"
    "The-Forge/Common_3/OS/Linux/LinuxFileSystem.c"
    "The-Forge/Common_3/OS/Linux/LinuxLog.c"
    "The-Forge/Common_3/OS/Linux/LinuxThread.c"
    "The-Forge/Common_3/OS/Linux/LinuxTime.c"
    "The-Forge/Common_3/OS/Linux/LinuxToolsFileSystem.c"
    "The-Forge/Common_3/OS/Linux/LinuxWindow.cpp"
    "The-Forge/Common_3/Utilities/FileSystem/UnixFileSystem.c"
    >
)

if (MSVC)
    target_compile_definitions (the-forge PRIVATE -D_UNICODE -DUNICODE)
    target_compile_definitions (the-forge PRIVATE -D_CRT_SECURE_NO_WARNINGS)
endif ()

if(LINUX)
    set(THREADS_PREFER_PTHREAD_FLAG ON)
    find_package(PkgConfig REQUIRED)
    find_package(X11 REQUIRED)
    find_package(Threads REQUIRED)

    pkg_check_modules(GTK REQUIRED gtk+-3.0 ) 
    pkg_check_modules(UDEV REQUIRED libudev)
    include_directories ( ${GTK_INCLUDE_DIRS} )

    target_include_directories(the-forge PRIVATE 
        ${GTK_INCLUDE_DIRS}
        ${X11_INCLUDE_DIRS}
    )

    target_link_libraries(the-forge PRIVATE 
        ${GTK_LIBRARIES}
        ${X11_LIBRARIES}
        ${X11_Xrandr_LIB}
        Threads::Threads
        ${CMAKE_DL_LIBS}
    )

    target_link_libraries(gainput PRIVATE
        ${UDEV_LIBRARIES}
    )
endif()

add_executable(BurbageEngine
    "src/burbage.cpp"
    "src/include/burbage.h"
    "src/ecs.cpp"
    "src/include/ecs.h"
)

target_link_libraries(BurbageEngine PRIVATE  
    the-forge
    gainput
)

if (WIN32)
    target_link_libraries(BurbageEngine PRIVATE 
        "${CMAKE_CURRENT_SOURCE_DIR}/The-Forge/Common_3/OS/ThirdParty/OpenSource/winpixeventruntime/bin/WinPixEventRuntime.lib"
        "${CMAKE_CURRENT_SOURCE_DIR}/The-Forge/Common_3/Graphics/ThirdParty/OpenSource/ags/ags_lib/lib/amd_ags_x64.lib"
        "${CMAKE_CURRENT_SOURCE_DIR}/The-Forge/Common_3/Graphics/ThirdParty/OpenSource/nvapi/amd64/nvapi64.lib"
        "${CMAKE_CURRENT_SOURCE_DIR}/The-Forge/Common_3/Graphics/ThirdParty/OpenSource/DirectXShaderCompiler/lib/x64/dxcompiler.lib"
        XInput 
    )

    add_custom_target(CopyDlls ALL      
        COMMAND ${CMAKE_COMMAND} -E make_directory "$<TARGET_FILE_DIR:BurbageEngine>/"      
        COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_SOURCE_DIR}/The-Forge/Common_3/OS/ThirdParty/OpenSource/winpixeventruntime/bin/WinPixEventRuntime.dll" "$<TARGET_FILE_DIR:BurbageEngine>/"
        COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_SOURCE_DIR}/The-Forge/Common_3/Graphics/ThirdParty/OpenSource/ags/ags_lib/lib/amd_ags_x64.dll" "$<TARGET_FILE_DIR:BurbageEngine>/"
        COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_SOURCE_DIR}/The-Forge/Common_3/Graphics/ThirdParty/OpenSource/DirectXShaderCompiler/bin/x64/dxcompiler.dll" "$<TARGET_FILE_DIR:BurbageEngine>/"
        COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_SOURCE_DIR}/The-Forge/Common_3/Graphics/ThirdParty/OpenSource/DirectXShaderCompiler/bin/x64/dxil.dll" "$<TARGET_FILE_DIR:BurbageEngine>/"
    )
elseif (LINUX)
    add_custom_target(CopyVulkan ALL
        COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_SOURCE_DIR}/The-Forge/Common_3/Graphics/ThirdParty/OpenSource/VulkanSDK/bin/Linux/VkLayer_khronos_validation.json" "$<TARGET_FILE_DIR:BurbageEngine>"
        COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_SOURCE_DIR}/The-Forge/Common_3/Graphics/ThirdParty/OpenSource/VulkanSDK/bin/Linux/libVkLayer_khronos_validation.so" "$<TARGET_FILE_DIR:BurbageEngine>"
    )
endif()

target_compile_features(BurbageEngine PRIVATE cxx_std_20)
set_property(TARGET BurbageEngine PROPERTY CXX_STANDARD 20)
set_property(TARGET BurbageEngine PROPERTY CXX_STANDARD_REQUIRED ON)

if (MSVC)
    # set_property(TARGET BurbageEngine PROPERTY WIN32_EXECUTABLE ON)
    target_compile_options(BurbageEngine PRIVATE /Zc:__cplusplus)
endif ()

target_include_directories(BurbageEngine PRIVATE
    "The-Forge/Common_3/Application/Interfaces"
    "The-Forge/Common_3/Application/ThirdParty/OpenSource/gainput/lib/source"
    "The-Forge/Common_3/Graphics/Interfaces"
    "The-Forge/Common_3/Graphics/ThirdParty/OpenSource/DirectXShaderCompiler/inc"
    "The-Forge/Common_3/OS/Interfaces"
    "The-Forge/Common_3/Resources/ResourceLoader/Interfaces"
    "The-Forge/Common_3/Utilities"
    "The-Forge/Common_3/Utilities/Interfaces"
    "The-Forge/Common_3/Utilities/ThirdParty/OpenSource/Nothings/"
    ${VULKAN_HEADERS_INCLUDE_DIRS}
)

target_link_directories(BurbageEngine PRIVATE
    "The-Forge/Common_3/Graphics/ThirdParty/OpenSource/ags/ags_lib/lib"
    "The-Forge/Common_3/Graphics/ThirdParty/OpenSource/DirectXShaderCompiler/lib/x64"
    "The-Forge/Common_3/Graphics/ThirdParty/OpenSource/nvapi/amd64"
    "The-Forge/Common_3/OS/ThirdParty/OpenSource/winpixeventruntime/bin"
)

add_custom_target(CopyGpuCfg ALL
    COMMAND ${CMAKE_COMMAND} -E make_directory "$<TARGET_FILE_DIR:BurbageEngine>/GPUCfg/"
    COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_SOURCE_DIR}/The-Forge/Examples_3/Unit_Tests/src/01_Transformations/GPUCfg/gpu.cfg" "$<TARGET_FILE_DIR:BurbageEngine>/GPUCfg/"
)

add_custom_target(CopyFonts ALL
    COMMAND ${CMAKE_COMMAND} -E make_directory "$<TARGET_FILE_DIR:BurbageEngine>/Fonts/TitilliumText/"
    COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_SOURCE_DIR}/The-Forge/Examples_3/Unit_Tests/UnitTestResources/Fonts/TitilliumText/TitilliumText-Bold.otf" "$<TARGET_FILE_DIR:BurbageEngine>/Fonts/TitilliumText/"
)

if(WIN32)
    set(Python3_ROOT_DIR "${CMAKE_CURRENT_SOURCE_DIR}/The-Forge/Tools/python-3.6.0-embed-amd64")
endif()

find_package(Python3 COMPONENTS Interpreter)

function(compile_shaders)
    set(oneValueArgs TARGET SHADER_LIST)
    cmake_parse_arguments(COMPILE_SHADERS "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    add_custom_target(${COMPILE_SHADERS_TARGET} ALL
        COMMAND ${CMAKE_COMMAND} -E make_directory "$<TARGET_FILE_DIR:BurbageEngine>/Shaders"
        COMMAND ${CMAKE_COMMAND} -E make_directory "$<TARGET_FILE_DIR:BurbageEngine>/CompiledShaders"
        COMMAND "${Python3_EXECUTABLE}"
            "${CMAKE_CURRENT_SOURCE_DIR}/The-Forge/Common_3/Tools/ForgeShadingLanguage/fsl.py"
            "-dShaders" "-bCompiledShaders" "-l $<$<PLATFORM_ID:Windows>:DIRECT3D12> VULKAN" --compile --verbose
            ${COMPILE_SHADERS_SHADER_LIST}
            WORKING_DIRECTORY "$<TARGET_FILE_DIR:BurbageEngine>"
)
endfunction()

compile_shaders(
    TARGET UiShader
    SHADER_LIST "${CMAKE_CURRENT_SOURCE_DIR}/The-Forge/Common_3/Application/UI/Shaders/FSL/UI_ShaderList.fsl"
)

compile_shaders(
    TARGET FontShader
    SHADER_LIST "${CMAKE_CURRENT_SOURCE_DIR}/The-Forge/Common_3/Application/Fonts/Shaders/FSL/Fonts_ShaderList.fsl"
)

compile_shaders(
    TARGET ProjectShader
    SHADER_LIST "${CMAKE_CURRENT_SOURCE_DIR}/shaders/FSL/ShaderList.fsl"
)