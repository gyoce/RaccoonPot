#ifndef RP_HPP
#define RP_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include <RP/Game.hpp>
#include <RP/GameOptions.hpp>
#include <RP/RPMacros.hpp>
#include <RP/Types.hpp>

// CORE
#include <RP/Core/Coordinator.hpp>
#include <RP/Core/Scene.hpp>

#include <RP/Core/Components/Transform2.hpp>

#include <RP/Core/Managers/EventManager.hpp>
#include <RP/Core/Managers/GuiManager.hpp>
#include <RP/Core/Managers/ResourceManager.hpp>
#include <RP/Core/Managers/SceneManager.hpp>

#include <RP/Core/Resources/Font.hpp>
#include <RP/Core/Resources/SpriteSheet.hpp>

#include <RP/Core/Systems/System.hpp>

// GUI
#include <RP/Gui/Anchors.hpp>
#include <RP/Gui/AlignItems.hpp>
#include <RP/Gui/GuiButton.hpp>
#include <RP/Gui/GuiButtonText.hpp>
#include <RP/Gui/GuiButtonTexture.hpp>
#include <RP/Gui/GuiButtonTextureText.hpp>
#include <RP/Gui/GuiBuilder.hpp>
#include <RP/Gui/GuiPanel.hpp>
#include <RP/Gui/GuiText.hpp>
#include <RP/Gui/GuiWidget.hpp>

// LOGS
#include <RP/Logs/Log.hpp>

// MATH
#include <RP/Math/Vector2.hpp>

#endif // RP_HPP