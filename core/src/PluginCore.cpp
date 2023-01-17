#include "PluginCore.hpp"
#include "ComponentFactory.hpp"
#include "SerializableObjectFactory.hpp"
#include "polymorph/engine/api/plugin/Symbols.hpp"
#include "ACollider2dComponent.hpp"

namespace polymorph::engine::api
{
    PluginCore::PluginCore(config::XmlNode &data, Engine &game,
                           std::string PluginsPath)
            : APlugin(data, game, PluginsPath)
    {

    }
    void PluginCore::preUpdateInternalSystems(std::shared_ptr<Scene> &scene)
    {
    }

    void PluginCore::updateInternalSystems(std::shared_ptr<Scene> &scene)
    {
        auto colliders = scene->getComponentsInScene<physics2D::ACollider2dComponent>();

        for (auto iterator = colliders.begin();
             iterator != colliders.end(); ++ iterator)
        {
            for (auto normal_iterator = iterator + 1;
                 normal_iterator != colliders.end(); ++normal_iterator)
            {
                (*iterator)->setColliderPosition();
                (*normal_iterator)->setColliderPosition();
                if ((*iterator)->enabled)
                    physics2D::ACollider2dComponent::checkCollision(*iterator, *normal_iterator);
                if (_game.isExiting() || _game.getSceneManager().isSceneUnloaded())
                    return;
                if ((*normal_iterator)->enabled)
                    physics2D::ACollider2dComponent::checkCollision(*normal_iterator, *iterator);
                if (_game.isExiting() || _game.getSceneManager().isSceneUnloaded())
                    return;
            }
        }
    }

    void PluginCore::postUpdateInternalSystems(std::shared_ptr<Scene> &scene)
    {
        if (_game.isDebugMode())
            return;
        auto colliders = scene->getComponentsInScene<physics2D::ACollider2dComponent>();
        for (auto &collider: colliders)
        {
            if ((*collider)->enabled)
                (*collider)->debugDraw();
        }
    }

    void PluginCore::startScripts(std::shared_ptr<Scene> &scene)
    {
    }

    void PluginCore::endScripts(std::shared_ptr<Scene> &scene)
    {
    }

    void PluginCore::createConfig(std::vector<std::shared_ptr<APluginConfig>> &configs)
    {
    }

    std::unique_ptr<AComponentFactory> PluginCore::createComponentFactory()
    {
        return std::unique_ptr<AComponentFactory>(new Phys2DFactory());
    }

    std::unique_ptr<ASerializableObjectFactory> PluginCore::createSerializableObjectFactory()
    {
        return std::unique_ptr<ASerializableObjectFactory>(new SerializableObjectFactory());
    }
}

EXPORT_MODULE polymorph::engine::api::APlugin *createPlugin(polymorph::engine::config::XmlNode &data,
                                                            polymorph::engine::Engine &game, std::string PluginsPath)
{
    return new polymorph::engine::api::PluginCore(data, game, std::move(PluginsPath));
}